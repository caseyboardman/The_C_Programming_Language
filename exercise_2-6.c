#include <stdio.h>
#include <string.h>

/* Write a function setbits(x, p, n, y) that returns x with the n bits that 
   begin at position p set to the rightmost n bits of y, leaving the other
   bits unchanged. */

#define TESTCOUNT 2 /* the number of tests */

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

/* helper for printing.  http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format */
const char *byte_to_binary (int x);

main() {
  unsigned int x[TESTCOUNT]        = { 0b0000, 0b1111 };
  unsigned int y[TESTCOUNT]        = { 0b1111, 0b0000 };
  int  p[TESTCOUNT]                = { 2,      1 };
  int  n[TESTCOUNT]                = { 2,      2 };
  unsigned int expected[TESTCOUNT] = { 0b1100, 0b1001 };
  unsigned int actual;
  int i;

  for (i=0; i<TESTCOUNT; i++) {
	actual = setbits(x[i], p[i], n[i], y[i]);

	if (actual == expected[i]) {
	  printf("Test %d : PASS\n", i);
	} else {
	  printf("Test %d : FAIL\n", i);
	  printf("  x: %s\n", byte_to_binary(x[i]));
	  printf("  y: %s\n", byte_to_binary(y[i]));
	  printf("  p: %d, n: %d\n", p[i], n[i]);
	  printf("  expected: %s\n", byte_to_binary(expected[i]));
	  printf("  actual:   %s\n", byte_to_binary(actual));
	}
  }
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {

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
