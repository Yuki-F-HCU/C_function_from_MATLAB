/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: quickselect.c
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
#include "quickselect.h"
#include "HARMMEAN_emxutil.h"
#include "sort3.h"

/* Function Declarations */
static int thirdOfFive(const emxArray_real_T *v, int ia, int ib);

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *v
 *                int ia
 *                int ib
 * Return Type  : int
 */
static int thirdOfFive(const emxArray_real_T *v, int ia, int ib)
{
  int im;
  int b_j1;
  int j3;
  int j4;
  int j5;
  double v4;
  double v5;
  boolean_T p;
  if ((ia == ib) || (ia + 1 == ib)) {
    im = ia;
  } else if ((ia + 2 == ib) || (ia + 3 == ib)) {
    sort3(ia, v->data[ia - 1], ia + 1, v->data[ia], ia + 2, v->data[ia + 1],
          &b_j1, &im, &j3);
  } else {
    sort3(ia, v->data[ia - 1], ia + 1, v->data[ia], ia + 2, v->data[ia + 1],
          &b_j1, &im, &j3);
    j4 = ia;
    j5 = ia + 1;
    v4 = v->data[ia + 2];
    v5 = v->data[ia + 3];
    p = (v->data[ia + 3] < v->data[ia + 2]);
    if (p) {
      j4 = ia + 1;
      j5 = ia;
      v5 = v->data[ia + 2];
      v4 = v->data[ia + 3];
    }

    p = (v5 < v->data[b_j1 - 1]);
    if (p) {
      im = b_j1;
    } else {
      p = (v5 < v->data[im - 1]);
      if (p) {
        im = j5 + 3;
      } else {
        p = (v4 < v->data[im - 1]);
        if (!p) {
          p = (v4 < v->data[j3 - 1]);
          if (p) {
            im = j4 + 3;
          } else {
            im = j3;
          }
        }
      }
    }
  }

  return im;
}

/*
 * Arguments    : emxArray_real_T *v
 *                int n
 *                int vlen
 *                double *vn
 *                int *nfirst
 *                int *nlast
 * Return Type  : void
 */
void quickselect(emxArray_real_T *v, int n, int vlen, double *vn, int *nfirst,
                 int *nlast)
{
  int ipiv;
  int ia;
  int ib;
  int oldnv;
  boolean_T checkspeed;
  boolean_T isslow;
  emxArray_real_T *b_v;
  boolean_T exitg1;
  int ic;
  int loop_ub;
  double vref;
  int ilast;
  int ngroupsof5;
  int k;
  double vk;
  boolean_T p;
  boolean_T guard1 = false;
  if (n > vlen) {
    *vn = rtNaN;
    *nfirst = 0;
    *nlast = 0;
  } else {
    ipiv = n - 1;
    ia = 1;
    ib = vlen - 1;
    *nfirst = 1;
    *nlast = vlen;
    oldnv = vlen;
    checkspeed = false;
    isslow = false;
    emxInit_real_T(&b_v, 2);
    exitg1 = false;
    while ((!exitg1) && (ia < ib + 1)) {
      ic = b_v->size[0] * b_v->size[1];
      b_v->size[0] = 1;
      b_v->size[1] = v->size[1];
      emxEnsureCapacity((emxArray__common *)b_v, ic, (int)sizeof(double));
      loop_ub = v->size[0] * v->size[1];
      for (ic = 0; ic < loop_ub; ic++) {
        b_v->data[ic] = v->data[ic];
      }

      vref = v->data[ipiv];
      b_v->data[ipiv] = v->data[ib];
      b_v->data[ib] = v->data[ipiv];
      ilast = ia - 1;
      ngroupsof5 = -1;
      for (k = ia - 1; k + 1 <= ib; k++) {
        vk = b_v->data[k];
        if (b_v->data[k] == vref) {
          b_v->data[k] = b_v->data[ilast];
          b_v->data[ilast] = vk;
          ngroupsof5++;
          ilast++;
        } else {
          p = (b_v->data[k] < vref);
          if (p) {
            b_v->data[k] = b_v->data[ilast];
            b_v->data[ilast] = vk;
            ilast++;
          }
        }
      }

      b_v->data[ib] = b_v->data[ilast];
      b_v->data[ilast] = v->data[ipiv];
      ic = v->size[0] * v->size[1];
      v->size[0] = 1;
      v->size[1] = b_v->size[1];
      emxEnsureCapacity((emxArray__common *)v, ic, (int)sizeof(double));
      loop_ub = b_v->size[1];
      for (ic = 0; ic < loop_ub; ic++) {
        v->data[v->size[0] * ic] = b_v->data[b_v->size[0] * ic];
      }

      *nlast = ilast + 1;
      guard1 = false;
      if (n <= ilast + 1) {
        *nfirst = ilast - ngroupsof5;
        if (n >= *nfirst) {
          exitg1 = true;
        } else {
          ib = ilast - 1;
          guard1 = true;
        }
      } else {
        ia = ilast + 2;
        guard1 = true;
      }

      if (guard1) {
        loop_ub = (ib - ia) + 2;
        if (checkspeed) {
          isslow = (loop_ub > oldnv / 2);
          oldnv = loop_ub;
        }

        checkspeed = !checkspeed;
        if (isslow) {
          while (loop_ub > 1) {
            ngroupsof5 = loop_ub / 5;
            *nlast = loop_ub - ngroupsof5 * 5;
            loop_ub = ngroupsof5;
            for (k = 0; k + 1 <= ngroupsof5; k++) {
              ic = ia + k * 5;
              ic = thirdOfFive(v, ic, ic + 4) - 1;
              ipiv = (ia + k) - 1;
              vref = v->data[ipiv];
              v->data[ipiv] = v->data[ic];
              v->data[ic] = vref;
            }

            if (*nlast > 0) {
              ic = ia + ngroupsof5 * 5;
              ic = thirdOfFive(v, ic, (ic + *nlast) - 1) - 1;
              ipiv = (ia + ngroupsof5) - 1;
              vref = v->data[ipiv];
              v->data[ipiv] = v->data[ic];
              v->data[ic] = vref;
              loop_ub = ngroupsof5 + 1;
            }
          }
        } else {
          if (loop_ub >= 3) {
            ic = ia + (loop_ub - 1) / 2;
            sort3(ia, b_v->data[ia - 1], ic, b_v->data[ic - 1], ib + 1,
                  b_v->data[ib], &loop_ub, &ipiv, &ngroupsof5);
            if (ipiv > ia) {
              v->data[ia - 1] = b_v->data[ipiv - 1];
              v->data[ipiv - 1] = b_v->data[ia - 1];
            }
          }
        }

        ipiv = ia - 1;
        *nfirst = ia;
        *nlast = ib + 1;
      }
    }

    emxFree_real_T(&b_v);
    *vn = v->data[*nlast - 1];
  }
}

/*
 * File trailer for quickselect.c
 *
 * [EOF]
 */
