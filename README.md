*This project was created as part of the 42 curriculum by pifonsec*

##Description

The push_swap project is a highly effective exercise in algorithm complexity. The goal is simple: sort a stack of integers using a limited set of instructions, with the lowest possible number of operations.

You are given two stacks, Stack A and Stack B. You must find the most efficient way to move and sort the numbers until Stack A is ordered from smallest to largest and Stack B is empty.

##Instructions

Operations :

The program can only use the following movements:

    sa, sb, ss: Swap the first two elements of a stack.

    pa, pb: Push the top element from one stack to another.

    ra, rb, rr: Rotate the stack (first element becomes the last).

    rra, rrb, rrr: Reverse rotate (last element becomes the first).

How to use :

    Compile the project using make.

    Run the program:
    
    Pass a list of integers as arguments. The program will output the shortest list of instructions to sort them.

    ./push_swap 2 1 3 6 5 8

    Visualization / Verification:
    To check if the list is sorted and see the count:

    ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

Technical Features

    Error Handling: Manages non-numeric parameters, duplicates, and integers exceeding the INT_MIN or INT_MAX limits.

    Efficiency: Designed to sort 100 numbers in fewer than 700 moves and 500 numbers in fewer than 5500 moves (for full points).

    Memory Management: Strictly follows the 42 Norm, ensuring no memory leaks and proper cleanup of the stacks.

Resources

    AI was used to structure this README and assist in debugging potential memory leaks or logic errors in the sorting algorithm.
