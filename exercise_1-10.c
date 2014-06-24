#include <stdio.h>

/* Program to replace \, tabs, and newlines with
   \\, \t, and \n, respectively */

main() {

  int c;
  while ((c = getchar()) != EOF) {
	if (c == '\\') {
	  printf("\\\\");
	}
	else if (c == '\t') {
	  printf("\\t");
	}
	else if (c == '\n') {
	  printf("\\n");
	}
	else {
	  putchar(c);
	}
  } 
}
