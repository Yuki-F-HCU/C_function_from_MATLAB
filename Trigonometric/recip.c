/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: recip.c
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
#include "recip.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T y
 * Return Type  : creal_T
 */
creal_T recip(const creal_T y)
{
  creal_T z;
  double brm;
  double bim;
  double d;
  brm = fabs(y.re);
  bim = fabs(y.im);
  if (y.im == 0.0) {
    z.re = 1.0 / y.re;
    z.im = 0.0;
  } else if (y.re == 0.0) {
    z.re = 0.0;
    z.im = -1.0 / y.im;
  } else if (brm > bim) {
    bim = y.im / y.re;
    d = y.re + bim * y.im;
    z.re = 1.0 / d;
    z.im = -bim / d;
  } else if (brm == bim) {
    bim = 0.5;
    if (y.re < 0.0) {
      bim = -0.5;
    }

    d = 0.5;
    if (y.im < 0.0) {
      d = -0.5;
    }

    z.re = bim / brm;
    z.im = -d / brm;
  } else {
    bim = y.re / y.im;
    d = y.im + bim * y.re;
    z.re = bim / d;
    z.im = -1.0 / d;
  }

  return z;
}

/*
 * File trailer for recip.c
 *
 * [EOF]
 */
