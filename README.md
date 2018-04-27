# Seminar on programming practice

This is a seminar that functions aims to create a space where students can learn more about programming in practice, or practical programming.
It has been run once so far, and this document covers initial intentions behind the course, how they turned out and recommendations for future running of the course based on observations from the first run-through.


For the sake of a common language, most of the course is taught in C++. This is not a limitation however, and comparisons may be drawn when relevant to other languages and specific systems.
Since 3rd and 4th year UBC students will have encountered C++ before, some basic knowledge of the language is assumed.

The course is composed of one project, a set of taught topics and a series of assignments.

Course materials list:
- https://godbolt.org/
- http://en.cppreference.com/w/

Interesting video links:
- GoingNative 2013 C++ Seasoning: https://www.youtube.com/watch?v=W2tWOdzgXHA
- CppCon 2015: Andrei Alexandrescu “std::allocator...”: https://www.youtube.com/watch?v=LIb3L4vKZ7U
- CppCon 2014: Mike Acton "Data-Oriented Design and C++: https://www.youtube.com/watch?v=rX0ItVEVjHc

## Table of Contents

  * [Topics](#topics)
     * [Hello World dismantled](#hello-world-dismantled)
     * [Build systems, intro to CMake](#build-systems-intro-to-cmake)
     * [How C   represents objects](#how-c-represents-objects)
     * [Intro to templates](#intro-to-templates)
     * [Advanced topics in templates](#advanced-topics-in-templates)
     * [Operator overloads](#operator-overloads)
     * [Lambdas, functional programming in C  ](#lambdas-functional-programming-in-c)
     * [Discussion session: C++ best practices](#discussion-session-c-best-practices)
     * [Approaches to asynchrony](#approaches-to-asynchrony)
     * [Personal topics: bring an interesting piece of code](#personal-topics-bring-an-interesting-piece-of-code)
     * [Discussion session: C++ current affairs, politics and future direction](#discussion-session-c-current-affairs-politics-and-future-direction)
  * [Assignments](#assignments)
     * [Assignment 1](#assignment-1)
     * [Assignment 2](#assignment-2)
        * [Specification](#specification)
        * [Precise rubric](#precise-rubric)
     * [Assignment 3](#assignment-3)
        * [Challenge 1 [40\x]](#challenge-1-40)
        * [Challenge 2 [45\x]](#challenge-2-45)
        * [Challenge 3 [15\x]](#challenge-3-15)
        * [Starter files](#starter-files)
     * [Assignment 4](#assignment-4)
  * [Project](#project)
     * [Can it be in a language other than C++?](#can-it-be-in-a-language-other-than-c)
     * [What kind of thing could I have as a project?](#what-kind-of-thing-could-i-have-as-a-project)
  * [Grading criteria](#grading-criteria)
     * [Assignments](#assignments-1)
     * [Project rubric](#project-rubric)

## Topics

An interesting aspect of the course topics is that they are flexible.
It is viable and encouraged that students propose topics to be explored - we did this by creating a topic board and choosing topics as we went along.

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

This section is organised as presentation notes - it is unlikely to be useful as handouts.
Recommended future work is to produce more handouts that are targeted at students.

### Hello World dismantled

This worked as the introductory session.
Students were encouraged to bring a version of the classic Hello World program in C/C++ so that we could discuss it.

Key points to discuss:

- What each part of the program does - there are at least 2 ways to print to the console, `std::cout` and `printf`.
You can highlight what the `<<` syntax actuall does, maybe question how they achieve the effect of printing to the console. (does one of the students have a systems background?)
It also pays to look at what `#include` does in general.

- What it a translation unit? Which translation unit is a header part of?

- Touch on linking, in our case we ran into an interesting edge case where one of the Hello World programs was missing an `#include` but ran anyway due to a linker quirk.

- What is the compiler actually doing?
    - Parsing your code
    - Preprocessor step
    - Generating object files
    - Running the linker

- What can a binary program look like? (touch on ELF files, static, dynamic and runtime linking)

### Build systems, intro to CMake

This topic was introduced via an idea board - asking students to contribute different build systems they've dealt with.
The intention here is to paint an overall picture of different build systems, what they can be used for and what tradeoffs they make.

Then, the idea is to zoom into practical usage of CMake on some small example projects.

- Bring in 2-3 examples of working builds (see https://github.com/fhackett/cpsc490/tree/master/session4 for the ones I covered)
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

See this table for reference: http://en.cppreference.com/w/cpp/language/operators

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

### Lambdas, functional programming in C++

Key points to discuss:
- lambda syntax `[...](...) -> ... {...}`
- a callable is something with a call operator (see previous topic)
- what is a lambda really? (it's a struct with a call operator)
- discuss std::function, take a look at compiles compared to plain lambdas in godbolt
- discuss meta-functions and revisit `std::algorithm`

### Discussion session: C++ best practices
Project rubric

This topic uses a different format to the others - we used a semi-official set of best practices guidelines published here: 

The purpose is for each student to read through parts of the document that are interesting to them and comment, question and discuss the guidelines.
Care should be taken to consider context.
Is something universally true, or is it just often true?
What tradeoffs do the guidelines make?

### Approaches to asynchrony

This session covers a lot of ground, functioning as more of a taster than necessarily one single learning process.
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

Examples of topics that have been presented:
- Blocks and coroutines in Ruby
- Hacking Python's integers to make `3 == 2` become true
- JavaScript's event loop, examples of how to write long-running code without hanging the browser
- Scala syntax sugar (`fmap`)
- Rust's borrow checker (it's just like move semantics)
- Notes on how to perform asynchronous processing with PHP in a production system (similar issues to JavaScript)

### Discussion session: C++ current affairs, politics and future direction

This session is part discussion part news-reading.
It functions well as a closing session.

Points of interest:
- Discuss the linked articles
- Highlight C++'s committee structure and its effect on the language
- All the articles linked contain copious references to future work for C++, encourage questions on that topic

Articles discussed:
- http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0592r0.html
- https://herbsutter.com/2017/07/15/trip-report-summer-iso-c-standards-meeting-toronto/
- https://botondballo.wordpress.com/2017/11/20/trip-report-c-standards-meeting-in-albuquerque-november-2017/

We also discussed the IBM trigraphs controversy: https://isocpp.org/files/papers/N4210.pdf

## Assignments

Overall the assignments described here should form a decent starting point. During the course we noticed that the small number of assignments lead to difficulty spikes between them.

A way to work around this could be to increase the number of assignments and make them a more significant part of the course load both in terms of time and grading.

Some ideas for supplementary assignments:
- Create a build system for a set of source files. Similar to the example builds from the CMake session, but without the CMakeLists. There would be one very basic build with source code that just uses the standard library, then some more difficult examples like: a build that requires a specific feature/version of C++; a build that requires linking to a third-party library. Assessment could be performed based on robustness - it is important to be able to identify cross-platform build issues.
- Fixing template errors. Similar to assignment 4 but with more emphasis on common template issues, students would have the opportunity to witness and learn from a wide variety of mistakes in handling templates.
- Reimplement std::vector. Either with templates or without, reimplementing this common data structure can be very educational. It puts into practice all of the constructor/assignment overloads and provides a good exercise in more general-purpose memory management. When involving templates, it also demonstrates things like placement-new if you require students to implement `emplace_back`.
- Implement an atomic increment. If we represent an N-bit integer as `std::atomic<bool>[N]`, design and implement an algorithm that will increment that number. The catch is that the algorithm has to be concurrency-safe without using locks. This means you can only use atomic operations, so you have to think through all the possible interleavings of operations and design an algorithm that will work under all possible interleavings.

### Assignment 1

This exercise is provided to give a basic introduction to compiling code.

Provide three code snippets that will fail to compile with one of the following compilation errors (as long as the meaning is correct, the exact wording is not required - these come from clang, explain your reasoning if in doubt):

- expected expression, or expected [...] after expression
- no matching function for call to [...]
- invalid operands to binary expression
- use of undeclared identifier
- no viable conversion from [...] to [...], or assigning from incompatible type
- no viable overloaded [...]

One should be able to paste your code into the Godbolt compiler and see that error (or something that means the same thing) in the output. One error per piece of code, and you should specify which error each code should produce.

The markscheme is out of 3 marks, one per code snippet that matches the error your provide. Half marks for close but incorrect answers with working. Only the first 3 answers will be marked, but further answers can be given for feedback.

For those that are not confident in their C++, start with the Hello World below and experiment with breaking it and reading the errors produced. There are some curveballs, but you should find enough to get 3/3 with some experimentation and minimal changes to the code.

```
#include <iostream>

int main(){
int i = 2;
std::cout << "Hello World!\n";
std::cout << i << "\n";
return 0;
}
```

### Assignment 2

Starter files: https://github.com/fhackett/cpsc490/tree/master/hw2_starter

Assignment 2 is designed to test topics surrounding CMake and linking by having students implement a dynamic plugin system.

The general concept is to make this kind of code work:

```
#include "talker_interface.hpp"

int main(){
	auto talker1 = talker_interface::load("mytalker1.so");
	auto talker2 = talker_interface::load("mytalker2.so");
	auto instance1 = talker1.make();
	auto instance2 = talker2.make();
	// should return
	// "(talker 1) says Hello to (talker 2)"
	std::string result = instance1.say_to(instance2, "Hello");
	std::cout << result << "\n";
	return 0;
}
```

There will be a set of starter files with a working CMakeLists.txt. There are 6 test cases provided for students to work against, and 2 have left out in order to get students thinking about what other tests might be reasonable.

The challenge is to edit talker_interface.hpp until it is correct. A set of test plugins have been provided as examples of the kind of plugins that will be used as tests. Not all of them are well-behaved.

Since this is very crashy C-like code all the tests are their own programs and files and use C asserts. If the test program crashes, you probably have a problem. If it runs, you are probably (but not necessarily) ok.

#### Specification

- If the plugin being loaded is missing a required function, talker_interface::load should throw an std::runtime_error (desirable but not required: a useful error message).
- If the plugin being loaded does not exist or there is some other kind of loading error, talker_interface::load should throw a std::runtime_error (highly recommended: with the error message provided by dlopen).
- The main program should not leak memory (defined as showing no definitely lost blocks when run under valgrind), unless a plugin leaks memory. That is out of the program's control by definition.
- You are not required to catch pointers that are neither null nor correct. Functions that are present but were compiled with the wrong signature are also out of scope.
- Within the context of the above, a rogue plugin should not be able to break other plugins. Watch for nulls. Take this spec very literally, and make sure to ask questions if it's ambiguous and/or giving you trouble.

#### Precise rubric

- [ 6 marks ] the code operates per spec
- [ 2 marks ] no valgrind failures (definitely leaked), -1 for 1 or 2, -2 for more than 2
- [ 2 marks ] to test if you can foresee bugs I didn't give you test cases for, 2 more test cases I will release after grading is complete

### Assignment 3

The challenge this time is to complete some code. There are simplifications in place to avoid an explosion in complexity surrounding iterators (that's its own assignment really), so keep in mind this is not :quite: what you'd see in fully idiomatic code.

By the time you're done, something like this should work:

```
std::vector<int> foo(std::vector<int> a, std::vector<int> b){
	return make_vector(
		make_proxy(a) + make_proxy(b) * make_proxy(b)
	);
}
```

The effect is that instead of doing each piece of work one by one, some templating tricks make the entire operation this function performs run in one piece, going directly from (a,b) to the result with no significant intermediates (less well-tuned implementations might actually generate all the partial arrays, how inefficient!). The intermediates are in fact special objects representing the deferred computation that should be performed. make_vector acts as a request to actually perform the computation - though as you will see from inspecting its implementation, it is ignorant of what exactly the computation entails.

The assignment is organised into 3 challenges. Make sure to ask questions - as usual, C++ will find a way to do something confusing and/or that I may not have explained yet.

#### Challenge 1 [40%]

Addition works in the code provided. Try adapting this to multiplication so the example above would run.

#### Challenge 2 [45%]

Further extend this set of operations with a concatenation operator. For example:

make_vector(make_proxy(a) | make_proxy(b))

should give you a vector that is the combined length of a and b (a.size() + b.size()), containing all the elements of a followed by all the elements of b.


Performing arithmetic on any intermediate values should work, as in:

```
make_vector((make_proxy(a)|make_proxy(b)) * (make_proxy(b)|make_proxy(a)))
```

should work the same as the first example, but with the elements multiplied together as well.

#### Challenge 3 [15%]

Use SFINAE to make sure no-one can "misuse" these new operators we defined.

This example should fail with an error like "invalid operands" instead of actually trying (and also failing) to instantiate the assignment code:

```
struct X{};
X{}+X{};
```

As a hint for this one: try to think about what is unique to the proxy types you defined - how can you make sure your template parameters look like that? Do they at least have the write types and methods?

There are a few different ways to do SFINAE depending on the situation and it can be a bit daunting at first, so don't be discouraged if your first try doesn't work.

Here's a mini-example where the struct SFINAE will only compile if you pass it a type with a member T:

```
struct Test{
	using T = int;
};
struct BadTest{};

template<typename Input, typename=typename Input::T>
struct SFINAE{};

using TryIt = SFINAE<Test>;
//fails
// using TryIt2 = SFINAE<BadTest>;
```

#### Starter files

Available here: https://github.com/fhackett/cpsc490/tree/master/hw3_starter

You should edit proxy.hpp. The tests are there for your benefit - since the rubric includes compile errors your code will be tested onits own merits rather than against a test suite. That said, if the tests pass then your work is probably good. If something is ambigous feel free to request extra tests on a particular area.

### Assignment 4

Assignment 4 covers some everyday template use and some fun with classes.

There are two parts:

- to_fix: someone wrote a (bad) object-oriented "graphics" library. It has bugs due to C++ OO gotchas. Find them, fix them and explain your fixes. 1 mark per bug, 1 mark per fix, 1 mark per explanation, out of 9. This should give you some practice with virtual dispatch and inheritance.
- to_complete: implement a clone of unique_ptr following the API on cppreference, except where annotated otherwise. Out of 10 marks, score based on feature completion and bug-freedom. This will involve some practice in common use of templates, as well as some hands-on experience with the rule of 5.

Starter code: https://github.com/fhackett/cpsc490/tree/master/hw4_starter

There are no tests, but you are encouraged to write your own. Catch or anything else is acceptable. There is also no build file - writing one may be worthwhile, but is not required. You could refer to previous examples of CMakeLists.txt for inspiration.

## Project

A lot of the project is described by its grading rubric. The project is very free-form and provides a platform for students to investigate topics they are interested by trying to build something.

One thing that is not on the rubric: it is important that students present a written proposal for their topic of choice including setting goals for their milestones. This helps people get an idea together and sets an expectation for what students will need to do / talk about at their first milestone presentation.

Here are some notes on how the project went in the form of an FAQ.

### Can it be in a language other than C++?

Possibly, but only if a good rationale is given. Embedded scripting languages for example can be a very useful tool if used correctly.


### What kind of thing could I have as a project?

Here is a series of examples from previous iterations of the class:
- Foodie, an esoteric scripting language which tries to follow the semantics of cooking recipes
- A Minecraft mod (written in C++ despite Minecraft running on the JVM) that builds and analyses a dataflow graph between machines in the game
- An investigation into the relative benefits of tiling vs. quadtree data structures in a gaming context
- Writing a neural net and training it to play Mario Kart (interesting screen capture challenge, as well as a lot of numeric C++)
- A clone of BASH featuring some support for process management (requires a lot of reading about POSIX)
- A networked multiplayer game with an unusual strategy for resolving disagreements between game clients (written using the Godot engine, makes use of Godot's embedded scripting language for some game logic)

## Grading criteria

The course had a mix of assignments and project work.
70% of the course grade was split evenly between the 3 project milestones, and the other 30% was split evenly between assignments.

### Assignments

Assignments were fairly well-received overall, but if given as-is they cause some problematic difficulty spikes. See recommendations from the assignments section on possible future work.

The late policy as given was -1/3 of the total mark per day, but it might also be worth trying a per-minute penalty since that makes being late by an hour less of a problem.

### Project rubric

The spirit of the project is to gain experience writing unique code, dealing with unique problems and writing/talking about them.

There will be monthly milestone presentations where students will present and discuss the state of their project. These presentations will be graded. This course spans 3 and a bit months, so there will be 3 milestones, one at the end of each month. The final milestone will also be the final presentation.

The grading scheme for each milestone is as follows (each milestone will be worth 1/3 of the full project, and be out of 10):

- [2 marks] Does the thing perform as described?
        When presenting your project you should describe what you did and how it works
        If it is possible to crash your project or make it fail to compile while following that description, that is a problem. i.e state all dependencies and assumptions including OS, compiler type, libraries, usage, etc...
- [2 marks] Have the goals set in the last milestone been achieved, and if not did you reflect on why?
        You started with a goal in mind. Did you reach it? To what extent?
- [2 marks] Did this milestone teach you something useful?
        If you can convincingly claim you learned something, you will get marks.
        This ensures the grader judges your project's value to you, not whether it would be interesting to the grader.
- [2 marks] Is a future direction described, and does it relate meaningfully to current findings and the project brief?
        Where are you going next? Are you properly referring to your existing work and reflecting on it?
        It is possible to demonstrate that your current project is a dead end and start something new without losing marks, but you must be clear and convincing.
- [2 marks] Is the code as readable as similar real-world code?
        If you can argue that your code would be readable to a group of real-world developers, it is ok. If necessary, you can identify that group or cite a project you're basing your coding style on.
- [1 mark, bonus] Did this teach someone else something new?

