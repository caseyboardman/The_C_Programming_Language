#include <stdio.h>

/* Problem: Write a function expand(s1, s2) that expands shorthand
   notations like a-z in the string s1 into the equivalent complete 
   list abc...xyz in s2.  Allow for letters of either case and digits,
   and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
   Arrange that a leading or trailing - is taken literally. */

void expand(char *s1, char *s2);

main() {
  char inputs[12][128]  = { "Hello World!", 
						   "a-z",
						   "l-o",
						   "A-Z", 
						   "0-9",
						   "2-7",
						   "a-z0-9",
						   "-a-z", 
						   "a-b-c",
						   "a-Z",
						   "abcd-fghi" };
  char expected[12][128] = { "Hello World!", 
							 "abcdefghijklmnopqrstuvwxyz",
							 "lmno",
							 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
							 "0123456789",
							 "234567",
							 "abcdefghijklmnopqrstuvwxyz0123456789",
							 "-abcdefghijklmnopqrstuvwxyz", 
							 "abc",
							 "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
							 "abcdefghi" };

  /* there... */
  char actual[128];
  int i;
  for (i=0; i<9; i++) {
	expand(inputs[i], actual);

	if (0 == strcmp(actual, expected[i])) {
	  printf("Test %d : PASS\n", i);
	} else {
	  printf("Test %d : FAIL\n", i);
	}

	printf("  INPUT:    %s\n", inputs[i]);
	printf("  EXPECTED: %s\n", expected[i]);
	printf("  ACTUAL:   %s\n\n", actual);
  }
}

void expand(char *s1, char *s2) {
  int i, j;
  int prior, next;

  char lowerlimit, upperlimit;

  for (i=0, j=0; s1[i] != '\0'; i++, j++) { 
	if (s1[i] == '-' && i > 0) {

	  /* Fill in the letters from the character at s2[j-1] through the character at s1[i+1] */
	  prior = s1[i-1];
	  next = s1[i+1];

	  if (((prior >= '0'&& prior < '9') && (next > '0' && next <= '9')) 
		  || ((prior >= 'a'&& prior < 'z') && (next > 'a' && next <= 'z')) 
		  ||((prior >= 'A'&& prior < 'Z') && (next > 'A' && next <= 'Z'))) {

		prior++;
		while (prior < next) {
		  s2[j++] = prior++;
		}
	  }
	  i++;
	} 

	s2[j] = s1[i];
  }

  s2[j] = '\0';
}
