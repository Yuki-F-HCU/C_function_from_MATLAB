/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: UNIFCDF_UPPER.c
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

/* Function Definitions */

/*
 * Arguments    : double x
 *                double a
 *                double b
 * Return Type  : double
 */
double UNIFCDF_UPPER(double x, double a, double b)
{
  double c;
  if (a < b) {
    if (x >= b) {
      c = 0.0;
    } else if ((x > a) && (x < b)) {
      c = (b - x) / (b - a);
    } else {
      c = 1.0;
    }
  } else {
    c = rtNaN;
  }

  return c;
}

/*
 * File trailer for UNIFCDF_UPPER.c
 *
 * [EOF]
 */
