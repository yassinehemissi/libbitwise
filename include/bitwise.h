#ifndef BITWISE_H
#define BITWISE_H
#include <stdio.h> 
#include <stdint.h>
#include <math.h> 

// Bit Operations (Basic)
int set_bit(int n, int p);
int clear_bit(int n, int p);
int toggle_bit(int n, int p);
int check_bit(int n, int p);
int update_bit(int n, int p, int v);
int swap_two_bits(int n, int p1, int p2);

// Swap Two Numbers 
void swap_two_numbers_without_temp(int * a, int * b);

// Bit count 

int count_set_bits(int n);
int is_power_of_two(int n);
int lowest_set_bit(int n);
int highest_set_bit(int n);
int parity(int n);

// Bit Mask

unsigned int make_mask(int start, int len);
unsigned int extract_bits(unsigned int n, int start, int len);
unsigned int clear_bits_range(unsigned int n, int start, int len);
unsigned int set_bits_range(unsigned int n, int start, int len);
unsigned int insert_bits(unsigned int dest, unsigned int src, int start, int len);

// Bit Rotation 

uint32_t rotl32(uint32_t x, int r);
uint32_t rotr32(uint32_t x, int r);
uint32_t reverse_bits32(uint32_t x);

// Bit Arithmethic

int32_t add_no_plus(int32_t a, int32_t b);
int32_t sub_no_minus(int32_t a, int32_t b);
int32_t negate32(int32_t x);
int32_t abs_no_branch(int32_t x);
int32_t min_no_branch(int32_t a, int32_t b);
int32_t max_no_branch(int32_t a, int32_t b);
int have_opposite_signs(int32_t a, int32_t b);
int32_t average_no_overflow(int32_t a, int32_t b);

#endif 
