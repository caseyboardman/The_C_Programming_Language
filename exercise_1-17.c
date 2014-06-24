#include <stdio.h>

#define MAXLINE 80 /* maximum input line size */

int mygetline(char line[], int maxline);


/* print the longest input line and its length */
main() {
  int len;      /* current line length */
  char line[MAXLINE];    /* current input line */

  while ((len = mygetline(line, MAXLINE)) > 0) {
	if (len > MAXLINE) {
	  printf("%s\n", line);	  
	}
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
