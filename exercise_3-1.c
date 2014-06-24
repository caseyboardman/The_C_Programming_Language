#include <stdio.h>
#include <stdlib.h>

/* Problem: Our binary search makes two tests inside the loop,
   when one would suffice (at the price of more tests outside).
   Write a version with only one test inside the loop and 
   measure the difference in run-time. */

int binsearch (int x, int v[], int n);
int my_binsearch (int x, int v[], int n);

main() {

  int v[3][100];
  int i, j;

  /* all */
  for (i=0; i<100; i++) {
	v[0][i] = i;
  }

  /* evens */
  j=0;
  for (i=0; i<200; i++) {
	if (i % 2 == 0) {
	  v[1][j++] = i;
	}
  }

  /* odds */
  j=0;
  for (i=0; i<200; i++) {
	if (i % 2 == 1) {
	  v[2][j++] = i;
	}
  }

  /* tests */
  int old, new;
  char* result;
  int x[3] = { 69, 0, 100 };

  for (j=0; j<3; j++) {
	for (i=0; i<3; i++) {
	  old = binsearch(x[j], v[i], 100);
	  new = my_binsearch(x[j], v[i], 100);
	  result = old == new ? "PASS" : "FAIL";
	  printf("%s: look for %d: old: %d, new: %d\n", result, x[j], old, new);
	}
  }
}

/* Find x in v[0]...v[n-1].  Return index if found, -1 if not. */
int binsearch (int x, int v[], int n) {

  /* start combing the desert */
  int low, high, mid;

  low = 0;
  high = n-1;
  while (low <= high) {
	mid = (low+high)/2;
	if (x < v[mid]) {
	  high = mid-1;
	} else if (x > v[mid]) {
	  low = mid +1;
	} else {
	  /* found it! */
	  return mid;
	}
  }

  /* we ain't found shit */
  return -1;
}

/* Find x in v[0]...v[n-1].  Return index if found, -1 if not. */
int my_binsearch (int x, int v[], int n) {
  /* start combing the desert */
  int low, high, mid;

  int safety = 0;  /* safety catch */

  low = 0;
  mid = 0;
  high = n-1;

  while (low < high) {
	mid = (low+high)/2;

	if (x <= v[mid]) {
	  high = mid;
	} else {
	  low = mid+1;
	}					

	if (safety++ > n ) {
	  /* we could have done a linear search at this 
		 point, probably stuck in a loop */
	  return -2;
	}
  }

  /* Don't just test for mid: low<high loop test can be too tight */
  if (x == v[mid]) { 
	return mid;
  }
  if (x == v[low]) { 
	return low;
  }
  if (x == v[high]) { 
	return high;
  }

  /* we ain't found shit */
  return -1;
}
