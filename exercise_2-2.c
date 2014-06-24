#include <stdio.h>

/* Write a loop equivalent to loop A without using && and || */

#define MAXLINE 70 /* maximum input line size */
#define GETLINE getlineB /* the getline function to call */

int getlineA(char line[], int maxline);
int getlineB(char line[], int maxline);

main() { 

  int len;      /* current line length */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line so far */

  printf("%s:\n", (char*)GETLINE);

  while ((len = GETLINE(line, MAXLINE)) > 0) {
	printf("%s", line);
  }

  return 0;
}

/* mygetline: read a line into s (up to lim characters), return length */
int getlineA(char s[], int lim) {
  int c, i;

  for (i=0; i<lim-1 && (c = getchar()) != '\n' && c != EOF; ++i) {
	s[i] = c;
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

/* mygetline: read a line into s (up to lim characters), return length */
int getlineB(char s[], int lim) {
  int c, i;

  i = 0;
  while (i<lim-1) {
	c = getchar();
	if (c == '\n') {
	  break;
	}

	if (c == EOF) {
	  break;
	}
	
	s[i] = c;

	++i;
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
