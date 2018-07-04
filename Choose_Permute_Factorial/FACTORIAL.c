/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: FACTORIAL.c
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
 * Arguments    : double k
 * Return Type  : double
 */
double FACTORIAL(double k)
{
  double a;
  a = k;
  factorial(&a);
  return a;
}

/*
 * File trailer for FACTORIAL.c
 *
 * [EOF]
 */
