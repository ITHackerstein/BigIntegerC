#ifndef BI_STRUCTURE_LOGIC_HEADER
#define BI_STRUCTURE_LOGIC_HEADER
#include "BI_Structure.h"

extern int BI_Sign(BigInteger bi);
extern int BI_IsZero(BigInteger bi);
extern int BI_Eq(BigInteger bi1, BigInteger bi2);
extern int BI_Greater(BigInteger bi1, BigInteger bi2);
extern int BI_GreaterEq(BigInteger bi1, BigInteger bi2);
extern int BI_Less(BigInteger bi1, BigInteger bi2);
extern int BI_LessEq(BigInteger bi1, BigInteger bi2);
extern int BI_Above(BigInteger bi1, BigInteger bi2);
extern int BI_AboveEq(BigInteger bi1, BigInteger bi2);
extern int BI_Below(BigInteger bi1, BigInteger bi2);
extern int BI_BelowEq(BigInteger bi1, BigInteger bi2);

#endif
