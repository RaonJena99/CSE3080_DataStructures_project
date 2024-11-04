# CSE3080_DataStructures_project

---

# CSE3080 Data Structures Assignments

This repository contains solutions for two assignments focused on data structures: **String Pattern Matching** and **Minimum Spanning Tree (MST) Calculation**. Each project is implemented in C, with specific requirements and constraints on input/output formatting, error handling, and performance. Below is a detailed description of each assignment.

## Table of Contents
1. [Assignment 1: String Pattern Matching](#assignment-1-string-pattern-matching)
2. [Assignment 2: Minimum Spanning Tree (MST) Calculation](#assignment-2-minimum-spanning-tree-mst-calculation)

---

## Assignment 1: String Pattern Matching

### Overview
This assignment involves implementing string pattern matching algorithms, both a **Naïve Algorithm** and the **Knuth-Morris-Pratt (KMP) Algorithm**. The assignment consists of two problems: detecting multiple occurrences of a substring within a string and finding the largest integer `n` such that a string `s` can be represented as a repetition of a substring.

### Problem Descriptions

#### Problem 1-1: Pattern Occurrence Detection
- Implement two versions of a program to find occurrences of a substring `pat` in a string `str`:
  - `hw1_naive`: Uses the Naïve algorithm with a time complexity of \(O(mn)\).
  - `hw1_kmp`: Uses the KMP algorithm with a time complexity of \(O(m + n)\).
- Both programs should read the input from files `string.txt` (for `str`) and `pattern.txt` (for `pat`), and output the results in `result_naive.txt` and `result_kmp.txt`, respectively.
- Output format:
  - The first line contains the count of `pat` occurrences in `str`.
  - The second line lists the starting positions of each occurrence.

#### Problem 1-2: Largest Substring Repetition
- Implement a program `hw1_problem2` that uses the KMP algorithm to find the largest integer `n` such that a string `s` can be represented as `a^n` for some substring `a`.
- The input is read from `string.txt`, with each line containing a separate string `s`.
- Output format:
  - `result.txt` should contain the integer `n` for each input string on a separate line.

### Files and Structure
- **Directory structure**:
  ```
  cse3080_hw1_studentID
  ├── problem1
  │   ├── Makefile
  │   ├── hw1_naive.c
  │   └── hw1_kmp.c
  ├── problem2
  │   ├── Makefile
  │   └── hw1_problem2.c
  ```
- **Makefile**:
  - Compile using `make`, producing executables `hw1_naive`, `hw1_kmp`, and `hw1_problem2`.
- **Error Handling**:
  - If input files are missing, print an error message (e.g., "The string file does not exist") and terminate.

### Example Usage
```bash
./hw1_naive string.txt pattern.txt
./hw1_kmp string.txt pattern.txt
./hw1_problem2 string.txt
```

### Performance Requirements
- **Efficiency**: Ensure `hw1_kmp` runs faster than `hw1_naive` on large input files.
- **Memory Management**: Handle long strings (up to 9,999,999 characters) without segmentation faults.

---

## Assignment 2: Minimum Spanning Tree (MST) Calculation

### Overview
This assignment requires implementing **Kruskal's Algorithm** to find the Minimum Spanning Tree (MST) of an undirected graph. The MST calculation is optimized using a min-heap and disjoint-set trees to achieve a time complexity of \(O(E \log E)\), where `E` is the number of edges.

### Requirements

1. **Program**:
   - Implement a single C program named `fp1`.
   - The program reads a graph from an input file specified as a command-line argument, computes the MST, and writes the results to `fp1_result.txt`.

2. **Input Format**:
   - The first line contains the number of vertices.
   - The second line contains the number of edges.
   - Each subsequent line represents an edge with three values: two vertex endpoints and the edge weight.

   **Example**:
   ```
   7
   9
   0 1 28
   0 5 10
   1 2 16
   1 6 14
   ...
   ```

3. **Output Format**:
   - List each edge in the MST in ascending order of weights, followed by the total cost and connectivity status.
   - **Example output**:
     ```
     0 5 10
     2 3 12
     1 6 14
     ...
     99
     CONNECTED
     ```

4. **Additional Requirements**:
   - Error handling:
     - Print a usage message if the command-line argument count is incorrect: `usage: ./fp1 input_filename`.
     - Print an error if the input file does not exist.
   - Running Time:
     - At the end of the program, print the total running time, e.g., `running time: 0.073622 seconds`.

### Files and Structure
- **Directory structure**:
  ```
  cse3080_hw2_studentID
  ├── Makefile
  └── fp1.c
  ```
- **Makefile**:
  - Compile using `make`, producing an executable named `fp1`.

### Example Usage
```bash
./fp1 input.txt
```

### Performance and Constraints
- Support up to 10,000 vertices and 50,000,000 edges.
- Implement using data structures that meet the required time complexity, such as min-heaps and disjoint sets.

---

## Submission Guidelines

1. Each assignment should be compressed into a zip file:
   - `cse3080_hw1_studentID.zip` for Assignment 1.
   - `cse3080_hw2_studentID.zip` for Assignment 2.
2. Follow the specified directory structure exactly to avoid penalties.
3. Ensure the code compiles and runs on the designated environment before submission.

---

This `README.md` provides a complete guide to the projects, with details on structure, requirements, and usage. Each program is rigorously tested to meet performance and functionality specifications.
