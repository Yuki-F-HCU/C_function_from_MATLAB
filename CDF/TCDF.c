/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: TCDF.c
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
#include "erfc.h"
#include "betainc.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                double nu
 * Return Type  : double
 */
double TCDF(double x, double nu)
{
  double c;
  double xsq;
  creal_T dc7;
  if ((nu > 0.0) && (!rtIsNaN(x))) {
    if (x == 0.0) {
      c = 0.5;
    } else if (nu > 1.0E+7) {
      c = 0.5 * b_erfc(-x / 1.4142135623730951);
    } else if (nu == 1.0) {
      c = atan(1.0 / -x) / 3.1415926535897931;
      if (x > 0.0) {
        c++;
      }
    } else {
      xsq = x * x;
      if (nu < xsq) {
        dc7 = betainc(nu / (nu + xsq), nu / 2.0, 0.5);
        c = dc7.re / 2.0;
      } else {
        dc7 = b_betainc(xsq / (nu + xsq), 0.5, nu / 2.0);
        c = dc7.re / 2.0;
      }

      if (x > 0.0) {
        c = 1.0 - c;
      }
    }
  } else {
    c = rtNaN;
  }

  return c;
}

/*
 * File trailer for TCDF.c
 *
 * [EOF]
 */
