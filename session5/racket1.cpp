
template<auto Fst_, typename Rst_>
struct cons{
    static const auto Fst = Fst_;
    using Rst = Rst_;
};

struct empty{};

using List1 = cons<
    5,
    cons<
    5,
    cons<
    6,
    cons<
    314,
    empty>>>>;

template<int N, typename L>
struct get_n{
    static const auto value = get_n<N-1, typename L::Rst>::value;
};

template<typename L>
struct get_n<0, L>{
    static const auto value = L::Fst;
};

int main(){
    return get_n<3, List1>::value;
}

