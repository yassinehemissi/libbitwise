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

### Bit Operations 

* set_bit(int number, int position)
* clear_bit(int number, int position)
* toggle_bit(int number, int position)
* check_bit(int number, int position)
* update_bit(int number, int position, int value)
* swap_two_bits(int number, int pos1, int pos2)

### Number Manipulation

* swap_two_numbers_without_temp(int *a, int *b)

### Bit Count 


* count_set_bits(int n)
* is_power_of_two(int n)
* lowest_set_bit(int n)
* highest_set_bit(int n)
* parity(int n)

### Bit Masks 

* make_mask(int start, int len)
* extract_bits(unsigned int n, int start, int len)
* clear_bits_range(unsigned int n, int start, int len)
* set_bits_range(unsigned int n, int start, int len)
* insert_bits(unsigned int dest, unsigned int src, int start, int len)



All functions are implemented using only:

```
&  |  ^  ~  <<  >>
```

---

## Build

Compile with GCC:

```
gcc src/*.c test/*.c main.c -Iinclude -o bitwise_test
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
