/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BETACDF_data.c
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
#include "BETACDF_data.h"

/* Variable Definitions */
unsigned int method;
unsigned int state;
unsigned int b_state[2];
unsigned int c_state[625];
boolean_T state_not_empty;
boolean_T method_not_empty;

/*
 * File trailer for BETACDF_data.c
 *
 * [EOF]
 */
