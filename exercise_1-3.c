#include <stdio.h>

/* Print Fahrenheit-Celsius table */

main() {
  float fahrenheit, celsius;
  int lower, upper, step;

  lower = 0;    /* lower limit of temperature table */
  upper = 300;  /* upper limit of temperature table */
  step = 20;    /* step size */
  fahrenheit = lower;

  printf("  F      C\n");

  while (fahrenheit <= upper) {
	celsius = (5.0/9.0) * (fahrenheit - 32.0);
	printf("%3.0f %6.1f\n", fahrenheit, celsius);
	fahrenheit = fahrenheit + step;
  }
}
