/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: RAND_initialize.c
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
#include "RAND_initialize.h"
#include "eml_rand_shr3cong_stateful.h"
#include "eml_rand_mcg16807_stateful.h"
#include "eml_rand.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "eml_randn.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void RAND_initialize(void)
{
  rt_InitInfAndNaN(8U);
  method_not_empty_init();
  state_not_empty_init();
  eml_rand_init();
  eml_rand_mcg16807_stateful_init();
  eml_rand_shr3cong_stateful_init();
}

/*
 * File trailer for RAND_initialize.c
 *
 * [EOF]
 */
