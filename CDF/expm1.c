/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: expm1.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Jun-2018 22:14:08
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "BETACDF.h"
#include "BETACDF_UPPER.h"
#include "BINOCDF.h"
#include "BINOCDF_UPPER.h"
#include "CHI2CDF.h"
#include "CHI2CDF_UPPER.h"
#include "EVCDF.h"
#include "EXPCDF.h"
#include "FCDF.h"
#include "FCDF_UPPER.h"
#include "GAMCDF.h"
#include "LOGNCDF.h"
#include "NORMCDF.h"
#include "TCDF.h"
#include "TCDF_UPPER.h"
#include "UNIFCDF.h"
#include "UNIFCDF_UPPER.h"
#include "expm1.h"

/* Function Definitions */

/*
 * Arguments    : double *x
 * Return Type  : void
 */
void b_expm1(double *x)
{
  double u;
  double z;
  double absz;
  u = exp(*x);
  if ((u < 1.1102230246251565E-16) || (!((!rtIsInf(u)) && (!rtIsNaN(u))))) {
    *x = u - 1.0;
  } else if (u < 0.5) {
    *x = (u - 1.0) * (*x / log(u));
  } else {
    if (u != 1.0) {
      z = u - 1.0;
      absz = fabs(u - 1.0);
      if ((absz > 4.503599627370496E+15) || (!((!rtIsInf(u - 1.0)) && (!rtIsNaN
             (u - 1.0))))) {
        z = log(1.0 + (u - 1.0));
      } else {
        if (!(absz < 2.2204460492503131E-16)) {
          z = log(1.0 + (u - 1.0)) * ((u - 1.0) / ((1.0 + (u - 1.0)) - 1.0));
        }
      }

      *x = (u - 1.0) * (*x / z);
    }
  }
}

/*
 * File trailer for expm1.c
 *
 * [EOF]
 */
