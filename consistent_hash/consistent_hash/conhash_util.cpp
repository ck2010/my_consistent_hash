#include "conhash_util.h"

void conhash_md5_digest(const unsigned char *instr, unsigned char digest[16])
{
	md5_state_t md5state;

	md5_init(&md5state);
	md5_append(&md5state, instr, strlen((const char*)instr));
	md5_finish(&md5state, digest);
}
