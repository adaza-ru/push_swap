<div align="center">

# Push Swap — Sorting Two Stacks in the Fewest Moves
 
**A stack-sorting algorithm project: `push_swap` computes the shortest sequence of operations to sort a list of integers across two stacks, and `checker` replays and verifies that sequence.**
 
![C](https://img.shields.io/badge/language-C-00599C?logo=c&logoColor=white)
![Make](https://img.shields.io/badge/build-Make-red)
![Algorithms](https://img.shields.io/badge/focus-algorithms-orange)

*This project has been created as part of the 42 curriculum by adaza-ru.*
 
</div>
 
## Table of Contents
 
- [Overview](#overview)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Algorithm Overview](#algorithm-overview)
- [Stress Testing](#stress-testing)
- [Resources](#resources)
- [Notes](#notes)
---
 
## Overview
 
Push Swap sorts a list of integers using only a fixed set of operations on two stacks, `a` and `b` — no direct indexing or extra storage, just swaps, pushes, rotates, and reverse rotates. The objective is correctness with as few operations as possible.
 
The project builds two binaries:
 
- **`push_swap`** (mandatory) — takes the integers as arguments and prints the operation sequence that sorts them.
- **`checker`** (bonus) — takes the same integers, then reads operations from standard input and reports whether the result is sorted (`OK`), not sorted (`KO`), or the input was invalid (`Error`).
Both stacks are implemented as circular doubly linked lists. Argument parsing validates numeric format, `int` range, and duplicates. `checker` reads its input line by line with a custom `get_next_line`, validating and executing each command as it arrives.
 
Since both binaries operate on the exact same stack structure with the exact same primitive operations, that logic — stack primitives, argument parsing, error handling — lives in a shared module compiled once and linked into both, instead of being duplicated per binary.
 
## Project Structure
 
```
push_swap/
├── Makefile
├── include/
│   └── push_swap.h
└── src/
    ├── common/       # shared by both binaries: stack ops, parsing, errors
    ├── push_swap/    # mandatory: sorting algorithm, entry point
    └── checker/      # bonus: reads & verifies operations from stdin
```
 
## Getting Started
 
### Requirements
 
- A C compiler
- `make`
### Build
 
```bash
git clone https://github.com/adaza-ru/push_swap.git
cd push_swap
make          # builds both push_swap and checker
```
 
**Other targets:**
 
```
make mandatory   # push_swap only
make bonus       # checker only
make clean
make fclean
make re
```
 
## Usage
 
**Mandatory:**
 
```bash
./push_swap 3 2 1
```
 
**Checking a run:**
 
```bash
./push_swap 3 2 1 | ./checker 3 2 1
```
 
**Manual operations:**
 
```bash
./checker 2 1 3
sa
<Ctrl+D>
```
 
## Algorithm Overview
 
The algorithm branches by input size and works on normalized indexes throughout, to keep comparisons simple regardless of the actual integer values.
 
### Small inputs (3 and 5 elements)
 
- **3 elements** — a direct, case-based routine checks the relative order of the top/middle/bottom values and applies a minimal sequence of `sa`/`ra`/`rra`.
- **Up to 5 elements** — the smallest-indexed values are pushed to stack `b`; the remaining 3 in `a` are sorted with the 3-element routine; elements are pushed back from `b` to `a`, fixing local order as needed.
### Large inputs
 
1. Compute a chunk size proportional to `sqrt(n)`, via the Newton-Raphson method, scaled by a tuning constant.
2. Push from `a` to `b` in waves: elements within the current index boundary go to `b`; very small indexes get pushed then rotated deeper into `b`; otherwise `a` rotates until a suitable element surfaces.
3. Once everything is in `b`, rebuild `a` in descending index order: find the target's position from both directions in `b`, rotate `b` in whichever direction is shorter, push the target back to `a`, and repeat.
### State machine design
 
Program flow is implemented as a finite state machine over an `enum`, keeping control flow explicit and each phase's responsibility separate:
 
| State | Responsibility |
|---|---|
| `START` | Initial validation entry point |
| `LOADING` | Parse arguments and build the stacks |
| `SORTING_SMALL` / `SORTING_FIVE` / `SORTING_BIG` | Run the selected sorting/checking logic |
| `DONE` | Normal successful termination |
| `ERROR` | Invalid input or command; terminate with error handling |
 
## Stress Testing
 
Random large-input runs, checked against `checker` and audited for leaks with Valgrind:
 
```bash
ARG=$(shuf -e $(seq 0 499) | awk -v min=-2147483648 -v max=2147483647 'BEGIN{srand();}{print int(min + rand() * (max - min + 1))}' | tr '\n' ' ')
valgrind --leak-check=full ./push_swap $ARG 2> leaks.txt | tee >(wc -l) | ./checker $ARG; grep -E "ERROR SUMMARY|definitely lost|indirectly lost" leaks.txt
```
 
## Resources
 
- Peer-to-peer discussion
- [CS50 — Algorithms lecture](https://www.youtube.com/watch?v=6Svu_ae5ebk/)
- [GeeksforGeeks — Sorting Algorithms](https://www.geeksforgeeks.org/dsa/sorting-algorithms/)
- [GeeksforGeeks — Introduction to Finite Automata](https://www.geeksforgeeks.org/theory-of-computation/introduction-of-finite-automata/)
- [GeeksforGeeks — GDB step-by-step introduction](https://www.geeksforgeeks.org/c/gdb-step-by-step-introduction/)
## Notes
 
Originally built as part of the 42 curriculum. AI tools were used as a learning and review aid — design guidance on the enum-driven state machine, help refining the Newton-Raphson chunk-size calculation and its scaling factor, learning resources for step-through debugging with GDB, and support diagnosing segmentation faults. All final code decisions, testing, and subject-compliance checks were done manually by the author.
 
