#include <stdio.h>

/* Problem:  Write a program to remove all comments from a C program.
 *   Don't forget to handle quoted strings and character constants
 *   properly.  C comments do not nest.
 */

main() {
  int c, d;   /* character to read in */
  int inComment = 0; /* are we in a comment? */
  int inString = 0;  /* are we in a string? */
  

  while ((c = getchar()) != EOF) {

	/* if we're not in a string, check for the start of one */
	if (!inComment && !inString && (c == '"')) {
	  inString = 1;
	}
	
	/* if we're in a string check for the end */
	if (!inComment && inString && (c == '"')) {
	  inString = 0;
	}

	/* if we're in a string, don't get fooled the next time around by quotes */
	if (!inComment && inString && (c == '\\')) {
	  /* this could be a quote in a string, what's the next character? */
	  if ((d = getchar()) == EOF) {
		putchar(c);
		break;
	  } 
	  if (d == '"') {
		putchar(c);
		c = d;
	  }
	}

	/* if we're not in a comment already, check for the start of one */
	if ( !inString && !inComment && (c == '/')) {
	  /* this could be a comment, what's the next character? */
	  if ((d = getchar()) == EOF) {
		putchar(c);
		break;
	  } 
	  if (d == '*') {
		inComment = 1;
	  }
	}

	/* print out non-comments */
	if (!inComment) {
	  putchar(c);
	}

	/* if we're in a comment, check for the end */
	if ( inComment && (c == '*')) {
	  /* this could be a comment, what's the next character? */
	  if ((d = getchar()) == EOF) {
		putchar(c);
		break;
	  } 
	  if (d == '/') {
		inComment = 0;
	  }
	}
  }

  return 0;
}
