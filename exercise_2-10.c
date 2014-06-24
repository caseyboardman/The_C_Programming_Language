#include <stdio.h>

/* Problem: Rewrite the function lower, which converts upper case
   letters to lower case, with a conditional expression instead 
   of if-else. */

/* convert c to lower case.  ASCII only */
int lower_old(int c);
int lower_new(int c);


main() {
  int old, new, i;

  for (i='A'; i<='z'; i++) {

	/* got to skip some */
	if (i > 'Z' && i < 'a') {
	  continue;
	}

	old = lower_old(i);
	new = lower_new(i);

	if (old == new) {
	  printf("PASS:");
	} else {
	  printf("FAIL:");
	}
	printf(" i: %d, %c, old: %c, new: %c\n", i, i, old, new);
  }
}

int lower_old(int c) {
  if (c >= 'A' && c <= 'Z') {
	return c + 'a' - 'A';
  } else {
	return c;
  }
}

int lower_new(int c) {
  return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
