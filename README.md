LeetCode-Style Prompt: Implement MyUniquePtr

Problem Statement

You are tasked with implementing a custom smart pointer class, MyUniquePtr, that mimics the core functionality of std::unique_ptr in C++. The MyUniquePtr class must adhere to the following requirements:
	1.	Ownership Semantics:
	•	MyUniquePtr should take ownership of a raw pointer upon construction.
	•	It should ensure that the owned object is deleted when the MyUniquePtr is destroyed.
	•	Ownership is unique, meaning no two MyUniquePtr instances should manage the same raw pointer.
	2.	Non-Copyable:
	•	The MyUniquePtr must not allow copy operations. Both copy construction and copy assignment should be disabled.
	3.	Dereference Operators:
	•	Implement operator* to dereference the raw pointer.
	•	Implement operator-> to access members of the managed object.
	4.	Custom Deleters:
	•	Support the ability to pass a custom deleter function or functor during construction. This custom deleter will be called when the managed object is destroyed.