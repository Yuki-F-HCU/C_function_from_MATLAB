/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: RANDG.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 01-Jul-2018 01:45:46
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "RAND.h"
#include "RANDG.h"
#include "RANDI.h"
#include "RANDN.h"
#include "randn1.h"
#include "rand1.h"

/* Function Declarations */
static double rt_powd_snf(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_powd_snf(double u0, double u1)
{
  double y;
  double d0;
  double d1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d0 = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d0 == 1.0) {
        y = rtNaN;
      } else if (d0 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/*
 * Arguments    : double a
 * Return Type  : double
 */
double RANDG(double a)
{
  double x;
  double d;
  double ur[2];
  double u;
  double p;
  double c;
  int iter;
  double v;
  boolean_T reject;
  if (a <= 0.0) {
    if (a == 0.0) {
      x = 0.0;
    } else {
      x = rtNaN;
    }
  } else if ((!rtIsInf(a)) && (!rtIsNaN(a))) {
    if (a >= 1.0) {
      d = a - 0.33333333333333331;
      u = c_rand();
      p = 1.0;
    } else {
      d = (a + 1.0) - 0.33333333333333331;
      d_rand(ur);
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
          u = c_rand();
        }
      }
    }

    x = d * v * p;
  } else {
    x = a;
  }

  return x;
}

/*
 * File trailer for RANDG.c
 *
 * [EOF]
 */
