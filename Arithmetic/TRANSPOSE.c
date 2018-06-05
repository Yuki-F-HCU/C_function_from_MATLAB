/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: TRANSPOSE.c
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
 * Arguments    : const emxArray_real_T *A
 *                emxArray_real_T *B
 * Return Type  : void
 */
void TRANSPOSE(const emxArray_real_T *A, emxArray_real_T *B)
{
  int i6;
  int loop_ub;
  int b_loop_ub;
  int i7;
  i6 = B->size[0] * B->size[1];
  B->size[0] = A->size[1];
  B->size[1] = A->size[0];
  emxEnsureCapacity((emxArray__common *)B, i6, (int)sizeof(double));
  loop_ub = A->size[0];
  for (i6 = 0; i6 < loop_ub; i6++) {
    b_loop_ub = A->size[1];
    for (i7 = 0; i7 < b_loop_ub; i7++) {
      B->data[i7 + B->size[0] * i6] = A->data[i6 + A->size[0] * i7];
    }
  }
}

/*
 * File trailer for TRANSPOSE.c
 *
 * [EOF]
 */
