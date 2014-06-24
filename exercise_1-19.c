#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */

int mygetline(char line[], int maxline);
void reverse_copy(char to[], char from[]);

/* reverse all lines */
main() {
  int len;      /* current line length */
  int max;      /* maximum line length seen so far */
  char line[MAXLINE];    /* current input line */
  char current[MAXLINE]; /* current line to print */

  max = 0;
  while ((len = mygetline(line, MAXLINE)) > 0) {
	reverse_copy(current, line);
	printf("%s\n", current);
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

/* reverse_copy: copy 'from' into 'to', backwards.  Assume 'to' is big enough. */
void reverse_copy(char to[], char from[]) {

  int last, i;

  /* find the end */
  last=0;
  while (from[last] != '\0') {
  	last++;
  }
  /* last is one too high (watch the null string) */
  if (last > 0) {
	last--;
  }

  /* copy the string backwards */
  for(i=0; i<=last; i++) {
  	to[i] = from[last-i];
  }
  to[i] = '\0';
}
