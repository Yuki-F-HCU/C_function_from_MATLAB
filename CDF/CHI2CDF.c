/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CHI2CDF.c
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

/* Function Definitions */

/*
 * Arguments    : double x
 *                double v
 * Return Type  : double
 */
double CHI2CDF(double x, double v)
{
  double c;
  double vd2;
  double xk;
  creal_T dc2;
  vd2 = v / 2.0;
  xk = x;
  if ((vd2 >= 0.0) && (!rtIsNaN(x))) {
    if (x < 0.0) {
      xk = 0.0;
    }

    dc2 = gammainc(xk / 2.0, vd2);
    c = dc2.re;
  } else {
    c = rtNaN;
  }

  return c;
}

/*
 * File trailer for CHI2CDF.c
 *
 * [EOF]
 */
