# Everything is a fixed size

This topic explores memory management in C++.

## Learning objectives
- Learn the difference between:
    - stack allocation
    - static allocation
    - dynamic allocation
- Identify advantages and disadvantages of each
- Appreciate how a memory allocator works
- Get some experience and context

## Preparation

- Prepare to think about memory models
- Bring your existing knowledge of multithreading
- Try checking out some of the links before you come. Some skimming of them is assumed.

## Outline

- What does std::vector do?
- Heap allocation, good and bad
    - Effects on concurrency?
    - You have to wait for malloc
    - [jemalloc](http://jemalloc.net/)
    - [Hoard allocator](http://people.cs.umass.edu/~emery/pubs/berger-asplos2000.pdf)
- Avoiding heap allocation (why, how)
- Let's build an allocator [with Andrei Alexandrescu](https://www.youtube.com/watch?v=LIb3L4vKZ7U)

