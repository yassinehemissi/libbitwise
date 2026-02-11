#ifndef BITWISE_H
#define BITWISE_H

#include <stdio.h> 
#include <math.h> 

int set_bit(int n, int p);
int clear_bit(int n, int p);
int toggle_bit(int n, int p);
int check_bit(int n, int p);
int update_bit(int n, int p, int v);
int swap_two_bits(int n, int p1, int p2);

void swap_two_numbers_without_temp(int * a, int * b);

#endif 
