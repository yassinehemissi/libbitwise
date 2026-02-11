# libbitwise

A small modular C library implementing fundamental bitwise operations from scratch.
The goal is to strengthen binary manipulation skills and low-level reasoning.

---

## Project Structure

```
bitwise/
├── include/
│   └── bitwise.h
├── src/
│   └── bit_ops.c
├── test/
│   └── bit_ops_test.c
├── main.c
└── README.md
```

---

## Implemented Functions

### Bit Operations (To be implemented in next commit)

* set_bit(int number, int position)
* clear_bit(int number, int position)
* toggle_bit(int number, int position)
* check_bit(int number, int position)
* update_bit(int number, int position, int value)
* swap_two_bits(int number, int pos1, int pos2)

### Number Manipulation

* swap_two_numbers_without_temp(int *a, int *b)

All functions are implemented using only:

```
&  |  ^  ~  <<  >>
```

---

## Build

Compile with GCC:

```
gcc src/bit_ops.c test/bit_ops_test.c main.c -Iinclude -o bitwise_test
```

Run:

```
./bitwise_test
```

Or use script `run.sh`:

```
bash run.sh 
```


---

## Notes

* Bit positions are 0-based (LSB = position 0)
* check_bit returns strictly 0 or 1
* update_bit treats non-zero values as 1
* No external dependencies


--- 

*AI Generated README.md*
