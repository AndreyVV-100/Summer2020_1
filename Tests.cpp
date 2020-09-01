#include <stdio.h>
#include <math.h>
#include "Tests.h"

const double EPS_ = 1e-5;

void Tests()
{
	                 /*   0     1     2     3   4   5*/
	double    a[6] = { 1e-6, 1e-6, 1e-6,   -1,  1,  1 },
		      b[6] = { 1e-6, 1e-6,    1,   -1,  2, -5 },
		      c[6] = { 1e-6, 1000,   -1, -100,  1,  6 },
           ans0[6] = {   -1,    0,    1,    0,  1,  2 },
		   ans1[6] = {    0,    0,    1,    0, -1,  2 },
		   ans2[6] = {    0,    0,    0,    0,  0,  3 };
	
	double x1, x2;
	int i, check;
	for (i = 0; i < 6; i++)
	{
		check = Solve(a[i], b[i], c[i], &x1, &x2);
		if (check == ans0[i] &&
			(check == 0  ||
			 check == -1 ||
				check == 1 && abs(x1 - ans1[i]) < EPS_ ||
				check == 2 &&
				(abs(x1 - ans1[i]) < EPS_ && abs(x2 - ans2[i]) < EPS_ ||
				 abs(x1 - ans2[i]) < EPS_ && abs(x2 - ans1[i]) < EPS_)))
			printf("Test #%d OK\n", i);
		else
			printf("Test #%d failed, input: a = %f, b = %f, c = %f\n", i, a[i], b[i], c[i]);
	}
}