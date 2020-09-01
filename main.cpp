#include <stdio.h>
#include <math.h>

main()
{
	//Tests();
	printf("This progmam can solve square eqation in R.\n");
	double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
	printf("Put the coefficients a, b, c:\n");
	scanf_s("%lg %lg %lg", &a, &b, &c);
	int solutions = Solve(a, b, c, &x1, &x2);
	switch (solutions)
	{
		case 0:
			printf("\nNo solutions\n");
			break;
		case 1:
			printf("\nOne solution: %0.5lf\n", x1);
			break;
		case 2:
			printf("\nTwo solutions: %0.5lf, %0.5lf\n", x1, x2);
			break;
		case -1:
			printf("\nAll numbers in R are solutions.\n");
			break;
		default:
			printf("\nError: function returned anomalius number.\n");
			break;
	}
}