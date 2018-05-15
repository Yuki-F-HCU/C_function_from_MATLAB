/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: binodeviance.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 15-May-2018 14:46:03
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "BINOCDF.h"
#include "BINOINV.h"
#include "BINOPDF.h"
#include "BINORND.h"
#include "binodeviance.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                double np
 * Return Type  : double
 */
double binodeviance(double x, double np)
{
  double bd0;
  double v;
  double e;
  double j;
  double vv;
  double d;
  int exponent;
  if (fabs(x - np) < 0.1 * (x + np)) {
    bd0 = (x - np) * (x - np) / (x + np);
    v = (x - np) / (x + np);
    e = 2.0 * x * v;
    j = 1.0;
    vv = v * v;
    do {
      e *= vv;
      j += 2.0;
      d = e / j;
      bd0 += d;
      v = fabs(bd0);
      if ((!rtIsInf(v)) && (!rtIsNaN(v))) {
        if (v <= 2.2250738585072014E-308) {
          v = 4.94065645841247E-324;
        } else {
          frexp(v, &exponent);
          v = ldexp(1.0, exponent - 53);
        }
      } else {
        v = rtNaN;
      }
    } while (!(fabs(d) <= v));
  } else {
    bd0 = (x * log(x / np) + np) - x;
  }

  return bd0;
}

/*
 * File trailer for binodeviance.c
 *
 * [EOF]
 */
