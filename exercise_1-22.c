#include <stdio.h>

/* Problem:  Write a program to "fold" long input lines into two
 *   or more shorter lines after the last non-blank character 
 *   that occures before the n-th column if input.  Do something
 *   intelligent with very long lines, and if there are no blanks
 *   or tabs by the n-th column.
 */

#define LINESIZE 10  /* the max size of line to output */

main() {

  int c;  /* character to read in */

  char current[LINESIZE+1]; /* the current line to buffer for output */
  int index = 0;

  int lastWhitespace = -1;  /* the index of the last whitespace we saw */

  int i, j;  /* loop counters */

  /* read a character into current */
  while((c = getchar()) != EOF) {

	/* add the character, increment the index */
	current[index] = c;
	index++;

	if (c == '\n') {
	  /* end of line */
	  current[index] = '\0';
	  printf("%s\n", current);
	  index = 0;
	  continue;
	}

	if (c == ' ' || c == '\t') {
	  /* keep a bookmark here */
	  lastWhitespace = index;
	}

	if (index == LINESIZE ) {
	  /* out of room, break on the last whitespace */
	  if (lastWhitespace == -1) {
		/* we didn't have a whitespace */
		current[index] = '\\';
		current[index+1] = '\0';
		printf("%s\n", current);
		index = 0;

	  } else {

		/* print current from beginning to whitespace */
		for (i=0; i<lastWhitespace; i++) {
		  putchar(current[i]);
		}
		putchar('\n');

		/* shift current from whitespace+1 to beginning */
		j = 0;
		for(i=lastWhitespace; i<index; i++) {
		  current[j] = current[i];
		  j++;
		}
		
		/* shift the index down the same number of places */
		index = j;
	  }
	}

  }

  /* finish what you started */
  current[index] = '\0';
  printf("%s", current);
}
