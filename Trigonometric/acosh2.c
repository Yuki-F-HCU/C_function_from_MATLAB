/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: acosh2.c
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
#include "acosh2.h"
#include "acos2.h"
#include "asinh1.h"
#include "sqrt.h"
#include "ACOS_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : creal_T *x
 * Return Type  : void
 */
void b_acosh(creal_T *x)
{
  creal_T v;
  double yr;
  creal_T u;
  double yi;
  if (rtIsNaN(x->re) && (x->im == 0.0)) {
    yr = x->re;
    if (yr < 1.0) {
      yr = rtNaN;
    } else if (yr >= 2.68435456E+8) {
      yr = log(yr) + 0.69314718055994529;
    } else if (yr > 2.0) {
      yr = log(yr + sqrt(yr * yr - 1.0));
    } else {
      yr = (yr - 1.0) + sqrt(2.0 * (yr - 1.0) + (yr - 1.0) * (yr - 1.0));
      if (!((!rtIsInf(yr)) && (!rtIsNaN(yr)))) {
        yr = log(1.0 + yr);
      } else {
        if (!(yr < 2.2204460492503131E-16)) {
          yr = log(1.0 + yr) * (yr / ((1.0 + yr) - 1.0));
        }
      }
    }

    yi = 0.0;
  } else {
    v.re = x->re + 1.0;
    v.im = x->im;
    b_sqrt(&v);
    u.re = x->re - 1.0;
    u.im = x->im;
    b_sqrt(&u);
    yr = u.re * v.re + u.im * v.im;
    realScalarAsinh(&yr);
    if (rtIsInf(u.im) && rtIsInf(v.re)) {
      yi = rtNaN;
    } else {
      yi = 2.0 * rt_atan2d_snf(fabs(u.im), fabs(v.re));
      if ((u.im < 0.0) != (v.re < 0.0)) {
        yi = -yi;
      }
    }
  }

  x->re = yr;
  x->im = yi;
}

/*
 * File trailer for acosh2.c
 *
 * [EOF]
 */
