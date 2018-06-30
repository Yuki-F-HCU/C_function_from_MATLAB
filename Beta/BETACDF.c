/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BETACDF.c
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
#include "gammaln.h"
#include "BETACDF_rtwutil.h"

/* Function Declarations */
static double eml_gammainc(double x, double a, double la, double lgap1);

/* Function Definitions */

/*
 * Arguments    : double x
 *                double a
 *                double la
 *                double lgap1
 * Return Type  : double
 */
static double eml_gammainc(double x, double a, double la, double lgap1)
{
  double rval;
  double asq;
  double stirlerr;
  static const double dv0[31] = { 0.0, 0.15342640972002736, 0.081061466795327261,
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
  int i0;
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
        stirlerr = dv0[(int)(asq + 1.0) - 1];
      } else {
        stirlerr = ((lgap1 - (a + 0.5) * la) + a) - 0.91893853320467267;
      }
    } else {
      asq = a * a;
      stirlerr = (0.083333333333333329 + (-0.0027777777777777779 +
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

    logpax = (-0.5 * (1.8378770664093453 + la) - stirlerr) - xD0;
    if (x > 1.0E+6) {
      xD0 = sqrt(x);
      t = fabs((a - x) - 1.0) / xD0;
      asq = t * t;
      if (t < 15.0) {
        a1 = eml_PHIc(t) * 2.5066282746310002 * exp(0.5 * asq);
        old = (a1 * ((asq - 3.0) * t) - (asq - 4.0)) / 6.0;
        stirlerr = (a1 * ((asq * asq - 9.0) * asq + 6.0) - ((asq - 1.0) * asq -
          6.0) * t) / 72.0;
        asq = (a1 * (((((5.0 * asq + 45.0) * asq - 81.0) * asq - 315.0) * asq +
                      270.0) * t) - ((((5.0 * asq + 40.0) * asq - 111.0) * asq -
                 174.0) * asq + 192.0)) / 6480.0;
      } else {
        a1 = (1.0 + (-1.0 + (3.0 - 15.0 / asq) / asq) / asq) / t;
        old = (1.0 + (-4.0 + (25.0 - 210.0 / asq) / asq) / asq) / asq;
        stirlerr = (1.0 + (-11.0 + (130.0 - 1750.0 / asq) / asq) / asq) / (asq *
          t);
        asq = (1.0 + (-26.0 + (546.0 - 11368.0 / asq) / asq) / asq) / (asq * asq);
      }

      if (x < a - 1.0) {
        asq = a * (((a1 / xD0 - old / x) + stirlerr / (x * xD0)) - asq / (x * x));
        if (logpax < 709.782712893384) {
          b_logpax = exp(logpax) * asq;
        } else {
          b_logpax = exp(logpax + log(asq));
        }

        rval = 1.0 - b_logpax;
      } else {
        asq = a * (((a1 / xD0 + old / x) + stirlerr / (x * xD0)) + asq / (x * x));
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
        i0 = (int)((1.0 + (-1.0 - (n - 1.0))) / -1.0);
        for (i = 0; i < i0; i++) {
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
          stirlerr = 0.0;
          t = 1.0;
          fac = 1.0 / x;
          n = 1.0;
          asq = fac;
          term = 0.0;
          while (fabs(asq - term) > 2.2204460492503131E-16 * asq) {
            term = asq;
            asq = n - xD0;
            old = (a1 + old * asq) * fac;
            stirlerr = (t + stirlerr * asq) * fac;
            asq = n * fac;
            a1 = x * old + asq * a1;
            t = x * stirlerr + asq * t;
            fac = 1.0 / a1;
            asq = t * fac;
            n++;
          }

          asq *= x;
          n = floor(a) + 1.0;
        }
      }

      i0 = (int)((1.0 + (-1.0 - (n - 1.0))) / -1.0);
      for (i = 0; i < i0; i++) {
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
 *                double b
 * Return Type  : double
 */
double BETACDF(double x, double a, double b)
{
  double p;
  double glna1;
  double glnb1;
  double d0;
  if ((a > 0.0) && (b > 0.0) && (!rtIsInf(a)) && (!rtIsInf(b)) && (!rtIsNaN(x)))
  {
    if (x < 0.0) {
      p = 0.0;
    } else if (x <= 1.0) {
      glna1 = a;
      gammaln(&glna1);
      glnb1 = b;
      gammaln(&glnb1);
      d0 = a + b;
      gammaln(&d0);
      p = eml_betainc(x, a, b, (glna1 + glnb1) - d0);
    } else {
      p = 1.0;
    }
  } else {
    p = rtNaN;
  }

  return p;
}

/*
 * Arguments    : double x
 *                double a
 *                double b
 * Return Type  : double
 */
double betainc_cf(double x, double a, double b)
{
  double y;
  double aplusb;
  double C;
  double Dinv;
  int m;
  int exitg1;
  double yold;
  int twom;
  double d;
  double b_y;
  aplusb = a + b;
  C = 1.0;
  Dinv = 1.0 - aplusb * x / (a + 1.0);
  y = 1.0 / Dinv;
  m = 0;
  do {
    exitg1 = 0;
    if (m < 1000) {
      yold = y;
      twom = (1 + m) << 1;
      d = (1.0 + (double)m) * (b - (1.0 + (double)m)) * x / (((a - 1.0) +
        (double)twom) * (a + (double)twom));
      b_y = d / C;
      C = 1.0 + d / C;
      Dinv = 1.0 + d / Dinv;
      y *= (1.0 + b_y) / Dinv;
      d = -(a + (1.0 + (double)m)) * (aplusb + (1.0 + (double)m)) * x / ((a +
        (double)twom) * ((a + 1.0) + (double)twom));
      C = 1.0 + d / C;
      Dinv = 1.0 + d / Dinv;
      y *= C / Dinv;
      if (fabs(y - yold) < 2.2204460492503131E-15) {
        exitg1 = 1;
      } else {
        m++;
      }
    } else {
      y = rtNaN;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return y;
}

/*
 * Arguments    : double z
 * Return Type  : double
 */
double eml_PHIc(double z)
{
  double y;
  double x;
  double t;
  x = 0.70710678118654746 * z;
  t = 3.97886080735226 / (fabs(x) + 3.97886080735226);
  y = 0.5 * ((((((((((((((((((((((0.0012710976495261409 * (t - 0.5) +
    0.00011931402283834095) * (t - 0.5) + -0.0039638509736051354) * (t - 0.5) +
    -0.00087077963531729586) * (t - 0.5) + 0.0077367252831352668) * (t - 0.5) +
    0.0038333512626488732) * (t - 0.5) + -0.012722381378212275) * (t - 0.5) +
    -0.013382364453346007) * (t - 0.5) + 0.016131532973325226) * (t - 0.5) +
    0.039097684558848406) * (t - 0.5) + 0.0024936720005350331) * (t - 0.5) +
                        -0.0838864557023002) * (t - 0.5) + -0.11946395996432542)
                      * (t - 0.5) + 0.016620792496936737) * (t - 0.5) +
                     0.35752427444953105) * (t - 0.5) + 0.80527640875291062) *
                   (t - 0.5) + 1.1890298290927332) * (t - 0.5) +
                  1.3704021768233816) * (t - 0.5) + 1.313146538310231) * (t -
    0.5) + 1.0792551515585667) * (t - 0.5) + 0.77436819911953858) * (t - 0.5) +
              0.49016508058531844) * (t - 0.5) + 0.27537474159737679) * t * exp(
    -x * x);
  if (x < 0.0) {
    y = 1.0 - y;
  }

  return y;
}

/*
 * Arguments    : double x
 *                double a
 *                double b
 *                double lbeta
 * Return Type  : double
 */
double eml_betainc(double x, double a, double b, double lbeta)
{
  double rval;
  boolean_T b0;
  boolean_T guard1 = false;
  double logx;
  double log1mx;
  if (!(a >= 0.0)) {
    rval = rtNaN;
  } else if (!(b >= 0.0)) {
    rval = rtNaN;
  } else {
    if ((0.0 < x) && (x < 1.0)) {
      b0 = true;
    } else {
      b0 = false;
    }

    if (!b0) {
      if (x == 0.0) {
        rval = 0.0;
      } else if (x == 1.0) {
        rval = 1.0;
      } else {
        rval = rtNaN;
      }
    } else if (a == 0.0) {
      if (b > 0.0) {
        rval = !(x == 0.0);
      } else if (x == 0.0) {
        rval = 0.0;
      } else if (x == 1.0) {
        rval = 1.0;
      } else {
        rval = rtNaN;
      }
    } else if (b == 0.0) {
      rval = !(x < 1.0);
    } else if (a == rtInf) {
      if (b < rtInf) {
        rval = !(x < 1.0);
      } else if (x == 0.0) {
        rval = 0.0;
      } else if (x == 1.0) {
        rval = 1.0;
      } else {
        rval = rtNaN;
      }
    } else if (b == rtInf) {
      rval = !(x == 0.0);
    } else {
      guard1 = false;
      if (a + b < 1.0E+7) {
        logx = log(x);
        if (1.0 - x != 1.0) {
          log1mx = log(1.0 - x) * (-x / ((1.0 - x) - 1.0));
        } else {
          log1mx = -x;
        }

        if (x < (a + 1.0) / ((a + b) + 2.0)) {
          rval = exp(((a * logx + b * log1mx) - log(a)) - lbeta) * betainc_cf(x,
            a, b);
        } else {
          rval = 1.0 - exp(((a * logx + b * log1mx) - log(b)) - lbeta) *
            betainc_cf(1.0 - x, b, a);
        }

        if (rval == rval) {
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        logx = rt_powd_snf(b * x, 0.33333333333333331);
        log1mx = rt_powd_snf(a * (1.0 - x), 0.33333333333333331);
        if (((a + b) - 1.0) * (1.0 - x) > 0.8) {
          rval = eml_PHIc(-(3.0 * ((1.0 - 1.0 / (9.0 * b)) * logx - (1.0 - 1.0 /
            (9.0 * a)) * log1mx) / sqrt(logx * logx / b + log1mx * log1mx / a)));
        } else {
          logx = b;
          gammaln(&logx);
          rval = eml_gammainc(0.5 * (((a + b) - 1.0) * (3.0 - x) - (b - 1.0)) *
                              (1.0 - x), b, log(b), logx);
        }
      }
    }
  }

  return rval;
}

/*
 * File trailer for BETACDF.c
 *
 * [EOF]
 */
