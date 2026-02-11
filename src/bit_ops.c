#include "../include/bitwise.h"


int get_mask(int p){
  return (1 << p); // generate a "1" + "0" * p 
}

int set_bit(int n, int p){
  return (n | get_mask(p));
}

int clear_bit(int n, int p){
  return (n & ~(get_mask(p)));
}

int toggle_bit(int n, int p){
  return n ^ (get_mask(p)); 
}

int check_bit(int n, int p){
  // first implementation 
  //  int m = get_mask(p);
  //  int r  = n & m; 
  //  return (r >> p);
  // simpler:
  return (n >> p) & 1; 
}

int update_bit(int n, int p, int v){
  return ((n & (~get_mask(p))) | ((!!v) << p)); 
}

int swap_two_bits(int n, int p1, int p2){
  int m1 = get_mask(p1);
  int m2 = get_mask(p2);

  int b1 = !!(n & m1);
  int b2 = !!(n & m2);

  if (b1 == b2) return n;

  int cn = n & ~(m1 | m2);

  return (b1 << p2) |  (b2 << p1) | cn ;
}

void swap_two_numbers_without_temp(int * a, int * b){
  if (a == b) return;  
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
};



