#include "UniqPtr.hpp"
#include <gtest/gtest.h>

int main(int argv, char** argc){
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);

    // Run all tests
    return RUN_ALL_TESTS();
}
