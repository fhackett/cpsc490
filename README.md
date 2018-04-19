# Seminar on programming practice

This is a seminar that functions aims to create a space where students can learn more about programming in practice, or practical programming.
It has been run once so far, and this document covers initial intentions behind the course, how they turned out and recommendations for future running of the course based on observations from the first run-through.


For the sake of a common language, most of the course is taught in C++. This is not a limitation however, and comparisons may be drawn when relevant to other languages and specific systems.
Since 3rd and 4th year UBC students will have encountered C++ before, some basic knowledge of the language is assumed.
The course is composed of one project, a set of taught topics and a series of assignments.

## Topics

An interesting aspect of the course topics is that they are flexible.
It is viable and encouraged that students propose topics to be explored - we did this by creating a topic board.
Not all topics were covered in the end, but those that were will be discussed here.
The different versions of the topic board are available as an appendix.

Topics we covered:

- Hello World dismantled (semantics, translation units and linking)
- Build systems, intro to CMake
- How C++ represents objects (classes and vtables)
- Intro to templates
- Operator overloads (case study: how iterators work)
- Discussion session: C++ best practices
- Approaches to asynchrony
- Functional programming in C++
- Personal topics: bring an interesting piece of code
- C++ current affairs, politics and future direction

### Hello World dismantled

This worked as the introductory session.
Students were encouraged to bring a version of the classic Hello World program in C/C++ so that we could discuss it.

Key points to discuss:

- What each part of the program does - there are at least 2 ways to print to the console, `std::cout` and `printf`.
You can highlight what the `<<` syntax actuall does, maybe question how they achieve the effect of printing to the console. (does one of the students have a systems background?)
It also pays to look at what `#include` does in general.

- What it a translation unit? Which translation unit is a header part of?

- Touch on linking, in our case we ran into an interesting edge case where one of the programs was missing an `#include` but ran anyway due to a linker quirk.

- What is the compiler actually doing?
    - Parsing your code
    - Preprocessor step
    - Generating object files
    - Running the linker

- What can a binary program look like? (touch on ELF files, static, dynamic and runtime linking)

### Build systems, intro to CMake

This topic was introduced via an idea board - asking students to contribute different build systems they've dealt with.
The intention here was to paint an overall picture of different build systems, what they can be used for and what tradeoffs they make.

Then, the idea was to zoom into practical usage of CMake on some small example projects.

At the time I was blinded by variety and attempted to cover too many build systems, harming the overall ability of students to internalise the concepts.
After discussing general build systems, it is important to transition to one specific build system on which you have prepared a good amount of material.

As a mixture of future recommendation and an account of how I went back over what didn't go so well in the next session, here is how this should be done:

- Bring in 2-3 examples of working builds (see the folder for the ones I covered)
- Before revealing how the working builds are set up, present the problem scenarios.
- Prompt students to suggest workarounds or methods that might work, discuss any suggestions.
- Provide an overview of how CMake approaches the issues discussed (or how it fails to approach them in some cases)
- While not done in my run of the course, set an assignment to set up 3 more builds:
    - One simple build with 2 files that link to form one executable
    - One simple library that has one header file and one implementation file, with another executable that uses it (possible in a different project since that helps push students to figure out how inter-project dependencies work)
    - One more complex build where students need to link an external library (something like Lua, but not Lua as that is already provided here)

### How C++ represents objects

This session was mostly done using live coding and the Godbolt compiler explorer.

We would sketch out different class hierarchies and look at what they compiled to by looking at the assembly output.
Some management of compiler optimisation flags was necessary in order to stop the compiler from omitting important details.

Key points to discuss:

- Classes and structs are the same thing
- The mechanism behind inheritance (you just stack them)
- Upcasting and downcasting
- The diamond problem
- Virtual functions and vtables
- What is virtual inheritance?
- Private inheritance

In student feedback it was noted that there could have been more take-home examples. I agree - here are some key gotchas that should have been covered here but came up at various other points instead:
- calling virtual functions from a constructor doesn't do what you think
- non-virtual destructors and runtime polymorphism don't mix
- overloading a virtual method does not make the overload virtual (overloading and overriding are not the same)
- using the `override` specifier for great profit
- polymorphism can work with both pointers and references
- object slicing (why you can't store a derived class in an array of their base class)

Recommended assignment: 

### Intro to templates

C++ has a powerful generic programming system, and it is important to understand how it works in the context of more traditional programming features.
Specifically, this might be the first time students see language semantics that operate specifically at compile time.

As it was presented the course in general over-emphasized SFINAE and advanced "tricks".
These are important, but require more groundwork than was done.
This topic and the advanced templates topic's notes have been rearranged to reflect this.

Key points to discuss:
- Templates are a way for you to ask the compiler to copy-paste code for you while replacing certain things
- Yes macros can do something similar, but the compiler gives ... better ... error messages with templates
- You can template the following:
    - Functions
    - classes / structs (because they are the same thing)
    - variables (post-C++14)
    - type aliases (`using`) (since C++11)
- You can use these things to replicate "generics" from other languages, and to reproduce some advantages scripting languages have for generic programming.
- It is possible to "specialise" templates, that is: you can redefine a templated class or function using a special syntax, so that the new definition if chosen under some circumstances and not others.
- Template substitution is Turing complete - can you see how?

### Advanced topics in templates

There are a lot of interesting things you can do with templates other than just making generic functions.
As with many more advanced features of C++, they can both aid and harm code quality.
They can be used to create a small core of very involved code that drastically reduces the complexity of the rest of the application or library you are working on.
Using templates everywhere is usualy a bad idea however, unless you know why you are using them.

Here are some tricks that have come into usage:
- Recursive templates: functional programming in the type system (requires template specialisation)
- Hypothecticals: `decltype` and `std::declval`
- SFINAE: Substitution Failure Is Not An Error, or proof that the C++ committee does not care for snappy acronyms (arguably the hardest trick here, useful if you want to enforce that template arguments have certain properties)

### Operator overloads

When designing a class, you can provide a specialised implementation of almost any operation that is possible on a class.
Some of these come pre-generated, others default to not being available.

See this table for reference: 

Key points to discuss:
- Constructors, destructors, copying, moving ... what do they do?
    - What's an rvalue reference?
    - Rule of 0-3-5:
        - Rule of 0: define only specialised constructors that are not copy constructors or move constructors, nothing else
        - Rule of 3: define only copy constructors, copy assignment and a destructor
        - Rule of 5: define copy constructors, move constructors, copy assignment, move assignment and a destructor (that is, all the things)
- Try to define a semantically meaningful set of operators - discussion point: what's a value type? What do you expect from it? Can you think of other common interfaces in C++? (hint: pointers?)
- Talk about std::algorithm and iterators

The single hardest thing you can do in this topic is talk about iterators.
They are very useful and important, but defining them is also incredibly difficult and time-consuming.
We did a session on this which went all right but could have done with more context.

### Lambdas, functional programming in C++

Key points to discuss:
- lambda syntax `[...](...) -> ... {...}`
- a callable is something with a call operator (see previous topic)
- what is a lambda really? (it's a struct with a call operator)
- discuss std::function, take a look at compiles compared to plain lambdas in godbolt
- discuss meta-functions and revisit `std::algorithm`

### Discussion session: C++ best practices

This topic uses a different format to the others - we used a semi-official set of best practices guidelines published here: 

The purpose is for each student to read through parts of the document that are interesting to them and comment, question and discuss the guidelines.
Care should be taken to consider context.
Is something universally true, or is it just often true?
What tradeoffs do the guidelines make?

### Approaches to asynchrony

This session covered a lot of ground, functioning as more of a taster than necessarily one single learning process.
The goal was to provide a primer on approaches to asynchrony, both in terms of how C++ can deal with them and what they look like in general.

Key points to discuss:
- Threads
- OS threads vs. "green" threads
- Thread pools
- Event loops (boost::asyncio)
- Futures
- How asynchrony applies to data structures:
    - Locking
    - Atomic operations

Questions to discuss: where are the interfaces here?

Possible follow-up exercise: implement an atomic binary increment on a binary number represented as a `std::vector<std::atomic<bool>>`

### Personal topics: bring an interesting piece of code

This is a free-form session with no material, only a format.
Students are instructed to bring a piece of code that is somehow interesting to them, and to be prepared to describe and discuss it.

Topics that have been presented:
- Blocks and coroutines in Ruby
- Hacking Python's integers to make `3 == 2` become true
- JavaScript's event loop, examples of how to write long-running code without hanging the browser
- Scala syntax sugar (`fmap`)
- Rust's borrow checker (it's just like move semantics)

### Discussion session: C++ current affairs, politics and future direction

This session is part discussion part news-reading.
It functions well as a closing session.

I posted a set of articles for students to read ahead of time, then we discussed them.
I also fielded questions raised on the consequences of "design by committee".

