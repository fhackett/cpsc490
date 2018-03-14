
/**
 * A reimplementation of the classic unique_ptr from the
 * C++ standard library.
 *
 * see here: http://en.cppreference.com/w/cpp/memory/unique_ptr
 *
 * Your implementation must match the official specification precisely,
 * except where noted. To avoid clutter, we will not be covering compatibility
 * with auto_ptr or usage with deleters.
 *
 * Notation will be closely related to the specification linked above, if
 * in doubt look at the relevant section there.
 *
 * Follow the C++17 versions of the spec points when in doubt, and watch out
 * for the template specialisation.
 */
template<typename T>
class my_unique_ptr{
public:
    /**
     * Constructor.
     *
     * For simplicity, skip the following overloads 3, 4 and 7.
     * For overload 6, follow this instead:
     * template<class U> my_unique_ptr(my_unique_ptr<U>&& u) noexcept;
     */

    /**
     * Do not implement get_deleter(), as we do not support them.
     */

private:
    T* p;
};

/**
 * Specialisation for arrays goes here.
 */

/**
 * Implementing make_unique is optional; you do not have to, but it
 * is interesting to do so if you want to go above and beyond.
 */

/**
 * You are not required to implement operator<< or std::hash.
 */

// tests go here, testing is encouraged. use catch.hpp maybe?

