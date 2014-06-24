#include <stdio.h>

/* Copies input, replacing a string of multiple blanks
   with one blank. */

#define SKIPCHAR ' '    /* The character we are shrinking */

main() {

  /* for     testing        */

  int c;
  while ((c = getchar()) != EOF) {

	/* Print a skip character if we got one */
	if (c == SKIPCHAR) {
	  	putchar(c);
	}

	/* Then skip the rest of the skip characters until we hit something else */
	while (c == SKIPCHAR) {
	  c = getchar();
	} 

	/* We got something we're not skipping */
	putchar(c);
  } 

  /* for     testing        */
}
