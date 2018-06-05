/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: PLUS.c
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
 *                const emxArray_real_T *B
 *                emxArray_real_T *C
 * Return Type  : void
 */
void PLUS(const emxArray_real_T *A, const emxArray_real_T *B, emxArray_real_T *C)
{
  int i4;
  int loop_ub;
  i4 = C->size[0] * C->size[1];
  C->size[0] = A->size[0];
  C->size[1] = A->size[1];
  emxEnsureCapacity((emxArray__common *)C, i4, (int)sizeof(double));
  loop_ub = A->size[0] * A->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    C->data[i4] = A->data[i4] + B->data[i4];
  }
}

/*
 * File trailer for PLUS.c
 *
 * [EOF]
 */
