/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: NCHOOSEK.c
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
#include "GCD_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : double n
 *                double k
 * Return Type  : double
 */
double NCHOOSEK(double n, double k)
{
  double c;
  double b_k;
  double nmk;
  int j;
  if (k > n) {
    c = rtNaN;
  } else {
    b_k = k;
    if ((!rtIsInf(n)) && (!rtIsNaN(n)) && ((!rtIsInf(k)) && (!rtIsNaN(k)))) {
      if (k > n / 2.0) {
        b_k = n - k;
      }

      if (b_k > 1000.0) {
        c = rtInf;
      } else {
        c = 1.0;
        nmk = n - b_k;
        for (j = 0; j < (int)b_k; j++) {
          c *= ((1.0 + (double)j) + nmk) / (1.0 + (double)j);
        }

        c = rt_roundd_snf(c);
      }
    } else {
      c = rtNaN;
    }
  }

  return c;
}

/*
 * File trailer for NCHOOSEK.c
 *
 * [EOF]
 */
