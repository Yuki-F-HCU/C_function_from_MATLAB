/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: nanvar1.c
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
#include "nanvar1.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double nanvar(const emxArray_real_T *x)
{
  double y;
  int n;
  int ix;
  double xbar;
  int nn;
  int k;
  double r;
  n = x->size[1];
  if (x->size[1] == 0) {
    y = rtNaN;
  } else {
    ix = 0;
    xbar = 0.0;
    nn = 0;
    for (k = 1; k <= n; k++) {
      if (!rtIsNaN(x->data[ix])) {
        xbar += x->data[ix];
        nn++;
      }

      ix++;
    }

    if (nn == 0) {
      y = rtNaN;
    } else {
      xbar /= (double)nn;
      ix = 0;
      y = 0.0;
      for (k = 1; k <= n; k++) {
        if (!rtIsNaN(x->data[ix])) {
          r = x->data[ix] - xbar;
          y += r * r;
        }

        ix++;
      }

      if (nn > 1) {
        nn--;
      }

      y /= (double)nn;
    }
  }

  return y;
}

/*
 * File trailer for nanvar1.c
 *
 * [EOF]
 */
