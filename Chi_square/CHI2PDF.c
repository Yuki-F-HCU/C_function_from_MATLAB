/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CHI2PDF.c
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
#include "gampdf.h"

/* Function Definitions */

/*
 * Arguments    : double X
 *                double V
 * Return Type  : double
 */
double CHI2PDF(double X, double V)
{
  double Y;
  double vd2;
  double zk;
  vd2 = V / 2.0;
  if ((vd2 >= 0.0) && (!rtIsNaN(X))) {
    zk = X / 2.0;
    if (zk == 0.0) {
      if (vd2 < 1.0) {
        Y = rtInf;
      } else if (vd2 > 1.0) {
        Y = 0.0;
      } else {
        Y = 0.5;
      }
    } else if ((zk < 0.0) || rtIsInf(zk) || rtIsInf(vd2)) {
      Y = 0.0;
    } else if (vd2 < 1.0) {
      vd2 = f(zk, vd2) * exp(log(vd2) - log(zk));
      Y = vd2 / 2.0;
    } else {
      vd2 = f(zk, vd2 - 1.0);
      Y = vd2 / 2.0;
    }
  } else {
    Y = rtNaN;
  }

  return Y;
}

/*
 * File trailer for CHI2PDF.c
 *
 * [EOF]
 */
