#include <stdio.h>

main() {

  int result; /* value of comparison */

  while (result = (getchar() != EOF)) {
	printf("result: %d\n", result);
  }

  /* print the one we didn't get in the loop */
  printf("result: %d\n", result);
}
