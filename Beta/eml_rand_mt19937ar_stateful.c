/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eml_rand_mt19937ar_stateful.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 01-Jul-2018 00:59:48
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "BETACDF.h"
#include "BETACDF_UPPER.h"
#include "BETAINV.h"
#include "BETAPDF.h"
#include "BETARND.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "BETACDF_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void state_not_empty_init(void)
{
  state_not_empty = false;
}

/*
 * File trailer for eml_rand_mt19937ar_stateful.c
 *
 * [EOF]
 */
