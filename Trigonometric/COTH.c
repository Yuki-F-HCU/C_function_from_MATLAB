/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: COTH.c
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
creal_T COTH(const creal_T x)
{
  creal_T y;
  double tanhxr;
  double tanxi;
  double x_re;
  double bi;
  double bim;
  tanhxr = tanh(x.re);
  if (x.im == 0.0) {
    x_re = tanhxr;
    tanxi = 0.0;
  } else {
    tanxi = tan(x.im);
    bi = tanhxr * tanxi;
    if (bi == 0.0) {
      if (tanxi == 0.0) {
        x_re = tanhxr;
        tanxi = 0.0;
      } else if (tanhxr == 0.0) {
        x_re = 0.0;
      } else {
        x_re = tanhxr;
      }
    } else {
      bim = fabs(bi);
      if (1.0 > bim) {
        bim = bi;
        bi = 1.0 + bi * bi;
        x_re = (tanhxr + bim * tanxi) / bi;
        tanxi = (tanxi - bim * tanhxr) / bi;
      } else if (bim == 1.0) {
        if (bi > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }

        x_re = tanhxr * 0.5 + tanxi * bim;
        tanxi = tanxi * 0.5 - tanhxr * bim;
      } else {
        bim = 1.0 / bi;
        bi += bim;
        x_re = (bim * tanhxr + tanxi) / bi;
        tanxi = (bim * tanxi - tanhxr) / bi;
      }
    }
  }

  if (tanxi == 0.0) {
    y.re = 1.0 / x_re;
    y.im = 0.0;
  } else if (x_re == 0.0) {
    y.re = 0.0;
    y.im = -(1.0 / tanxi);
  } else {
    tanhxr = fabs(x_re);
    bim = fabs(tanxi);
    if (tanhxr > bim) {
      bim = tanxi / x_re;
      bi = x_re + bim * tanxi;
      y.re = (1.0 + bim * 0.0) / bi;
      y.im = (0.0 - bim) / bi;
    } else if (bim == tanhxr) {
      if (x_re > 0.0) {
        bi = 0.5;
      } else {
        bi = -0.5;
      }

      if (tanxi > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      y.re = (bi + 0.0 * bim) / tanhxr;
      y.im = (0.0 * bi - bim) / tanhxr;
    } else {
      bim = x_re / tanxi;
      bi = tanxi + bim * x_re;
      y.re = bim / bi;
      y.im = (bim * 0.0 - 1.0) / bi;
    }
  }

  return y;
}

/*
 * File trailer for COTH.c
 *
 * [EOF]
 */
