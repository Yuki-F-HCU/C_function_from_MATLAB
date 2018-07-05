/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: gcd1.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 06-Jul-2018 03:08:24
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "GCD.h"
#include "ISPRIME.h"
#include "LCM.h"
#include "NCHOOSEK.h"
#include "gcd1.h"

/* Function Definitions */

/*
 * Arguments    : double a
 *                double b
 * Return Type  : double
 */
double gcd(double a, double b)
{
  double g;
  boolean_T p;
  double flxk;
  boolean_T guard1 = false;
  double b_flxk;
  double r;
  double glast;
  double c_flxk;
  p = false;
  flxk = floor(a);
  if ((!((!rtIsInf(flxk)) && (!rtIsNaN(flxk)))) || (a != floor(a))) {
    p = true;
  }

  guard1 = false;
  if (p) {
    guard1 = true;
  } else {
    p = false;
    flxk = floor(b);
    if ((!((!rtIsInf(flxk)) && (!rtIsNaN(flxk)))) || (b != floor(b))) {
      p = true;
    }

    if (p) {
      guard1 = true;
    } else {
      p = false;
    }
  }

  if (guard1) {
    p = true;
  }

  if (p) {
    g = rtNaN;
  } else if (b == 0.0) {
    g = a;
  } else {
    g = b;
    flxk = a / b;
    if (flxk < 0.0) {
      b_flxk = ceil(flxk);
    } else {
      b_flxk = floor(flxk);
    }

    for (r = a - b * b_flxk; r != 0.0; r = glast - r * c_flxk) {
      glast = g;
      g = r;
      flxk = glast / r;
      if (flxk < 0.0) {
        c_flxk = ceil(flxk);
      } else {
        c_flxk = floor(flxk);
      }
    }

    if (g < 0.0) {
      g = -g;
    }
  }

  return g;
}

/*
 * File trailer for gcd1.c
 *
 * [EOF]
 */
