#include "../include/bitwise.h"


uint32_t rotl32(uint32_t x, int r){
  r %= 32;
  if (r < 0) r += 32;
  if (r == 0) return x; 
  uint32_t m1 =  ~((1u << (32 - r)) - 1); 
  uint32_t bits = (m1 & x) >> (32 - r);
  return bits | (x << r);
}

uint32_t rotr32(uint32_t x, int r){
  r %= 32;
  if (r < 0) r += 32;
  if (r == 0) return x; 
  uint32_t m1 =  ((1u << r) - 1); 
  uint32_t bits = (m1 & x) << (32 - r);
  return bits | (x >> r);
}

uint32_t reverse_bits32(uint32_t x){
  uint32_t res = 0u;
  for (uint32_t i = 0; i < 32; i++){
    uint32_t bit = (x >> i) & 1; 
    res |= (bit << (31 - i));
  }
  return res;  
}


