/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: TAN.c
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
creal_T TAN(const creal_T x)
{
  creal_T y;
  double tanxr;
  double tanhxi;
  double bi;
  double bim;
  double s;
  if (x.im == 0.0) {
    y.re = tan(x.re);
    y.im = 0.0;
  } else {
    tanxr = tan(x.re);
    tanhxi = tanh(x.im);
    bi = -tanxr * tanhxi;
    if (bi == 0.0) {
      if (tanhxi == 0.0) {
        y.re = tanxr;
        y.im = 0.0;
      } else if (tanxr == 0.0) {
        y.re = 0.0;
        y.im = tanhxi;
      } else {
        y.re = tanxr;
        y.im = tanhxi;
      }
    } else {
      bim = fabs(bi);
      if (1.0 > bim) {
        bim = 1.0 + bi * bi;
        y.re = (tanxr + bi * tanhxi) / bim;
        y.im = (tanhxi - bi * tanxr) / bim;
      } else if (bim == 1.0) {
        if (bi > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }

        y.re = tanxr * 0.5 + tanhxi * bim;
        y.im = tanhxi * 0.5 - tanxr * bim;
      } else {
        s = 1.0 / bi;
        bim = bi + s;
        y.re = (s * tanxr + tanhxi) / bim;
        y.im = (s * tanhxi - tanxr) / bim;
      }
    }
  }

  return y;
}

/*
 * File trailer for TAN.c
 *
 * [EOF]
 */
