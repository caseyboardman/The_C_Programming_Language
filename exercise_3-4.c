#include <stdio.h>
#include <string.h>
#include <limits.h>

/* Problem: In a two's complement number representation, out version
   of itoa does not handle the largest negative number, that is, the 
   value of n equal to -(2^(wordsize-1)).  Explain why not.  Modify
   it to print the value correctly, regardless of the machine on 
   which of the machine on which it runs. */

/* reverse a string (from page 63) */
void reverse(char s[]);

/* from the book, page 64 */
void bad_itoa(int n, char s[]);

/* the assignment */
void good_itoa(int n, char s[]);

main() {
  int input[] = {0, 1, -1, INT_MAX, INT_MIN};
  char expected[][16] = {"0", "1", "-1", "2147483647", "-2147483648"};

  char actual[16];
  char bad[16];
  int i;
  for (i=0; i<5; i++) {
	bad_itoa(input[i], bad);
	good_itoa(input[i], actual);

	if (0 == strcmp(actual, expected[i])) {
	  printf("Test %d : PASS\n", i);
	} else {
	  printf("Test %d : FAIL\n", i);
	}

	printf("  INPUT:    %d\n", input[i]);
	printf("  BAD VERSION:   %s\n", bad);
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

/* This fails on the sign assignment.
   The largest positive int is 2147483647.
   The largest negative int is -2147483648.
   Negating the -int, one would expect
   214748648, which is too large to hold in n,
   so n wraps back around, and fails the 
   while loop, as it is still negative.
*/
void bad_itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) {
	n = -n;
  }
  i = 0;
  do {
	s[i++] = n % 10 + '0';
  } while ((n/=10) > 0);

  if (sign < 0) {
	s[i++] = '-';
  }
  s[i] = '\0';

  reverse(s);  
}

void good_itoa(int n, char s[]) {
  int i;
  i = 0;

  if (n < 0) {
	/* negatives are trickier, handle the sign after dividing */
	do {
	  s[i++] = (n % 10) * -1 + '0';
	  s[i] = '\0';

	} while ((n/=10) < 0);

	s[i++] = '-';

  } else {

	/* postive number - no probs, just do it like the book */
	do {
	  s[i++] = n % 10 + '0';
	} while ((n/=10) > 0);
  }

  s[i] = '\0';
  reverse(s);  
}
