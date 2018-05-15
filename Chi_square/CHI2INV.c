/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CHI2INV.c
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
#include "gammaincinv.h"
#include "gammaln.h"

/* Function Definitions */

/*
 * Arguments    : double P
 *                double V
 * Return Type  : double
 */
double CHI2INV(double P, double V)
{
  double x;
  double vd2;
  double lga1;
  double lgap11;
  double b_lgap11;
  vd2 = V / 2.0;
  if ((0.0 <= vd2) && (!rtIsInf(vd2)) && (P >= 0.0) && (P <= 1.0)) {
    if ((P > 0.0) && (P < 1.0) && (vd2 > 0.0)) {
      lga1 = vd2;
      gammaln(&lga1);
      lgap11 = vd2 + 1.0;
      gammaln(&lgap11);
      b_lgap11 = vd2 + 1.0;
      gammaln(&b_lgap11);
      x = eml_gammaincinv(P, vd2, log(vd2), lga1, lgap11) * 2.0;
    } else if ((vd2 == 0.0) || (P == 0.0)) {
      x = 0.0;
    } else if (P == 1.0) {
      x = rtInf;
    } else {
      x = rtNaN;
    }
  } else {
    x = rtNaN;
  }

  return x;
}

/*
 * File trailer for CHI2INV.c
 *
 * [EOF]
 */
