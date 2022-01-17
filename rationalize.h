/*============================================================================

  rationalize

  rationalize.h 

  Copyright (c)2022 Kevin Boone, GPL 3.0

============================================================================*/
#ifndef __RATIONALIZE_H
#define __RATIONALIZE_H

#ifndef BOOL
typedef int BOOL;
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE 
#define FALSE 0 
#endif

/** Convert the number n to a fraction, with results written to
    *whole, *numerator, and *denominator. The function will find the
    fraction that is nearest to the input number, considering 'order'
    digits of precision. If *improper is TRUE, output a top-heavy
    fraction when n > 1. */
void rationalize (double n, int order, BOOL improper, int *whole, 
         int *numerator, int *denominator, BOOL *negative);

#endif
