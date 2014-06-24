#include <stdio.h>
#include <limits.h>

/* Program to print a histogram of the frequencies of characters */

main() {

  int c, i, j;

  /* array of counts of lengths of words.  Index equals length. */
  int characters[CHAR_MAX+1]; 
  for (i=0; i<=CHAR_MAX; i++) {
	characters[i] = 0;
  }

  while ((c = getchar()) != EOF){
	characters[c]++;
  }

  /* print horizontally */
  for (i=0; i<=CHAR_MAX; i++) {
	putchar(i);
	printf(" : ");
	for (j=1; j<=characters[i]; j++){
	  putchar('=');
	}
	putchar('\n');
  }
}
