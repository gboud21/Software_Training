# Error Handling and Testing in C

This document defines the language-specific standards for error propagation, resource management, and unit testing in **C**.

---

## ⚠️ Error Handling in C

C lacks high-level language features like exceptions or built-in Option/Result wrappers. Therefore, error handling must follow strict structural patterns.

### 1. Error Status Return Codes
*   **Return Code Standard**: Functions that can fail must return a status code (typically a custom enum representing success and error states) rather than the actual data.
*   **Data Out Parameters**: The actual output of a function must be passed back via pointer parameters (out-parameters).
*   ❌ **Bad**:
    ```c
    int get_sensor_value(Sensor* s); // Returns -1 on error, or the reading on success
    ```
*   **Why**: This mixes error state with valid readings (e.g., if a valid reading is -1).
*   ✅ **Good**:
    ```c
    typedef enum {
        STATUS_SUCCESS = 0,
        STATUS_ERR_NULL_PTR,
        STATUS_ERR_TIMEOUT,
        STATUS_ERR_HW_FAIL
    } Status_t;

    Status_t get_sensor_value(Sensor* s, int* outValue);
    ```

### 2. Resource Cleanup: The `goto cleanup` Pattern
To prevent resource leaks (memory, hardware locks, file descriptors) in functions with multiple exit points, use the structured single-exit `goto cleanup` pattern. This is the **only approved exception** to the ban on `goto`.
*   **Rules**:
    *   Initialize all resources/pointers to safe defaults (e.g., `NULL`, `-1`) at the start of the function.
    *   Perform cleanup operations under a single `cleanup:` label at the bottom of the function.
    *   Do not jump backward; only jump forward to the cleanup label.
*   ✅ **Example**:
    ```c
    Status_t process_file(const char* filepath) {
        Status_t status = STATUS_SUCCESS;
        FILE* file = NULL;
        uint8_t* buffer = NULL;

        file = fopen(filepath, "r");
        if (!file) {
            status = STATUS_ERR_HW_FAIL;
            goto cleanup;
        }

        buffer = malloc(1024);
        if (!buffer) {
            status = STATUS_ERR_OUT_OF_MEM;
            goto cleanup;
        }

        // Process file logic here...

    cleanup:
        if (buffer) free(buffer);
        if (file) fclose(file);
        return status;
    }
    ```

### 3. Checking System Calls
*   Always check the return value of system and library calls (e.g., `malloc`, `read`, `write`).
*   Where thread safety allows, check `errno` to diagnose the specific cause of failure for standard library functions.

---

## 🧪 Unit Testing in C

### 1. Frameworks
*   Use lightweight testing frameworks suitable for C:
    *   **Unity**: Excellent for embedded microcontrollers.
    *   **cmocka**: Great for mocking and desktop-hosted testing of C code.

### 2. Link-Time Mocking
*   Since C does not support runtime polymorphism (interfaces/virtual tables) out of the box, use **link-time mocking** (e.g., the linker `--wrap` option in GCC) to isolate units under test from hardware or external dependencies.

### 3. Assertions
*   Use `assert()` from `<assert.h>` to catch programmer errors (preconditions, invalid states) during development.
*   Ensure that production builds disable assertions (compile with `NDEBUG`) to prevent unexpected crashes in deployed devices, substituting them with runtime recovery logic.
