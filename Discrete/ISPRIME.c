/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ISPRIME.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 06-Jul-2018 03:08:24
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "GCD.h"
#include "ISPRIME.h"
#include "LCM.h"
#include "NCHOOSEK.h"
#include "GCD_emxutil.h"
#include "eml_primes_core.h"
#include "GCD_rtwutil.h"

/* Function Declarations */
static void eml_primes(int N, emxArray_int32_T *p);
static double rt_remd_snf(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : int N
 *                emxArray_int32_T *p
 * Return Type  : void
 */
static void eml_primes(int N, emxArray_int32_T *p)
{
  int j;
  unsigned int q;
  emxArray_boolean_T *isp;
  int kmax;
  int k;
  int nleft;
  if (N < 2) {
    j = p->size[0] * p->size[1];
    p->size[0] = 1;
    p->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)p, j, (int)sizeof(int));
  } else if (N < 3) {
    j = p->size[0] * p->size[1];
    p->size[0] = 1;
    p->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)p, j, (int)sizeof(int));
    p->data[0] = 2;
  } else {
    q = (unsigned int)N >> 1;
    if (N - (q << 1) > 0U) {
      q++;
    }

    emxInit_boolean_T(&isp, 2);
    j = isp->size[0] * isp->size[1];
    isp->size[0] = 1;
    isp->size[1] = (int)q;
    emxEnsureCapacity((emxArray__common *)isp, j, (int)sizeof(boolean_T));
    kmax = (int)q;
    for (j = 0; j < kmax; j++) {
      isp->data[j] = true;
    }

    kmax = intsqrt(N);
    k = 3;
    nleft = (int)q;
    while (k <= kmax) {
      if (isp->data[(k + 1) / 2 - 1]) {
        for (j = (k * k + 1) / 2; j <= (int)q; j += k) {
          if (isp->data[j - 1]) {
            isp->data[j - 1] = false;
            nleft--;
          }
        }
      }

      k += 2;
    }

    j = p->size[0] * p->size[1];
    p->size[0] = 1;
    p->size[1] = nleft;
    emxEnsureCapacity((emxArray__common *)p, j, (int)sizeof(int));
    kmax = 1;
    p->data[0] = 2;
    for (k = 2; k <= (int)q; k++) {
      if (isp->data[k - 1] && (kmax < 6605207)) {
        kmax++;
        p->data[kmax - 1] = (k << 1) - 1;
      }
    }

    emxFree_boolean_T(&isp);
  }
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_remd_snf(double u0, double u1)
{
  double y;
  double b_u1;
  double tr;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = rtNaN;
  } else {
    if (u1 < 0.0) {
      b_u1 = ceil(u1);
    } else {
      b_u1 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != b_u1)) {
      tr = u0 / u1;
      if (fabs(tr - rt_roundd_snf(tr)) <= DBL_EPSILON * fabs(tr)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/*
 * Arguments    : double x
 * Return Type  : boolean_T
 */
boolean_T ISPRIME(double x)
{
  boolean_T y;
  double n;
  double rtmp;
  emxArray_int32_T *p;
  double b_rtmp;
  int j;
  boolean_T exitg1;
  n = 0.0;
  if (x > 0.0) {
    n = x;
  }

  rtmp = floor(sqrt(n));
  emxInit_int32_T(&p, 2);
  if (rtmp * rtmp > n) {
    b_rtmp = rtmp - 1.0;
  } else {
    b_rtmp = rtmp;
  }

  n = rt_roundd_snf(b_rtmp);
  if (n < 2.147483648E+9) {
    j = (int)n;
  } else {
    j = MAX_int32_T;
  }

  eml_primes(j, p);
  if (x < 2.0) {
    y = false;
  } else {
    y = true;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && ((j <= p->size[1] - 1) && (!(x <= p->data[j])))) {
      if (rt_remd_snf(x, p->data[j]) == 0.0) {
        y = false;
        exitg1 = true;
      } else {
        j++;
      }
    }
  }

  emxFree_int32_T(&p);
  return y;
}

/*
 * File trailer for ISPRIME.c
 *
 * [EOF]
 */
