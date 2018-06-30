/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eml_rand_mcg16807_stateful.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 01-Jul-2018 01:45:46
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "RAND.h"
#include "RANDG.h"
#include "RANDI.h"
#include "RANDN.h"
#include "eml_rand_mcg16807_stateful.h"
#include "RAND_data.h"

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
