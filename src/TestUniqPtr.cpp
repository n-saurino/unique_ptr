#include <gtest/gtest.h>
#include "UniqPtr.hpp"

struct TestStruct {
    int value;
    void increment() { value++; }
};

TEST(UniqPtrTest, Constructor) {
    UniqPtr<int> uniqPtr(new int(10));
    EXPECT_EQ(*uniqPtr, 10);
}

TEST(UniqPtrTest, Destructor) {
    // This test ensures no crash or memory leak occurs upon destruction.
    UniqPtr<int> uniqPtr(new int(20));
    // No explicit EXPECT statement; the test will pass if there are no runtime errors.
}

TEST(UniqPtrTest, MoveConstructor) {
    UniqPtr<int> uniqPtr1(new int(30));
    UniqPtr<int> uniqPtr2(std::move(uniqPtr1));
    
    EXPECT_EQ(*uniqPtr2, 30);
    EXPECT_EQ(uniqPtr1.get(), nullptr); // Original pointer should be null after move
}

TEST(UniqPtrTest, MoveAssignmentOperator) {
    UniqPtr<int> uniqPtr1(new int(40));
    UniqPtr<int> uniqPtr2(new int(50));
    
    uniqPtr2 = std::move(uniqPtr1);
    
    EXPECT_EQ(*uniqPtr2, 40);
    EXPECT_EQ(uniqPtr1.get(), nullptr); // Original pointer should be null after move
}

TEST(UniqPtrTest, OperatorDereference) {
    UniqPtr<int> uniqPtr(new int(60));
    EXPECT_EQ(*uniqPtr, 60);
}

TEST(UniqPtrTest, OperatorArrow) {
    UniqPtr<TestStruct> uniqPtr(new TestStruct{10});
    uniqPtr->increment();
    EXPECT_EQ(uniqPtr->value, 11);
}

TEST(UniqPtrTest, GetPointer) {
    int* rawPtr = new int(70);
    UniqPtr<int> uniqPtr(rawPtr);
    EXPECT_EQ(uniqPtr.get(), rawPtr);
}