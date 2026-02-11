#include "../include/bitwise.h";


int get_mask(int p){
  return (1 << p);
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

