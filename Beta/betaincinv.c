/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: betaincinv.c
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
#include "betaincinv.h"
#include "gammaln.h"
#include "BETACDF_rtwutil.h"

/* Function Declarations */
static double b_eml_betainc(double x, double a, double b, double lbeta,
  boolean_T upper);
static double c_eml_gammainc(double x, double a, double la, double lgap1,
  boolean_T upper);

/* Function Definitions */

/*
 * Arguments    : double x
 *                double a
 *                double b
 *                double lbeta
 *                boolean_T upper
 * Return Type  : double
 */
static double b_eml_betainc(double x, double a, double b, double lbeta,
  boolean_T upper)
{
  double rval;
  int tail;
  boolean_T b3;
  boolean_T guard1 = false;
  double logx;
  double log1mx;
  tail = upper;
  if (!(a >= 0.0)) {
    rval = rtNaN;
  } else if (!(b >= 0.0)) {
    rval = rtNaN;
  } else {
    if ((0.0 < x) && (x < 1.0)) {
      b3 = true;
    } else {
      b3 = false;
    }

    if (!b3) {
      if (x == 0.0) {
        rval = tail;
      } else if (x == 1.0) {
        rval = 1.0 - (double)tail;
      } else {
        rval = rtNaN;
      }
    } else if (a == 0.0) {
      if (b > 0.0) {
        if (x == 0.0) {
          rval = tail;
        } else {
          rval = 1 - tail;
        }
      } else if (x == 0.0) {
        rval = tail;
      } else if (x == 1.0) {
        rval = 1.0 - (double)tail;
      } else {
        rval = rtNaN;
      }
    } else if (b == 0.0) {
      if (x < 1.0) {
        rval = tail;
      } else {
        rval = 1 - tail;
      }
    } else if (a == rtInf) {
      if (b < rtInf) {
        if (x < 1.0) {
          rval = tail;
        } else {
          rval = 1 - tail;
        }
      } else if (x == 0.0) {
        rval = tail;
      } else if (x == 1.0) {
        rval = 1.0 - (double)tail;
      } else {
        rval = rtNaN;
      }
    } else if (b == rtInf) {
      if (x == 0.0) {
        rval = tail;
      } else {
        rval = 1 - tail;
      }
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
          if (upper) {
            rval = 1.0 - rval;
          }
        } else {
          rval = exp(((a * logx + b * log1mx) - log(b)) - lbeta) * betainc_cf
            (1.0 - x, b, a);
          if (!upper) {
            rval = 1.0 - rval;
          }
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
          logx = 3.0 * ((1.0 - 1.0 / (9.0 * b)) * logx - (1.0 - 1.0 / (9.0 * a))
                        * log1mx) / sqrt(logx * logx / b + log1mx * log1mx / a);
          if (upper) {
            rval = eml_PHIc(logx);
          } else {
            rval = eml_PHIc(-logx);
          }
        } else {
          logx = b;
          gammaln(&logx);
          rval = c_eml_gammainc(0.5 * (((a + b) - 1.0) * (3.0 - x) - (b - 1.0)) *
                                (1.0 - x), b, log(b), logx, !upper);
        }
      }
    }
  }

  return rval;
}

/*
 * Arguments    : double x
 *                double a
 *                double la
 *                double lgap1
 *                boolean_T upper
 * Return Type  : double
 */
static double c_eml_gammainc(double x, double a, double la, double lgap1,
  boolean_T upper)
{
  double rval;
  int tail;
  double asq;
  double stirlerr;
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
  int exitg2;
  int i;
  tail = upper;
  if (!(a > 0.0)) {
    if (a == 0.0) {
      if (x == x) {
        rval = 1.0 - (double)tail;
      } else {
        rval = rtNaN;
      }
    } else {
      rval = rtNaN;
    }
  } else if (a == rtInf) {
    if (x < rtInf) {
      rval = tail;
    } else {
      rval = rtNaN;
    }
  } else if (!(x > 0.0)) {
    if (x == 0.0) {
      rval = tail;
    } else {
      rval = rtNaN;
    }
  } else if (x == rtInf) {
    if (a < rtInf) {
      rval = 1.0 - (double)tail;
    } else {
      rval = rtNaN;
    }
  } else {
    if (a <= 15.0) {
      asq = 2.0 * a;
      if (asq == floor(asq)) {
        stirlerr = dv2[(int)(asq + 1.0) - 1];
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
          rval = exp(logpax) * asq;
        } else {
          rval = exp(logpax + log(asq));
        }

        if (upper) {
          rval = 1.0 - rval;
        }
      } else {
        asq = a * (((a1 / xD0 + old / x) + stirlerr / (x * xD0)) + asq / (x * x));
        if (logpax < 709.782712893384) {
          rval = exp(logpax) * asq;
        } else {
          rval = exp(logpax + log(asq));
        }

        if (!upper) {
          rval = 1.0 - rval;
        }
      }
    } else if (upper && (x < 1.0) && (a < 1.0)) {
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
        rval = 1.0 - (double)tail;
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
        tail = (int)((1.0 + (-1.0 - (n - 1.0))) / -1.0);
        for (i = 0; i < tail; i++) {
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

        if (upper) {
          rval = 1.0 - rval;
        }
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

      tail = (int)((1.0 + (-1.0 - (n - 1.0))) / -1.0);
      for (i = 0; i < tail; i++) {
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

      if (!upper) {
        rval = 1.0 - rval;
      }
    }
  }

  return rval;
}

/*
 * Arguments    : double p
 *                double a
 *                double b
 *                double lbeta
 * Return Type  : double
 */
double eml_betaincinv(double p, double a, double b, double lbeta)
{
  double rval;
  boolean_T upper;
  boolean_T b2;
  double pLower;
  double r;
  double y;
  double t;
  double h;
  int sgn;
  double zlo;
  double zhi;
  int i;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  upper = false;
  if (!(a >= 0.0)) {
    rval = rtNaN;
  } else if (!(b >= 0.0)) {
    rval = rtNaN;
  } else {
    if ((0.0 < p) && (p < 1.0)) {
      b2 = true;
    } else {
      b2 = false;
    }

    if (!b2) {
      if (p == 0.0) {
        rval = 0.0;
      } else if (p == 1.0) {
        rval = 1.0;
      } else {
        rval = rtNaN;
      }
    } else if (a == 0.0) {
      if (b > 0.0) {
        rval = !(p < 1.0);
      } else if (p == 0.0) {
        rval = 0.0;
      } else if (p == 1.0) {
        rval = 1.0;
      } else {
        rval = rtNaN;
      }
    } else if (b == 0.0) {
      rval = !(p == 0.0);
    } else if (a == rtInf) {
      if (b < rtInf) {
        rval = !(p == 0.0);
      } else if (p == 0.0) {
        rval = 0.0;
      } else if (p == 1.0) {
        rval = 1.0;
      } else {
        rval = rtNaN;
      }
    } else if (b == rtInf) {
      rval = !(p < 1.0);
    } else {
      if (p > 0.5) {
        p = 1.0 - p;
        upper = true;
      }

      if (upper) {
        pLower = 1.0 - p;
        if (1.0 - p == 1.0) {
          pLower = 0.9999999999999778;
        }
      } else {
        pLower = p;
      }

      r = sqrt(-2.0 * log(pLower));
      y = r - (2.30753 + 0.27061 * r) / (1.0 + (0.99229 + 0.04481 * r) * r);
      if ((a > 1.0) && (b > 1.0)) {
        r = (y * y - 3.0) / 6.0;
        pLower = 1.0 / (2.0 * a - 1.0);
        t = 1.0 / (2.0 * b - 1.0);
        h = 2.0 / (pLower + t);
        rval = a / (a + b * exp(2.0 * (y * sqrt(h + r) / h - (t - pLower) * ((r
          + 0.83333333333333337) - 2.0 / (3.0 * h)))));
      } else {
        r = 2.0 * b;
        t = 1.0 / (9.0 * b);
        t = (1.0 - t) + y * sqrt(t);
        t *= r * t * t;
        if (t > 0.0) {
          t = ((4.0 * a + r) - 2.0) / t;
          if (t > 1.0) {
            rval = 1.0 - 2.0 / (t + 1.0);
          } else {
            rval = exp((log(pLower * a) + lbeta) / a);
          }
        } else {
          rval = 1.0 - exp((log((1.0 - pLower) * b) + lbeta) / b);
        }
      }

      if (rval >= 0.0001) {
        pLower = rval;
      } else {
        pLower = 0.0001;
      }

      if (pLower <= 0.9999) {
        rval = pLower;
      } else {
        rval = 0.9999;
      }

      r = rtInf;
      y = rtInf;
      if (p > 1.0021E-294) {
        t = 2.2204460492503131E-14 * p;
      } else {
        t = 2.2251089859537388E-308;
      }

      if (upper) {
        sgn = -1;
      } else {
        sgn = 1;
      }

      zlo = 0.0;
      zhi = 1.0;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 1000)) {
        pLower = (double)sgn * (b_eml_betainc(rval, a, b, lbeta, upper) - p);
        if ((pLower * r < 0.0) && (fabs(r) <= fabs(pLower))) {
          rval = 0.5 * (rval + y);
          pLower = (double)sgn * (b_eml_betainc(rval, a, b, lbeta, upper) - p);
        }

        if (pLower > 0.0) {
          zhi = rval;
        } else {
          zlo = rval;
        }

        if ((fabs(pLower) < t) || (fabs(rval - y) < 2.2204460492503131E-16 *
             rval + 2.2250738585072014E-308)) {
          exitg1 = true;
        } else {
          guard1 = false;
          guard2 = false;
          guard3 = false;
          if (i < 200) {
            y = rval;
            r = pLower;
            if (1.0 - rval != 1.0) {
              h = log(1.0 - rval) * (-rval / ((1.0 - rval) - 1.0));
            } else {
              h = -rval;
            }

            rval -= pLower / exp(((a - 1.0) * log(rval) + (b - 1.0) * h) - lbeta);
            if (rval <= zlo) {
              if (zlo == 0.0) {
                pLower = b_eml_betainc(2.2250738585072014E-308, a, b, lbeta,
                  upper) - p;
                if (fabs((double)upper - p) < fabs(pLower)) {
                  rval = 0.0;
                  exitg1 = true;
                } else {
                  zlo = 2.2250738585072014E-308;
                  guard3 = true;
                }
              } else {
                guard3 = true;
              }
            } else if (rval >= zhi) {
              if (zhi == 1.0) {
                pLower = b_eml_betainc(0.99999999999999989, a, b, lbeta, upper)
                  - p;
                if (fabs((1.0 - (double)upper) - p) < fabs(pLower)) {
                  rval = 1.0;
                  exitg1 = true;
                } else {
                  zhi = 0.99999999999999989;
                  guard2 = true;
                }
              } else {
                guard2 = true;
              }
            } else {
              guard1 = true;
            }
          } else {
            rval = 0.5 * (zlo + zhi);
            guard1 = true;
          }

          if (guard3) {
            rval = 0.99 * zlo + 0.01 * zhi;
            guard1 = true;
          }

          if (guard2) {
            rval = 0.01 * zlo + 0.99 * zhi;
            guard1 = true;
          }

          if (guard1) {
            i++;
          }
        }
      }
    }
  }

  return rval;
}

/*
 * File trailer for betaincinv.c
 *
 * [EOF]
 */
