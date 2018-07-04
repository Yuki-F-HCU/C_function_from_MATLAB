/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: NCHOOSEK.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 04-Jul-2018 12:24:31
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FACTORIAL.h"
#include "NCHOOSEK.h"
#include "NPERMSK.h"

/* Function Declarations */
static double rt_roundd_snf(double u);

/* Function Definitions */

/*
 * Arguments    : double u
 * Return Type  : double
 */
static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/*
 * Arguments    : double n
 *                double k
 * Return Type  : double
 */
double NCHOOSEK(double n, double k)
{
  double a;
  double b_k;
  double nmk;
  int j;
  if (k > n) {
    a = rtNaN;
  } else {
    b_k = k;
    if ((!rtIsInf(n)) && (!rtIsNaN(n)) && ((!rtIsInf(k)) && (!rtIsNaN(k)))) {
      if (k > n / 2.0) {
        b_k = n - k;
      }

      if (b_k > 1000.0) {
        a = rtInf;
      } else {
        a = 1.0;
        nmk = n - b_k;
        for (j = 0; j < (int)b_k; j++) {
          a *= ((1.0 + (double)j) + nmk) / (1.0 + (double)j);
        }

        a = rt_roundd_snf(a);
      }
    } else {
      a = rtNaN;
    }
  }

  return a;
}

/*
 * File trailer for NCHOOSEK.c
 *
 * [EOF]
 */
