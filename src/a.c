#include <stdio.h>
#include <stdlib.h>
static uint64_t mulmod(uint64_t a, uint64_t b, uint64_t n) {
    uint64_t r = 0;
    if (a >= n) a %= n;   /* Careful attention from the caller */
    if (b >= n) b %= n;   /* should make these unnecessary.    */
    if ((a|b) < (1ULL << 32)) return (a*b) % n;
    if (a < b) { uint64_t t = a; a = b; b = t; }
    if (n <= (1ULL << 63)) {
      while (b > 0) {
        if (b & 1)  { r += a;  if (r >= n) r -= n; }
        b >>= 1;
        if (b)      { a += a;  if (a >= n) a -= n; }
      }
    } else {
      while (b > 0) {
        if (b & 1)  r = ((n-r) > a) ? r+a : r+a-n;    /* r = (r + a) % n */
        b >>= 1;
        if (b)      a = ((n-a) > a) ? a+a : a+a-n;    /* a = (a + a) % n */
      }
    }
    return r;
}

int main(){
unsigned long long a=242481168282967107;
unsigned long long MOD=18446744073709551521ULL;

printf("r %llu\n",mulmod(a,a,MOD));
}
