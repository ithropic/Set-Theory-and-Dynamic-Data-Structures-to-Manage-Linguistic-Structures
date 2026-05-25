================================================================================
PROJECT: SET OPERATIONS ON TEXT DATA USING BINARY SEARCH TREES
COURSE: ALSDD (Algorithms and Dynamic Data Structures)
================================================================================

--------------------------------------------------------------------------------
1. PROJECT ABSTRACT
--------------------------------------------------------------------------------
This project is a C-based text analysis system designed to apply mathematical 
set operations—namely Union, Intersection, and Difference—to structured text 
data. By utilizing Binary Search Trees (BST) as the underlying data structure, 
the application efficiently organizes, stores, and compares individual phrases 
extracted from paragraphs across multiple files. 

The software bridges the gap between formal set theory and practical data 
processing, providing a robust, high-performance environment for identifying 
textual overlaps and unique content.

--------------------------------------------------------------------------------
2. KEY FEATURES
--------------------------------------------------------------------------------
* Robust File Parsing Pipeline:
  - Dynamically processes large text files without hardcoded buffer limits.
  - Automatically sanitizes messy Windows file paths (stripping quotes, spaces, 
    and PowerShell call operators).
  - Handles cross-platform line endings (\r\n vs \n) seamlessly.

* Abstract Machine Architecture:
  - Strictly separates the "Text Parsing Pipeline" from the "BST Data Structure 
    Machine," adhering to best practices for Abstract Data Types (ADTs).

* Mathematical Set Operations via BST:
  - Union (A ∪ B): Merges two paragraph trees, ignoring duplicate phrases.
  - Intersection (A ∩ B): Extracts phrases present in both paragraphs.
  - Difference (A \ B): Identifies unique phrases present only in the first.
  - O(log N) average time complexity for insertions and lookups.

* Immersive Terminal Interface:
  - Automatically relaunches itself in a maximized Windows Command Prompt.
  - Features an interactive, animated "Hacker Green" terminal menu.
  - Step-by-step guidance for file and paragraph selection.

* Memory Safe:
  - Thorough dynamic memory management (malloc, realloc, strdup).
  - Full memory cleanup implementation (Post-order tree traversal to free nodes) 
    preventing memory leaks upon program termination.

--------------------------------------------------------------------------------
3. PROJECT ARCHITECTURE & FILES
--------------------------------------------------------------------------------
The source code is modularly structured into numbered files to reflect the logical 
pipeline of the application:

[ Headers / Definitions ]
* 00_structures.h       : Contains core typedefs (tree_node, text_file).
* 01_text_processing.h  : Prototypes for string manipulation and extraction.
* 02_operations.h       : Prototypes for the BST Abstract Machine (Set Logic).
* 03_interface.h        : Prototypes for the terminal UI and animations.

[ Source Files ]
* 05_file_processing.c  : Handles file I/O, path sanitization, and reading 
                          entire files into dynamic memory buffers.
* 06_text_processing.c  : The "Parser" - breaks down files into paragraphs (\n) 
                          and phrases (delimited by .?!;), stripping spaces.
* 07_main.c             : The entry point. Manages the terminal interface, 
                          state loop, and end-of-program memory deallocation.
* 08_union.c            : Core logic for merging trees without duplicates.
* 09_intersection.c     : Tree traversal logic to find and extract common nodes.
* 10_difference.c       : Logic to isolate mutually exclusive nodes.

--------------------------------------------------------------------------------
4. PREREQUISITES & COMPILATION
--------------------------------------------------------------------------------
* Compiler: GCC (MinGW for Windows recommended).
* Operating System: Designed primarily for Windows (utilizes <windows.h> for 
  terminal maximization and UI elements).

To compile the project via terminal:
    gcc *.c -o set_analyzer.exe

--------------------------------------------------------------------------------
5. USAGE INSTRUCTIONS
--------------------------------------------------------------------------------
1. Run the compiled executable:
   ./set_analyzer.exe
2. The terminal will automatically maximize and display the startup animation.
3. Enter the number of text files you wish to analyze.
4. For each file, provide the absolute path. (You can safely use Windows 
   "Copy as Path"; the program will automatically clean the formatting).
5. From the main menu, select the Set Operation you want to perform (Union, 
   Intersection, or Difference).
6. Select the file and the specific paragraph number for "Set A".
7. Select the file and the specific paragraph number for "Set B".
8. The program will compute the operation and display the resulting phrases 
   in alphabetical order (In-order traversal).
9. Select "Exit" from the main menu to safely free all allocated memory and close.

--------------------------------------------------------------------------------
6. TEST DATA STRUCTURE
--------------------------------------------------------------------------------
To test the program, ensure your text files are formatted as follows:
- Paragraphs must be separated by the Return/Enter key (Newlines).
- Phrases inside paragraphs must be separated by standard delimiters: 
  period (.), question mark (?), exclamation point (!), or semicolon (;).

Example:
Data structures are essential; learning C is fun.
Trees are hierarchical? Binary search trees are fast.

================================================================================
