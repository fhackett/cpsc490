# Learning Goals Breakdown

## Read, Write, Debug

- Given a statement in C++ and sufficient context, identify which functions will
be called and what code will likely be executed.
- Given a compiler error and code, identify location(s) in the code that
might produce this error
- Given a runtime error, code and a debugger if necessary, identify constructs
that might cause that error
    - Understand the difference between the location at which the error became apparent
    and the code that caused the error
    - Develop an intuition for what aspects of C++ one can and cannot trust when
    a program is not functioning correctly
- Given a specification and a C++ reference manual, write code that follows that
specification.
    - Observe subtleties of different C++ constructs that help and hinder different
    operations

## Performance

- Given code and appropriate context, determine best, worst and average case asymptotic
performance of that code
- Given a piece of code and appropriate context, refine initial performance estimates
using knowledge of:
    - cache locality
    - blocking and non-blocking operations

## Usability and maintainability

- Given an interface defined in C++ and a context in which it is expected to be used,
assess which operations from that context can apply to that interface and whether they
do what one would expect.
- Given some code, assess how easy it might be to understand based on:
    - Levels of indirection used
    - (Mis)alignment between the commonly expected use of a feature and what it is actually
    used for
    - To what extent the apparent intention behind code matches what the author intended
    it to do
- Provide a variety of task examples for a given API
- Perform basic user research (for example, among classmates) on their code to assess how
it might be used by others

## Template Metaprogramming

- Understand the difference between compile time and runtime computation
- Given a function or class, abstract away types in order to make it generic
- Given an expression that uses templates, explain what that expression will do with
reference to both the expression itself and its interaction with any template variables
- Given a specification for an operation, implement it in such a way that the resulting
implementation is usable at compile time
- Assess the potential performance and usability impacts of C++ expressions in a generic
context, i.e when the user may alter one or more types or functions at will
    - Different types have different costs for their operations (copying, arithmetic...)
    - Bad matchups between assumed usage and actual usage can lead to subtle bugs
    and performance issues
- Given some C++ template code and a specification of the expected inputs and outputs
of that code, modify the code so that providing improper inputs fails to compile
    - Bonus: with an understandable error message

