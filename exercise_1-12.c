#include <stdio.h>

/* Program to print the input one word per line */

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

main() {

  int c, state;
  state = OUT;

  while ((c = getchar()) != EOF){
	
	/* Is it whitespace? */
	if ((c == ' ') || (c == '\t') || (c == '\n')) {

	  /* If we just wrapped up a word, end the line */
	  if (state == IN) {
		putchar('\n');
	  }

	  /* End the word */
	  state = OUT;

	} else {
	  /* We have a word. */
	  state = IN;
	}

	/* Print the char if we are in a word */
	if (state == IN) {
	  putchar(c);
	}
  }  
}
