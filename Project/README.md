*This project has been created as part of the 42 curriculum by adaza-ru.*

# Push Swap

## Description
Push Swap is a 42 project focused on algorithms and optimization using stack operations.

### Project goals:

Sort a list of integers with the smallest possible number of operations.
Use only the allowed operations on two stacks: a and b.

### Quick overview:

**Mandatory program (push_swap):** takes integers as arguments and prints the sequence of operations needed to sort them.

**Bonus program (checker):** takes integers as arguments, then reads operations from standard input and checks whether the final result is sorted (OK), not sorted (KO), or invalid (Error).

### Technical Notes
Stacks are implemented as circular doubly linked lists.

Input parsing validates:
* Numeric format
* int range
* Duplicates

Bonus checker reads commands line by line with get_next_line, validates each command, and executes it on the stacks.

## Instructions

### Build
``make all``

This builds both binaries in this multi-binary project: ``push_swap`` & ``checker``


**Other available targets:**
```
make mandatory
make bonus
make clean
make fclean
make re
```


### Run
**Example (mandatory):**
``./push_swap 3 2 1``

**Example (bonus check):**
``./push_swap 3 2 1 | ./checker 3 2 1``

**Example with manual operations:**
```bash
./checker 2 1 3
sa
<Ctrl+D>
```
### Stress Test
```bash
ARG=$(shuf -e $(seq 0 499) | awk -v min=-2147483648 -v max=2147483647 'BEGIN{srand();}{print int(min + rand() * (max - min + 1))}' | tr '\n' ' ')
valgrind --leak-check=full ./push_swap $ARG 2> leaks.txt | tee >(wc -l) | ./checker_linux $ARG; grep -E "ERROR SUMMARY|definitely lost|indirectly lost" leaks.txt
```

## Algorithm Overview
The project uses different strategies depending on input size, working with normalized indexes to simplify comparisons.

### Small Inputs (3 and 5 elements)

**For 3 elements:**

A direct case-based routine is used.
It checks the relative order of the top/middle/bottom values and applies a minimal sequence of operations (sa, ra, rra).

**For up to 5 elements:**

The smallest indexed values are pushed to stack b.
The remaining 3 values in a are sorted with the 3-element routine.
Elements are pushed back from b to a, fixing local order when needed.

### Large Inputs

For larger inputs, the algorithm uses a dynamic chunk:

* Compute a chunk size proportional to sqrt(n) with the Newton-Raphson Method, scaled by a constant factor.
* Push from a to b in waves:
	* If top of a has index less than or equal to current boundary, push to b.
	* For very small indexes, push then rotate b to place them deeper.
	* Otherwise rotate a until a suitable element appears.
* Once all elements are in b, rebuild a in descending index order:
	* Find target index position from both directions in b.
	* Rotate b in the shortest direction.
	* Push target back to a.
	* Repeat until all elements are restored in sorted order.

### State Machine Design (enum)

The program flow is implemented as a finite state machine using an enum state variable. This design keeps control flow explicit and easy to debug, separating responsibilities by phase and making transitions (START -> LOADING -> SORTING -> DONE/ERROR) predictable and maintainable.

**Typical states:**

* **START:** initial validation entry point.
* **LOADING:** parse arguments and build stacks.
* **SORTING_(SMALL/FIVE/BIG):** execute the selected sorting/checking logic.
* **DONE:** normal successful termination.
* **ERROR:** invalid input or command; terminate with error handling.


## Resources


* P2P
* CS50x 2026 - Algorithms Lecture ([CS50 Algorithms](https://www.youtube.com/watch?v=6Svu_ae5ebk/))
* GeeksForGeeks - Sorting Algorithms ([Sorting Algorithms](https://www.geeksforgeeks.org/dsa/sorting-algorithms/))
* GeeksForGeeks - Introduction of Finite Automata ([Finite State Machines](https://www.geeksforgeeks.org/theory-of-computation/introduction-of-finite-automata/))
* GeeksForGeeks - GDB (Step by Step Introduction) ([GDB](https://www.geeksforgeeks.org/c/gdb-step-by-step-introduction/))

### AI usage in this project:

* Reviewing Makefile and Readme
* Suggesting refactors to satisfy line limits and style
* Design guidance for implementing a finite state machine (enum-driven control flow) to structure the program phases 
* Assistance on the Newton-Raphson iteration method for computing optimal sqrt(n)-based chunk boundaries and refinement of the scaling factor (1.45) that adjusts chunk size for target operation efficiency.
* Learning resources and practical examples for using gdb (GNU Debugger) for step-through debugging and breakpoint management.
* Troubleshooting segmentation faults and understanding stack behavior during program execution.

All final code decisions, tests, and subject compliance checks were performed manually by the author.
