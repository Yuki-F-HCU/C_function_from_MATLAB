/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BINOCDF_initialize.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 15-May-2018 14:46:03
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "BINOCDF.h"
#include "BINOINV.h"
#include "BINOPDF.h"
#include "BINORND.h"
#include "BINOCDF_initialize.h"
#include "eml_rand_shr3cong_stateful.h"
#include "eml_rand_mcg16807_stateful.h"
#include "eml_rand.h"
#include "eml_rand_mt19937ar_stateful.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void BINOCDF_initialize(void)
{
  rt_InitInfAndNaN(8U);
  state_not_empty_init();
  eml_rand_init();
  eml_rand_mcg16807_stateful_init();
  eml_rand_shr3cong_stateful_init();
}

/*
 * File trailer for BINOCDF_initialize.c
 *
 * [EOF]
 */
