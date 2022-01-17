/*============================================================================

  rationalize

  rationalize.c

  Turn a floating-point decimal number into a fraction, with specified
  precision.

  Version 1 -- all calculations in floating-point.

  Copyright (c)2022 Kevin Boone, GPL 3.0

============================================================================*/
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "rationalize.h" 

/*============================================================================

  rationalize 

============================================================================*/
void rationalize (double num, int order, BOOL improper, 
         int *whole, int *numerator, 
         int *denominator, BOOL *negative)
  {
  *negative = FALSE;
  if (num < 0) 
    {
    *negative = TRUE;
    num = -num;
    }

  if (!improper)
    {
    double frac = num - floor (num);
    *whole = (int) floor (num);
    num = frac;
    }
  else
    *whole = 0;

  double x = num;
  double a = floor (x);

  double n = a;
  double n1 = 1;
  double n2;
  
  double d = 1;
  double d1 = 0;
  double d2;
  
  double eps = pow (10, -order);

  // At this point, a is the first continued fraction coefficient
  //   in the expansion of x.
  // Repeat the continued fraction expansion of x until the continued
  //   fraction coefficient is as a close to an integer as we like.
  while (x - a > eps * d * d) 
    {
    x = 1 / (x-a);
    a = floor(x);
    // a is the next continued fraction coefficient in the expansion
    //   of x
    // We don't store the continued fraction coefficients -- we don't
    //   need to because we use the method of "left to right expansion".
    // In this method, all we need are the current cofficient a, the
    //   previous numerator or denominator, and the numerator or 
    //   denominator before that.
    // As we go, we shift the numerators and denominators such that
    //   the previous because this one, and the last-but-one becomes 
    //   the previous. The method doesn't require us to store more
    //   numerators or denominators than this.
    n2 = n1; 
    n1 = n;
    n = n2 + a * n1;

    d2 = d1; 
    d1 = d;
    d = d2 + a * d1;
    }

  *numerator = n;
  *denominator = d;
  }






