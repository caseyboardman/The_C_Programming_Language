#include <stdio.h>
#include <string.h>
#include <limits.h>

/* Problem: Write a version of itoa that accepts three arguments
   instead of two.  The third argument is a minimum field width; 
   the converted number must be padded with blanks on the left 
   if neccessary to make it wide enough. */

/* reverse a string (from page 63) */
void reverse(char s[]);

/* the assignment */
void itoa(int n, char s[], int w);

main() {
  int input[] = {0, 1, -1, INT_MAX, INT_MIN,
				 0, 1, -1, INT_MAX, INT_MIN};
  int width[] = {0, 0, 0, 0, 0,
				 3, 3, 3, 3, 3};
  char expected[][16] = {"0", "1", "-1", "2147483647", "-2147483648",
						 "  0", "  1", " -1", "2147483647", "-2147483648"};

  char actual[16];
  char bad[16];
  int i;
  for (i=0; i<10; i++) {
	itoa(input[i], actual, width[i]);

	if (0 == strcmp(actual, expected[i])) {
	  printf("Test %d : PASS\n", i);
	} else {
	  printf("Test %d : FAIL\n", i);
	}

	printf("  INPUT:    %d\n", input[i]);
	printf("  WIDTH:    %d\n", width[i]);
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

/*
 * TODO
 */
void itoa(int n, char s[], int w) {
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
