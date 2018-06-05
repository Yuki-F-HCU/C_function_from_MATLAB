/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SUM.c
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
double SUM(const emxArray_real_T *x)
{
  double s;
  int k;
  if (x->size[1] == 0) {
    s = 0.0;
  } else {
    s = x->data[0];
    for (k = 2; k <= x->size[1]; k++) {
      s += x->data[k - 1];
    }
  }

  return s;
}

/*
 * File trailer for SUM.c
 *
 * [EOF]
 */
