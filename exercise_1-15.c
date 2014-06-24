#include <stdio.h>

#define LOWER 0         /* lower limit of table */
#define UPPER 300       /* upper limit of table */
#define STEP  20        /* step size */

/* Function to convert Fahrenehit to Celsius */
float fahrenheit_to_celsius(float fahrenheit) {
  return ((5.0/9.0) * (fahrenheit - 32.0));
}

/* Print Fahrenheit-Celsius table */
main() {
  float fahrenheit;

  printf("  F      C\n");
  for (fahrenheit = UPPER; fahrenheit >= LOWER; fahrenheit -= STEP) {
	printf("%3.0f %6.1f\n", fahrenheit, fahrenheit_to_celsius(fahrenheit));
  }
}
