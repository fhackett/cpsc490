
struct empty{};

template<auto fst_, typename Rst_>
struct cons{
    static const auto fst = fst_;
    using Rst = Rst_;
};

template<typename List>
struct sum{
    static const auto value = List::fst + sum<typename List::Rst>::value;
};

template<>
struct sum<empty>{
    static const auto value = 0;
};

template<template<auto> class Fn, typename List>
struct map{
    using Result = cons<
        Fn<List::fst>::Result,
        typename map<Fn, typename List::Rst>::Result>;
};

template<template<auto> class Fn>
struct map<Fn, empty>{
    using Result = empty;
};

template<int x>
struct Transform{
    static const int Result = x*2;
};

int main(){
    using MyList = cons<1,cons<2,cons<3,empty>>>;
    using MyList2 = map<Transform, MyList>::Result;
    return sum<MyList2>::value;
}

