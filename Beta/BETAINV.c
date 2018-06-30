/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BETAINV.c
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
#include "betaincinv.h"

/* Function Definitions */

/*
 * Arguments    : double p
 *                double a
 *                double b
 * Return Type  : double
 */
double BETAINV(double p, double a, double b)
{
  double x;
  double glna1;
  double glnb1;
  double d1;
  if ((a > 0.0) && (b > 0.0) && (!rtIsInf(a)) && (!rtIsInf(b)) && (p >= 0.0) &&
      (p <= 1.0)) {
    glna1 = a;
    gammaln(&glna1);
    glnb1 = b;
    gammaln(&glnb1);
    d1 = a + b;
    gammaln(&d1);
    x = eml_betaincinv(p, a, b, (glna1 + glnb1) - d1);
    glna1 = a;
    gammaln(&glna1);
    glnb1 = b;
    gammaln(&glnb1);
    d1 = a + b;
    gammaln(&d1);
    eml_betainc(x, a, b, (glna1 + glnb1) - d1);
  } else {
    x = rtNaN;
  }

  return x;
}

/*
 * File trailer for BETAINV.c
 *
 * [EOF]
 */
