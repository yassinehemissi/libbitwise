#include "../include/bitwise.h"


unsigned int make_mask(int start, int len){
  unsigned int mask = (1u << len) - 1;   
  mask = mask << start; 
  return mask;
}


unsigned int extract_bits(unsigned int n, int start, int len){
  unsigned int mask = make_mask(start, len);
  unsigned int bits = mask & n;
  bits = bits >> start;
  return bits; 
}

unsigned int clear_bits_range(unsigned int n, int start, int len){
  unsigned int mask = make_mask(start, len);
  mask = ~mask; 
  n &= mask;
  return n;
}

unsigned int set_bits_range(unsigned int n, int start, int len){
  unsigned int mask = make_mask(start, len);
  n |= mask;
  return n;
}

unsigned int insert_bits(unsigned int dest, unsigned int src, int start, int len){
  unsigned int m1 = make_mask(0, len);
  unsigned int bits = src & m1;
  bits = bits << start; 
  dest = clear_bits_range(dest, start, len);
  dest |= bits;
  return dest;
}


