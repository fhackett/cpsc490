# Compiler errors

A very common issue programmers encounter (when compilers are involved) is compiler errors.

This exercise attempts to turn the usual practice of getting an error and asking "well what does that mean?", or hiding in a corner (or both) on its head.
Normally you get compiler errors by accident and have to figure them out on the spot.
This time, we go looking for them in order to get familiar with what each one really means.

TODO: classify these errors by the point in the course at which people should be able to understand the code that generates them.

Try to write code that generates the following errors:
- expected expression
- no matching function for call to [...]
- use of undeclared identifier
- redefinition of [...]
- functions that differ only in their return type cannot be overloaded
- attempt to use a deleted function
- no viable overloaded [...]
- member reference base type [...] is not a structure or union
- no member named [...] in [...]
- no viable conversion from returned value of type [...] to function return type [...]
- excess elements in struct initializer
- call to implicitly-deleted default constructor of [...]
- non-constant-expression cannot be narrowed from type [...] to [...] in initializer list
- cannot be narrowed from type
- cannot assign to variable [...] with const-qualified type
- cannot assign to non-static data member within const member function
- member function [...] not viable: 'this' argument has type 'const [...]', but function is not marked const
- recursive template instantiation exceeded maximum depth of [...]

Also try to get the compiler to add these notes to the above errors:
- in instantiation of function template specialization
- in instantiation of template class

Try to write code that generates the following warnings:
- unused variable [...]
- control reaches end of non-void function 
- implicit conversion from [...] to [...] changes value from [...] to [...]

