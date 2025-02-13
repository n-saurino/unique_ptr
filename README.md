# MyUniquePtr Implementation Challenge

## Problem Description

Implement a custom smart pointer class `MyUniquePtr` that mimics the core functionality of `std::unique_ptr` in C++. The implementation must provide unique ownership semantics, proper resource management, and support for custom deleters.

## Core Requirements

### 1. Ownership Semantics
- Take ownership of raw pointer upon construction
- Ensure proper deletion of owned object upon destruction
- Maintain unique ownership (no shared ownership)

### 2. Non-Copyable Behavior
- Disable copy construction
- Disable copy assignment
- Support move semantics

### 3. Pointer Operations
- Implement dereference operator (`*`)
- Implement member access operator (`->`)
- Support pointer ownership transfer

### 4. Custom Deleter Support
- Accept custom deleter during construction
- Use custom deleter for resource cleanup
- Support both function pointers and functors

## Interface

```cpp
template<typename T, typename Deleter = std::default_delete<T>>
class MyUniquePtr {
public:
    // Constructors
    explicit MyUniquePtr(T* ptr = nullptr);
    MyUniquePtr(T* ptr, Deleter d);
    
    // Move semantics
    MyUniquePtr(MyUniquePtr&& other) noexcept;
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept;
    
    // Disable copy operations
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;
    
    // Destructor
    ~MyUniquePtr();
    
    // Operators
    T& operator*() const;
    T* operator->() const;
    
    // Utility functions
    T* get() const;
    T* release();
    void reset(T* ptr = nullptr);
    
private:
    T* ptr_;
    Deleter deleter_;
};
```

## Example Usage

```cpp
// Basic usage
MyUniquePtr<int> ptr1(new int(42));
std::cout << *ptr1 << std::endl;  // Prints 42

// Custom class
class MyClass {
public:
    void doSomething() { std::cout << "Hello\n"; }
};

MyUniquePtr<MyClass> ptr2(new MyClass());
ptr2->doSomething();  // Calls MyClass::doSomething()

// Custom deleter
auto customDeleter = [](int* p) {
    std::cout << "Custom deleting: " << *p << std::endl;
    delete p;
};

MyUniquePtr<int, decltype(customDeleter)> ptr3(new int(100), customDeleter);
```

## Technical Requirements

### Memory Management
1. Proper resource acquisition
2. Guaranteed resource release
3. No memory leaks
4. Exception safety

### Move Semantics
1. Efficient ownership transfer
2. No resource duplication
3. Proper null state handling
4. Strong exception guarantees

### Custom Deleter Support
1. Type-safe deleter storage
2. Proper deleter invocation
3. Support for stateful deleters
4. Support for reference deleters

## Best Practices

1. Use RAII principles
2. Implement proper move semantics
3. Handle null pointers correctly
4. Provide strong exception guarantees
5. Maintain const correctness

## Testing Considerations

### Test Scenarios
1. Basic pointer operations
2. Move semantics
3. Custom deleters
4. Edge cases
5. Exception handling

### Validation Points
1. Memory leak detection
2. Proper ownership transfer
3. Correct deletion behavior
4. Exception safety
5. Move semantics correctness

## Common Pitfalls to Avoid

1. Memory leaks during transfers
2. Double deletions
3. Incorrect null state handling
4. Poor exception handling
5. Improper deleter type handling

## Follow-Up Questions

1. How would you implement array support?
2. How can you optimize for small object optimization?
3. What considerations are needed for polymorphic types?
4. How would you handle custom allocators?
5. What thread safety guarantees would you provide?
