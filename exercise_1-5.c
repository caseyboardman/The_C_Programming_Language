#include <stdio.h>

#define LOWER 0         /* lower limit of table */
#define UPPER 300       /* upper limit of table */
#define STEP  20        /* step size */

/* Print Fahrenheit-Celsius table */
main() {
  float fahrenheit, celsius;

  printf("  F      C\n");
  for (fahrenheit = UPPER; fahrenheit >= LOWER; fahrenheit -= STEP) {
	celsius = (5.0/9.0) * (fahrenheit - 32.0);
	printf("%3.0f %6.1f\n", fahrenheit, celsius);
  }
}
