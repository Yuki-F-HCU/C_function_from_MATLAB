/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ACOT.c
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
#include "atanh1.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T x
 * Return Type  : creal_T
 */
creal_T ACOT(const creal_T x)
{
  creal_T y;
  creal_T t;
  double brm;
  double bim;
  double d;
  if (x.im == 0.0) {
    t.re = 1.0 / x.re;
    t.im = 0.0;
  } else if (x.re == 0.0) {
    t.re = 0.0;
    t.im = -(1.0 / x.im);
  } else {
    brm = fabs(x.re);
    bim = fabs(x.im);
    if (brm > bim) {
      bim = x.im / x.re;
      d = x.re + bim * x.im;
      t.re = (1.0 + bim * 0.0) / d;
      t.im = (0.0 - bim) / d;
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

      t.re = (bim + 0.0 * d) / brm;
      t.im = (0.0 * bim - d) / brm;
    } else {
      bim = x.re / x.im;
      d = x.im + bim * x.re;
      t.re = bim / d;
      t.im = (bim * 0.0 - 1.0) / d;
    }
  }

  if (t.im == 0.0) {
    y.re = atan(t.re);
    y.im = 0.0;
  } else {
    bim = t.re;
    t.re = -t.im;
    t.im = bim;
    b_atanh(&t);
    y.re = t.im;
    y.im = -t.re;
  }

  return y;
}

/*
 * File trailer for ACOT.c
 *
 * [EOF]
 */
