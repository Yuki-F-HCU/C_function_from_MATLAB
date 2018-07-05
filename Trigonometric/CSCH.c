/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CSCH.c
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

/* Function Definitions */

/*
 * Arguments    : const creal_T x
 * Return Type  : creal_T
 */
creal_T CSCH(const creal_T x)
{
  creal_T y;
  double x_re;
  double x_im;
  double brm;
  double bim;
  double s;
  if (x.im == 0.0) {
    x_re = sinh(x.re);
    x_im = 0.0;
  } else {
    x_re = sinh(x.re) * cos(x.im);
    x_im = cosh(x.re) * sin(x.im);
  }

  if (x_im == 0.0) {
    y.re = 1.0 / x_re;
    y.im = 0.0;
  } else if (x_re == 0.0) {
    y.re = 0.0;
    y.im = -(1.0 / x_im);
  } else {
    brm = fabs(x_re);
    bim = fabs(x_im);
    if (brm > bim) {
      s = x_im / x_re;
      bim = x_re + s * x_im;
      y.re = (1.0 + s * 0.0) / bim;
      y.im = (0.0 - s) / bim;
    } else if (bim == brm) {
      if (x_re > 0.0) {
        s = 0.5;
      } else {
        s = -0.5;
      }

      if (x_im > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      y.re = (s + 0.0 * bim) / brm;
      y.im = (0.0 * s - bim) / brm;
    } else {
      s = x_re / x_im;
      bim = x_im + s * x_re;
      y.re = s / bim;
      y.im = (s * 0.0 - 1.0) / bim;
    }
  }

  return y;
}

/*
 * File trailer for CSCH.c
 *
 * [EOF]
 */
