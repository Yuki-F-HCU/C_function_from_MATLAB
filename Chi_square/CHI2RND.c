/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CHI2RND.c
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
#include "randn.h"
#include "rand.h"
#include "gammaincinv.h"
#include "CHI2CDF_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : double V
 * Return Type  : double
 */
double CHI2RND(double V)
{
  double vd2;
  double d;
  double ur[2];
  double u;
  double c;
  int iter;
  double v;
  double x;
  boolean_T reject;
  vd2 = V / 2.0;
  if (vd2 <= 0.0) {
    if (vd2 == 0.0) {
      vd2 = 0.0;
    } else {
      vd2 = rtNaN;
    }
  } else {
    if ((!rtIsInf(vd2)) && (!rtIsNaN(vd2))) {
      if (vd2 >= 1.0) {
        d = vd2 - 0.33333333333333331;
        u = b_rand();
        vd2 = 1.0;
      } else {
        d = (vd2 + 1.0) - 0.33333333333333331;
        c_rand(ur);
        u = ur[0];
        if (vd2 < 7.4567656047833286E-20) {
          vd2 = 0.0;
        } else {
          vd2 = rt_powd_snf(ur[1], 1.0 / vd2);
        }
      }

      c = 1.0 / sqrt(9.0 * d);
      iter = 0;
      v = 0.0;
      x = 0.0;
      reject = true;
      while (reject) {
        for (v = -1.0; v <= 0.0; v = 1.0 + c * x) {
          x = randn();
        }

        v *= v * v;
        x *= x;
        if (u < 1.0 - 0.0331 * x * x) {
          reject = false;
        } else if (log(u) < 0.5 * x + d * ((1.0 - v) + log(v))) {
          reject = false;
        } else {
          iter++;
          if (iter > 1000000) {
            reject = false;
          } else {
            u = b_rand();
          }
        }
      }

      vd2 *= d * v;
    }
  }

  return 2.0 * vd2;
}

/*
 * File trailer for CHI2RND.c
 *
 * [EOF]
 */
