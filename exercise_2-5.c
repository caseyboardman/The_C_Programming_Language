#include <stdio.h>

/* Write the function any(s1, s2), which returns the first location in the 
   string s1 where any character of the string s2 occurs, or -1 if if s1
   contains no characters from s2.  */

#define TESTCOUNT 5 /* the number of tests */

int any(char s1[], char s2[]);
int contains(char string[], char character);

main() {
  char s1s[TESTCOUNT][32] = {"abcdef", "abcdef", "abcdef", "abcdef", "abcdef"};
  char s2s[TESTCOUNT][32] = {"xyz", "zyxaw", "cde", "fghi", "cea"};
  int  expected[TESTCOUNT] = {-1, 0, 2, 5, 0};
  int actual;
  int i;

  for (i=0; i<TESTCOUNT; i++) {
	actual = any(s1s[i], s2s[i]);

	if (actual == expected[i]) {
	  printf("Test %d : PASS\n", i);
	} else {
	  printf("Test %d : FAIL\n", i);
	  printf("  s1: %s\n  s2: %s\n  actual: %d\n  expected: %d\n", s1s[i], s2s[i], actual, expected[i]);
	}
  }
}

/* Returns the first location in the string s1 where any character of the 
   string s2 occurs, or -1 if if s1 contains no characters from s2 */
int any(char s1[], char s2[]){
  int i;
  int index; 
  int firstIndex = -1;

  for (i=0; s2[i] != '\0'; i++) {
	index = contains(s1, s2[i]);

	if (index >= 0 && (index < firstIndex || firstIndex == -1)) {
	  /* found one! */
	  firstIndex = index;
	}
  }
  
  /* we ain't found shit */
  return firstIndex;
}

/* Searches for character in string.  Returns index if found, 
   -1 if not found */
int contains(char string[], char character) {

  int i;
  for(i=0; string[i] != '\0'; i++) {
	if (string[i] == character) {
	  return i;
	}
  }

  return -1;
}
