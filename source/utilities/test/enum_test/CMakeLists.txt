set(TARGET_NAME enum_test)

# Create a variable to contain the source files
set(TEST_SRC
    ExtendableEnum-test.cpp
    )


# This command tells CMake to create an executable using the specified source code files
add_library(${TARGET_NAME}
            ${TEST_SRC}
            )

target_link_libraries(${TARGET_NAME}
                    gtest_main
                    utl_enum
                    )

target_include_directories(${TARGET_NAME} PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}")
