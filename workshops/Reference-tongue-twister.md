# Reference tongue twister

## Learning objectives
- Get comfortable with reference and pointer semantics
- Be able to trace the effects of combinations of pointers and references as a program executes

## Exercises

```cpp
#include <iostream>

int main(){
    int x = 1, y=2;
    std::cout << x << ' ' << y << '\n';

    x = 2;
    std::cout << x << ' ' << y << '\n';
    
    y = 3;
    std::cout << x << ' ' << y << '\n';

    return 0;
}
```

```cpp
#include <iostream>

int main(){
    int x = 2;
    int y = 3;
    int* z = &x;

    std::cout << x << ' ' << y << ' ' << z << ' ' << *z << '\n';
    
    x = 4;
    std::cout << x << ' ' << y << ' ' << z << ' ' << *z << '\n';

    y = 5;
    std::cout << x << ' ' << y << ' ' << z << ' ' << *z << '\n';

    z = &x;
    std::cout << x << ' ' << y << ' ' << z << ' ' << *z << '\n';

    z = (int*)6;
    std::cout << x << ' ' << y << ' ' << z << '\n';

    z = &x;
    *z = 10;
    std::cout << x << ' ' << y << ' ' << z << ' ' << *z << '\n';

    return 0;
}
```

## TODO:
- References
- Function calls
- Structures and nested data
- Things with scope

