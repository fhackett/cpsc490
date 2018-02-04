#pragma once

#include <type_traits>
#include <vector>

/**
 * The main idea behind this system is proxy objects - they wrap
 * things, mostly other proxy objects, providing an lazy interface
 * to sequences.
 *
 * Proxy objects must have the following members:
 * - type : a the type of the elements the proxy yields
 * - size() : reports the size of the sequence the proxy represents
 * - get(pos) : returns a copy of the element at position pos in proxy's sequence
 *
 * You'll notice any class here has a make_* function that returns an instance of it.
 * This is because C++ prior to C++17 can only guess the template parameters of
 * template functions, not classes. Notice that the example code does not have any <>
 * to say what any types are, it's all inferred.
 */

namespace proxy{
/**
 * This is a proxy to a sequence - it holds a reference to that sequence
 * and yields copies of its elements or reports its size on request.
 *
 * It also has a type member "type" that describes the type of the elements
 * it yields.
 */
template<typename T, typename Sequence>
class sequence_proxy{
    Sequence const& sequence;
    public:
    using type = T;
    constexpr sequence_proxy(Sequence const& sequence):
        sequence{sequence}
    {}
    constexpr std::size_t size() const{
        return std::distance(std::begin(sequence), std::end(sequence));
    }
    constexpr T get(std::size_t pos) const {
        return sequence[pos];
    }
};

template<typename Sequence>
constexpr
auto make_proxy(Sequence const& sequence) ->
sequence_proxy<
    // some "magic" to get the sequence's element type
    // basically reads as:
    // - say hypothetically that I had a value of type Sequence (std::declval)
    // - now let's say I obtained an iterator to its beginning (std::begin)
    //   note: it's the only thing you can do reliably on any type, it even works on native
    //   arrays!
    // - now let's say I dereference the iterator (iterators work like pointers, it's a *)
    // - now tell me the type of what I get (decltype)
    // - but first, remove any & or const from it (std::decay) so my code doesn't get
    // random & and consts in it where there shouldn't be any
    //
    // not too bad once you know what the bits do right?
    // (feel free to ask questions if you're curious)
    typename std::decay<
        decltype(*std::begin(std::declval<Sequence>()))>::type,
    Sequence>
{
    return {sequence};
}

/**
 * A proxy that holds a reference to two other proxies and yields
 * their elements added together. It reports its size as the minimum
 * of the size of the two proxies it uses. Probably not the best for
 * error reporting, but it works.
 */
template<typename P1, typename P2>
class adder_proxy{
    P1 const& p1;
    P2 const& p2;
    public:
    using type = typename std::common_type<
        typename P1::type,
        typename P2::type
        >::type;
    adder_proxy(P1 const& p1, P2 const& p2):
        p1{p1},
        p2{p2}
    {}
    std::size_t size() const {
        return std::min(p1.size(), p2.size());
    }
    type get(std::size_t pos) const {
        return p1.get(pos) + p2.get(pos);
    }
};

/**
 * This is the adder_proxy's make_* function as an operator.
 * Just add two proxies together and you get an adder_proxy.
 */
template<typename P1, typename P2>
adder_proxy<P1, P2>
operator+(P1 const& p1, P2 const& p2){
    return {p1, p2};
}

/**
 * Takes a proxy and converts it to a vector. There's a
 * much more interesting polymorphic version of this that
 * generalises to all containers but it requires iterators.
 * That's probably for next time :)
 */
template<typename Proxy>
std::vector<typename Proxy::type>
make_vector(Proxy const& p){
    std::vector<typename Proxy::type> v;
    // since we know how big this vector can get, preallocate
    // enough memory so we skip resizes in push_back
    v.reserve(p.size());
    for(std::size_t i = 0; i < p.size(); ++i){
        v.push_back(p.get(i));
    }
    return v;
}

}

