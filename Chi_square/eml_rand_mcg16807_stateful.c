/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eml_rand_mcg16807_stateful.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 14-May-2018 23:32:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "CHI2CDF.h"
#include "CHI2INV.h"
#include "CHI2PDF.h"
#include "CHI2RND.h"
#include "eml_rand_mcg16807_stateful.h"
#include "CHI2CDF_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void eml_rand_mcg16807_stateful_init(void)
{
  state = 1144108930U;
}

/*
 * File trailer for eml_rand_mcg16807_stateful.c
 *
 * [EOF]
 */
