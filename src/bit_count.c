#include "../include/bitwise.h"

int count_set_bits(int n){
  int i = 0;
  while (n != 0){
    i += 1;
    n = n & (n - 1);
  }
  return i;
}

int is_power_of_two(int n){
  if (n <= 0) return 0; 
  if (n & (n - 1)) return 0;
  return 1;
}

int lowest_set_bit(int n){
  return n & (-n);
}

int highest_set_bit(int n){
  if (n == 0) return 0;
  for (int i = 1; i <= 16; i*=2)
    n |= (n >> i);
  return (n + 1) >> 1;
}

int parity(int n){
  for (int i = 16; i >= 1; i/=2)
    n ^= (n >> i);
  return (n & 1);
}


