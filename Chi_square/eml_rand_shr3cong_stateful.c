/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eml_rand_shr3cong_stateful.c
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
#include "eml_rand_shr3cong_stateful.h"
#include "CHI2CDF_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void eml_rand_shr3cong_stateful_init(void)
{
  int i2;
  for (i2 = 0; i2 < 2; i2++) {
    b_state[i2] = 362436069U + 158852560U * i2;
  }
}

/*
 * File trailer for eml_rand_shr3cong_stateful.c
 *
 * [EOF]
 */
