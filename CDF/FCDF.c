/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: FCDF.c
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
double FCDF(double x, double v1, double v2)
{
  double c;
  creal_T dc4;
  double num;
  if ((v1 > 0.0) && (v2 > 0.0) && (!rtIsNaN(x))) {
    if (x > 0.0) {
      if (rtIsInf(x)) {
        c = 1.0;
      } else if (rtIsInf(v1)) {
        if (rtIsInf(v2)) {
          c = (x >= 1.0);
        } else {
          dc4 = b_gammainc(v2 / x / 2.0, v2 / 2.0);
          c = dc4.re;
        }
      } else if (rtIsInf(v2)) {
        dc4 = gammainc(v1 * x / 2.0, v1 / 2.0);
        c = dc4.re;
      } else if (v2 <= x * v1) {
        dc4 = b_betainc(v2 / (v2 + x * v1), v2 / 2.0, v1 / 2.0);
        c = dc4.re;
      } else {
        num = v1 * x;
        dc4 = betainc(num / (num + v2), v1 / 2.0, v2 / 2.0);
        c = dc4.re;
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
 * File trailer for FCDF.c
 *
 * [EOF]
 */
