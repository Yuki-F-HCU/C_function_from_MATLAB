/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rand.c
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
#include "rand.h"
#include "randn.h"
#include "CHI2CDF_data.h"

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
 * File trailer for rand.c
 *
 * [EOF]
 */
