# A seminar on programming practice

## Introduction

The goal of this seminar is to explore basic programming via discussion and practical experimentation.
Students can expect to question, debate, critique and (re)create the basic constructs and patterns they use in programming on a day to day basis.
The main language will be C++ due to the variety of constructs that can be written in it and the interesting variations in accepted practice that exist within communities that use it.
To help students reach the level of proficiency in C++ required for the course, workshops will be given on some interesting features and common practices in the language.

## Learning Goals
    
By the end of the seminar, students should be able to:
    
- Read, write and debug a variety of programs in C++.
- Reason about the performance, usability and maintainability of programming styles in C++.
- Have a basic understanding of template metaprogramming.
- Reason about abstraction using at least the following devices, and assess their situational appropriateness:
    - [Type erasure](https://akrzemi1.wordpress.com/2013/12/06/type-erasure-part-ii/)
    - Inheritance
    - [Iterators, and by extension ranges](http://ericniebler.com/2014/11/07/ranges-concepts-and-the-future-of-the-standard-library/)
    - [Resource Acquisition Is Initialization](http://en.cppreference.com/w/cpp/language/raii)
    - Move semantics and move-only types
    - [Tagged unions](http://en.cppreference.com/w/cpp/utility/variant)
    - Operator overloading

Students should also have tried and reflected on their own design/reimagining and implementation of a given abstraction, chosen from (but not limited to):
- strings
- mappings
- graphs
- concurrency primitives (atomics, futures)
- task scheduling and execution
- data serialization/deserialization
- some aspect of the C++ standard library

## Grading criteria

Here is a preliminary set of assignments with proposed weightings:
<dl>
    <dt>Weekly homework [30%]</dt>
    <dd>
    To be completed and handed in at the end of the week, one or two small summative coding problems.
    These could be graded electronically.
    </dd>
    <dt>Final project [70%]<dt>
    <dd>
    Students present an exploration of one of the topics listed in the learning goals, complete with two or more implementations of their chosen abstraction and reflections on each.
    This would be split into at least one milestone with one of the implementations, and a final peer-reviewed presentation at the end of term.
    </dd>
</dl>

### Final project rubric

Grading of the project elements would be by presentation to the group.
Assessment would be in terms of the completion of the implementations they provide and their ability to reflect on their progress: what did they achieve, what worked, what didn't, why?

Based on both the presentation and code reviews, grading could be done almost entirely by peers, though attention would be required to make sure grading remains as fair and objective as possible.

## Interesting links

- [The Godbolt compiler](https://gcc.godbolt.org/) (shows you the assembly output by different compilers given your source code)

