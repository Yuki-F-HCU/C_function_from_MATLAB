/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: MEDIAN.c
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
#include "sort3.h"
#include "quickselect.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double MEDIAN(const emxArray_real_T *x)
{
  double M;
  int n;
  int k;
  emxArray_real_T *v;
  int exitg1;
  int midm1;
  int loop_ub;
  int unusedU3;
  boolean_T p;
  double a;
  if (x->size[1] == 0) {
    M = rtNaN;
  } else {
    n = x->size[1];
    k = 0;
    emxInit_real_T(&v, 2);
    do {
      exitg1 = 0;
      if (k + 1 <= n) {
        if (rtIsNaN(x->data[k])) {
          M = x->data[k];
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        if (n <= 4) {
          if (n == 1) {
            M = x->data[0];
          } else if (n == 2) {
            if (((x->data[0] < 0.0) && (x->data[1] >= 0.0)) || rtIsInf(x->data[0])
                || rtIsInf(x->data[1])) {
              M = (x->data[0] + x->data[1]) / 2.0;
            } else {
              M = x->data[0] + (x->data[1] - x->data[0]) / 2.0;
            }
          } else if (n == 3) {
            p = (x->data[0] < x->data[1]);
            if (p) {
              p = (x->data[1] < x->data[2]);
              if (p) {
                loop_ub = 1;
              } else {
                p = (x->data[0] < x->data[2]);
                if (p) {
                  loop_ub = 2;
                } else {
                  loop_ub = 0;
                }
              }
            } else {
              p = (x->data[0] < x->data[2]);
              if (p) {
                loop_ub = 0;
              } else {
                p = (x->data[1] < x->data[2]);
                if (p) {
                  loop_ub = 2;
                } else {
                  loop_ub = 1;
                }
              }
            }

            M = x->data[loop_ub];
          } else {
            sort3(1, x->data[0], 2, x->data[1], 3, x->data[2], &k, &loop_ub,
                  &unusedU3);
            p = (x->data[k - 1] < x->data[3]);
            if (p) {
              p = (x->data[3] < x->data[unusedU3 - 1]);
              if (p) {
                if (((x->data[loop_ub - 1] < 0.0) && (x->data[3] >= 0.0)) ||
                    rtIsInf(x->data[loop_ub - 1]) || rtIsInf(x->data[3])) {
                  M = (x->data[loop_ub - 1] + x->data[3]) / 2.0;
                } else {
                  M = x->data[loop_ub - 1] + (x->data[3] - x->data[loop_ub - 1])
                    / 2.0;
                }
              } else if (((x->data[loop_ub - 1] < 0.0) && (x->data[unusedU3 - 1]
                >= 0.0)) || rtIsInf(x->data[loop_ub - 1]) || rtIsInf(x->
                          data[unusedU3 - 1])) {
                M = (x->data[loop_ub - 1] + x->data[unusedU3 - 1]) / 2.0;
              } else {
                M = x->data[loop_ub - 1] + (x->data[unusedU3 - 1] - x->
                  data[loop_ub - 1]) / 2.0;
              }
            } else if (((x->data[k - 1] < 0.0) && (x->data[loop_ub - 1] >= 0.0))
                       || rtIsInf(x->data[k - 1]) || rtIsInf(x->data[loop_ub - 1]))
            {
              M = (x->data[k - 1] + x->data[loop_ub - 1]) / 2.0;
            } else {
              M = x->data[k - 1] + (x->data[loop_ub - 1] - x->data[k - 1]) / 2.0;
            }
          }
        } else {
          midm1 = n >> 1;
          if ((n & 1) == 0) {
            k = v->size[0] * v->size[1];
            v->size[0] = 1;
            v->size[1] = x->size[1];
            emxEnsureCapacity((emxArray__common *)v, k, (int)sizeof(double));
            loop_ub = x->size[0] * x->size[1];
            for (k = 0; k < loop_ub; k++) {
              v->data[k] = x->data[k];
            }

            quickselect(v, midm1 + 1, n, &M, &k, &unusedU3);
            if (midm1 < k) {
              quickselect(v, midm1, unusedU3 - 1, &a, &k, &loop_ub);
              if (((a < 0.0) && (M >= 0.0)) || rtIsInf(a) || rtIsInf(M)) {
                M = (a + M) / 2.0;
              } else {
                M = a + (M - a) / 2.0;
              }
            }
          } else {
            k = v->size[0] * v->size[1];
            v->size[0] = 1;
            v->size[1] = x->size[1];
            emxEnsureCapacity((emxArray__common *)v, k, (int)sizeof(double));
            loop_ub = x->size[0] * x->size[1];
            for (k = 0; k < loop_ub; k++) {
              v->data[k] = x->data[k];
            }

            quickselect(v, midm1 + 1, n, &M, &k, &unusedU3);
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);

    emxFree_real_T(&v);
  }

  return M;
}

/*
 * File trailer for MEDIAN.c
 *
 * [EOF]
 */
