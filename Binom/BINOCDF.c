/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BINOCDF.c
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
#include "binopdf1.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                double N
 *                double p
 * Return Type  : double
 */
double BINOCDF(double x, double N, double p)
{
  double y;
  double xf;
  double mu;
  double sd;
  double x2;
  double t2;
  int j;
  int i0;
  if ((p >= 0.0) && (p <= 1.0) && (N == floor(N)) && (!rtIsNaN(x))) {
    if (x >= N) {
      y = 1.0;
    } else if ((p == 0.0) && (x >= 0.0)) {
      y = 1.0;
    } else if (p == 1.0) {
      y = (x >= N);
    } else if (x >= 0.0) {
      xf = floor(x);
      if (N < 100000.0) {
        if ((x <= N * p) || (p < 0.0001)) {
          y = 0.0;
          for (j = 0; j < (int)(xf + 1.0); j++) {
            y += binopdf(j, N, p);
          }

          if (y > 1.0) {
            y = 1.0;
          }
        } else {
          x2 = (N - xf) - 1.0;
          y = 0.0;
          for (j = 0; j < (int)(x2 + 1.0); j++) {
            y += binopdf(j, N, 1.0 - p);
          }

          if (y > 1.0) {
            y = 1.0;
          }

          y = 1.0 - y;
        }
      } else {
        mu = N * p;
        sd = sqrt(N * p * (1.0 - p));
        t2 = 10.0;
        x2 = ceil(mu + 10.0 * sd);
        while ((xf <= x2) && (binopdf(x2, N, p) > 0.0)) {
          t2 *= 1.5;
          x2 = ceil(mu + t2 * sd);
        }

        if (xf >= x2) {
          y = 1.0;
        } else {
          t2 = 40.0;
          x2 = floor(mu - 40.0 * sd);
          while ((0.0 < x2) && (binopdf(x2, N, p) > 2.2204460492503131E-16)) {
            t2 *= 1.5;
            x2 = floor(mu - t2 * sd);
          }

          if (x2 < 0.0) {
            x2 = 0.0;
          }

          if (xf < x2) {
            y = 0.0;
          } else {
            y = 0.0;
            i0 = (int)(xf + (1.0 - x2));
            for (j = 0; j < i0; j++) {
              y += binopdf(x2 + (double)j, N, p);
            }

            if (y > 1.0) {
              y = 1.0;
            }
          }
        }
      }
    } else {
      y = 0.0;
    }
  } else {
    y = rtNaN;
  }

  return y;
}

/*
 * File trailer for BINOCDF.c
 *
 * [EOF]
 */
