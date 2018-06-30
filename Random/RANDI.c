/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: RANDI.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 01-Jul-2018 01:45:46
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "RAND.h"
#include "RANDG.h"
#include "RANDI.h"
#include "RANDN.h"
#include "rand1.h"

/* Function Definitions */

/*
 * Arguments    : double i
 * Return Type  : double
 */
double RANDI(double i)
{
  double x;
  if (i < 0.0) {
    i = ceil(i);
  } else {
    i = floor(i);
  }

  x = b_rand();
  return 1.0 + floor(x * i);
}

/*
 * File trailer for RANDI.c
 *
 * [EOF]
 */
