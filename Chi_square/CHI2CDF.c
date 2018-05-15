/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CHI2CDF.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 14-May-2018 23:32:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "CHI2CDF.h"
#include "CHI2INV.h"
#include "CHI2PDF.h"
#include "CHI2RND.h"
#include "gammainc.h"
#include "gammaln.h"

/* Function Definitions */

/*
 * Arguments    : double X
 *                double V
 * Return Type  : double
 */
double CHI2CDF(double X, double V)
{
  double P;
  double vd2;
  double xk;
  double lgap11;
  vd2 = V / 2.0;
  xk = X;
  if ((vd2 >= 0.0) && (!rtIsNaN(X))) {
    if (X < 0.0) {
      xk = 0.0;
    }

    lgap11 = vd2 + 1.0;
    gammaln(&lgap11);
    P = (scalar_gammainc(xk / 2.0, vd2, log(vd2), lgap11)).re;
  } else {
    P = rtNaN;
  }

  return P;
}

/*
 * File trailer for CHI2CDF.c
 *
 * [EOF]
 */
