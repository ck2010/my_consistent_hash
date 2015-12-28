#include "conhash_inter.h"

/*
* the default hash function, using md5 algorithm
* @instr: input string
*/
unsigned int __conhash_hash_def(const char *instr)
{
	int i;
	unsigned int hash = 0;
	unsigned char digest[16];
	conhash_md5_digest((const unsigned char*)instr, digest);

	/* use successive 4-bytes from hash as numbers */
	for (i = 0; i < 4; i++)
	{
		hash += ((unsigned int)(digest[i * 4 + 3] & 0xFF) << 24)
			| ((unsigned int)(digest[i * 4 + 2] & 0xFF) << 16)
			| ((unsigned int)(digest[i * 4 + 1] & 0xFF) << 8)
			| ((unsigned int)(digest[i * 4 + 0] & 0xFF));
	}
	return hash;
}