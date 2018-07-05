/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: asin1.c
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
#include "asinh1.h"
#include "acos2.h"
#include "sqrt.h"
#include "ACOS_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : creal_T *x
 * Return Type  : void
 */
void b_asin(creal_T *x)
{
  creal_T v;
  creal_T u;
  double uvr;
  double yr;
  if ((x->im == 0.0) && (!(fabs(x->re) > 1.0))) {
    x->re = asin(x->re);
    x->im = 0.0;
  } else {
    v.re = 1.0 + x->re;
    v.im = x->im;
    b_sqrt(&v);
    if (x->im != 0.0) {
      u.re = 1.0 - x->re;
      u.im = -x->im;
      b_sqrt(&u);
    } else {
      u.re = 1.0 - x->re;
      u.im = x->im;
      b_sqrt(&u);
    }

    uvr = u.re * v.re - u.im * v.im;
    yr = rt_atan2d_snf(fabs(x->re), fabs(uvr));
    if ((x->re < 0.0) != (uvr < 0.0)) {
      yr = -yr;
    }

    uvr = u.re * v.im - u.im * v.re;
    realScalarAsinh(&uvr);
    x->re = yr;
    x->im = uvr;
  }
}

/*
 * File trailer for asin1.c
 *
 * [EOF]
 */
