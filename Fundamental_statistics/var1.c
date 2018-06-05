/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: var1.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 15-May-2018 16:15:49
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "HARMMEAN.h"
#include "MAX.h"
#include "MEAN.h"
#include "MEDIAN.h"
#include "NANMAX.h"
#include "NANMEAN.h"
#include "NANMEDIAN.h"
#include "NANSTD.h"
#include "NANSUM.h"
#include "NANVAR.h"
#include "STD.h"
#include "SUM.h"
#include "VAR.h"
#include "var1.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double var(const emxArray_real_T *x)
{
  double y;
  int i0;
  int d;
  int ix;
  double xbar;
  int k;
  double r;
  i0 = x->size[1];
  if (x->size[1] > 1) {
    d = x->size[1] - 1;
  } else {
    d = x->size[1];
  }

  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    ix = 0;
    xbar = x->data[0];
    for (k = 2; k <= i0; k++) {
      ix++;
      xbar += x->data[ix];
    }

    xbar /= (double)x->size[1];
    ix = 0;
    r = x->data[0] - xbar;
    y = r * r;
    for (k = 2; k <= i0; k++) {
      ix++;
      r = x->data[ix] - xbar;
      y += r * r;
    }

    y /= (double)d;
  }

  return y;
}

/*
 * File trailer for var1.c
 *
 * [EOF]
 */
