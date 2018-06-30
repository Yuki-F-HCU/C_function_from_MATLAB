/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rand.h
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 01-Jul-2018 00:59:48
 */

#ifndef RAND_H
#define RAND_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "BETACDF_types.h"

/* Function Declarations */
extern double b_rand(void);
extern void c_rand(double r[2]);
extern void genrand_uint32_vector(unsigned int mt[625], unsigned int u[2]);
extern boolean_T is_valid_state(const unsigned int mt[625]);
extern void twister_state_vector(unsigned int mt[625], unsigned int seed);

#endif

/*
 * File trailer for rand.h
 *
 * [EOF]
 */
