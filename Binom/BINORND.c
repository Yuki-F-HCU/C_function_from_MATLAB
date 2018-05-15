/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BINORND.c
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
#include "rand.h"

/* Function Definitions */

/*
 * Arguments    : double N
 *                double P
 * Return Type  : double
 */
double BINORND(double N, double P)
{
  double R;
  int j;
  if ((0.0 <= P) && (P <= 1.0) && (0.0 <= N) && (floor(N) == N)) {
    R = 0.0;
    for (j = 0; j < (int)N; j++) {
      if (b_rand() < P) {
        R++;
      }
    }
  } else {
    R = rtNaN;
  }

  return R;
}

/*
 * File trailer for BINORND.c
 *
 * [EOF]
 */
