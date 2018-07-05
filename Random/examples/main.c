/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 01-Jul-2018 01:45:46
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
#include "RAND.h"
#include "RANDG.h"
#include "RANDI.h"
#include "RANDN.h"
#include "main.h"
#include "RAND_terminate.h"
#include "RAND_initialize.h"

/* Function Declarations */
static double argInit_real_T(void);
static void main_RAND(void);
static void main_RANDG(void);
static void main_RANDI(void);
static void main_RANDN(void);

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
 * Return Type  : void
 */
static void main_RAND(void)
{
  double x;

  /* Call the entry-point 'RAND'. */
  x = RAND();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_RANDG(void)
{
  double x;

  /* Initialize function 'RANDG' input arguments. */
  /* Call the entry-point 'RANDG'. */
  x = RANDG(argInit_real_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_RANDI(void)
{
  double x;

  /* Initialize function 'RANDI' input arguments. */
  /* Call the entry-point 'RANDI'. */
  x = RANDI(argInit_real_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_RANDN(void)
{
  double x;

  /* Call the entry-point 'RANDN'. */
  x = RANDN();
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
  RAND_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_RAND();
  main_RANDG();
  main_RANDI();
  main_RANDN();

  /* Terminate the application.
     You do not need to do this more than one time. */
  RAND_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
