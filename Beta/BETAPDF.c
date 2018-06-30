/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BETAPDF.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 01-Jul-2018 00:59:48
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "BETACDF.h"
#include "BETACDF_UPPER.h"
#include "BETAINV.h"
#include "BETAPDF.h"
#include "BETARND.h"
#include "gammaln.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                double a
 *                double b
 * Return Type  : double
 */
double BETAPDF(double x, double a, double b)
{
  double y;
  double b_logb;
  double d2;
  double d3;
  double d4;
  if ((a > 0.0) && (b > 0.0) && (!rtIsNaN(x))) {
    if ((x > 0.0) && (x < 1.0)) {
      if (x < 0.1) {
        b_logb = -x;
        if (!(fabs(-x) < 2.2204460492503131E-16)) {
          b_logb = log(1.0 + -x) * (-x / ((1.0 + -x) - 1.0));
        }

        b_logb *= b - 1.0;
      } else {
        b_logb = (b - 1.0) * log(1.0 - x);
      }

      d2 = a;
      gammaln(&d2);
      d3 = b;
      gammaln(&d3);
      d4 = a + b;
      gammaln(&d4);
      y = exp(((a - 1.0) * log(x) + b_logb) - ((d2 + d3) - d4));
    } else if ((a == 1.0) && (x == 0.0)) {
      y = b;
    } else if ((b == 1.0) && (x == 1.0)) {
      y = a;
    } else if (((a < 1.0) && (x == 0.0)) || ((b < 1.0) && (x == 1.0))) {
      y = rtInf;
    } else {
      y = 0.0;
    }
  } else {
    y = rtNaN;
  }

  return y;
}

/*
 * File trailer for BETAPDF.c
 *
 * [EOF]
 */
