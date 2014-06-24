#include <stdio.h>

/* A program that replaces tabs in the input with the proper number of blanks 
 *  to space to the next tab stop.  Assumme tab stops every n columns.
 * 
 *  Question:  Should n be a variable or symbolic parameter?
 *  Answer: Variable if you want to be able to read it in/parameterize it. 
 */

#define TABSTOP 4   /* Tabs every x columns */
#define MAXLINE 100 /* maximum input line size */

int mygetline(char line[], int maxline);
void entab(char to[], char from[]);

main() {
  int len;      /* current line length */
  char line[MAXLINE];    /* current input line */
  char current[MAXLINE]; /* current line to print */

  while ((len = mygetline(line, MAXLINE)) > 0) {
	detab(current, line);
	printf("%s", current);
  }

  return 0;

}

/* mygetline: read a line into s (up to lim characters), return length */
int mygetline(char s[], int lim) {
  int c, i;
  
  /* count all the characters but newline.  Put all we can (lim) into s */
  for (i=0; (c=getchar()) != EOF && c!='\n'; i++) {
	if (i<lim) {
	  s[i] = c;
	}
  }

  /* We stopped.  Get the newline */
  if (c=='\n') {
	if (i<lim) {
	  s[i] = c;
	}
	i++;
  }

  /* add the null terminator to s */
  if (i<lim) {
	s[i] = '\0';
  } else {
	/* ran out of space, cut it off */
	s[lim-1] = '\0';
  }

  return i;
}

/* copy: copy 'from' into 'to'.  Remove tabs and add spaces to shift to the
         next	tab stop.  Assume 'to' is big enough. */
void entab(char to[], char from[]) {
  int i, j;

  i = j = 0;
  while ((to[j] = from[i]) != '\0') {

	/* shift if we hit a tab */
	if (to[j] == '\t') {
	  to[j] = ' ';
	  j++;

	  while (j % TABSTOP != 0) {
		to[j] = ' ';
		j++;
	  }
	  j--;
	}

	/* increment the indicies */
	i++;
	j++;
  }
}
