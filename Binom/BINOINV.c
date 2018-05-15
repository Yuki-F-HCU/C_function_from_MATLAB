/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BINOINV.c
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
 * Arguments    : double y
 *                double N
 *                double p
 * Return Type  : double
 */
double BINOINV(double y, double N, double p)
{
  double x;
  double cumdist;
  int exitg1;
  if ((N >= 0.0) && (p >= 0.0) && (p <= 1.0) && (y >= 0.0) && (y <= 1.0) &&
      (floor(N) == N)) {
    if (y == 1.0) {
      x = N;
    } else {
      x = 0.0;
      cumdist = 0.0;
      do {
        exitg1 = 0;
        cumdist += binopdf(x, N, p);
        if ((cumdist > y) || (x >= N)) {
          exitg1 = 1;
        } else {
          x++;
        }
      } while (exitg1 == 0);
    }
  } else {
    x = rtNaN;
  }

  return x;
}

/*
 * File trailer for BINOINV.c
 *
 * [EOF]
 */
