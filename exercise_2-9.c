#include <stdio.h>
#include <math.h>

/* Problem:  In a two's complement number system, x &= (x-1) deletes the
   rightmost 1 bit in x.  Explain why.  Use this observation to write a
   faster version of bitcount.  */

/* bitcount: count the 1 bits in x */
int bitcount_old(unsigned int x);
int bitcount_new(unsigned int x);

main() {

  unsigned i, old, new;

  for (i=0; i<=8; i++) {

	old = bitcount_old(i);
	new = bitcount_new(i);

	if (old == new) {
	  printf("PASS:");
	} else {
	  printf("FAIL:");
	}
	printf(" i: %d, old: %d, new: %d\n", i, old, new);
  }
}


int bitcount_old (unsigned x) {
  int b;
  for (b = 0; x != 0; x >>= 1) {
	if (x & 01) {
	  b++;
	}
  }
  
  return b;
}

/*
   x   x-1 x&(x-1)
   00  11   00
   01  00   00
   10  01   00
   11  10   10

   If x is 0, x & anything will be 0.  There are no 1 bits to remove.

   If x is odd, ex. xxx1, x-1 = xxx0, and xxx1 & xxx0 = xxx0.  The rightmost 
   1 bit is removed due to the subtraction, and the 0 clears the 1 during the
   logical AND.

   If x is even, ex. xxx0, x-1 = yyy1, where all zeroes (up to the first 1) 
   will change to 1 due to borrowing, and that 1 (which gets borrowed from)
   changes to zero.  These new and old zeroes go to zero in the logical AND.

   The old version has a shift, assignment, logical and, if.
   The new version has a subtraction, logical and, assignment.  
   The new version has one less step.
   
*/
int bitcount_new (unsigned x) {
  int b;
  for (b = 0; x != 0; x &= (x-1)) {
	b++;
  }

  return b;
}
