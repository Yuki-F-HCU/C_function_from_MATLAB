/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CTRANSPOSE.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 20-May-2018 00:37:42
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "CTRANSPOSE.h"
#include "LDIVIDE.h"
#include "MINUS.h"
#include "PLUS.h"
#include "RDIVIDE.h"
#include "TIMES.h"
#include "TRANSPOSE.h"
#include "UMINUS.h"
#include "UPLUS.h"
#include "CTRANSPOSE_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void CTRANSPOSE(const emxArray_real_T *x, emxArray_real_T *y)
{
  int i0;
  int loop_ub;
  int b_loop_ub;
  int i1;
  i0 = y->size[0] * y->size[1];
  y->size[0] = x->size[1];
  y->size[1] = x->size[0];
  emxEnsureCapacity((emxArray__common *)y, i0, (int)sizeof(double));
  loop_ub = x->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_loop_ub = x->size[1];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      y->data[i1 + y->size[0] * i0] = x->data[i0 + x->size[0] * i1];
    }
  }
}

/*
 * File trailer for CTRANSPOSE.c
 *
 * [EOF]
 */
