/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: TANH.c
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
creal_T TANH(const creal_T x)
{
  creal_T y;
  double tanhxr;
  double tanxi;
  double bi;
  double bim;
  double s;
  tanhxr = tanh(x.re);
  if (x.im == 0.0) {
    y.re = tanhxr;
    y.im = 0.0;
  } else {
    tanxi = tan(x.im);
    bi = tanhxr * tanxi;
    if (bi == 0.0) {
      if (tanxi == 0.0) {
        y.re = tanhxr;
        y.im = 0.0;
      } else if (tanhxr == 0.0) {
        y.re = 0.0;
        y.im = tanxi;
      } else {
        y.re = tanhxr;
        y.im = tanxi;
      }
    } else {
      bim = fabs(bi);
      if (1.0 > bim) {
        bim = 1.0 + bi * bi;
        y.re = (tanhxr + bi * tanxi) / bim;
        y.im = (tanxi - bi * tanhxr) / bim;
      } else if (bim == 1.0) {
        if (bi > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }

        y.re = tanhxr * 0.5 + tanxi * bim;
        y.im = tanxi * 0.5 - tanhxr * bim;
      } else {
        s = 1.0 / bi;
        bim = bi + s;
        y.re = (s * tanhxr + tanxi) / bim;
        y.im = (s * tanxi - tanhxr) / bim;
      }
    }
  }

  return y;
}

/*
 * File trailer for TANH.c
 *
 * [EOF]
 */
