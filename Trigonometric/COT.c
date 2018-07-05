/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: COT.c
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
creal_T COT(const creal_T x)
{
  creal_T y;
  double tanxr;
  double x_re;
  double tanhxi;
  double bi;
  double bim;
  if (x.im == 0.0) {
    x_re = tan(x.re);
    tanhxi = 0.0;
  } else {
    tanxr = tan(x.re);
    tanhxi = tanh(x.im);
    bi = -tanxr * tanhxi;
    if (bi == 0.0) {
      if (tanhxi == 0.0) {
        x_re = tanxr;
        tanhxi = 0.0;
      } else if (tanxr == 0.0) {
        x_re = 0.0;
      } else {
        x_re = tanxr;
      }
    } else {
      bim = fabs(bi);
      if (1.0 > bim) {
        bim = bi;
        bi = 1.0 + bi * bi;
        x_re = (tanxr + bim * tanhxi) / bi;
        tanhxi = (tanhxi - bim * tanxr) / bi;
      } else if (bim == 1.0) {
        if (bi > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }

        x_re = tanxr * 0.5 + tanhxi * bim;
        tanhxi = tanhxi * 0.5 - tanxr * bim;
      } else {
        bim = 1.0 / bi;
        bi += bim;
        x_re = (bim * tanxr + tanhxi) / bi;
        tanhxi = (bim * tanhxi - tanxr) / bi;
      }
    }
  }

  if (tanhxi == 0.0) {
    y.re = 1.0 / x_re;
    y.im = 0.0;
  } else if (x_re == 0.0) {
    y.re = 0.0;
    y.im = -(1.0 / tanhxi);
  } else {
    tanxr = fabs(x_re);
    bim = fabs(tanhxi);
    if (tanxr > bim) {
      bim = tanhxi / x_re;
      bi = x_re + bim * tanhxi;
      y.re = (1.0 + bim * 0.0) / bi;
      y.im = (0.0 - bim) / bi;
    } else if (bim == tanxr) {
      if (x_re > 0.0) {
        bi = 0.5;
      } else {
        bi = -0.5;
      }

      if (tanhxi > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      y.re = (bi + 0.0 * bim) / tanxr;
      y.im = (0.0 * bi - bim) / tanxr;
    } else {
      bim = x_re / tanhxi;
      bi = tanhxi + bim * x_re;
      y.re = bim / bi;
      y.im = (bim * 0.0 - 1.0) / bi;
    }
  }

  return y;
}

/*
 * File trailer for COT.c
 *
 * [EOF]
 */
