#include <stdio.h>
#include <string.h>

/* A program that replaces spaces with tabs so that the text is displayed 
 *  at the proper tab stops.  Assumme tab stops every n columns.
 * 
 *  Question:  Should n be a variable or symbolic parameter?
 */

#define TABSTOP 4   /* Tabs every x columns */
#define MAXLINE 100 /* maximum input line size */

int mygetline(char line[], int maxline);
void entab(char to[], char from[]);

void test(char expected[], char input[] ) {
  char actual[MAXLINE];
  entab(actual, input);

  int result;
  result = strcmp(expected, actual);
  if (result != 0) {
	printf("Expected: %s\n  but got %s\n", expected, actual);
  }
}

test_main() {
  test("hello", "hello");
  test("	tab",          "    tab");
  test("a	tab at start", "a   tab at start");
  test("b	  tab at start", "b     tab at start");
  test("c		tab at start", "c       tab at start");
}


main() {
  int len;      /* current line length */
  char line[MAXLINE];    /* current input line */
  char current[MAXLINE]; /* current line to print */

  while ((len = mygetline(line, MAXLINE)) > 0) {
	entab(current, line);
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

/* entab: copy 'from' into 'to'.  Remove spaces and add tabs to shift to the 
         next tab stop.  Assume 'to' is big enough. */
void entab(char to[], char from[]) {
  int i, j, spacestart;

  /* haven't seen a space yet */
  spacestart = -1;

  /* start copying from the beginning */
  i = j = 0;
  while (from[i] != '\0') {

	/* printf("from[i]: %c, i: %d, j: %d, spacestart: %d\n", from[i], i, j, spacestart); */

	/* copy the character */
	to[j] = from[i];	

	if (from[i] == ' ' && spacestart < 0) {
	  /* starting some spaces */
	  spacestart = j;
	}

	if ((spacestart >= 0) && (j - spacestart > 1) && ((i % TABSTOP) == 0)) {
	  /* in a line of spaces, just hit a tabstop */
	  j = spacestart;
	  to[j] = '\t';
	  j++;
	  to[j] = from[i];

	  if (from[i] == ' ') {
		spacestart = j;
	  } else {
		spacestart = -1;
	  }
	}

	if (from[i] != ' ' && spacestart >= 0) {
	  /* ending some spaces */
	  spacestart = -1;
	}

	/* increment the indicies */
	i++;
	j++;
  }

  /* wrap it up */
  to[j] = '\0';
}
