# Set Operations on Text Data Using Binary Search Trees

A C-based text analysis system that applies mathematical set operations — **Union**, **Intersection**, and **Difference** — to structured text data. Built for the ALSDD (Algorithms and Dynamic Data Structures) course.

By using Binary Search Trees (BSTs) as the underlying data structure, the program organizes, stores, and compares individual phrases extracted from paragraphs across multiple files, bridging formal set theory with practical text processing.

## Features

- **Robust file parsing pipeline**
  - Dynamically processes large text files with no hardcoded buffer limits.
  - Automatically sanitizes messy Windows file paths (strips quotes, spaces, and PowerShell call operators).
  - Handles cross-platform line endings (`\r\n` vs `\n`) seamlessly.

- **Abstract machine architecture**
  - Strictly separates the text parsing pipeline from the BST data structure machine, following ADT best practices.

- **Mathematical set operations via BST**
  - **Union (A ∪ B)** — merges two paragraph trees, ignoring duplicate phrases.
  - **Intersection (A ∩ B)** — extracts phrases present in both paragraphs.
  - **Difference (A \ B)** — identifies phrases unique to the first paragraph.
  - O(log N) average time complexity for insertions and lookups.

- **Immersive terminal interface**
  - Automatically relaunches in a maximized Windows Command Prompt.
  - Interactive, animated "hacker green" terminal menu.
  - Step-by-step guidance for file and paragraph selection.

- **Memory safe**
  - Thorough dynamic memory management (`malloc`, `realloc`, `strdup`).
  - Full cleanup via post-order tree traversal, preventing memory leaks on exit.

## Project Architecture

Source files are numbered to reflect the logical pipeline of the application.

**Headers / Definitions**

| File | Purpose |
|---|---|
| `00_structures.h` | Core typedefs (`tree_node`, `text_file`) |
| `01_text_processing.h` | Prototypes for string manipulation and extraction |
| `02_operations.h` | Prototypes for the BST abstract machine (set logic) |
| `03_interface.h` | Prototypes for the terminal UI and animations |

**Source Files**

| File | Purpose |
|---|---|
| `05_file_processing.c` | File I/O, path sanitization, reading files into dynamic buffers |
| `06_text_processing.c` | Parser — splits files into paragraphs (`\n`) and phrases (`. ? ! ;`), strips spaces |
| `07_main.c` | Entry point — terminal interface, state loop, end-of-program cleanup |
| `08_union.c` | Merges trees without duplicates |
| `09_intersection.c` | Tree traversal to find and extract common nodes |
| `10_difference.c` | Isolates mutually exclusive nodes |

## Prerequisites

- **Compiler:** GCC (MinGW recommended for Windows)
- **OS:** Designed primarily for Windows (uses `<windows.h>` for terminal maximization and UI elements)

## Compilation

```bash
gcc *.c -o set_analyzer.exe
```

## Usage

1. Run the compiled executable:
   ```bash
   ./set_analyzer.exe
   ```
2. The terminal automatically maximizes and displays the startup animation.
3. Enter the number of text files you wish to analyze.
4. For each file, provide the absolute path (Windows "Copy as Path" works — the program cleans the formatting automatically).
5. From the main menu, select a set operation: Union, Intersection, or Difference.
6. Select the file and paragraph number for **Set A**.
7. Select the file and paragraph number for **Set B**.
8. The program computes the operation and displays the resulting phrases in alphabetical order (in-order traversal).
9. Select **Exit** to safely free all allocated memory and close.

## Test Data Format

- Paragraphs must be separated by newlines (Enter key).
- Phrases within a paragraph must be separated by one of: `.` `?` `!` `;`

**Example:**

```
Data structures are essential; learning C is fun.
Trees are hierarchical? Binary search trees are fast.
```
