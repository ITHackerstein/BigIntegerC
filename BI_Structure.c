#include "BI_Structure.h"

BigInteger BI_Create(uint64 msbs, uint64 lsbs) {
	BigInteger bi = {lsbs, msbs};
	return bi;
}
