#include <stdio.h>

#define MAXLINE 70 /* maximum input line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line and its length */
main() {
  int len;      /* current line length */
  int max;      /* maximum line length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line so far */

  max = 0;
  while ((len = mygetline(line, MAXLINE)) > 0) {
	if (len > max) {
	  max = len;
	  copy(longest, line);
	}
  }

  if (max > 0) {
	/* there was at least one line */
	printf("%d : %s\n", max, longest);
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

/* copy: copy 'from' into 'to'.  Assume 'to' is big enough. */
void copy(char to[], char from[]) {
  int i;

  i=0;
  while ((to[i] = from[i]) != '\0') {
	i++;
  }
}
