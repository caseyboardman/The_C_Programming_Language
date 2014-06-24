#include <stdio.h>

/* Print Celsius-Fahrenehit table */

main() {
  float fahrenheit, celsius;
  int lower, upper, step;

  lower = -20;    /* lower limit of temperature table */
  upper = 100;  /* upper limit of temperature table */
  step = 10;    /* step size */
  celsius = lower;

  printf("  C      F\n");

  while (celsius <= upper) {
	fahrenheit = ((9.0/5.0) * celsius) + 32.0;
	printf("%3.0f %6.1f\n", celsius, fahrenheit);
	celsius = celsius + step;
  }
}
