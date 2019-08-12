# CS 165: Project 1
This project involves testing various sorting algorithms and determining their 
real-world running times experimentally.

# Motivation
This is based on the instructions for the first project of CS 165. How I am approaching the project is test-driven, with the tests being made first before
the sorts are applied onto the inputs. Each sort will be done on randomized input.

# Tech/Framework Used
**Build with:**
- C++
    - cmath
    - ctime
    - iostream
    - ifstream
    - random
    - vector
- Python
    - matplotlib
    - numpy
- LaTeX
- Bash

# Features
The project can sort a vector of *n* integers with the following:
- Bubble Sort
- Insertion Sort
- Spin-the-Bottle Sort
- Shell Sort with modifiable parameters
- Annealing Sort with modifiable parameters

In addition, the project comes with these features:
- generator for randomized input
- timer to test sorted input
- functions to graph out the data
- a report with analysis on sorting algorithm performance

# How to use?

# TODO
- Fix the include folder paths
- Include the <chrono> library
- Fix shell sort