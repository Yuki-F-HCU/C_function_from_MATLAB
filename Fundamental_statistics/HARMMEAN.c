/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: HARMMEAN.c
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
#include "HARMMEAN_emxutil.h"
#include "mean1.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double HARMMEAN(const emxArray_real_T *x)
{
  double m;
  emxArray_real_T *b_x;
  int k;
  int loop_ub;
  emxInit_real_T(&b_x, 2);
  k = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)b_x, k, (int)sizeof(double));
  loop_ub = x->size[0] * x->size[1];
  for (k = 0; k < loop_ub; k++) {
    b_x->data[k] = x->data[k];
  }

  for (k = 0; k < x->size[1]; k++) {
    b_x->data[k] = 1.0 / b_x->data[k];
  }

  m = mean(b_x);
  m = 1.0 / m;
  emxFree_real_T(&b_x);
  return m;
}

/*
 * File trailer for HARMMEAN.c
 *
 * [EOF]
 */
