#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

/* Write a function rightrot(x, n) that returns the value of the 
   the integer x rotated to the right by n bit positions. */

#define TESTCOUNT 4 /* the number of tests */

int rightrot(int x, int n);

/* helper for printing.  http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format */
const char *byte_to_binary (int x);

main() {
  int x[TESTCOUNT]        = { 0b00000001, 0b00000010, 0b01010101, 0b00001111 };
  int n[TESTCOUNT]        = { 1,          1,          1,          3};
  int expected[TESTCOUNT] = { 0b10000000, 0b00000001, 0b10101010, 0b11100001 };
  int actual;
  int i;

  for (i=0; i<TESTCOUNT; i++) {
	actual = rightrot(x[i], n[i]);

	/* printf("  2^(CHAR_BIT-1): %s\n", byte_to_binary(pow(2, CHAR_BIT-1))); */

	if (actual == expected[i]) {
	  printf("Test %d : PASS\n", i);
	} else {
	  printf("Test %d : FAIL\n", i);
	  printf("  x: %s\n", byte_to_binary(x[i]));
	  printf("  expected: %s\n", byte_to_binary(expected[i]));
	  printf("  actual:   %s\n", byte_to_binary(actual));
	}
  }
}

/* The same as setbitps in previous exercise, where y = ~x */
int rightrot(int x, int n) {

  int i;
  for (i=0; i<n; i++) {
	if ( (x % 2) == 1) {
	  /* odd number, 1 is going to get shifted off */
	  x = (x >> 1) + pow(2, CHAR_BIT-1);
	} else {
	  /* even number, zero will get shifted on */
	  x = (x >> 1);
	}
  }

  return x;
}


const char *byte_to_binary (int x) {
  static char b[CHAR_BIT];
  b[0] = '\0';

  int z;
  for (z = pow(2, CHAR_BIT-1); z > 0; z >>= 1) {
	strcat(b, ((x & z) == z) ? "1" : "0");
  }

  return b;
}
