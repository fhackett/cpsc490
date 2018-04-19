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

## Assignments

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

The markscheme is out of 3 marks, one per code snippet that matches the error your provide. Half marks for close but incorrect answers with working. [EDIT: thanks Peter] Only the first 3 answers will be marked, but further answers can be given for feedback.

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

Assignment 2 is designed to test topics surrounding CMake and linking by having students implement a synamic plugin system.

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

I have provided a set of starter files with a working CMakeLists.txt. There are 6 test cases provided for you to work against, and 2 I have left out in order to get you thinking about what other tests might be reasonable. (don't worry, I made sure there are no absurd logical leaps to arrive at the missing steps).

The challenge is to edit talker_interface.hpp until it is correct. A set of test plugins have been provided to give you an idea of what you're working with. Not all of them are well-behaved.

Since this is very crashy C-like code I left all the tests as their own programs and files and stuck with C asserts. If the test program crashes, you probably have a problem. If it runs, you are probably ok. Let me know if you hit any bizarre edge cases.

#### Specification

- If the plugin being loaded is missing a required function, talker_interface::load should throw an std::runtime_error (desirable but not required: a useful error message).
- If the plugin being loaded does not exist or there is some other kind of loading error, talker_interface::load should throw a std::runtime_error (highly recommended: with the error message provided by dlopen).
- The main program should not leak memory (defined as showing no definitely lost blocks when run under valgrind), unless a plugin leaks memory. That is out of the program's control by definition.
- You are not required to catch pointers that are neither null nor correct. Functions that are present but were compiled with the wrong signature are also out of scope.
- Within the context of the above, a rogue plugin should not be able to break other plugins. Watch for nulls. Take this spec very literally, and let me know if it's ambiguous and/or giving you trouble.
- [BONUS] Hard but rewarding: nothing the plugin does, including crashing itself or passing non-null bad pointers around, should take out the main program in an unexpected way (but catching things like a plugin installing malware is out of scope - that's a full project if you want to try). Any plugin error should be reported as a std::runtime_error (again, optional: helpful error messages). To try this, you have to create a plugin sandbox similar to Google Chrome or Firefox (back when Flash Player and Java web apps were relevant).
        Look up the POSIX fork() function: https://linux.die.net/man/3/fork
        Look up the POSIX pipe() function: https://linux.die.net/man/7/pipe
        If you want to attempt this madness, I'm happy to talk more about this.

 

#### Precise rubric

- [ 6 marks ] the code operates per spec
- [ 2 marks ] no valgrind failures (definitely leaked), -1 for 1 or 2, -2 for more than 2
- [ 2 marks ] to test if you can foresee bugs I didn't give you test cases for, 2 more test cases I will release after grading is complete
- [ + 6% to your overall grade ] you were dedicated enough to make the bonus work, wow (this is for an unambiguously complete bonus solution, I may give part credit if you can get it mostly correct)

#### Handin

The start files are provided on the course Github in the folder "hw2_starter". As before, please submit your solution via private post. This time, please put the folder you want marked in an archive. You can files to a Piazza post with Insert->Insert file.

The archive should compile at least on the grad machines, and ideally on my machine (not that you can test that). Let me know if you hit build issues - issues with that are not part of the assignment. If you are using Windows, you'll need a copy of Cygwin for POSIX functions like dlopen() to work. CMake should take care of the rest.

### Assignment 3

The challenge this time is to complete some code I've written. There are simplifications in place to avoid an explosion in complexity surrounding iterators (that's its own assignment really), so keep in mind this is not :quite: what you'd see in fully idiomatic code.

By the time you're done, something like this should work:

```
std::vector<int> foo(std::vector<int> a, std::vector<int> b){
	return make_vector(
		make_proxy(a) + make_proxy(b) * make_proxy(b)
	);
}
```

The effect is that instead of doing each piece of work one by one, some templating tricks make the entire operation this function performs run in one piece, going directly from (a,b) to the result with no significant intermediates (less well-tuned implementations might actually generate all the partial arrays, how inefficient!). The intermediates are in fact special objects representing the deferred computation that should be performed. make_vector acts as a request to actually perform the computation - though as you will see from inspecting its implementation, it is ignorant of what exactly the computation entails.

I've organised this assignment into 3 challenges - I imagine you'd want to try them in order. Let me know if you have any questions - as usual, C++ will find a way to do something confusing and/or that I may not have explained yet.

#### Challenge 1 [40%]

I've already made addition work in the code provided. Try adapting this to multiplication so the example above would run.

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

Like I showed in class, use SFINAE to make sure no-one can "misuse" these new operators we defined.

 

This example should fail with an error like "invalid operands" instead of actually trying (and also failing) to instantiate the assignment code:

```
struct X{};
X{}+X{};
```

As a hint for this one: try to think about what is unique to the proxy types you defined - how can you make sure your template parameters look like that? Do they at least have the write types and methods?

If you're still stuck, don't be afraid to ask me - there's a few different ways to do SFINAE depending on the situation and it can be a bit daunting at first.

 

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

You should edit proxy.hpp. The tests are there for your benefit - testing this stuff comprehensively is hard so I'll look at what you've actually written to determine your grade. That said, if the tests pass then your work is probably good. Let me know if you want more tests, and if so on what part(s).

### Assignment 4

Assignment 4 covers some everyday template use and some fun with classes.

There are two parts:

- to_fix: I wrote a (bad) object-oriented "graphics" library. It has bugs due to C++ OO gotchas. Find them, fix them and explain your fixes. 1 mark per bug, 1 mark per fix, 1 mark per explanation, out of 9. This should give you some practice with virtual dispatch and inheritance.
- to_complete: implement a clone of unique_ptr following the API on cppreference, except where annotated otherwise. Out of 10 marks, score based on feature completion and bug-freedom. This will involve some practice in common use of templates, as well as some hands-on experience with the rule of 5.

[Link to the starter code](https://github.com/fhackett/cpsc490/tree/master/hw4_starter)

There are no tests, but you are encouraged to write your own. Catch or anything else is acceptable. There is also no build file - writing one may be worthwhile, but is not required. You could refer to previous examples of CMakeLists.txt for inspiration.

