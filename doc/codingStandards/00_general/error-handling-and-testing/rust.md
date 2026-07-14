# Error Handling and Testing in Rust

This document defines the language-specific standards for error propagation, panic safety, and unit testing in **Rust**.

---

## ⚠️ Error Handling in Rust

Rust lacks standard exceptions, enforcing error handling at compile time using the type system via `Result<T, E>` and `Option<T>`.

### 1. Recoverable Errors: `Result` & the `?` Operator
*   **Result Pattern**: Functions that can fail must return a `Result<T, E>`.
*   **The `?` Operator**: Use the `?` operator to propagate errors up the call stack cleanly. Avoid boilerplate `match` or `if let` blocks unless error conversion or logging is needed at the call site.
*   **Actionable Errors**: Define custom error enums representing all failure modes. Annotate them with descriptive display messages.
    ```rust
    #[derive(Debug)]
    pub enum SensorError {
        Timeout,
        InvalidData,
        BusError,
    }
    ```

### 2. Unrecoverable Errors: Panics
Panics (`panic!`, `unwrap()`, `expect()`) bypass standard control flow and terminate the thread (or application).
*   **No Panics in Production Code**: Do not call `unwrap()` or `expect()` in library, driver, or application code where failures are possible. Handle errors gracefully and propagate them as `Result`.
*   **Exceptions for `expect()`**: Calling `expect()` is only allowed:
    *   In unit test code.
    *   In code examples.
    *   To declare an impossible logical state (e.g., locking a mutex that cannot be poisoned).
*   **Format**: Always write a descriptive reason inside `expect()` explaining why the operation *must* succeed:
    ```rust
    // Approved usage: mutex poisoning is an unrecoverable system state
    let guard = lock.lock().expect("mutex poisoned by failing thread");
    ```

### 3. Option vs. Result
*   Use `Option<T>` when the absence of a value is a normal and expected state, and no explanation is required (e.g., a cache miss).
*   Use `Result<T, E>` when the absence of a value indicates a failure, and the caller needs to understand *why* it failed.

---

## 🧪 Unit Testing in Rust

Rust features a built-in testing framework that is highly integrated into the language.

### 1. Test Location
*   **Unit Tests**: Must be written in the same file as the production code they test, inside an inline module annotated with `#[cfg(test)]`. This allows testing private functions.
*   **Integration Tests**: Place in a separate `tests/` directory at the root of the project/crate.

### 2. Standard Structure
*   A standard test module structure:
    ```rust
    #[cfg(test)]
    mod tests {
        use super::*;

        #[test]
        fn test_sensor_read_success() {
            // Given (Build)
            let sensor = MockSensor::new(42);

            // When (Operate)
            let val = sensor.read();

            // Then (Check)
            assert_eq!(val, Ok(42));
        }
    }
    ```

### 3. Verification & Panic Testing
*   Use `assert!`, `assert_eq!`, and `assert_ne!` for validation.
*   For testing code that is *expected* to panic under certain conditions, annotate the test function with the `#[should_panic]` attribute, including the expected panic message fragment:
    ```rust
    #[test]
    #[should_panic(expected = "index out of bounds")]
    fn test_out_of_bounds() {
        let list = vec![1, 2];
        let _val = list[5];
    }
    ```
