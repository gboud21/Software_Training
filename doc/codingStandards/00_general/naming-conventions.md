# General Naming Conventions

This document defines the naming standards for all codebase components. Consistent and descriptive naming is critical for readability and team collaboration.

---

## 🎯 Core Rules

### 1. Intent-Revealing Names
The name of any variable, function, or class must clearly reveal **why it exists**, **what it does**, and **how it is used**. If a name requires a comment to explain its purpose, the name is inadequate.
*   ❌ **Bad**: `int d; // elapsed time in days`
*   ✅ **Good**: `int elapsedTimeInDays;`

### 2. Pronounceable and Searchable Names
*   **Discussion Friendly**: Avoid cryptic acronyms. If you cannot pronounce a name, you cannot easily discuss it during code reviews.
*   **Search friendly**: Choose names that are easy to locate via text search. Single-letter names (e.g., `e`, `t`) should only be used as local loop counters or within small lambda expressions. Any variable with scope larger than a few lines must have a searchable name.

### 3. Avoid Encodings & Noise Words
*   **No Hungarian Notation**: Do not prefix variables with type indicators (e.g., `i_count` or `str_name`). Modern compilers and IDEs handle type tracking.
*   **No Member Prefixes**: Avoid prefixing member variables with `m_` or `_` unless required by specific language requirements.
*   **No Noise Words**: Avoid meaningless distinctions like `AccountInfo` vs. `AccountData` vs. `Account`. If they represent the same concept, use one name.

---

## 🏛️ Parts of Speech and Casing

Different code components must follow specific casing and grammatical patterns:

| Component | Case Style | Part of Speech | Example |
| :--- | :--- | :--- | :--- |
| **Classes / Structs** | `PascalCase` | Noun or Noun Phrase | `DeviceManager`, `TelemetryPacket` |
| **Interfaces** | `PascalCase` | Noun / Adjective | `Reader`, `Serializable` |
| **Methods / Functions** | `camelCase` | Verb or Verb Phrase | `initializeHardware()`, `readSensor()` |
| **Variables** | `camelCase` | Noun or Adjective | `sampleCount`, `isActive` |
| **Constants** | `SCREAMING_SNAKE_CASE` | Noun | `MAX_BUFFER_SIZE`, `BAUD_RATE` |
| **Enums** | `PascalCase` | Noun | `ConnectionState` (values: `CONNECTED`) |

> [!NOTE]
> For interfaces, avoid prefixing with `I` (e.g., `IStorage`) unless it is a strict standard of the target language/framework (e.g., C#). If you must differentiate interfaces from implementations, suffix the implementation (e.g., `Storage` -> `FileStorage`).

---

## 🔄 Concept Consistency

Choose one word for each abstract concept and use it consistently across the entire codebase. Do not mix synonyms:
*   Pick **one** retrieval word: `get()`, `fetch()`, or `retrieve()`.
*   Pick **one** controller word: `Manager`, `Controller`, or `Handler`.
*   Pick **one** write word: `save()`, `persist()`, or `write()`.
