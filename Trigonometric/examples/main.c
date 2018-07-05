/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 06-Jul-2018 01:48:54
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
#include "ACOS.h"
#include "ACOSD.h"
#include "ACOSH.h"
#include "ACOT.h"
#include "ACOTD.h"
#include "ACOTH.h"
#include "ACSC.h"
#include "ACSCD.h"
#include "ACSCH.h"
#include "ASEC.h"
#include "ASECD.h"
#include "ASECH.h"
#include "ASIN.h"
#include "ASIND.h"
#include "ASINH.h"
#include "ATAN.h"
#include "ATAN2.h"
#include "ATAN2D.h"
#include "ATAND.h"
#include "ATANH.h"
#include "COS.h"
#include "COSD.h"
#include "COSH.h"
#include "COT.h"
#include "COTD.h"
#include "COTH.h"
#include "CSC.h"
#include "CSCD.h"
#include "CSCH.h"
#include "DEG2RAD.h"
#include "HYPOT.h"
#include "RAD2DEG.h"
#include "SEC.h"
#include "SECH.h"
#include "SIN.h"
#include "SIND.h"
#include "SINH.h"
#include "TAN.h"
#include "TAND.h"
#include "TANH.h"
#include "main.h"
#include "ACOS_terminate.h"
#include "ACOS_initialize.h"

/* Function Declarations */
static creal_T argInit_creal_T(void);
static double argInit_real_T(void);
static void main_ACOS(void);
static void main_ACOSD(void);
static void main_ACOSH(void);
static void main_ACOT(void);
static void main_ACOTD(void);
static void main_ACOTH(void);
static void main_ACSC(void);
static void main_ACSCD(void);
static void main_ACSCH(void);
static void main_ASEC(void);
static void main_ASECD(void);
static void main_ASECH(void);
static void main_ASIN(void);
static void main_ASIND(void);
static void main_ASINH(void);
static void main_ATAN(void);
static void main_ATAN2(void);
static void main_ATAN2D(void);
static void main_ATAND(void);
static void main_ATANH(void);
static void main_COS(void);
static void main_COSD(void);
static void main_COSH(void);
static void main_COT(void);
static void main_COTD(void);
static void main_COTH(void);
static void main_CSC(void);
static void main_CSCD(void);
static void main_CSCH(void);
static void main_DEG2RAD(void);
static void main_HYPOT(void);
static void main_RAD2DEG(void);
static void main_SEC(void);
static void main_SECH(void);
static void main_SIN(void);
static void main_SIND(void);
static void main_SINH(void);
static void main_TAN(void);
static void main_TAND(void);
static void main_TANH(void);

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : creal_T
 */
static creal_T argInit_creal_T(void)
{
  creal_T result;

  /* Set the value of the complex variable.
     Change this value to the value that the application requires. */
  result.re = argInit_real_T();
  result.im = argInit_real_T();
  return result;
}

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
static void main_ACOS(void)
{
  creal_T x;

  /* Initialize function 'ACOS' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ACOS'. */
  x = ACOS(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ACOSD(void)
{
  creal_T x;

  /* Initialize function 'ACOSD' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ACOSD'. */
  x = ACOSD(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ACOSH(void)
{
  creal_T x;

  /* Initialize function 'ACOSH' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ACOSH'. */
  x = ACOSH(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ACOT(void)
{
  creal_T x;

  /* Initialize function 'ACOT' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ACOT'. */
  x = ACOT(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ACOTD(void)
{
  creal_T x;

  /* Initialize function 'ACOTD' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ACOTD'. */
  x = ACOTD(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ACOTH(void)
{
  creal_T x;

  /* Initialize function 'ACOTH' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ACOTH'. */
  x = ACOTH(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ACSC(void)
{
  creal_T x;

  /* Initialize function 'ACSC' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ACSC'. */
  x = ACSC(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ACSCD(void)
{
  creal_T x;

  /* Initialize function 'ACSCD' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ACSCD'. */
  x = ACSCD(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ACSCH(void)
{
  creal_T x;

  /* Initialize function 'ACSCH' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ACSCH'. */
  x = ACSCH(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ASEC(void)
{
  creal_T x;

  /* Initialize function 'ASEC' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ASEC'. */
  x = ASEC(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ASECD(void)
{
  creal_T x;

  /* Initialize function 'ASECD' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ASECD'. */
  x = ASECD(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ASECH(void)
{
  creal_T x;

  /* Initialize function 'ASECH' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ASECH'. */
  x = ASECH(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ASIN(void)
{
  creal_T x;

  /* Initialize function 'ASIN' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ASIN'. */
  x = ASIN(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ASIND(void)
{
  creal_T x;

  /* Initialize function 'ASIND' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ASIND'. */
  x = ASIND(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ASINH(void)
{
  creal_T x;

  /* Initialize function 'ASINH' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ASINH'. */
  x = ASINH(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ATAN(void)
{
  creal_T x;

  /* Initialize function 'ATAN' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ATAN'. */
  x = ATAN(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ATAN2(void)
{
  double z;

  /* Initialize function 'ATAN2' input arguments. */
  /* Call the entry-point 'ATAN2'. */
  z = ATAN2(argInit_real_T(), argInit_real_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ATAN2D(void)
{
  double z;

  /* Initialize function 'ATAN2D' input arguments. */
  /* Call the entry-point 'ATAN2D'. */
  z = ATAN2D(argInit_real_T(), argInit_real_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ATAND(void)
{
  creal_T x;

  /* Initialize function 'ATAND' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ATAND'. */
  x = ATAND(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_ATANH(void)
{
  creal_T x;

  /* Initialize function 'ATANH' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'ATANH'. */
  x = ATANH(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_COS(void)
{
  creal_T x;

  /* Initialize function 'COS' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'COS'. */
  x = COS(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_COSD(void)
{
  creal_T x;

  /* Initialize function 'COSD' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'COSD'. */
  x = COSD(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_COSH(void)
{
  creal_T x;

  /* Initialize function 'COSH' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'COSH'. */
  x = COSH(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_COT(void)
{
  creal_T x;

  /* Initialize function 'COT' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'COT'. */
  x = COT(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_COTD(void)
{
  creal_T x;

  /* Initialize function 'COTD' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'COTD'. */
  x = COTD(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_COTH(void)
{
  creal_T x;

  /* Initialize function 'COTH' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'COTH'. */
  x = COTH(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_CSC(void)
{
  creal_T x;

  /* Initialize function 'CSC' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'CSC'. */
  x = CSC(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_CSCD(void)
{
  creal_T x;

  /* Initialize function 'CSCD' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'CSCD'. */
  x = CSCD(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_CSCH(void)
{
  creal_T x;

  /* Initialize function 'CSCH' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'CSCH'. */
  x = CSCH(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_DEG2RAD(void)
{
  creal_T d;

  /* Initialize function 'DEG2RAD' input arguments. */
  /* Initialize function input argument 'd'. */
  d = argInit_creal_T();

  /* Call the entry-point 'DEG2RAD'. */
  d = DEG2RAD(d);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_HYPOT(void)
{
  double c;

  /* Initialize function 'HYPOT' input arguments. */
  /* Initialize function input argument 'a'. */
  /* Initialize function input argument 'b'. */
  /* Call the entry-point 'HYPOT'. */
  c = HYPOT(argInit_creal_T(), argInit_creal_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_RAD2DEG(void)
{
  creal_T r;

  /* Initialize function 'RAD2DEG' input arguments. */
  /* Initialize function input argument 'r'. */
  r = argInit_creal_T();

  /* Call the entry-point 'RAD2DEG'. */
  r = RAD2DEG(r);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_SEC(void)
{
  creal_T x;

  /* Initialize function 'SEC' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'SEC'. */
  x = SEC(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_SECH(void)
{
  creal_T x;

  /* Initialize function 'SECH' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'SECH'. */
  x = SECH(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_SIN(void)
{
  creal_T x;

  /* Initialize function 'SIN' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'SIN'. */
  x = SIN(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_SIND(void)
{
  creal_T x;

  /* Initialize function 'SIND' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'SIND'. */
  x = SIND(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_SINH(void)
{
  creal_T x;

  /* Initialize function 'SINH' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'SINH'. */
  x = SINH(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_TAN(void)
{
  creal_T x;

  /* Initialize function 'TAN' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'TAN'. */
  x = TAN(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_TAND(void)
{
  creal_T x;

  /* Initialize function 'TAND' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'TAND'. */
  x = TAND(x);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_TANH(void)
{
  creal_T x;

  /* Initialize function 'TANH' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_creal_T();

  /* Call the entry-point 'TANH'. */
  x = TANH(x);
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
  ACOS_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_ACOS();
  main_ACOSD();
  main_ACOSH();
  main_ACOT();
  main_ACOTD();
  main_ACOTH();
  main_ACSC();
  main_ACSCD();
  main_ACSCH();
  main_ASEC();
  main_ASECD();
  main_ASECH();
  main_ASIN();
  main_ASIND();
  main_ASINH();
  main_ATAN();
  main_ATAN2();
  main_ATAN2D();
  main_ATAND();
  main_ATANH();
  main_COS();
  main_COSD();
  main_COSH();
  main_COT();
  main_COTD();
  main_COTH();
  main_CSC();
  main_CSCD();
  main_CSCH();
  main_DEG2RAD();
  main_HYPOT();
  main_RAD2DEG();
  main_SEC();
  main_SECH();
  main_SIN();
  main_SIND();
  main_SINH();
  main_TAN();
  main_TAND();
  main_TANH();

  /* Terminate the application.
     You do not need to do this more than one time. */
  ACOS_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
