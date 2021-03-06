/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sind1.c
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
#include "sind1.h"
#include "ACOS_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : creal_T *x
 * Return Type  : void
 */
void sind(creal_T *x)
{
  double xi;
  double crx;
  double absx;
  signed char n;
  xi = x->re;
  if (!((!rtIsInf(xi)) && (!rtIsNaN(xi)))) {
    crx = rtNaN;
    absx = rtNaN;
  } else {
    xi = rt_remd_snf(xi, 360.0);
    absx = fabs(xi);
    if (absx > 180.0) {
      if (xi > 0.0) {
        xi -= 360.0;
      } else {
        xi += 360.0;
      }

      absx = fabs(xi);
    }

    if (absx <= 45.0) {
      xi *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (xi > 0.0) {
        xi = 0.017453292519943295 * (xi - 90.0);
        n = 1;
      } else {
        xi = 0.017453292519943295 * (xi + 90.0);
        n = -1;
      }
    } else if (xi > 0.0) {
      xi = 0.017453292519943295 * (xi - 180.0);
      n = 2;
    } else {
      xi = 0.017453292519943295 * (xi + 180.0);
      n = -2;
    }

    if (n == 0) {
      crx = cos(xi);
      absx = sin(xi);
    } else if (n == 1) {
      crx = -sin(xi);
      absx = cos(xi);
    } else if (n == -1) {
      crx = sin(xi);
      absx = -cos(xi);
    } else {
      crx = -cos(xi);
      absx = -sin(xi);
    }
  }

  if (x->im == 0.0) {
    x->re = absx;
    x->im = 0.0;
  } else {
    xi = x->im * 0.017453292519943295;
    x->re = absx * cosh(xi);
    x->im = crx * sinh(xi);
  }
}

/*
 * File trailer for sind1.c
 *
 * [EOF]
 */
