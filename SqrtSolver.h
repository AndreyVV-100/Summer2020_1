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
//! Return -2, if input is bad.
//! Need module <math.h> (functions abs ans sqrt).
//--------------------------------------------

int Solve(double a, double b, double c, double *x1, double *x2)
{
	if (x1 == NULL ||
		x2 == NULL ||
		!isfinite(a) ||
		!isfinite(b) ||
		!isfinite(c))
		return -2; /*Check input*/
	if (abs(a) < EPS)
	{
		if (abs(b) < EPS)
		{
			if (abs(c) < EPS) return -1;
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