/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: NANMEAN.c
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
double NANMEAN(const emxArray_real_T *x)
{
  double m;
  int c;
  int k;
  if (x->size[1] == 0) {
    m = rtNaN;
  } else {
    m = 0.0;
    c = 0;
    for (k = 0; k + 1 <= x->size[1]; k++) {
      if (!rtIsNaN(x->data[k])) {
        m += x->data[k];
        c++;
      }
    }

    if (c == 0) {
      m = rtNaN;
    } else {
      m /= (double)c;
    }
  }

  return m;
}

/*
 * File trailer for NANMEAN.c
 *
 * [EOF]
 */
