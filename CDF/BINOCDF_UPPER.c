/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BINOCDF_UPPER.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Jun-2018 22:14:08
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "BETACDF.h"
#include "BETACDF_UPPER.h"
#include "BINOCDF.h"
#include "BINOCDF_UPPER.h"
#include "CHI2CDF.h"
#include "CHI2CDF_UPPER.h"
#include "EVCDF.h"
#include "EXPCDF.h"
#include "FCDF.h"
#include "FCDF_UPPER.h"
#include "GAMCDF.h"
#include "LOGNCDF.h"
#include "NORMCDF.h"
#include "TCDF.h"
#include "TCDF_UPPER.h"
#include "UNIFCDF.h"
#include "UNIFCDF_UPPER.h"
#include "binopdf.h"
#include "binocdf1.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                double N
 *                double p
 * Return Type  : double
 */
double BINOCDF_UPPER(double x, double N, double p)
{
  double c;
  double xk;
  double xf;
  int j;
  if ((p >= 0.0) && (p <= 1.0) && (N == floor(N)) && (!rtIsNaN(x))) {
    xk = (N - 1.0) - floor(x);
    if (xk >= N) {
      c = 1.0;
    } else if ((1.0 - p == 0.0) && (xk >= 0.0)) {
      c = 1.0;
    } else if (1.0 - p == 1.0) {
      c = (xk >= N);
    } else if (xk >= 0.0) {
      xf = floor(xk);
      if (N < 100000.0) {
        if ((xk <= N * (1.0 - p)) || (1.0 - p < 0.0001)) {
          c = 0.0;
          for (j = 0; j < (int)(xf + 1.0); j++) {
            c += binopdf(j, N, 1.0 - p);
          }

          if (c > 1.0) {
            c = 1.0;
          }
        } else {
          xk = (N - xf) - 1.0;
          xf = 0.0;
          for (j = 0; j < (int)(xk + 1.0); j++) {
            xf += binopdf(j, N, 1.0 - (1.0 - p));
          }

          if (xf > 1.0) {
            xf = 1.0;
          }

          c = 1.0 - xf;
        }
      } else {
        c = sumA2B(xf, N, 1.0 - p);
      }
    } else {
      c = 0.0;
    }
  } else {
    c = rtNaN;
  }

  return c;
}

/*
 * File trailer for BINOCDF_UPPER.c
 *
 * [EOF]
 */
