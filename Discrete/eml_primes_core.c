/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eml_primes_core.c
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
#include "eml_primes_core.h"

/* Function Definitions */

/*
 * Arguments    : int a
 * Return Type  : int
 */
int intsqrt(int a)
{
  int r;
  int rr;
  int rhi;
  int rlo;
  boolean_T exitg1;
  rr = a / 2 + 1;
  if (46340 <= rr) {
    rhi = 46340;
  } else {
    rhi = rr;
  }

  if (a >= rhi * rhi) {
    r = rhi;
  } else {
    rlo = 0;
    r = rhi / 2;
    exitg1 = false;
    while ((!exitg1) && (r > rlo)) {
      rr = r * r;
      if (rr == a) {
        exitg1 = true;
      } else {
        if (rr > a) {
          rhi = r;
        } else {
          rlo = r;
        }

        rr = (rhi - rlo) / 2;
        if ((rlo > 0) && (rr > MAX_int32_T - rlo)) {
          r = MAX_int32_T;
        } else {
          r = rlo + rr;
        }
      }
    }
  }

  return r;
}

/*
 * File trailer for eml_primes_core.c
 *
 * [EOF]
 */
