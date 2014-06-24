#include <stdio.h>
#include <string.h>

/* Problem: Write a function escape(s,t) that converts characters like
   newline and tab into visible escape sequences like \n and \t as it 
   copies the string t to s.  Use a switch.  Write a function for the 
   other direction as well, converting escape sequences into the real
   characters. */

void escape(char *s, char* t);
void unescape(char *s, char* t);

main() {
  char inputs[2][128]  = { "Hello World!", 
						   "OMG	tabs! OMG\nnewline" };
  char expected[2][128] = { "Hello World!", 
							"OMG\\ttabs! OMG\\nnewline" };

  /* There... */
  printf("\nPart I.\n");
  char actual[128];
  int i;
  for (i=0; i<2; i++) {
	escape(actual, inputs[i]);

	if (0 == strcmp(actual, expected[i])) {
	  printf("Test %d : PASS\n", i);
	} else {
	  printf("Test %d : FAIL\n", i);
	}

	printf("  INPUT:    %s\n", inputs[i]);
	printf("  EXPECTED: %s\n", expected[i]);
	printf("  ACTUAL:   %s\n\n", actual);
  }

  /* ...and back again */
  printf("\nPart II.\n");
  for (i=0; i<2; i++) {
	unescape(actual, expected[i]);

	if (0 == strcmp(actual, inputs[i])) {
	  printf("Test %d : PASS\n", i);
	} else {
	  printf("Test %d : FAIL\n", i);
	}

	printf("  INPUT:    %s\n", expected[i]);
	printf("  EXPECTED: %s\n", inputs[i]);
	printf("  ACTUAL:   %s\n\n", actual);
  }
}
 

void escape(char *s, char *t) {
  int i, j;
  for (i=0, j=0; t[i] != '\0'; i++, j++) {

	switch (t[i]) {
	case '\t':
	  s[j] = '\\';
	  j++;
	  s[j] = 't';
	  break;
	case '\n':
	  s[j] = '\\';
	  j++;
	  s[j] = 'n';
	  break;
	default :
	  s[j] = t[i];
	}
  }
  s[j] = '\0';
}

void unescape(char *s, char *t) {
  int i, j;
  for (i=0, j=0; t[i] != '\0'; i++, j++) {
	if (t[i] == '\\' && t[i+1] == 't') {
	  s[j] = '\t';
	  i++;
	} else if (t[i] == '\\' && t[i+1] == 'n') {
	  s[j] = '\n';
	  i++;
	} else {
	  s[j] = t[i];
	}
  }
  s[j] = '\0';
}
