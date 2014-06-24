#include <stdio.h>

/* Program to print a histogram of the words in its input */

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */
#define MAX_WORD_LENGTH 35 /* the max length of a word */

main() {

  int c, state, i, j, length, highestCount;
  state = OUT;
  length = 0;

  /* array of counts of lengths of words.  Index equals length. */
  int wordlengths[MAX_WORD_LENGTH+1]; 
  for (i=0; i<=MAX_WORD_LENGTH; i++) {
	wordlengths[i] = 0;
  }

  while ((c = getchar()) != EOF){

	/* Is it whitespace? */
	if ((c == ' ') || (c == '\t') || (c == '\n')) {

	  /* If we just wrapped up a word, count it */
	  if (state == IN) {
		wordlengths[length]++;
	  }

	  /* End the word */
	  state = OUT;
	  length = 0;

	} else {
	  /* We have a word. */
	  state = IN;
	  length++;

	  if (length > MAX_WORD_LENGTH) {
		printf("ERROR: Too long!");		
		return;
	  }
	}
  }

  /* print horizontally */
  for (i=1; i<=MAX_WORD_LENGTH; i++) {
	printf("%3d: ", i);
	for (j=1; j<=wordlengths[i]; j++){
	  putchar('=');
	}
	putchar('\n');
  }

  /* print vertically, top down */
  /* first get the tallest column */
  highestCount = 0;
  for(i=0; i<=MAX_WORD_LENGTH; i++){
	if (wordlengths[i] > highestCount) {
	  highestCount = wordlengths[i];
	}
  }

  /* then fill in the columns */
  for(i=highestCount; i>0; i--){
	for(j=1; j<=MAX_WORD_LENGTH; j++){
	  if (wordlengths[j] >= i) {
		printf(" + ");
	  } else {
		printf("   ");
	  }
	}
	putchar('\n');
  }

  /* now print the axis */
  for(j=1; j<=MAX_WORD_LENGTH; j++){
	printf("---");
  }
  putchar('\n');

  for(j=1; j<=MAX_WORD_LENGTH; j++){
	printf("%3d", j);
  }
  putchar('\n');

}
