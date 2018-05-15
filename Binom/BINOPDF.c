/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BINOPDF.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 15-May-2018 14:46:03
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "BINOCDF.h"
#include "BINOINV.h"
#include "BINOPDF.h"
#include "BINORND.h"
#include "binopdf1.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                double N
 *                double p
 * Return Type  : double
 */
double BINOPDF(double x, double N, double p)
{
  return binopdf(x, N, p);
}

/*
 * File trailer for BINOPDF.c
 *
 * [EOF]
 */
