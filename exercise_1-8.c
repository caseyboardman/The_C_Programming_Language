#include <stdio.h>

/* Program to count blanks, tabs, and newlines */

main() {
  int blanks, tabs, newlines;
  blanks = 0;
  tabs = 0;
  newlines = 0;

  int c;
  while ((c = getchar()) != EOF) {
	if (c == ' ') {
	  blanks++;
	}
	if (c == '\t') {
	  tabs++;
	}
	if (c == '\n') {
	  newlines++;
	}	
  } 

  printf("Blanks:   %5d\n", blanks);
  printf("Tabs:     %5d\n", tabs);
  printf("Newlines: %5d\n", newlines);
}
