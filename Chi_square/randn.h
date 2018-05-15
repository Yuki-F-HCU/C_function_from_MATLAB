/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: randn.h
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 14-May-2018 23:32:29
 */

#ifndef RANDN_H
#define RANDN_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "CHI2CDF_types.h"

/* Function Declarations */
extern void genrand_uint32_vector(unsigned int mt[625], unsigned int u[2]);
extern boolean_T is_valid_state(const unsigned int mt[625]);
extern double randn(void);
extern void twister_state_vector(unsigned int mt[625], unsigned int seed);

#endif

/*
 * File trailer for randn.h
 *
 * [EOF]
 */
