/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BETACDF.h
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 01-Jul-2018 00:59:48
 */

#ifndef BETACDF_H
#define BETACDF_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "BETACDF_types.h"

/* Function Declarations */
extern double BETACDF(double x, double a, double b);
extern double betainc_cf(double x, double a, double b);
extern double eml_PHIc(double z);
extern double eml_betainc(double x, double a, double b, double lbeta);

#endif

/*
 * File trailer for BETACDF.h
 *
 * [EOF]
 */
