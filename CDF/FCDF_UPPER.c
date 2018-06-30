/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: FCDF_UPPER.c
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
#include "gammainc.h"
#include "betainc.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                double v1
 *                double v2
 * Return Type  : double
 */
double FCDF_UPPER(double x, double v1, double v2)
{
  double c;
  double xk;
  creal_T dc5;
  if (x <= 0.0) {
    xk = rtInf;
  } else {
    xk = 1.0 / x;
  }

  if ((v2 > 0.0) && (v1 > 0.0) && (!rtIsNaN(xk))) {
    if (xk > 0.0) {
      if (rtIsInf(xk)) {
        c = 1.0;
      } else if (rtIsInf(v2)) {
        if (rtIsInf(v1)) {
          c = (xk > 1.0);
        } else {
          dc5 = b_gammainc(v1 / xk / 2.0, v1 / 2.0);
          c = dc5.re;
        }
      } else if (rtIsInf(v1)) {
        dc5 = gammainc(v2 * xk / 2.0, v2 / 2.0);
        c = dc5.re;
      } else if (v1 <= xk * v2) {
        dc5 = b_betainc(v1 / (v1 + xk * v2), v1 / 2.0, v2 / 2.0);
        c = dc5.re;
      } else {
        xk *= v2;
        dc5 = betainc(xk / (xk + v1), v2 / 2.0, v1 / 2.0);
        c = dc5.re;
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
 * File trailer for FCDF_UPPER.c
 *
 * [EOF]
 */
