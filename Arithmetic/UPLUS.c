/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: UPLUS.c
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
 *                emxArray_real_T *C
 * Return Type  : void
 */
void UPLUS(const emxArray_real_T *A, emxArray_real_T *C)
{
  int i9;
  int loop_ub;
  i9 = C->size[0] * C->size[1];
  C->size[0] = A->size[0];
  C->size[1] = A->size[1];
  emxEnsureCapacity((emxArray__common *)C, i9, (int)sizeof(double));
  loop_ub = A->size[0] * A->size[1];
  for (i9 = 0; i9 < loop_ub; i9++) {
    C->data[i9] = A->data[i9];
  }
}

/*
 * File trailer for UPLUS.c
 *
 * [EOF]
 */
