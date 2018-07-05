/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 20-May-2018 00:37:42
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
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
#include "main.h"
#include "CTRANSPOSE_terminate.h"
#include "CTRANSPOSE_emxAPI.h"
#include "CTRANSPOSE_initialize.h"

/* Function Declarations */
static double argInit_real_T(void);
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void);
static void main_CTRANSPOSE(void);
static void main_LDIVIDE(void);
static void main_MINUS(void);
static void main_PLUS(void);
static void main_RDIVIDE(void);
static void main_TIMES(void);
static void main_TRANSPOSE(void);
static void main_UMINUS(void);
static void main_UPLUS(void);

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void)
{
  emxArray_real_T *result;
  static int iv0[2] = { 2, 2 };

  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv0);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_CTRANSPOSE(void)
{
  emxArray_real_T *y;
  emxArray_real_T *x;
  emxInitArray_real_T(&y, 2);

  /* Initialize function 'CTRANSPOSE' input arguments. */
  /* Initialize function input argument 'x'. */
  x = c_argInit_UnboundedxUnbounded_r();

  /* Call the entry-point 'CTRANSPOSE'. */
  CTRANSPOSE(x, y);
  emxDestroyArray_real_T(y);
  emxDestroyArray_real_T(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_LDIVIDE(void)
{
  emxArray_real_T *X;
  emxArray_real_T *B;
  emxArray_real_T *A;
  emxInitArray_real_T(&X, 2);

  /* Initialize function 'LDIVIDE' input arguments. */
  /* Initialize function input argument 'B'. */
  B = c_argInit_UnboundedxUnbounded_r();

  /* Initialize function input argument 'A'. */
  A = c_argInit_UnboundedxUnbounded_r();

  /* Call the entry-point 'LDIVIDE'. */
  LDIVIDE(B, A, X);
  emxDestroyArray_real_T(X);
  emxDestroyArray_real_T(A);
  emxDestroyArray_real_T(B);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_MINUS(void)
{
  emxArray_real_T *C;
  emxArray_real_T *A;
  emxArray_real_T *B;
  emxInitArray_real_T(&C, 2);

  /* Initialize function 'MINUS' input arguments. */
  /* Initialize function input argument 'A'. */
  A = c_argInit_UnboundedxUnbounded_r();

  /* Initialize function input argument 'B'. */
  B = c_argInit_UnboundedxUnbounded_r();

  /* Call the entry-point 'MINUS'. */
  MINUS(A, B, C);
  emxDestroyArray_real_T(C);
  emxDestroyArray_real_T(B);
  emxDestroyArray_real_T(A);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_PLUS(void)
{
  emxArray_real_T *C;
  emxArray_real_T *A;
  emxArray_real_T *B;
  emxInitArray_real_T(&C, 2);

  /* Initialize function 'PLUS' input arguments. */
  /* Initialize function input argument 'A'. */
  A = c_argInit_UnboundedxUnbounded_r();

  /* Initialize function input argument 'B'. */
  B = c_argInit_UnboundedxUnbounded_r();

  /* Call the entry-point 'PLUS'. */
  PLUS(A, B, C);
  emxDestroyArray_real_T(C);
  emxDestroyArray_real_T(B);
  emxDestroyArray_real_T(A);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_RDIVIDE(void)
{
  emxArray_real_T *X;
  emxArray_real_T *A;
  emxArray_real_T *B;
  emxInitArray_real_T(&X, 2);

  /* Initialize function 'RDIVIDE' input arguments. */
  /* Initialize function input argument 'A'. */
  A = c_argInit_UnboundedxUnbounded_r();

  /* Initialize function input argument 'B'. */
  B = c_argInit_UnboundedxUnbounded_r();

  /* Call the entry-point 'RDIVIDE'. */
  RDIVIDE(A, B, X);
  emxDestroyArray_real_T(X);
  emxDestroyArray_real_T(B);
  emxDestroyArray_real_T(A);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_TIMES(void)
{
  emxArray_real_T *C;
  emxArray_real_T *A;
  emxArray_real_T *B;
  emxInitArray_real_T(&C, 2);

  /* Initialize function 'TIMES' input arguments. */
  /* Initialize function input argument 'A'. */
  A = c_argInit_UnboundedxUnbounded_r();

  /* Initialize function input argument 'B'. */
  B = c_argInit_UnboundedxUnbounded_r();

  /* Call the entry-point 'TIMES'. */
  TIMES(A, B, C);
  emxDestroyArray_real_T(C);
  emxDestroyArray_real_T(B);
  emxDestroyArray_real_T(A);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_TRANSPOSE(void)
{
  emxArray_real_T *B;
  emxArray_real_T *A;
  emxInitArray_real_T(&B, 2);

  /* Initialize function 'TRANSPOSE' input arguments. */
  /* Initialize function input argument 'A'. */
  A = c_argInit_UnboundedxUnbounded_r();

  /* Call the entry-point 'TRANSPOSE'. */
  TRANSPOSE(A, B);
  emxDestroyArray_real_T(B);
  emxDestroyArray_real_T(A);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_UMINUS(void)
{
  emxArray_real_T *C;
  emxArray_real_T *A;
  emxInitArray_real_T(&C, 2);

  /* Initialize function 'UMINUS' input arguments. */
  /* Initialize function input argument 'A'. */
  A = c_argInit_UnboundedxUnbounded_r();

  /* Call the entry-point 'UMINUS'. */
  UMINUS(A, C);
  emxDestroyArray_real_T(C);
  emxDestroyArray_real_T(A);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_UPLUS(void)
{
  emxArray_real_T *C;
  emxArray_real_T *A;
  emxInitArray_real_T(&C, 2);

  /* Initialize function 'UPLUS' input arguments. */
  /* Initialize function input argument 'A'. */
  A = c_argInit_UnboundedxUnbounded_r();

  /* Call the entry-point 'UPLUS'. */
  UPLUS(A, C);
  emxDestroyArray_real_T(C);
  emxDestroyArray_real_T(A);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  CTRANSPOSE_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_CTRANSPOSE();
  main_LDIVIDE();
  main_MINUS();
  main_PLUS();
  main_RDIVIDE();
  main_TIMES();
  main_TRANSPOSE();
  main_UMINUS();
  main_UPLUS();

  /* Terminate the application.
     You do not need to do this more than one time. */
  CTRANSPOSE_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
