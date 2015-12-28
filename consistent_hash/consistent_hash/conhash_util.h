#ifndef conhash_util_INCLUDED
#define conhash_util_INCLUDED

#include "md5.h"
#include <string.h>
#include <stdio.h>
#include "conhash.h"

void conhash_md5_digest(const unsigned char *instr, unsigned char digest[16]);

#endif