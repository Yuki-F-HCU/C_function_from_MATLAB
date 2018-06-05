/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: MAX.c
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

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double MAX(const emxArray_real_T *x)
{
  double M;
  int ixstart;
  int n;
  int ix;
  boolean_T exitg1;
  ixstart = 1;
  n = x->size[1];
  M = x->data[0];
  if (x->size[1] > 1) {
    if (rtIsNaN(x->data[0])) {
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= n)) {
        ixstart = ix;
        if (!rtIsNaN(x->data[ix - 1])) {
          M = x->data[ix - 1];
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < x->size[1]) {
      while (ixstart + 1 <= n) {
        if (x->data[ixstart] > M) {
          M = x->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  return M;
}

/*
 * File trailer for MAX.c
 *
 * [EOF]
 */
