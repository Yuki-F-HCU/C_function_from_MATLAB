/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: gampdf.c
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
#include "gammaln.h"

/* Function Definitions */

/*
 * Arguments    : double z
 *                double a
 * Return Type  : double
 */
double f(double z, double a)
{
  double y;
  double nn;
  double delta;
  static const double sfe[31] = { 0.0, 0.1534264097200273, 0.081061466795327261,
    0.054814121051917651, 0.04134069595540929, 0.033162873519936291,
    0.027677925684998338, 0.0237461636562975, 0.02079067210376509,
    0.01848845053267319, 0.01664469118982119, 0.01513497322191738,
    0.01387612882307075, 0.012810465242920231, 0.01189670994589177,
    0.01110455975820868, 0.0104112652619721, 0.0097994161261588022,
    0.0092554621827127329, 0.0087687001341393844, 0.00833056343336287,
    0.0079341145643140217, 0.0075736754879518406, 0.007244554301320383,
    0.00694284010720953, 0.0066652470327076821, 0.0064089941880042071,
    0.0061717122630394576, 0.0059513701127588484, 0.0057462165130101163,
    0.0055547335519628011 };

  double s;
  double e;
  double j;
  double vv;
  double d;
  int exponent;
  if (a <= 2.2250738585072014E-308 * z) {
    y = exp(-z);
  } else if (z < 2.2250738585072014E-308 * a) {
    nn = a + 1.0;
    gammaln(&nn);
    y = exp((a * log(z) - z) - nn);
  } else {
    nn = a * a;
    if (a <= 15.0) {
      nn = 2.0 * a;
      if (nn == floor(nn)) {
        delta = sfe[(int)(nn + 1.0) - 1];
      } else {
        nn = a + 1.0;
        gammaln(&nn);
        delta = ((nn - (a + 0.5) * log(a)) + a) - 0.91893853320467278;
      }
    } else if (a <= 35.0) {
      delta = (0.083333333333333329 - (0.0027777777777777779 -
                (0.00079365079365079365 - (0.00059523809523809518 -
                  0.00084175084175084182 / nn) / nn) / nn) / nn) / a;
    } else if (a <= 80.0) {
      delta = (0.083333333333333329 - (0.0027777777777777779 -
                (0.00079365079365079365 - 0.00059523809523809518 / nn) / nn) /
               nn) / a;
    } else if (a <= 500.0) {
      delta = (0.083333333333333329 - (0.0027777777777777779 -
                0.00079365079365079365 / nn) / nn) / a;
    } else {
      delta = (0.083333333333333329 - 0.0027777777777777779 / nn) / a;
    }

    if (fabs(a - z) < 0.1 * (a + z)) {
      s = (a - z) * (a - z) / (a + z);
      nn = (a - z) / (a + z);
      e = 2.0 * a * nn;
      j = 1.0;
      vv = nn * nn;
      do {
        e *= vv;
        j += 2.0;
        d = e / j;
        s += d;
        nn = fabs(s);
        if ((!rtIsInf(nn)) && (!rtIsNaN(nn))) {
          if (nn <= 2.2250738585072014E-308) {
            nn = 4.94065645841247E-324;
          } else {
            frexp(nn, &exponent);
            nn = ldexp(1.0, exponent - 53);
          }
        } else {
          nn = rtNaN;
        }
      } while (!(fabs(d) <= nn));
    } else {
      s = (a * log(a / z) + z) - a;
    }

    y = exp(((-0.91893853320467267 - 0.5 * log(a)) - delta) - s);
  }

  return y;
}

/*
 * File trailer for gampdf.c
 *
 * [EOF]
 */
