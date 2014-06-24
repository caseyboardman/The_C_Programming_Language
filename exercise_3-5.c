#include <stdio.h>
#include <string.h>
#include <limits.h>

/* Problem: Write the function itob(n, s, b) that converts the 
   integer n into a base b character representation in the 
   string s.  In particular, itob(n, s, 16), formats n as a
   hexadecimal integer in s. */

/* reverse a string (from page 63) */
void reverse(char s[]);

/* the assignment */
void itob(int n, char s[], int b);

main() {
  int input[] = {0, 1, -1, INT_MAX, INT_MIN, 
				 1, 2, 3, 4, 5, 6, 7, 8, 16, 32, 64,
				 -1, -2, -3, -4, -5, -6, -7, -8, -16, -32, -64,
				 1, 2, 3, 4, 5, 6, 7, 8, 16, 32, 64,
				 -1, -2, -3, -4, -5, -6, -7, -8, -16, -32, -64,
				 1, 2, 3, 4, 5, 6, 7, 8, 16, 32, 64};
  int base[] =  {10, 10, 10, 10, 10, 
				 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
				 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
				 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
				 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
				 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16};
  char expected[][16] = {"0", "1", "-1", "2147483647", "-2147483648", 
						 "1", "10", "11", "100", "101", "110", "111", "1000", "10000", "100000", "1000000",
						 "-1", "-10", "-11", "-100", "-101", "-110", "-111", "-1000", "-10000", "-100000", "-1000000",
						 "1", "2", "3", "4", "5", "6", "7", "10", "20", "40", "100",
						 "-1", "-2", "-3", "-4", "-5", "-6", "-7", "-10", "-20", "-40", "-100",
						 "1", "2", "3", "4", "5", "6", "7", "8", "10", "20", "40"};

  char actual[16];
  char bad[16];
  int i;
  int length = 60;
  for (i=0; i<length; i++) {
	itob(input[i], actual, base[i]);

	if (0 == strcmp(actual, expected[i])) {
	  printf("Test %d : PASS\n", i);
	} else {
	  printf("Test %d : FAIL\n", i);
	}

	printf("  INPUT:    %d\n", input[i]);
	printf("  BASE:     %d\n", base[i]);
	printf("  EXPECTED: %s\n", expected[i]);
	printf("  ACTUAL:   %s\n\n", actual);
  }
}

void reverse(char s[]) {
  int c, i, j;

  for (i=0, j=strlen(s)-1; i<j; i++, j--) {
	c = s[i];
	s[i] = s[j];
	s[j] = c;
  }
}

void itob(int n, char s[], int b) {
  int i;
  i = 0;

  if (n < 0) {
	/* negatives are trickier, handle the sign after dividing */
	do {
	  s[i++] = (n % b) * -1 + '0';
	  s[i] = '\0';

	} while ((n/=b) < 0);

	s[i++] = '-';

  } else {

	/* postive number - no probs, just do it like the book */
	do {
	  s[i++] = n % b + '0';
	} while ((n/=b) > 0);
  }

  s[i] = '\0';
  reverse(s);  
}
