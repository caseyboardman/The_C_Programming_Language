#include <stdio.h>

/* Write the function htoi(s), which converts a string of hexadecimal 
   digits (including an optional 0x or 0X) into its equivalent integer 
   value.  The allowable digits are 0 through 9, a through f, and A 
   through F. */

void htoi(char input[], char output[]);

main () {

  char inputs[16][4] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", \
						"9", "0xa", "0xb", "0XC", "0XD", "0xE", "0Xf"};
  char output[4];

  int i;
  for (i=0; i<16; i++) {
	printf("s[%d]: %s\n", i, inputs[i]);
	
	htoi(inputs[i], output);
	printf("s[%d]: %s\n", i, output);

	printf("\n");
  }

  return 0;
}

/* Takes character string (as hexadecimal number) and converts it to 
   an integer (represented as a string). */
void htoi(char input[], char output[]) {

  int i = 0;
  int j = 0;
  char first, second;

  while(input[i] != '\0') {
	
	output[j] = input[i];

	if (i==0) {
	  first = input[i];
	}

	if (i==1) {
	  second = input[i];

	  if (first == '0' && (second == 'x' || second == 'X')) {
		j-= 2;
	  }
	}

	++i;
	++j;
  }
  
  output[j] = '\0';
}
