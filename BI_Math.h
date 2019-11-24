#ifndef BI_MATH_HEADER
#define BI_MATH_HEADER
#include "BI_Structure.h"

extern BigInteger BI_Mul(BigInteger bi1, BigInteger bi2);
extern BigInteger* BI_Div(BigInteger bi1, BigInteger bi2);
extern BigInteger BI_Pow(BigInteger base, BigInteger exp);
extern BigInteger BI_Mod(BigInteger bi1, BigInteger bi2);
extern BigInteger BI_PowM(BigInteger base, BigInteger exp, BigInteger M);

#endif
