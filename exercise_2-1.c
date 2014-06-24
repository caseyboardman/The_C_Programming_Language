#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

/* Problem:  Write a program to determine the ranges of char, short, int, and
     long variables, both signed and unsigned, by printing appropriate values
	 from standard headers and by direct computation.  Harder if you compute 
	 them: determine the ranges of various floating-point types (float, 
	 double). */

main() {

  /* Part 1 */
  printf("From the headers:\n");

  printf(" char:\n  bits: %d\n  max: %d\n  min: %d\n", CHAR_BIT, CHAR_MAX, CHAR_MIN);
  printf(" signed char:\n  max: %d\n  min: %d\n", SCHAR_MAX, SCHAR_MIN);
  printf(" unsigned char:\n  max: %d\n", UCHAR_MAX);

  printf(" int:\n  max: %d\n  min: %d\n", INT_MAX, INT_MIN);
  printf(" unsigned int:\n  max: %u\n", UINT_MAX);

  printf(" short:\n  max: %d\n  min: %d\n", SHRT_MAX, SHRT_MIN);
  printf(" unsigned short:\n  max: %d\n", USHRT_MAX);

  printf(" long:\n  max: %ld\n  min: %ld\n", LONG_MAX, LONG_MIN);
  printf(" unsigned long:\n  max: %lu\n", ULONG_MAX);
  
  printf(" float:\n  max: %e\n  min: %e\n", FLT_MAX, FLT_MIN);
  printf("  Digits of precision: %d\n", FLT_DIG);

  printf(" double:\n  max: %e\n  min: %e\n", DBL_MAX, DBL_MIN);
  printf("  Digits of precision: %d\n", DBL_DIG);
  
  /* Part 2 */
  printf("Computed:\n"); 

  /* int */
  /* int x, maxi; */
  /* for (x=0; x>=0; x++) { */
  /* 	maxi = x; */
  /* 	/\* loop until we wrap around *\/ */
  /* } */
  /* printf(" int:\n  max: %d\n  min: %d\n", maxi, x); */
  
  /* char c, maxc; */
  /* for (c=0; c>=0; c++) { */
  /* 	/\* loop until we wrap around *\/ */
  /* 	maxc = c; */
  /* } */
  /* printf(" char:\n  max: %d\n  min: %d\n", maxc, c); */
  
  /* FLOAT MAX */
  /* float flt_a, flt_b, flt_m, flt_c, maxf; */
  /* flt_a = 2.0; */
  /* flt_b = 1.0; */
  /* flt_m = 0; */
  /* while (flt_a != flt_b) { */
  /* 	flt_m = flt_b;           /\* MAX POWER OF 2 IN MANTISSA *\/ */
  /* 	flt_b = flt_b * 2.0; */
  /* 	flt_a = flt_b + 1.0; */
  /* } */
  /* flt_m = flt_m + (flt_m - 1); /\* MAX VALUE OF MANTISSA *\/ */

  /* flt_a = flt_b = flt_c = flt_m; */
  /* while (flt_b == flt_c) { */
  /* 	flt_c = flt_a;         */
  /* 	flt_a = flt_a * 2.0; */
  /* 	flt_b = flt_a / 2.0; */
  /* } */
  /* maxf = 0; */

  /* /\* FLOAT MIN *\/ */
  /* int i = 0; */
  /* float minf, f, lastf; */
  /* f = 1.0; */
  /* lastf = f; */
  /* minf = f; */

  /* while (lastf == minf) { */
  /* 	/\* printf(" i: %d, f: %e\n", i, f); *\/ */
  /* 	minf = f; */
  /* 	f = f / 2.0; */
  /* 	lastf = f * 2.0; */
  /* } */

  /* printf(" float:\n  max: %e\n  min: %e\n  i: %d\n  real min: %e\n", maxf, minf, i, FLT_MIN); */

  /* flt_a = flt_b = flt_c = 1.0; */
  /* while (flt_b == flt_c) { */
  /* 	flt_c = flt_a;         */
  /* 	flt_a = flt_a / 2.0; */
  /* 	flt_b = flt_a * 2.0; */
  /* } */
  /* printf("COMPUTED %E\n", flt_c); */



  /* FLOAT MAX PART 2 */
   
  /* 1 bit sign */

  /* 8 bit exponent */
  /* int exponent = pow(2, 7) - 1; */

  /* /\* 23 bit significand *\/ */
  /* int significand = pow(2, 2); */

  /* float f = FLT_MAX; */

  /* significand = f / exponent; */

  /* printf("f: %d^%d = %e\n", significand, exponent, f); */

  /* printf("d: %ld\n", INT_MAX + 1); */

  /* long x = (long)INT_MAX + 1; */

  /* printf("x: %ld\n", x); */
  /* printf("x: %ld\n", x / pow(2, 31)); */

  float exponent, sign;
  float fraction;

  sign = 0;  /* 0 is positive, 1 is negative */
  exponent = 7;
  fraction = pow(2, 23);
  fraction = 1.8388607;

  float f = pow(-1, sign) * fraction * (pow(2, exponent)-1);

  printf("sign: %e, exponent: %e, fraction: %e = f: %e\n", sign, exponent, fraction, f);

  int i;
  for(i=125; i<130; i++) {
	f= pow(2.0, i);
	printf("i: %d, f: %e 2*f:%E\n", i, f, 2.0*f);
  }
}




