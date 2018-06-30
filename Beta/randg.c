/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: randg.c
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
#include "randg.h"
#include "randn.h"
#include "rand.h"
#include "BETACDF_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : double a
 * Return Type  : double
 */
double randg(double a)
{
  double y;
  double d;
  double ur[2];
  double u;
  double p;
  double c;
  int iter;
  double v;
  double x;
  boolean_T reject;
  if (a <= 0.0) {
    if (a == 0.0) {
      y = 0.0;
    } else {
      y = rtNaN;
    }
  } else if ((!rtIsInf(a)) && (!rtIsNaN(a))) {
    if (a >= 1.0) {
      d = a - 0.33333333333333331;
      u = b_rand();
      p = 1.0;
    } else {
      d = (a + 1.0) - 0.33333333333333331;
      c_rand(ur);
      u = ur[0];
      if (a < 7.4567656047833286E-20) {
        p = 0.0;
      } else {
        p = rt_powd_snf(ur[1], 1.0 / a);
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

    y = d * v * p;
  } else {
    y = a;
  }

  return y;
}

/*
 * File trailer for randg.c
 *
 * [EOF]
 */
