#include <stdio.h>
#include <string.h>

/* Write a function invert(x, p, n) that returns x with the n bits that 
   begin at position p inverted, leaving the others unchanged. */

#define TESTCOUNT 2 /* the number of tests */

unsigned int invert(unsigned int x, int p, int n);

/* helper for printing.  http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format */
const char *byte_to_binary (int x);

main() {
  unsigned int x[TESTCOUNT]        = { 0b0000, 0b1111 };
  int  p[TESTCOUNT]                = { 2,      1 };
  int  n[TESTCOUNT]                = { 2,      2 };
  unsigned int expected[TESTCOUNT] = { 0b1100, 0b1001 };
  unsigned int actual;
  int i;

  for (i=0; i<TESTCOUNT; i++) {
	actual = invert(x[i], p[i], n[i]);

	if (actual == expected[i]) {
	  printf("Test %d : PASS\n", i);
	} else {
	  printf("Test %d : FAIL\n", i);
	  printf("  x: %s\n", byte_to_binary(x[i]));
	  printf("  p: %d, n: %d\n", p[i], n[i]);
	  printf("  expected: %s\n", byte_to_binary(expected[i]));
	  printf("  actual:   %s\n", byte_to_binary(actual));
	}
  }
}

/* The same as setbits in previous exercise, where y = ~x */
unsigned int invert(unsigned int x, int p, int n) {

  unsigned int y = ~x;
  unsigned int x_mask;
  unsigned int y_mask;
  
  /* mask out the x */
  x_mask = (~( ~0 << p )) | (~0 << p+n);

  /* mask out the y */
  y_mask = ~x_mask;
  
  return (x & x_mask) | (y & y_mask);
}


const char *byte_to_binary (int x) {
  static char b[9];
  b[0] = '\0';

  int z;
  for (z = 256; z > 0; z >>= 1) {
	strcat(b, ((x & z) == z) ? "1" : "0");
  }

  return b;
}
