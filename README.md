# Line Operations

This project implements a program to process input lines according to specified rules. The program reads one line of input from the terminal, which is expected to consist of two parts separated by a colon ":". It then applies various comparisons to these parts and produces a single character as a result.

## Functionality

The program categorizes input lines based on the following rules:

- **N**: No colon on the line.
- **L**: The left part (before the colon) is longer than the right.
- **R**: The right part (after the colon) is longer than the left.
- **D**: The left and right parts have the same length but are different.
- **S**: The left and right parts are exactly the same.
- **M**: The left is a mirror of the right part.
- **P**: The left part is part of the right part.
- **Q**: Each character in the left part is found in the right part.

## Example Inputs and Outputs

- **N**: No colon on the line.
  - Input: `Sample Sample`
  - Output: `N`

- **L**: The left part is longer than the right.
  - Input: `Short:Long`
  - Output: `L`

- **R**: The right part is longer than the left.
  - Input: `Long:Short`
  - Output: `R`

- **D**: The left and right parts have the same length but are different.
  - Input: `Ahmed:Islam`
  - Output: `D`

- **S**: The left and right parts are exactly the same.
  - Input: `Sample:Sample`
  - Output: `S`

- **M**: The left is a mirror of the right part.
  - Input: `Ahmed:demhA`
  - Output: `M`

- **P**: The left part is part of the right part.
  - Input: `abc:ppabctt`
  - Output: `R P Q`

- **Q**: Each character in the left part is found in the right part.
  - Input: `abc:pcpattb`
  - Output: `R Q`

