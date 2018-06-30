/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: RAND_data.c
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
#include "RAND_data.h"

/* Variable Definitions */
unsigned int method;
unsigned int state;
unsigned int b_state[2];
unsigned int c_state[625];
boolean_T state_not_empty;
boolean_T method_not_empty;

/*
 * File trailer for RAND_data.c
 *
 * [EOF]
 */
