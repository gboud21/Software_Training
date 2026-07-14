# Comments and Formatting Standards

This document defines the rules for using code comments and enforcing consistent visual layout (formatting) across the project.

---

## 💬 Comments

Comments are a double-edged sword. While they can provide necessary context, they can also become out-of-date and mislead readers. **Clean code should explain itself without comments.**

### 1. Prohibited Comments (Code Smells)
*   **No Commented-Out Code**: Never check in commented-out code. It clutters files and creates confusion about whether it is needed. Delete it—version control will preserve the history.
*   **No Redundant Comments**: Do not write comments that merely restate what the code clearly does.
    ```java
    // Increment the count
    count++; 
    ```
*   **No Journal/Log Comments**: Do not maintain a log of edits at the top of a file. Use Git commit messages for this purpose.
*   **No Noise Comments**: Avoid trivial comments that add no information, such as `// default constructor` or `// getter for name`.

### 2. Approved Comments
*   **Legal & Copyright**: Standard licensing, copyright, and authorship headers at the top of source files.
*   **Explanation of Intent**: Comments explaining *why* an unusual or non-obvious solution was chosen (e.g., choosing a specific algorithm due to hardware limits).
*   **Warning of Consequences**: Warning other developers about potential pitfalls.
    ```c
    // NOTE: This call blocks the thread for up to 500ms. Do not call inside an ISR.
    ```
*   **TODO Comments**: Marked as `// TODO: (Owner) Description`. All TODOs must include an owner or a tracking ticket.

---

## 📐 Formatting

Consistent formatting ensures code looks professional and reads easily.

### 1. Vertical Formatting
*   **File Length**: Keep source files short. Most files should be between **100 and 300 lines**. Avoid files exceeding 500 lines.
*   **Vertical Openness**: Separate logical sections (imports, variable blocks, functions) with a single blank line.
*   **Vertical Distance**:
    *   **Local Variables**: Declare local variables immediately before their first use.
    *   **Instance/Member Variables**: Declare variables in a single, consistent location and format them according to language-specific standards (see Section 3 below).
    *   **Calling/Called Functions**: If function `A` calls function `B`, they should be vertically adjacent, with the caller `A` located above the callee `B`.

### 2. Horizontal Formatting
*   **Line Width**: Keep code lines short to prevent horizontal scrolling. The standard limit is **100 characters** (maximum 120 characters).
*   **Spacing**:
    *   Put spaces around assignment operators: `int count = 0;` (not `int count=0;`).
    *   No spaces between a function name and its opening parenthesis: `calculateTotal(value);`.
    *   Put a space after commas in argument lists: `execute(arg1, arg2, arg3);`.
*   **Indentation**: Code must be indented to show its block hierarchy. Never collapse short `if` statements or loops into a single line.

### 3. Member and Instance Variables (C / C++ / Rust)

To ensure memory efficiency and readable class interfaces, apply these language-specific standards for instance variables and struct fields:

#### C (Struct Members)
*   **Location**: Defined inside the `struct` block in header files (`.h`).
*   **Alignment Optimization**: Order struct fields by byte-size in descending order (e.g., pointers and 64-bit types first, then 32-bit, 16-bit, and 8-bit). This prevents compiler-inserted padding bytes and minimizes memory footprint.
*   **Documentation**: Annotate every struct member with trailing comments detailing unit of measure, bounds, or scaling factors.
    ```c
    struct SensorReading {
        uint32_t timestampMs; // System uptime in milliseconds
        int16_t temperature;  // Temperature in Celsius (Q12.4 format)
        uint8_t sensorId;     // Hardware bus identifier
    };
    ```

#### C++ (Class Member Variables)
*   **Location**: Always declare private and protected member variables at the **bottom** of the class definition, below all public constructors and methods. This highlights the public API first.
*   **Naming**: Suffix all private and protected member variables with a single trailing underscore (e.g., `baudRate_`). This prevents naming collisions with constructors/getters and avoids the need for prefix noise (like `m_`) or using `this->`.
*   **Initialization**: Initialize member variables directly at the point of declaration (inline initialization) or in the constructor initialization list. Never leave a member variable uninitialized.
    ```cpp
    class Controller {
    public:
        explicit Controller(uint32_t id) : deviceId_(id) {}
    private:
        uint32_t deviceId_;
        bool isEnabled_ = false; // Inline initialization
    };
    ```

#### Rust (Struct Fields)
*   **Location**: Declared inside the `struct` definition in source files (`.rs`).
*   **Casing**: Always use `snake_case` for field names.
*   **Visibility**: Keep fields private by default. Only expose fields via `pub` if the struct is a passive Data Transfer Object (DTO) with no invariants.
*   **Documentation**: Use outer doc comments (`///`) immediately above each field to detail invariants or scaling factors.
    ```rust
    pub struct PacketHeader {
        /// Unique packet identification number.
        pub sequence_id: u16,
        /// Payload length in bytes.
        pub size: u8,
    }
    ```
