/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: EVCDF.c
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
 *                double sigma
 * Return Type  : double
 */
double EVCDF(double x, double mu, double sigma)
{
  double c;
  double zk;
  if (sigma > 0.0) {
    zk = (x - mu) / sigma;
    if (zk > 3.62247112598261) {
      c = 1.0;
    } else {
      zk = -exp(zk);
      b_expm1(&zk);
      c = -zk;
    }
  } else {
    c = rtNaN;
  }

  return c;
}

/*
 * File trailer for EVCDF.c
 *
 * [EOF]
 */
