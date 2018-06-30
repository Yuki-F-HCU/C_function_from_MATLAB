/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: binocdf1.c
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
#include "binocdf1.h"
#include "binopdf.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                double n
 *                double p
 * Return Type  : double
 */
double sumA2B(double x, double n, double p)
{
  double y;
  double mu;
  double sd;
  double t2;
  double x2;
  int i2;
  int j;
  mu = n * p;
  sd = sqrt(n * p * (1.0 - p));
  t2 = 10.0;
  x2 = ceil(mu + 10.0 * sd);
  while ((x <= x2) && (binopdf(x2, n, p) > 0.0)) {
    t2 *= 1.5;
    x2 = ceil(mu + t2 * sd);
  }

  if (x >= x2) {
    y = 1.0;
  } else {
    t2 = 40.0;
    x2 = floor(mu - 40.0 * sd);
    while ((0.0 < x2) && (binopdf(x2, n, p) > 2.2204460492503131E-16)) {
      t2 *= 1.5;
      x2 = floor(mu - t2 * sd);
    }

    if (x2 < 0.0) {
      x2 = 0.0;
    }

    if (x < x2) {
      y = 0.0;
    } else {
      y = 0.0;
      i2 = (int)(x + (1.0 - x2));
      for (j = 0; j < i2; j++) {
        y += binopdf(x2 + (double)j, n, p);
      }

      if (y > 1.0) {
        y = 1.0;
      }
    }
  }

  return y;
}

/*
 * File trailer for binocdf1.c
 *
 * [EOF]
 */
