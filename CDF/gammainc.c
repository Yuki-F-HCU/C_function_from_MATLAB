/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: gammainc.c
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
#include "gammainc.h"
#include "betainc.h"
#include "gammaln.h"

/* Function Declarations */
static double c_eml_gammainc(double x, double a, double la, double lgap1);
static double d_eml_gammainc(double x, double a, double la, double lgap1);

/* Function Definitions */

/*
 * Arguments    : double x
 *                double a
 *                double la
 *                double lgap1
 * Return Type  : double
 */
static double c_eml_gammainc(double x, double a, double la, double lgap1)
{
  double rval;
  double asq;
  double b_stirlerr;
  static const double dv2[31] = { 0.0, 0.15342640972002736, 0.081061466795327261,
    0.054814121051917651, 0.0413406959554093, 0.033162873519936291,
    0.027677925684998338, 0.023746163656297496, 0.020790672103765093,
    0.018488450532673187, 0.016644691189821193, 0.015134973221917378,
    0.013876128823070748, 0.012810465242920227, 0.01189670994589177,
    0.011104559758206917, 0.010411265261972096, 0.0097994161261588039,
    0.0092554621827127329, 0.0087687001341393862, 0.00833056343336287,
    0.00793411456431402, 0.0075736754879518406, 0.007244554301320383,
    0.00694284010720953, 0.0066652470327076821, 0.0064089941880042071,
    0.0061717122630394576, 0.0059513701127588475, 0.0057462165130101155,
    0.0055547335519628011 };

  double t;
  double vsq;
  double xD0;
  double old;
  double logpax;
  int exitg3;
  double n;
  boolean_T exitg1;
  double a1;
  int i3;
  int exitg2;
  int i;
  double b_logpax;
  double gold;
  if (!(a > 0.0)) {
    if (a == 0.0) {
      if (x == x) {
        rval = 1.0;
      } else {
        rval = rtNaN;
      }
    } else {
      rval = rtNaN;
    }
  } else if (a == rtInf) {
    if (x < rtInf) {
      rval = 0.0;
    } else {
      rval = rtNaN;
    }
  } else if (!(x > 0.0)) {
    if (x == 0.0) {
      rval = 0.0;
    } else {
      rval = rtNaN;
    }
  } else if (x == rtInf) {
    if (a < rtInf) {
      rval = 1.0;
    } else {
      rval = rtNaN;
    }
  } else {
    if (a <= 15.0) {
      asq = 2.0 * a;
      if (asq == floor(asq)) {
        b_stirlerr = dv2[(int)(asq + 1.0) - 1];
      } else {
        b_stirlerr = ((lgap1 - (a + 0.5) * la) + a) - 0.91893853320467267;
      }
    } else {
      asq = a * a;
      b_stirlerr = (0.083333333333333329 + (-0.0027777777777777779 +
        (0.00079365079365079365 + (-0.00059523809523809529 +
        0.00084175084175084171 / asq) / asq) / asq) / asq) / a;
    }

    if (fabs(a - x) > 0.1 * (a + x)) {
      t = a / x;
      if (t < 2.2250738585072014E-308) {
        xD0 = x;
      } else if (t > 1.7976931348623157E+308) {
        xD0 = (a * la - a * log(x)) - a;
      } else {
        xD0 = (a * log(t) + x) - a;
      }
    } else {
      t = x / a;
      asq = (1.0 - t) / (1.0 + t);
      vsq = asq * asq;
      xD0 = (a - x) * asq;
      old = xD0;
      asq = 2.0 * (a * asq);
      t = 3.0;
      do {
        exitg3 = 0;
        asq *= vsq;
        xD0 += asq / t;
        if (xD0 == old) {
          exitg3 = 1;
        } else {
          old = xD0;
          t += 2.0;
        }
      } while (exitg3 == 0);
    }

    logpax = (-0.5 * (1.8378770664093453 + la) - b_stirlerr) - xD0;
    if (x > 1.0E+6) {
      vsq = sqrt(x);
      t = fabs((a - x) - 1.0) / vsq;
      asq = t * t;
      if (t < 15.0) {
        a1 = eml_PHIc(t) * 2.5066282746310002 * exp(0.5 * asq);
        xD0 = (a1 * ((asq - 3.0) * t) - (asq - 4.0)) / 6.0;
        old = (a1 * ((asq * asq - 9.0) * asq + 6.0) - ((asq - 1.0) * asq - 6.0) *
               t) / 72.0;
        asq = (a1 * (((((5.0 * asq + 45.0) * asq - 81.0) * asq - 315.0) * asq +
                      270.0) * t) - ((((5.0 * asq + 40.0) * asq - 111.0) * asq -
                 174.0) * asq + 192.0)) / 6480.0;
      } else {
        a1 = (1.0 + (-1.0 + (3.0 - 15.0 / asq) / asq) / asq) / t;
        xD0 = (1.0 + (-4.0 + (25.0 - 210.0 / asq) / asq) / asq) / asq;
        old = (1.0 + (-11.0 + (130.0 - 1750.0 / asq) / asq) / asq) / (asq * t);
        asq = (1.0 + (-26.0 + (546.0 - 11368.0 / asq) / asq) / asq) / (asq * asq);
      }

      if (x < a - 1.0) {
        asq = a * (((a1 / vsq - xD0 / x) + old / (x * vsq)) - asq / (x * x));
        if (logpax < 709.782712893384) {
          rval = exp(logpax) * asq;
        } else {
          rval = exp(logpax + log(asq));
        }
      } else {
        asq = a * (((a1 / vsq + xD0 / x) + old / (x * vsq)) + asq / (x * x));
        if (logpax < 709.782712893384) {
          b_logpax = exp(logpax) * asq;
        } else {
          b_logpax = exp(logpax + log(asq));
        }

        rval = 1.0 - b_logpax;
      }
    } else if ((x < a) || (x < 1.0)) {
      vsq = x / a;
      n = 1.0;
      if (vsq == rtInf) {
        rval = 1.0;
      } else {
        if (vsq > 2.2204460492503131E-16) {
          n = 2.0;
          do {
            exitg2 = 0;
            vsq = x * vsq / (a + (n - 1.0));
            if (vsq < 2.2204460492503131E-16) {
              exitg2 = 1;
            } else {
              n++;
            }
          } while (exitg2 == 0);
        }

        asq = 0.0;
        i3 = (int)((1.0 + (-1.0 - (n - 1.0))) / -1.0);
        for (i = 0; i < i3; i++) {
          asq = x * (1.0 + asq) / (a + ((n - 1.0) + -(double)i));
        }

        asq++;
        if (logpax < 709.782712893384) {
          rval = exp(logpax) * asq;
        } else {
          rval = exp(logpax + log(asq));
        }

        if (rval > 1.0) {
          rval = 1.0;
        }
      }
    } else {
      vsq = 1.0;
      n = 1.0;
      exitg1 = false;
      while ((!exitg1) && (n <= floor(a + x))) {
        vsq = (a - n) * vsq / x;
        if (fabs(vsq) < 2.2204460492503131E-16) {
          exitg1 = true;
        } else {
          n++;
        }
      }

      if (n <= floor(a + x)) {
        asq = 1.0;
      } else {
        xD0 = a - floor(a);
        if (xD0 == 0.0) {
          asq = 1.0;
          n = floor(a);
        } else if (xD0 == 0.5) {
          asq = sqrt(3.1415926535897931 * x) * exp(x) * (2.0 * eml_PHIc(sqrt(2.0
            * x)));
          n = floor(a) + 1.0;
        } else {
          old = 1.0;
          a1 = x;
          b_stirlerr = 0.0;
          t = 1.0;
          vsq = 1.0 / x;
          n = 1.0;
          asq = vsq;
          gold = 0.0;
          while (fabs(asq - gold) > 2.2204460492503131E-16 * asq) {
            gold = asq;
            asq = n - xD0;
            old = (a1 + old * asq) * vsq;
            b_stirlerr = (t + b_stirlerr * asq) * vsq;
            asq = n * vsq;
            a1 = x * old + asq * a1;
            t = x * b_stirlerr + asq * t;
            vsq = 1.0 / a1;
            asq = t * vsq;
            n++;
          }

          asq *= x;
          n = floor(a) + 1.0;
        }
      }

      i3 = (int)((1.0 + (-1.0 - (n - 1.0))) / -1.0);
      for (i = 0; i < i3; i++) {
        asq = 1.0 + (a - ((n - 1.0) + -(double)i)) * asq / x;
      }

      asq = asq * a / x;
      if (logpax < 709.782712893384) {
        rval = exp(logpax) * asq;
      } else {
        rval = exp(logpax + log(asq));
      }

      if (rval > 1.0) {
        rval = 1.0;
      }

      rval = 1.0 - rval;
    }
  }

  return rval;
}

/*
 * Arguments    : double x
 *                double a
 *                double la
 *                double lgap1
 * Return Type  : double
 */
static double d_eml_gammainc(double x, double a, double la, double lgap1)
{
  double rval;
  double asq;
  double b_stirlerr;
  static const double dv3[31] = { 0.0, 0.15342640972002736, 0.081061466795327261,
    0.054814121051917651, 0.0413406959554093, 0.033162873519936291,
    0.027677925684998338, 0.023746163656297496, 0.020790672103765093,
    0.018488450532673187, 0.016644691189821193, 0.015134973221917378,
    0.013876128823070748, 0.012810465242920227, 0.01189670994589177,
    0.011104559758206917, 0.010411265261972096, 0.0097994161261588039,
    0.0092554621827127329, 0.0087687001341393862, 0.00833056343336287,
    0.00793411456431402, 0.0075736754879518406, 0.007244554301320383,
    0.00694284010720953, 0.0066652470327076821, 0.0064089941880042071,
    0.0061717122630394576, 0.0059513701127588475, 0.0057462165130101155,
    0.0055547335519628011 };

  double t;
  double xD0;
  double old;
  double term;
  double logpax;
  int exitg4;
  double fac;
  double n;
  boolean_T exitg1;
  double a1;
  int exitg3;
  int i4;
  int exitg2;
  int i;
  double b_logpax;
  if (!(a > 0.0)) {
    if (a == 0.0) {
      if (x == x) {
        rval = 0.0;
      } else {
        rval = rtNaN;
      }
    } else {
      rval = rtNaN;
    }
  } else if (a == rtInf) {
    if (x < rtInf) {
      rval = 1.0;
    } else {
      rval = rtNaN;
    }
  } else if (!(x > 0.0)) {
    if (x == 0.0) {
      rval = 1.0;
    } else {
      rval = rtNaN;
    }
  } else if (x == rtInf) {
    if (a < rtInf) {
      rval = 0.0;
    } else {
      rval = rtNaN;
    }
  } else {
    if (a <= 15.0) {
      asq = 2.0 * a;
      if (asq == floor(asq)) {
        b_stirlerr = dv3[(int)(asq + 1.0) - 1];
      } else {
        b_stirlerr = ((lgap1 - (a + 0.5) * la) + a) - 0.91893853320467267;
      }
    } else {
      asq = a * a;
      b_stirlerr = (0.083333333333333329 + (-0.0027777777777777779 +
        (0.00079365079365079365 + (-0.00059523809523809529 +
        0.00084175084175084171 / asq) / asq) / asq) / asq) / a;
    }

    if (fabs(a - x) > 0.1 * (a + x)) {
      t = a / x;
      if (t < 2.2250738585072014E-308) {
        xD0 = x;
      } else if (t > 1.7976931348623157E+308) {
        xD0 = (a * la - a * log(x)) - a;
      } else {
        xD0 = (a * log(t) + x) - a;
      }
    } else {
      t = x / a;
      asq = (1.0 - t) / (1.0 + t);
      t = asq * asq;
      xD0 = (a - x) * asq;
      old = xD0;
      term = 2.0 * (a * asq);
      asq = 3.0;
      do {
        exitg4 = 0;
        term *= t;
        xD0 += term / asq;
        if (xD0 == old) {
          exitg4 = 1;
        } else {
          old = xD0;
          asq += 2.0;
        }
      } while (exitg4 == 0);
    }

    logpax = (-0.5 * (1.8378770664093453 + la) - b_stirlerr) - xD0;
    if (x > 1.0E+6) {
      xD0 = sqrt(x);
      t = fabs((a - x) - 1.0) / xD0;
      asq = t * t;
      if (t < 15.0) {
        a1 = eml_PHIc(t) * 2.5066282746310002 * exp(0.5 * asq);
        old = (a1 * ((asq - 3.0) * t) - (asq - 4.0)) / 6.0;
        b_stirlerr = (a1 * ((asq * asq - 9.0) * asq + 6.0) - ((asq - 1.0) * asq
          - 6.0) * t) / 72.0;
        asq = (a1 * (((((5.0 * asq + 45.0) * asq - 81.0) * asq - 315.0) * asq +
                      270.0) * t) - ((((5.0 * asq + 40.0) * asq - 111.0) * asq -
                 174.0) * asq + 192.0)) / 6480.0;
      } else {
        a1 = (1.0 + (-1.0 + (3.0 - 15.0 / asq) / asq) / asq) / t;
        old = (1.0 + (-4.0 + (25.0 - 210.0 / asq) / asq) / asq) / asq;
        b_stirlerr = (1.0 + (-11.0 + (130.0 - 1750.0 / asq) / asq) / asq) / (asq
          * t);
        asq = (1.0 + (-26.0 + (546.0 - 11368.0 / asq) / asq) / asq) / (asq * asq);
      }

      if (x < a - 1.0) {
        asq = a * (((a1 / xD0 - old / x) + b_stirlerr / (x * xD0)) - asq / (x *
                    x));
        if (logpax < 709.782712893384) {
          b_logpax = exp(logpax) * asq;
        } else {
          b_logpax = exp(logpax + log(asq));
        }

        rval = 1.0 - b_logpax;
      } else {
        asq = a * (((a1 / xD0 + old / x) + b_stirlerr / (x * xD0)) + asq / (x *
                    x));
        if (logpax < 709.782712893384) {
          rval = exp(logpax) * asq;
        } else {
          rval = exp(logpax + log(asq));
        }
      }
    } else if ((x < 1.0) && (a < 1.0)) {
      fac = a * -x;
      xD0 = fac / (a + 1.0);
      n = 2.0;
      do {
        exitg3 = 0;
        fac = -x * fac / n;
        term = fac / (a + n);
        xD0 += term;
        if (fabs(term) <= fabs(xD0) * 2.2204460492503131E-16) {
          exitg3 = 1;
        } else {
          n++;
        }
      } while (exitg3 == 0);

      asq = a * log(x) - lgap1;
      t = exp(asq);
      if (!(t == 1.0)) {
        if (t - 1.0 == -1.0) {
          asq = -1.0;
        } else {
          asq = (t - 1.0) * asq / log(t);
        }
      }

      rval = -((xD0 + asq) + xD0 * asq);
      if (rval < 0.0) {
        rval = 0.0;
      }
    } else if ((x < a) || (x < 1.0)) {
      fac = x / a;
      n = 1.0;
      if (fac == rtInf) {
        rval = 0.0;
      } else {
        if (fac > 2.2204460492503131E-16) {
          n = 2.0;
          do {
            exitg2 = 0;
            fac = x * fac / (a + (n - 1.0));
            if (fac < 2.2204460492503131E-16) {
              exitg2 = 1;
            } else {
              n++;
            }
          } while (exitg2 == 0);
        }

        asq = 0.0;
        i4 = (int)((1.0 + (-1.0 - (n - 1.0))) / -1.0);
        for (i = 0; i < i4; i++) {
          asq = x * (1.0 + asq) / (a + ((n - 1.0) + -(double)i));
        }

        asq++;
        if (logpax < 709.782712893384) {
          rval = exp(logpax) * asq;
        } else {
          rval = exp(logpax + log(asq));
        }

        if (rval > 1.0) {
          rval = 1.0;
        }

        rval = 1.0 - rval;
      }
    } else {
      fac = 1.0;
      n = 1.0;
      exitg1 = false;
      while ((!exitg1) && (n <= floor(a + x))) {
        fac = (a - n) * fac / x;
        if (fabs(fac) < 2.2204460492503131E-16) {
          exitg1 = true;
        } else {
          n++;
        }
      }

      if (n <= floor(a + x)) {
        asq = 1.0;
      } else {
        xD0 = a - floor(a);
        if (xD0 == 0.0) {
          asq = 1.0;
          n = floor(a);
        } else if (xD0 == 0.5) {
          asq = sqrt(3.1415926535897931 * x) * exp(x) * (2.0 * eml_PHIc(sqrt(2.0
            * x)));
          n = floor(a) + 1.0;
        } else {
          old = 1.0;
          a1 = x;
          b_stirlerr = 0.0;
          t = 1.0;
          fac = 1.0 / x;
          n = 1.0;
          asq = fac;
          term = 0.0;
          while (fabs(asq - term) > 2.2204460492503131E-16 * asq) {
            term = asq;
            asq = n - xD0;
            old = (a1 + old * asq) * fac;
            b_stirlerr = (t + b_stirlerr * asq) * fac;
            asq = n * fac;
            a1 = x * old + asq * a1;
            t = x * b_stirlerr + asq * t;
            fac = 1.0 / a1;
            asq = t * fac;
            n++;
          }

          asq *= x;
          n = floor(a) + 1.0;
        }
      }

      i4 = (int)((1.0 + (-1.0 - (n - 1.0))) / -1.0);
      for (i = 0; i < i4; i++) {
        asq = 1.0 + (a - ((n - 1.0) + -(double)i)) * asq / x;
      }

      asq = asq * a / x;
      if (logpax < 709.782712893384) {
        rval = exp(logpax) * asq;
      } else {
        rval = exp(logpax + log(asq));
      }

      if (rval > 1.0) {
        rval = 1.0;
      }
    }
  }

  return rval;
}

/*
 * Arguments    : double x
 *                double a
 * Return Type  : creal_T
 */
creal_T b_gammainc(double x, double a)
{
  creal_T b;
  double pax_modulus;
  double pax_angle;
  double pax_r;
  double pax_i;
  double Iax;
  int exitg1;
  double b_pax_i;
  pax_modulus = a + 1.0;
  gammaln(&pax_modulus);
  if (!(x < 0.0)) {
    b.re = d_eml_gammainc(x, a, log(a), pax_modulus);
    b.im = 0.0;
  } else {
    if (!(x < 0.0)) {
      pax_angle = 1.0;
      pax_modulus = 0.0;
    } else if (x == rtMinusInf) {
      pax_angle = rtNaN;
      pax_modulus = rtNaN;
    } else if (!(a > 0.0)) {
      pax_angle = rtNaN;
      pax_modulus = rtNaN;
    } else if (a == rtInf) {
      pax_angle = rtNaN;
      pax_modulus = rtNaN;
    } else {
      pax_modulus = exp((-x + a * log(-x)) - pax_modulus);
      pax_angle = a * 3.1415926535897931;
      if (a == 1.0) {
        pax_r = -pax_modulus;
        pax_i = 0.0;
      } else {
        pax_r = pax_modulus * cos(pax_angle);
        pax_i = pax_modulus * sin(pax_angle);
      }

      Iax = 1.0;
      pax_modulus = 1.0;
      pax_angle = 1.0;
      do {
        exitg1 = 0;
        pax_modulus = pax_modulus * x / (a + pax_angle);
        Iax += pax_modulus;
        if (fabs(pax_modulus) <= 2.2204460492503131E-16 * fabs(Iax)) {
          exitg1 = 1;
        } else {
          pax_angle++;
        }
      } while (exitg1 == 0);

      Iax = fabs(Iax);
      pax_angle = 1.0 - Iax * pax_r;
      if (pax_i == 0.0) {
        b_pax_i = 0.0;
      } else {
        b_pax_i = Iax * pax_i;
      }

      pax_modulus = 0.0 - b_pax_i;
    }

    b.re = pax_angle;
    b.im = pax_modulus;
  }

  return b;
}

/*
 * Arguments    : double x
 *                double a
 * Return Type  : creal_T
 */
creal_T gammainc(double x, double a)
{
  creal_T b;
  double pax_modulus;
  double pax_angle;
  double pax_r;
  double pax_i;
  double Iax;
  int exitg1;
  pax_modulus = a + 1.0;
  gammaln(&pax_modulus);
  if (!(x < 0.0)) {
    b.re = c_eml_gammainc(x, a, log(a), pax_modulus);
    b.im = 0.0;
  } else {
    if (!(x < 0.0)) {
      pax_angle = 0.0;
      pax_modulus = 0.0;
    } else if (x == rtMinusInf) {
      pax_angle = rtNaN;
      pax_modulus = rtNaN;
    } else if (!(a > 0.0)) {
      pax_angle = rtNaN;
      pax_modulus = rtNaN;
    } else if (a == rtInf) {
      pax_angle = rtNaN;
      pax_modulus = rtNaN;
    } else {
      pax_modulus = exp((-x + a * log(-x)) - pax_modulus);
      pax_angle = a * 3.1415926535897931;
      if (a == 1.0) {
        pax_r = -pax_modulus;
        pax_i = 0.0;
      } else {
        pax_r = pax_modulus * cos(pax_angle);
        pax_i = pax_modulus * sin(pax_angle);
      }

      Iax = 1.0;
      pax_modulus = 1.0;
      pax_angle = 1.0;
      do {
        exitg1 = 0;
        pax_modulus = pax_modulus * x / (a + pax_angle);
        Iax += pax_modulus;
        if (fabs(pax_modulus) <= 2.2204460492503131E-16 * fabs(Iax)) {
          exitg1 = 1;
        } else {
          pax_angle++;
        }
      } while (exitg1 == 0);

      Iax = fabs(Iax);
      pax_angle = Iax * pax_r;
      if (pax_i == 0.0) {
        pax_modulus = 0.0;
      } else {
        pax_modulus = Iax * pax_i;
      }
    }

    b.re = pax_angle;
    b.im = pax_modulus;
  }

  return b;
}

/*
 * File trailer for gammainc.c
 *
 * [EOF]
 */
