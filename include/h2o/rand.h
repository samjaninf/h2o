/*
 * Copyright (c) 2016 David Carlier
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#ifndef h2o__rand_h
#define h2o__rand_h

#include <stdlib.h>
#include <unistd.h>

/**
 * srand is a no-op
 */
#define h2o_srand()
/**
 * Wrapper of rand (3) or arc4random (3). Guaranteed to be multi-thread safe.
 */
#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
#define H2O_RAND_MAX UINT32_MAX
#define h2o_rand() arc4random()
#else
#define H2O_RAND_MAX RAND_MAX
#define H2O_DEFINE_RAND 1
int h2o_rand(void);
#endif

/*
 * size of a UUID string representation.
 */
#define H2O_UUID_STR_RFC4122_LEN (sizeof("01234567-0123-4000-8000-0123456789ab") - 1)

/**
 * generates and sets a UUIDv4 to dst, which must have an enough size, H2O_UUID_STR_RFC4122_LEN + 1.
 */
void h2o_generate_uuidv4(char *dst);

#endif
