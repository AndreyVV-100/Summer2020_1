#include <assert.h>
const double EPS = 1e-5;

//--------------------------------------------
//! Solves square eqation (a*x^2 + b*x + c = 0).
//! 
//! @param [in] a first coefficient
//! @param [in] b second coefficient
//! @param [in] c third coefficient
//! @param [out] x1 Pointer to first solve
//!	@param [out] x2 Pointer to seconde solve
//!
//! @note
//! Usualy return number of solves eqation.
//! Return -1, if eqation is multiplicity R.
//! Need module <math.h> (functions abs ans sqrt).
//--------------------------------------------

int Solve(double a, double b, double c, double *x1, double *x2)
{
	/*Check data*/
	assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));
	if (fabs(a) < EPS)
	{
		if (fabs(b) < EPS)
		{
			if (fabs(c) < EPS) return -1;
			else return 0; /*a == 0, b == 0, c != 0*/
		}
		else /*a == 0, b != 0, c != 0*/
		{
			*x1 = -c / b;
			return 1;
		}
	}
	else /*a != 0*/
	{
		double D = b * b - 4 * a * c;
		if (D < 0) return 0;
		else if (D == 0)
		{
			*x1 = -b / 2 / a;
			return 1;
		}
		else /*D > 0*/
		{
			*x1 = (-b - sqrt(D)) / 2 / a;
			*x2 = (-b + sqrt(D)) / 2 / a;
			return 2;
		}
	}
}