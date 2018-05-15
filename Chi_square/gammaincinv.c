/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: gammaincinv.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 14-May-2018 23:32:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "CHI2CDF.h"
#include "CHI2INV.h"
#include "CHI2PDF.h"
#include "CHI2RND.h"
#include "gammaincinv.h"
#include "gammainc.h"
#include "CHI2CDF_rtwutil.h"

/* Function Declarations */
static double b_eml_gammainc(double x, double a, double la, double lgap1,
  boolean_T upper);

/* Function Definitions */

/*
 * Arguments    : double x
 *                double a
 *                double la
 *                double lgap1
 *                boolean_T upper
 * Return Type  : double
 */
static double b_eml_gammainc(double x, double a, double la, double lgap1,
  boolean_T upper)
{
  double rval;
  int tail;
  double asq;
  double stirlerr;
  static const double dv1[31] = { 0.0, 0.15342640972002736, 0.081061466795327261,
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
        stirlerr = dv1[(int)(asq + 1.0) - 1];
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
 *                double la
 *                double lga
 *                double lgap1
 * Return Type  : double
 */
double eml_gammaincinv(double p, double a, double la, double lga, double lgap1)
{
  double rval;
  boolean_T upper;
  boolean_T b0;
  double nu;
  double pLower;
  double log1mpLower;
  int i;
  boolean_T exitg2;
  double r;
  double p1;
  double oldz;
  int sgn;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  upper = false;
  if (!(a > 0.0)) {
    if (a == 0.0) {
      if ((0.0 <= p) && (p <= 1.0)) {
        rval = 0.0;
      } else {
        rval = rtNaN;
      }
    } else {
      rval = rtNaN;
    }
  } else {
    if ((0.0 < p) && (p < 1.0)) {
      b0 = true;
    } else {
      b0 = false;
    }

    if (!b0) {
      if (p == 0.0) {
        rval = 0.0;
      } else if (p == 1.0) {
        rval = rtInf;
      } else {
        rval = rtNaN;
      }
    } else if (a == rtInf) {
      if (p == 0.0) {
        rval = 0.0;
      } else {
        rval = rtInf;
      }
    } else if (lga == rtInf) {
      rval = a;
    } else {
      nu = 2.0 * a;
      if (p > 0.5) {
        p = 1.0 - p;
        upper = true;
      }

      if (upper) {
        pLower = 1.0 - p;
        if (1.0 - p == 1.0) {
          pLower = 0.9999999999999778;
        }

        log1mpLower = log(p);
      } else {
        pLower = p;
        if (1.0 - p != 1.0) {
          log1mpLower = log(1.0 - p) * (-p / ((1.0 - p) - 1.0));
        } else {
          log1mpLower = -p;
        }
      }

      if (nu < -1.24 * log(pLower)) {
        pLower = rt_powd_snf(pLower * exp(lgap1 + a * 0.693147180559945), 1.0 /
                             a);
        if (pLower < 2.2250738585072014E-306) {
          pLower = 2.2250738585072014E-306;
        }
      } else if (nu <= 0.32) {
        pLower = 0.4;
        i = 0;
        exitg2 = false;
        while ((!exitg2) && (200 > i)) {
          oldz = pLower;
          p1 = 1.0 + pLower * (4.67 + pLower);
          r = pLower * (6.73 + pLower * (6.66 + pLower));
          pLower -= (1.0 - exp(((log1mpLower + lga) + 0.5 * pLower) + (a - 1.0) *
                               0.693147180559945) * r / p1) / ((-0.5 + (4.67 +
            2.0 * pLower) / p1) - (6.73 + pLower * (13.32 + 3.0 * pLower)) / r);
          if (fabs(oldz - pLower) < 0.01 * pLower) {
            exitg2 = true;
          } else {
            i++;
          }
        }
      } else {
        if (pLower <= 0.0) {
          if (pLower == 0.0) {
            rval = rtMinusInf;
          } else {
            rval = rtNaN;
          }
        } else if (pLower >= 1.0) {
          if (pLower == 1.0) {
            rval = rtInf;
          } else {
            rval = rtNaN;
          }
        } else if (fabs(pLower - 0.5) <= 0.425) {
          r = 0.180625 - (pLower - 0.5) * (pLower - 0.5);
          rval = (pLower - 0.5) * (((((((2509.0809287301227 * r +
            33430.575583588128) * r + 67265.7709270087) * r + 45921.95393154987)
            * r + 13731.693765509461) * r + 1971.5909503065513) * r +
            133.14166789178438) * r + 3.3871328727963665) /
            (((((((5226.4952788528544 * r + 28729.085735721943) * r +
                  39307.895800092709) * r + 21213.794301586597) * r +
                5394.1960214247511) * r + 687.18700749205789) * r +
              42.313330701600911) * r + 1.0);
        } else {
          if (pLower - 0.5 < 0.0) {
            r = sqrt(-log(pLower));
          } else {
            r = sqrt(-log(1.0 - pLower));
          }

          if (r <= 5.0) {
            r -= 1.6;
            rval = (((((((0.00077454501427834139 * r + 0.022723844989269184) * r
                         + 0.24178072517745061) * r + 1.2704582524523684) * r +
                       3.6478483247632045) * r + 5.769497221460691) * r +
                     4.6303378461565456) * r + 1.4234371107496835) /
              (((((((1.0507500716444169E-9 * r + 0.00054759380849953455) * r +
                    0.015198666563616457) * r + 0.14810397642748008) * r +
                  0.6897673349851) * r + 1.6763848301838038) * r +
                2.053191626637759) * r + 1.0);
          } else {
            r -= 5.0;
            rval = (((((((2.0103343992922881E-7 * r + 2.7115555687434876E-5) * r
                         + 0.0012426609473880784) * r + 0.026532189526576124) *
                       r + 0.29656057182850487) * r + 1.7848265399172913) * r +
                     5.4637849111641144) * r + 6.6579046435011033) /
              (((((((2.0442631033899397E-15 * r + 1.4215117583164459E-7) * r +
                    1.8463183175100548E-5) * r + 0.00078686913114561329) * r +
                  0.014875361290850615) * r + 0.13692988092273581) * r +
                0.599832206555888) * r + 1.0);
          }

          if (pLower - 0.5 < 0.0) {
            rval = -rval;
          }
        }

        p1 = 0.222222 / nu;
        pLower = (rval * sqrt(p1) + 1.0) - p1;
        pLower *= nu * pLower * pLower;
        if (pLower > 2.2 * nu + 6.0) {
          pLower = -2.0 * ((log1mpLower - (a - 1.0) * log(0.5 * pLower)) + lga);
        }
      }

      rval = 0.5 * pLower;
      r = rtInf;
      oldz = rtInf;
      if (p > 1.0021E-294) {
        pLower = 2.2204460492503131E-14 * p;
      } else {
        pLower = 2.2251089859537388E-308;
      }

      if (upper) {
        sgn = -1;
      } else {
        sgn = 1;
      }

      nu = 0.0;
      p1 = 1.7976931348623157E+308;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (1000 > i)) {
        log1mpLower = (double)sgn * (b_eml_gammainc(rval, a, la, lgap1, upper) -
          p);
        if ((log1mpLower * r < 0.0) && (fabs(r) <= fabs(log1mpLower))) {
          rval = 0.5 * rval + 0.5 * oldz;
          log1mpLower = (double)sgn * (b_eml_gammainc(rval, a, la, lgap1, upper)
            - p);
        }

        if (log1mpLower > 0.0) {
          p1 = rval;
        } else {
          nu = rval;
        }

        if ((fabs(log1mpLower) < pLower) || (fabs(rval - oldz) <
             2.2204460492503131E-16 * rval + 2.2250738585072014E-308)) {
          exitg1 = true;
        } else {
          oldz = rval;
          r = log1mpLower;
          guard1 = false;
          guard2 = false;
          if (i < 500) {
            rval *= 1.0 - log1mpLower / (rval * exp(((a - 1.0) * log(rval) -
              rval) - lga) + log1mpLower * ((rval + 1.0) - a) / 2.0);
            if (rval <= nu) {
              if (nu == 0.0) {
                if (fabs((double)upper - p) < fabs(b_eml_gammainc
                     (2.2250738585072014E-308, a, la, lgap1, upper) - p)) {
                  rval = 0.0;
                  exitg1 = true;
                } else {
                  nu = 2.2250738585072014E-308;
                  guard2 = true;
                }
              } else {
                guard2 = true;
              }
            } else {
              if (rval >= p1) {
                rval = 0.01 * nu + 0.99 * p1;
              }

              guard1 = true;
            }
          } else {
            if (1.0E+8 * nu < p1) {
              oldz = 1.0E+8 * nu;
              r = (double)sgn * (b_eml_gammainc(oldz, a, la, lgap1, upper) - p);
              if (r > 0.0) {
                p1 = oldz;
              } else {
                nu = oldz;
              }
            }

            rval = 0.5 * nu + 0.5 * p1;
            guard1 = true;
          }

          if (guard2) {
            rval = 0.99 * nu + 0.01 * p1;
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
 * File trailer for gammaincinv.c
 *
 * [EOF]
 */
