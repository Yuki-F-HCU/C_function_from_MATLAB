/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ACSCD.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 06-Jul-2018 01:48:54
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "ACOS.h"
#include "ACOSD.h"
#include "ACOSH.h"
#include "ACOT.h"
#include "ACOTD.h"
#include "ACOTH.h"
#include "ACSC.h"
#include "ACSCD.h"
#include "ACSCH.h"
#include "ASEC.h"
#include "ASECD.h"
#include "ASECH.h"
#include "ASIN.h"
#include "ASIND.h"
#include "ASINH.h"
#include "ATAN.h"
#include "ATAN2.h"
#include "ATAN2D.h"
#include "ATAND.h"
#include "ATANH.h"
#include "COS.h"
#include "COSD.h"
#include "COSH.h"
#include "COT.h"
#include "COTD.h"
#include "COTH.h"
#include "CSC.h"
#include "CSCD.h"
#include "CSCH.h"
#include "DEG2RAD.h"
#include "HYPOT.h"
#include "RAD2DEG.h"
#include "SEC.h"
#include "SECH.h"
#include "SIN.h"
#include "SIND.h"
#include "SINH.h"
#include "TAN.h"
#include "TAND.h"
#include "TANH.h"
#include "asin1.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T x
 * Return Type  : creal_T
 */
creal_T ACSCD(const creal_T x)
{
  creal_T y;
  creal_T dc1;
  double brm;
  double bim;
  double d;
  if (x.im == 0.0) {
    dc1.re = 1.0 / x.re;
    dc1.im = 0.0;
  } else if (x.re == 0.0) {
    dc1.re = 0.0;
    dc1.im = -(1.0 / x.im);
  } else {
    brm = fabs(x.re);
    bim = fabs(x.im);
    if (brm > bim) {
      bim = x.im / x.re;
      d = x.re + bim * x.im;
      dc1.re = (1.0 + bim * 0.0) / d;
      dc1.im = (0.0 - bim) / d;
    } else if (bim == brm) {
      if (x.re > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      if (x.im > 0.0) {
        d = 0.5;
      } else {
        d = -0.5;
      }

      dc1.re = (bim + 0.0 * d) / brm;
      dc1.im = (0.0 * bim - d) / brm;
    } else {
      bim = x.re / x.im;
      d = x.im + bim * x.re;
      dc1.re = bim / d;
      dc1.im = (bim * 0.0 - 1.0) / d;
    }
  }

  b_asin(&dc1);
  y.re = 57.295779513082323 * dc1.re;
  y.im = 57.295779513082323 * dc1.im;
  return y;
}

/*
 * File trailer for ACSCD.c
 *
 * [EOF]
 */
