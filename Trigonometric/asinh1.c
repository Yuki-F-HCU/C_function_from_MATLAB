/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: asinh1.c
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
#include "asinh1.h"

/* Function Definitions */

/*
 * Arguments    : double *x
 * Return Type  : void
 */
void realScalarAsinh(double *x)
{
  boolean_T xneg;
  double t;
  double absz;
  xneg = (*x < 0.0);
  if (xneg) {
    *x = -*x;
  }

  if (*x >= 2.68435456E+8) {
    *x = log(*x) + 0.69314718055994529;
  } else if (*x > 2.0) {
    *x = log(2.0 * *x + 1.0 / (sqrt(*x * *x + 1.0) + *x));
  } else {
    t = *x * *x;
    t = *x + t / (1.0 + sqrt(1.0 + t));
    *x = t;
    absz = fabs(t);
    if ((absz > 4.503599627370496E+15) || (!((!rtIsInf(t)) && (!rtIsNaN(t))))) {
      *x = log(1.0 + t);
    } else {
      if (!(absz < 2.2204460492503131E-16)) {
        *x = log(1.0 + t) * (t / ((1.0 + t) - 1.0));
      }
    }
  }

  if (xneg) {
    *x = -*x;
  }
}

/*
 * File trailer for asinh1.c
 *
 * [EOF]
 */
