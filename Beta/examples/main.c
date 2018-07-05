/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 01-Jul-2018 00:59:48
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
#include "BETACDF.h"
#include "BETACDF_UPPER.h"
#include "BETAINV.h"
#include "BETAPDF.h"
#include "BETARND.h"
#include "main.h"
#include "BETACDF_terminate.h"
#include "BETACDF_initialize.h"

/* Function Declarations */
static double argInit_real_T(void);
static void main_BETACDF(void);
static void main_BETACDF_UPPER(void);
static void main_BETAINV(void);
static void main_BETAPDF(void);
static void main_BETARND(void);

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
static void main_BETACDF(void)
{
  double p;

  /* Initialize function 'BETACDF' input arguments. */
  /* Call the entry-point 'BETACDF'. */
  p = BETACDF(argInit_real_T(), argInit_real_T(), argInit_real_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_BETACDF_UPPER(void)
{
  double p;

  /* Initialize function 'BETACDF_UPPER' input arguments. */
  /* Call the entry-point 'BETACDF_UPPER'. */
  p = BETACDF_UPPER(argInit_real_T(), argInit_real_T(), argInit_real_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_BETAINV(void)
{
  double x;

  /* Initialize function 'BETAINV' input arguments. */
  /* Call the entry-point 'BETAINV'. */
  x = BETAINV(argInit_real_T(), argInit_real_T(), argInit_real_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_BETAPDF(void)
{
  double y;

  /* Initialize function 'BETAPDF' input arguments. */
  /* Call the entry-point 'BETAPDF'. */
  y = BETAPDF(argInit_real_T(), argInit_real_T(), argInit_real_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_BETARND(void)
{
  double r;

  /* Initialize function 'BETARND' input arguments. */
  /* Call the entry-point 'BETARND'. */
  r = BETARND(argInit_real_T(), argInit_real_T());
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
  BETACDF_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_BETACDF();
  main_BETACDF_UPPER();
  main_BETAINV();
  main_BETAPDF();
  main_BETARND();

  /* Terminate the application.
     You do not need to do this more than one time. */
  BETACDF_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
