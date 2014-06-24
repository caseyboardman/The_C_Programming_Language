#include <stdio.h>
#include <string.h>

/* Write an alternate version of squeeze(s1, s2) that deletes each 
   character in s1 that matches any character in s2. */

#define TESTCOUNT 2  /* The number of tests to perform */

int contains(char string[], char character);
void squeeze(char input[], char removal[], char output[]);

main() {

  char inputs[TESTCOUNT][128] = {"abcdefg", "aaabbbccc"};
  char removals[TESTCOUNT][128] = {"cdb", "a"};
  char outputs[TESTCOUNT][128] = {"aefg", "bbbccc"};
  char output[128];
  int result;
  int i;

  for (i=0; i<TESTCOUNT; i++) {
	squeeze(inputs[i], removals[i], output);
	if (0 == strcmp(output, outputs[i])) {
	  printf("Test %d : PASS\n", i);
	} else {
	  printf("Test %d : FAIL\n", i);
	  printf("  input: %s\n  removal: %s\n  output: %s\n  expected: %s\n", inputs[i], removals[i], output, outputs[i]);
	}
  }
}

/* Removes all characters in removal from input, places resulting
   string in output. */
void squeeze(char input[], char removal[], char output[]) {
  int i = 0;
  int j = 0;

  for (i=0; input[i] != '\0'; i++) {
	if (!contains(removal, input[i])) {
	  output[j++] = input[i];
	}
  }
  
  output[j] = '\0';  
}

/* Searches for character in string.  Returns 1 if found, 
   0 if not found */
int contains(char string[], char character) {

  int i;
  for(i=0; string[i] != '\0'; i++) {
	if (string[i] == character) {
	  return 1;
	}
  }

  return 0;
}
