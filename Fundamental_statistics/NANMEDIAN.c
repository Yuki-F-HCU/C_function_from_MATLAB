/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: NANMEDIAN.c
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
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double NANMEDIAN(const emxArray_real_T *x)
{
  double M;
  emxArray_int32_T *idx;
  int n;
  int i2;
  int nj;
  emxArray_int32_T *iwork;
  boolean_T p;
  int i;
  int j;
  int pEnd;
  int b_p;
  double r;
  int q;
  int qEnd;
  int kEnd;
  if (x->size[1] == 0) {
    M = rtNaN;
  } else {
    emxInit_int32_T(&idx, 2);
    n = x->size[1] + 1;
    i2 = idx->size[0] * idx->size[1];
    idx->size[0] = 1;
    idx->size[1] = x->size[1];
    emxEnsureCapacity((emxArray__common *)idx, i2, (int)sizeof(int));
    nj = x->size[1];
    for (i2 = 0; i2 < nj; i2++) {
      idx->data[i2] = 0;
    }

    emxInit_int32_T1(&iwork, 1);
    nj = x->size[1];
    i2 = iwork->size[0];
    iwork->size[0] = nj;
    emxEnsureCapacity((emxArray__common *)iwork, i2, (int)sizeof(int));
    for (nj = 1; nj <= n - 2; nj += 2) {
      if ((x->data[nj - 1] <= x->data[nj]) || rtIsNaN(x->data[nj])) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
        idx->data[nj - 1] = nj;
        idx->data[nj] = nj + 1;
      } else {
        idx->data[nj - 1] = nj + 1;
        idx->data[nj] = nj;
      }
    }

    if ((x->size[1] & 1) != 0) {
      idx->data[x->size[1] - 1] = x->size[1];
    }

    i = 2;
    while (i < n - 1) {
      i2 = i << 1;
      j = 1;
      for (pEnd = 1 + i; pEnd < n; pEnd = qEnd + i) {
        b_p = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }

        nj = 0;
        kEnd = qEnd - j;
        while (nj + 1 <= kEnd) {
          if ((x->data[idx->data[b_p - 1] - 1] <= x->data[idx->data[q] - 1]) ||
              rtIsNaN(x->data[idx->data[q] - 1])) {
            p = true;
          } else {
            p = false;
          }

          if (p) {
            iwork->data[nj] = idx->data[b_p - 1];
            b_p++;
            if (b_p == pEnd) {
              while (q + 1 < qEnd) {
                nj++;
                iwork->data[nj] = idx->data[q];
                q++;
              }
            }
          } else {
            iwork->data[nj] = idx->data[q];
            q++;
            if (q + 1 == qEnd) {
              while (b_p < pEnd) {
                nj++;
                iwork->data[nj] = idx->data[b_p - 1];
                b_p++;
              }
            }
          }

          nj++;
        }

        for (nj = 0; nj + 1 <= kEnd; nj++) {
          idx->data[(j + nj) - 1] = iwork->data[nj];
        }

        j = qEnd;
      }

      i = i2;
    }

    emxFree_int32_T(&iwork);
    nj = x->size[1];
    while ((nj > 0) && rtIsNaN(x->data[idx->data[nj - 1] - 1])) {
      nj--;
    }

    if (nj < 1) {
      M = rtNaN;
    } else if (nj == 1) {
      M = x->data[idx->data[0] - 1];
    } else {
      r = 0.5 * (double)nj;
      i = (int)rt_roundd_snf(r);
      if (nj <= i) {
        M = x->data[idx->data[nj - 1] - 1];
      } else {
        r -= (double)i;
        M = (0.5 - r) * x->data[idx->data[i - 1] - 1] + (0.5 + r) * x->data
          [idx->data[i] - 1];
      }
    }

    emxFree_int32_T(&idx);
  }

  return M;
}

/*
 * File trailer for NANMEDIAN.c
 *
 * [EOF]
 */
