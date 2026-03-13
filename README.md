*This project has been created as part of the 42 curriculum by melmbaz, buranli.*

---

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a restricted set of operations, generating the **smallest possible sequence of moves**.

What makes the project interesting is the constraint model: you cannot sort in place, you cannot use arrays freely, and every move has a cost. The challenge is to pick the right algorithm depending on how disordered the input actually is — not just how large it is.

The program implements **four distinct sorting strategies** with different complexity classes, and an **adaptive mode** that measures the disorder of the input and automatically selects the most efficient strategy for it.

---

## Instructions

### Compilation

```bash
make        # builds push_swap
make clean  # removes object files
make fclean # removes object files and binary
make re     # full rebuild
```

### Usage

```bash
./push_swap [--strategy] [--bench] <integers>
```

**Strategy flags** (optional, default is `--adaptive`):

| Flag | Algorithm | Complexity |
|------|-----------|------------|
| `--simple` | Selection sort adaptation | O(n²) |
| `--medium` | Chunk-based sorting | O(n√n) |
| `--complex` | Radix sort (LSD) | O(n log n) |
| `--adaptive` | Auto-selects based on disorder | mixed |

**Other flags:**

| Flag | Effect |
|------|--------|
| `--bench` | Prints disorder, strategy used, and full operation breakdown to stderr after sorting |

### Examples

```bash
# Basic sort — outputs the operation list
./push_swap 5 3 1 4 2

# Single quoted string also works
./push_swap "5 3 1 4 2"

# Force a specific strategy
./push_swap --simple 5 4 3 2 1
./push_swap --complex 5 4 3 2 1

# Benchmark mode — suppresses operation output, prints metrics to stderr
./push_swap --bench 5 3 1 4 2

# Combine bench with a strategy flag
./push_swap --bench --complex 5 3 1 4 2

# Verify correctness with the checker
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG

# Count operations on a large input
ARG=$(shuf -i 0-499 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

### Error handling

```bash
./push_swap 1 2 abc      # Error — non-integer argument
./push_swap 1 2 1        # Error — duplicate value
./push_swap 99999999999  # Error — integer overflow
./push_swap              # no output, exits cleanly
```

---

## Algorithms

### Operations available

All four algorithms are built using the same 11 operations:

| Operation | Effect |
|-----------|--------|
| `sa` | Swap top two elements of stack a |
| `sb` | Swap top two elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Move top of b to top of a |
| `pb` | Move top of a to top of b |
| `ra` | Rotate a upward (first becomes last) |
| `rb` | Rotate b upward (first becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate a (last becomes first) |
| `rrb` | Reverse rotate b (last becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

---

### Disorder metric

Before sorting, the program measures how disordered the input is. The disorder value is a number between `0.0` (perfectly sorted) and `1.0` (completely reversed). It is computed by counting all pairs of elements where a larger number appears before a smaller one:

```
disorder = inversions / total_pairs
```

where `total_pairs = n*(n-1)/2`. A disorder of `0.5` means half of all pairs are out of order — essentially a random shuffle. The disorder is always measured **before** any moves are made, so it reflects the true initial state of the input.

---

### 1 — Simple algorithm — O(n²)

**Strategy:** Selection sort adaptation.

The algorithm repeatedly finds the minimum element in stack `a`, rotates it to the top (using `ra` or `rra` depending on which direction is shorter), and pushes it to stack `b`. Once only 3 elements remain in `a`, a dedicated 3-element sorter handles them directly using at most 2 operations. All elements are then pulled back from `b` to `a` in order via `pa`.

**Complexity argument:** Finding and rotating the minimum to the top costs O(n) operations per element. Over n elements, this gives O(n²) total operations in the push_swap model.

**Best used when:** The input is already nearly sorted (low disorder). In that case, few rotations are needed and the operation count stays small.

---

### 2 — Medium algorithm — O(n√n)

**Strategy:** Chunk-based sorting.

The indexed values (0 to n−1) are divided into √n chunks of size √n each. Stack `a` is scanned repeatedly; any element belonging to the current chunk is pushed to `b` immediately, while everything else is rotated past. Once all chunks are in `b`, elements are pulled back to `a` one at a time by always finding the current maximum in `b` and rotating it to the top before pushing it to `a`.

**Complexity argument:** Each of the √n chunk passes scans all remaining elements in `a`, costing O(n) per pass and O(n√n) total for the push phase. The pull phase finds the max in `b` each time and rotates to it, costing O(√n) per element on average, giving O(n√n) total. Overall: O(n√n).

**Best used when:** The disorder is moderate — the input is shuffled but not completely random. Chunk sorting is significantly more efficient than selection sort at medium sizes because it exploits locality within chunks.

---

### 3 — Complex algorithm — O(n log n)

**Strategy:** LSD Radix sort using two stacks.

Elements are first **indexed** (mapped to 0..n−1 based on sorted rank) so the sort works on clean non-negative integers. The algorithm then performs one bit-pass per bit of the index. In each pass, every element in `a` is examined: if the current bit is `0` it is pushed to `b`, if `1` it is rotated to the back of `a`. After the full pass, all elements in `b` are pushed back to `a`. After ⌈log₂(n)⌉ passes, `a` is sorted.

**Complexity argument:** Each bit-pass touches every element exactly once: O(n) operations per pass. The number of passes is ⌈log₂(n)⌉. Total: O(n log n) operations in the push_swap model.

**Best used when:** The input is large and heavily shuffled (high disorder). Radix sort's linear-per-pass structure makes it the most predictable and scalable of the three strategies.

---

### 4 — Adaptive algorithm

**Strategy:** Selects between the three strategies above based on the measured disorder of the input.

| Disorder range | Strategy used | Complexity |
|---------------|---------------|------------|
| `< 0.2` | Simple (selection sort) | O(n²) |
| `0.2 ≤ d < 0.5` | Medium (chunk sort) | O(n√n) |
| `≥ 0.5` | Complex (radix sort) | O(n log n) |

**Rationale for thresholds:**
- Below `0.2`, the stack is nearly sorted. The simple algorithm requires very few rotations because the minimum is usually near the top already. Using radix sort here would waste O(n log n) operations on a problem that only needs O(n).
- Between `0.2` and `0.5`, the stack is moderately shuffled. Chunk sort exploits partial ordering that radix sort ignores, and avoids the quadratic blowup of selection sort.
- At `0.5` and above, the input is effectively random. Radix sort's predictable O(n log n) cost dominates, and no amount of locality helps the other strategies.

This is the **default mode** when no strategy flag is given.

---

## Performance

Benchmarks measured on random inputs (indices 0..n−1, fully shuffled), using the `--adaptive` (default) strategy:

| Input size | Typical ops | Target (pass) | Target (good) | Target (excellent) |
|-----------|-------------|--------------|--------------|-------------------|
| 100 numbers | ~900–1100 | < 2000 | < 1500 | < 700 |
| 500 numbers | ~6700–7000 | < 12000 | < 8000 | < 5500 |

At 100 numbers the adaptive algorithm typically selects the medium (chunk) strategy, and at 500 numbers it selects the complex (radix) strategy, since fully random inputs have disorder close to `0.5`.

---

## Benchmark mode output

When `--bench` is passed, the program prints a summary to **stderr** after sorting (operations still go to **stdout** as normal):

```
[bench] disorder: 70.00%
[bench] strategy: Adaptive -> Complex / O(n*log(n))
[bench] total_ops: 6784
[bench] sa: 0 sb: 0 ss: 0 pa: 2284 pb: 2284
[bench] ra: 2216 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

To hide operations and see only the benchmark:
```bash
./push_swap --bench 5 3 1 4 2 2>/tmp/bench.txt >/dev/null && cat /tmp/bench.txt
```

---

## Contributions

This is a group project. Here is the breakdown of who implemented which part:

### buranli

- **Project architecture** — overall file structure, Makefile, header design
- **Linked list module** — `ft_lstnew`, `ft_lstadd_back`, `ft_lstadd_front`, `ft_lstlast`, `ft_lstsize`
- **All 11 operations** — `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- **Input parsing** — `parse_mode`, `validate_input`, argument splitting and validation
- **Utility functions** — `safe_atoi`, `ft_split`, `index_finder`, `create_stack`, `free_stack`, `is_sorted`
- **Strategy dispatcher** — `execute_strategy`, `adaptive_sort`
- **Disorder metric** — `compute_disorder`

### melmbaz

- **Simple sort** (`sort/simple_sort.c`, `sort/simple_utils.c`) — selection sort adaptation with 3-element special case, O(n²)
- **Medium sort** (`sort/medium_sort.c`, `sort/medium_utils.c`) — chunk-based sorting with √n chunks, O(n√n)
- **Complex sort** (`sort/complex_sort.c`) — LSD radix sort over indexed values, O(n log n)
- **Benchmark mode** (`utils/bench.c`, `utils/ft_putfd.c`) — `--bench` flag, disorder display, per-operation counters, output to stderr
- **Structural changes for bench** — added `t_op_counter` struct to the header, threaded it through all 11 operation signatures, added `op_bool_control` to suppress writes in bench mode, added `chosen_mode` and `bit_pass` scratch fields, updated `init_ops`, rewrote `main.c` to wire everything together

---

## Resources

### References

- Knuth, D. E. — *The Art of Computer Programming, Vol. 3: Sorting and Searching* — foundational reference on sorting algorithms and complexity
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) — quick reference for complexity classes
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort) — LSD radix sort explanation
- [Visualgo — Sorting](https://visualgo.net/en/sorting) — visual step-by-step sorting algorithm demonstrations
- [42 Norm v4.1](https://github.com/42School/norminette) — coding standard enforced in this project

### AI usage

AI (Claude, Anthropic) was used during this project for the following tasks:

- **Debugging** — identifying off-by-one errors in argument parsing, signature mismatches between declarations and definitions, and operator precedence bugs
- **Norm compliance** — checking line counts, variable counts, and function counts per file, and suggesting how to split functions to stay within the 25-line / 5-function / 5-variable limits
- **Architecture review** — advising on how to pass the `t_op_counter` struct through the call chain without exceeding the 4-parameter limit, and how to encode the bench flag inside the struct to avoid an extra parameter
- **README drafting** — this document was drafted with AI assistance and reviewed and corrected by both team members

All code was written, understood, and is fully explainable by both melmbaz and buranli.