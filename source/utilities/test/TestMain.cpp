#include <gtest/gtest.h>

#include "Error-test.cpp"
#include "ExtendableEnum-test.cpp"

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}