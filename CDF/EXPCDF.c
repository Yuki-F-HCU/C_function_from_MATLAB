/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: EXPCDF.c
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
#include "expm1.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                double mu
 * Return Type  : double
 */
double EXPCDF(double x, double mu)
{
  double c;
  double xk;
  xk = x;
  if ((mu > 0.0) && (!rtIsNaN(x))) {
    if (x < 0.0) {
      xk = 0.0;
    }

    xk = -(xk / mu);
    b_expm1(&xk);
    c = -xk;
  } else {
    c = rtNaN;
  }

  return c;
}

/*
 * File trailer for EXPCDF.c
 *
 * [EOF]
 */
