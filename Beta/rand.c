/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rand.c
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
#include "rand.h"
#include "BETACDF_data.h"

/* Function Declarations */
static double eml_rand_mcg16807(unsigned int *e_state);
static double eml_rand_mt19937ar(unsigned int e_state[625]);

/* Function Definitions */

/*
 * Arguments    : unsigned int *e_state
 * Return Type  : double
 */
static double eml_rand_mcg16807(unsigned int *e_state)
{
  int hi;
  unsigned int test1;
  unsigned int test2;
  hi = (int)(*e_state / 127773U);
  test1 = 16807U * (*e_state - hi * 127773U);
  test2 = 2836U * hi;
  if (test1 < test2) {
    *e_state = (test1 - test2) + 2147483647U;
  } else {
    *e_state = test1 - test2;
  }

  return (double)*e_state * 4.6566128752457969E-10;
}

/*
 * Arguments    : unsigned int e_state[625]
 * Return Type  : double
 */
static double eml_rand_mt19937ar(unsigned int e_state[625])
{
  double r;
  int exitg1;
  unsigned int u[2];

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    exitg1 = 0;
    genrand_uint32_vector(e_state, u);
    r = 1.1102230246251565E-16 * ((double)(u[0] >> 5U) * 6.7108864E+7 + (double)
      (u[1] >> 6U));
    if (r == 0.0) {
      if (!is_valid_state(e_state)) {
        twister_state_vector(e_state, 5489U);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return r;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
double b_rand(void)
{
  double r;
  unsigned int u0;
  unsigned int u1;
  if (method == 4U) {
    r = eml_rand_mcg16807(&state);
  } else if (method == 5U) {
    u0 = 69069U * b_state[0] + 1234567U;
    u1 = b_state[1] ^ b_state[1] << 13;
    u1 ^= u1 >> 17;
    u1 ^= u1 << 5;
    b_state[0] = u0;
    b_state[1] = u1;
    r = (double)(u0 + u1) * 2.328306436538696E-10;
  } else {
    if (!state_not_empty) {
      memset(&c_state[0], 0, 625U * sizeof(unsigned int));
      twister_state_vector(c_state, 5489U);
      state_not_empty = true;
    }

    r = eml_rand_mt19937ar(c_state);
  }

  return r;
}

/*
 * Arguments    : double r[2]
 * Return Type  : void
 */
void c_rand(double r[2])
{
  int k;
  unsigned int u2;
  unsigned int u3;
  if (method == 4U) {
    for (k = 0; k < 2; k++) {
      r[k] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    for (k = 0; k < 2; k++) {
      u2 = 69069U * b_state[0] + 1234567U;
      u3 = b_state[1] ^ b_state[1] << 13;
      u3 ^= u3 >> 17;
      u3 ^= u3 << 5;
      b_state[0] = u2;
      b_state[1] = u3;
      r[k] = (double)(u2 + u3) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      memset(&c_state[0], 0, 625U * sizeof(unsigned int));
      twister_state_vector(c_state, 5489U);
      state_not_empty = true;
    }

    for (k = 0; k < 2; k++) {
      r[k] = eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 * Arguments    : unsigned int mt[625]
 *                unsigned int u[2]
 * Return Type  : void
 */
void genrand_uint32_vector(unsigned int mt[625], unsigned int u[2])
{
  int j;
  unsigned int mti;
  int kk;
  unsigned int y;
  unsigned int b_y;
  unsigned int c_y;
  unsigned int d_y;
  for (j = 0; j < 2; j++) {
    mti = mt[624] + 1U;
    if (mti >= 625U) {
      for (kk = 0; kk < 227; kk++) {
        y = (mt[kk] & 2147483648U) | (mt[1 + kk] & 2147483647U);
        if ((int)(y & 1U) == 0) {
          b_y = y >> 1U;
        } else {
          b_y = y >> 1U ^ 2567483615U;
        }

        mt[kk] = mt[397 + kk] ^ b_y;
      }

      for (kk = 0; kk < 396; kk++) {
        y = (mt[kk + 227] & 2147483648U) | (mt[228 + kk] & 2147483647U);
        if ((int)(y & 1U) == 0) {
          d_y = y >> 1U;
        } else {
          d_y = y >> 1U ^ 2567483615U;
        }

        mt[kk + 227] = mt[kk] ^ d_y;
      }

      y = (mt[623] & 2147483648U) | (mt[0] & 2147483647U);
      if ((int)(y & 1U) == 0) {
        c_y = y >> 1U;
      } else {
        c_y = y >> 1U ^ 2567483615U;
      }

      mt[623] = mt[396] ^ c_y;
      mti = 1U;
    }

    y = mt[(int)mti - 1];
    mt[624] = mti;
    y ^= y >> 11U;
    y ^= y << 7U & 2636928640U;
    y ^= y << 15U & 4022730752U;
    y ^= y >> 18U;
    u[j] = y;
  }
}

/*
 * Arguments    : const unsigned int mt[625]
 * Return Type  : boolean_T
 */
boolean_T is_valid_state(const unsigned int mt[625])
{
  boolean_T isvalid;
  int k;
  boolean_T exitg1;
  if ((mt[624] >= 1U) && (mt[624] < 625U)) {
    isvalid = true;
  } else {
    isvalid = false;
  }

  if (isvalid) {
    isvalid = false;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (k < 625)) {
      if (mt[k - 1] == 0U) {
        k++;
      } else {
        isvalid = true;
        exitg1 = true;
      }
    }
  }

  return isvalid;
}

/*
 * Arguments    : unsigned int mt[625]
 *                unsigned int seed
 * Return Type  : void
 */
void twister_state_vector(unsigned int mt[625], unsigned int seed)
{
  unsigned int r;
  int mti;
  r = seed;
  mt[0] = seed;
  for (mti = 0; mti < 623; mti++) {
    r = (r ^ r >> 30U) * 1812433253U + (1 + mti);
    mt[mti + 1] = r;
  }

  mt[624] = 624U;
}

/*
 * File trailer for rand.c
 *
 * [EOF]
 */
