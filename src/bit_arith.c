#include "../include/bitwise.h"

int32_t add_no_plus(int32_t a, int32_t b){
  uint32_t sum = (uint32_t)a ^ (uint32_t)b;
  uint32_t carry = ((uint32_t)a & (uint32_t)b) << 1;
  while (carry != 0u){
    uint32_t c2 = (sum & carry) << 1;
    sum ^= carry;
    carry = c2;
  }
  return (int32_t)sum;
}

int32_t negate32(int32_t x){
  return add_no_plus(~x, 1);
}

int32_t sub_no_minus(int32_t a, int32_t b){
  return add_no_plus(a, negate32(b));
}

int32_t abs_no_branch(int32_t x){
  int32_t mask = x >> 31;
  int32_t y = (x ^ mask);
  return add_no_plus(y, (mask & 1));
}

int have_opposite_signs(int32_t a, int32_t b){
  return ((a ^ b) < 0);
}

int32_t max_no_branch(int32_t a, int32_t b){
  int32_t diff = sub_no_minus(a, b);
  uint32_t sign = ((uint32_t)diff) >> 31;
  int32_t mask = negate32((int32_t)sign);
  return sub_no_minus(a, (diff & mask));
}

int32_t min_no_branch(int32_t a, int32_t b){
  int32_t diff = sub_no_minus(a, b);
  uint32_t sign = ((uint32_t)diff) >> 31;
  int32_t mask = negate32((int32_t)sign);
  return add_no_plus(b, (diff & mask));
}

int32_t average_no_overflow(int32_t a, int32_t b){
  int32_t t1 = (a & b);
  int32_t t2 = (a ^ b) >> 1;
  return add_no_plus(t1, t2);
}
