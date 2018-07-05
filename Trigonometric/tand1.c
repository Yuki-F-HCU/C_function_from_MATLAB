/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: tand1.c
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
#include "tand1.h"
#include "ACOS_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : creal_T *x
 * Return Type  : void
 */
void tand(creal_T *x)
{
  double b_x;
  double tanxr;
  double absx;
  double tanhxi;
  signed char n;
  double s;
  b_x = x->re;
  if (!((!rtIsInf(b_x)) && (!rtIsNaN(b_x)))) {
    tanxr = rtNaN;
  } else {
    b_x = rt_remd_snf(b_x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = 0.017453292519943295 * (b_x - 90.0);
        n = 1;
      } else {
        b_x = 0.017453292519943295 * (b_x + 90.0);
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = 0.017453292519943295 * (b_x - 180.0);
      n = 2;
    } else {
      b_x = 0.017453292519943295 * (b_x + 180.0);
      n = -2;
    }

    tanxr = tan(b_x);
    if ((n == 1) || (n == -1)) {
      b_x = 1.0 / tanxr;
      tanxr = -(1.0 / tanxr);
      if (rtIsInf(tanxr) && (n == 1)) {
        tanxr = -(-b_x);
      }
    }
  }

  if (x->im == 0.0) {
    x->re = tanxr;
    x->im = 0.0;
  } else {
    tanhxi = tanh(x->im * 0.017453292519943295);
    absx = -tanxr * tanhxi;
    if (absx == 0.0) {
      if (tanhxi == 0.0) {
        x->re = tanxr;
        x->im = 0.0;
      } else if (tanxr == 0.0) {
        x->re = 0.0;
        x->im = tanhxi;
      } else {
        x->re = tanxr;
        x->im = tanhxi;
      }
    } else {
      b_x = fabs(absx);
      if (1.0 > b_x) {
        b_x = 1.0 + absx * absx;
        x->re = (tanxr + absx * tanhxi) / b_x;
        x->im = (tanhxi - absx * tanxr) / b_x;
      } else if (b_x == 1.0) {
        if (absx > 0.0) {
          b_x = 0.5;
        } else {
          b_x = -0.5;
        }

        x->re = tanxr * 0.5 + tanhxi * b_x;
        x->im = tanhxi * 0.5 - tanxr * b_x;
      } else {
        s = 1.0 / absx;
        b_x = absx + s;
        x->re = (s * tanxr + tanhxi) / b_x;
        x->im = (s * tanhxi - tanxr) / b_x;
      }
    }
  }
}

/*
 * File trailer for tand1.c
 *
 * [EOF]
 */
