#ident "$Id$"
/* ----------------------------------------------------------------------- *
 *   
 *   Copyright 2004 H. Peter Anvin - All Rights Reserved
 *
 *   Permission is hereby granted, free of charge, to any person
 *   obtaining a copy of this software and associated documentation
 *   files (the "Software"), to deal in the Software without
 *   restriction, including without limitation the rights to use,
 *   copy, modify, merge, publish, distribute, sublicense, and/or
 *   sell copies of the Software, and to permit persons to whom
 *   the Software is furnished to do so, subject to the following
 *   conditions:
 *   
 *   The above copyright notice and this permission notice shall
 *   be included in all copies or substantial portions of the Software.
 *   
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 *
 * ----------------------------------------------------------------------- */

/*
 * stdcon.c
 *
 * Default console
 */

#include <errno.h>
#include <string.h>
#include <com32.h>
#include <minmax.h>
#include <fcntl.h>
#include <console.h>
#include "file.h"

extern ssize_t __stdcon_read(struct file_info *, void *, size_t);
extern ssize_t __stdcon_write(struct file_info *, const void *, size_t);

const struct dev_info dev_stdcon = {
  .dev_magic  = __DEV_MAGIC,
  .flags      = __DEV_TTY,
  .fileflags  = O_RDWR|O_CREAT|O_TRUNC|O_APPEND,
  .read       = __stdcon_read,
  .write      = __stdcon_write,
  .close      = NULL,
};
