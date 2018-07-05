/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: atanh1.c
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
#include "acos2.h"
#include "ACOS_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : creal_T *x
 * Return Type  : void
 */
void b_atanh(creal_T *x)
{
  double xr;
  double xi;
  double t;
  double b_xr;
  double b_xi;
  xr = fabs(x->re);
  xi = fabs(x->im);
  if ((xr > 3.3519519824856489E+153) || (xi > 3.3519519824856489E+153)) {
    if (xi == 0.0) {
      xr = 1.0 / xr;
    } else if (xr == 0.0) {
      xr = 0.0;
    } else if (xr > xi) {
      t = xi / xr;
      xr = (1.0 + t * 0.0) / (xr + t * xi);
    } else if (xi == xr) {
      if (xr > 0.0) {
        b_xr = 0.5;
      } else {
        b_xr = -0.5;
      }

      if (xi > 0.0) {
        b_xi = 0.5;
      } else {
        b_xi = -0.5;
      }

      xr = (b_xr + 0.0 * b_xi) / xr;
    } else {
      t = xr / xi;
      xr = t / (xi + t * xr);
    }

    xi = 1.5707963267948966;
  } else if ((xr == 1.0) && (xi == 0.0)) {
    xr = rtInf;
    xi = 0.0;
  } else if (xr == 1.0) {
    xr = log(sqrt(sqrt(4.0 + xi * xi)) / sqrt(xi + 2.9833362924800834E-154));
    xi = (1.5707963267948966 + atan((xi + 2.9833362924800834E-154) / 2.0)) / 2.0;
  } else if ((xi == 0.0) && (!(xr > 1.0))) {
    if (xr < 0.5) {
      t = xr + xr;
      t += t * (xr / (1.0 - xr));
      if (!(t < 2.2204460492503131E-16)) {
        t = log(1.0 + t) * (t / ((1.0 + t) - 1.0));
      }

      xr = t / 2.0;
    } else if (xr == 1.0) {
      xr = rtInf;
    } else {
      t = (xr + xr) / (1.0 - xr);
      xr = fabs(t);
      if ((xr > 4.503599627370496E+15) || (!((!rtIsInf(t)) && (!rtIsNaN(t))))) {
        t = log(1.0 + t);
      } else {
        if (!(xr < 2.2204460492503131E-16)) {
          t = log(1.0 + t) * (t / ((1.0 + t) - 1.0));
        }
      }

      xr = t / 2.0;
    }

    xi = 0.0;
  } else {
    t = xi + 2.9833362924800834E-154;
    xi = rt_atan2d_snf(2.0 * xi, (1.0 - xr) * (1.0 + xr) - (xi +
      2.9833362924800834E-154) * (xi + 2.9833362924800834E-154)) / 2.0;
    t = 4.0 * (xr / ((1.0 - xr) * (1.0 - xr) + t * t));
    xr = fabs(t);
    if ((xr > 4.503599627370496E+15) || (!((!rtIsInf(t)) && (!rtIsNaN(t))))) {
      t = log(1.0 + t);
    } else {
      if (!(xr < 2.2204460492503131E-16)) {
        t = log(1.0 + t) * (t / ((1.0 + t) - 1.0));
      }
    }

    xr = t / 4.0;
  }

  if (x->re < 0.0) {
    xr = -xr;
  }

  if ((x->im < 0.0) || ((x->im == 0.0) && (x->re < -1.0))) {
    xi = -xi;
  }

  x->re = xr;
  x->im = xi;
}

/*
 * File trailer for atanh1.c
 *
 * [EOF]
 */
