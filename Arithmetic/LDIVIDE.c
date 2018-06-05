/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: LDIVIDE.c
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
#include "rdivide1.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *B
 *                const emxArray_real_T *A
 *                emxArray_real_T *X
 * Return Type  : void
 */
void LDIVIDE(const emxArray_real_T *B, const emxArray_real_T *A, emxArray_real_T
             *X)
{
  rdivide(A, B, X);
}

/*
 * File trailer for LDIVIDE.c
 *
 * [EOF]
 */
