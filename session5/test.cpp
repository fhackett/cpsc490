#include <iostream>
#include <string>
#include <type_traits>

template<typename T>
struct correct_type{
    using type = T;
};

template<>
struct correct_type<int>{
};

/*std::string add(std::string a, std::string b){
    return a+b;
}*/

template<typename T>
typename std::enable_if<
    std::is_integral<T>::value,
    T>::type
add(std::string a, T b){
    return a.size()+b;
}

template<typename T>
struct pointless{
    T value;
};

template<int x_>
struct pointless2{
    static const int x = x_;
};

template<>
struct pointless2<3>{
    static const int x = 5;
};

int main(){
    std::string aa = "aa", bb = "bb";
    std::cout << add(aa, std::size_t(22)) << pointless2<6>::x << "\n";
    return 0;
}

