/*
   BLAKE reference C implementation

   Copyright (c) 2012 Jean-Philippe Aumasson <jeanphilippe.aumasson@gmail.com>

   To the extent possible under law, the author(s) have dedicated all copyright
   and related and neighboring rights to this software to the public domain
   worldwide. This software is distributed without any warranty.

   You should have received a copy of the CC0 Public Domain Dedication along with
   this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 */
#ifndef BLAKE_H
#define BLAKE_H
#include "Common/Tcdefs.h"

#include <string.h>
#include <stdio.h>
#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct
{
  uint64_t h[8], s[4], t[2];
  int buflen, nullt;
  uint8_t buf[128];
} state512;

typedef state512 state384;

  /* Streaming API */
  void blake512_init( state512 *S );
  void blake512_update( state512 *S, const void *in, size_t inlen );
  void blake512_final( state512 *S, unsigned char *out );

  /* Simple API */
  void blake512( void *out, const void *in, size_t inlen );

#if defined(__cplusplus)
}
#endif

#endif