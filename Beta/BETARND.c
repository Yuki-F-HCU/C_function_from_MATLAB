/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BETARND.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 01-Jul-2018 00:59:48
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "BETACDF.h"
#include "BETACDF_UPPER.h"
#include "BETAINV.h"
#include "BETAPDF.h"
#include "BETARND.h"
#include "rand.h"
#include "randg.h"

/* Function Definitions */

/*
 * Arguments    : double a
 *                double b
 * Return Type  : double
 */
double BETARND(double a, double b)
{
  double r;
  double g1k;
  g1k = randg(a);
  r = g1k + randg(b);
  if (r > 0.0) {
    r = g1k / r;
  } else {
    if ((!rtIsNaN(r)) && (b_rand() < a / (a + b))) {
      r = 1.0;
    }
  }

  return r;
}

/*
 * File trailer for BETARND.c
 *
 * [EOF]
 */
