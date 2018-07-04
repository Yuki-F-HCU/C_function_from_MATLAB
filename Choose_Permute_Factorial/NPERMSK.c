/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: NPERMSK.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 04-Jul-2018 12:24:31
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FACTORIAL.h"
#include "NCHOOSEK.h"
#include "NPERMSK.h"
#include "factorial1.h"

/* Function Definitions */

/*
 * Arguments    : double n
 *                double k
 * Return Type  : double
 */
double NPERMSK(double n, double k)
{
  double x;
  double y;
  x = n;
  factorial(&x);
  y = n - k;
  factorial(&y);
  return x / y;
}

/*
 * File trailer for NPERMSK.c
 *
 * [EOF]
 */
