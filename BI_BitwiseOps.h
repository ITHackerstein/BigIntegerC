#ifndef BI_BITWISE_HEADER
#define BI_BITWISE_HEADER
#include "BI_Structure.h"

extern BigInteger BI_Shr(BigInteger bi, int shift);
extern BigInteger BI_Shl(BigInteger bi, int shift);
extern BigInteger BI_Not(BigInteger bi);
extern BigInteger BI_And(BigInteger bi1, BigInteger bi2);
extern BigInteger BI_Or(BigInteger bi1, BigInteger bi2);
extern BigInteger BI_Xor(BigInteger bi1, BigInteger bi2);

#endif
