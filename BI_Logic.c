#include "BI_Structure.h"
#include "BI_BasicOps.h"
#include "BI_Logic.h"

int BI_Sign(BigInteger bi) {
	return (bi.MSBs >> 63) & 1;
}

int BI_IsZero(BigInteger bi) {
	return (bi.LSBs == 0) && (bi.MSBs == 0);
}

int BI_Eq(BigInteger bi1, BigInteger bi2) {
	BigInteger diff = BI_Sub(bi1, bi2);
	return BI_IsZero(diff);
}

int BI_NotEq(BigInteger bi1, BigInteger bi2) {
	return !BI_Eq(bi1, bi2);
}

int BI_Greater(BigInteger bi1, BigInteger bi2) {
	if (BI_Sign(bi1) && BI_Sign(bi2)) return BI_Less(BI_Neg(bi1), BI_Neg(bi2));
	if (BI_Sign(bi1)) return 0;
	if (BI_Sign(bi2)) return 1;
	BigInteger diff = BI_Sub(bi1, bi2);
	return !BI_Sign(diff) && !BI_IsZero(diff);
}

int BI_GreaterEq(BigInteger bi1, BigInteger bi2) {
	if (BI_Sign(bi1) && BI_Sign(bi2)) return BI_LessEq(BI_Neg(bi1), BI_Neg(bi2));
	if (BI_Sign(bi1)) return 0;
	if (BI_Sign(bi2)) return 1;
	BigInteger diff = BI_Sub(bi1, bi2);
	return !BI_Sign(diff);
}

int BI_Less(BigInteger bi1, BigInteger bi2) {
	if (BI_Sign(bi1) && BI_Sign(bi2)) return BI_Less(BI_Neg(bi1), BI_Neg(bi2));
	if (BI_Sign(bi1)) return 1;
	if (BI_Sign(bi2)) return 0;
	BigInteger diff = BI_Sub(bi1, bi2);
	return BI_Sign(diff);
}

int BI_LessEq(BigInteger bi1, BigInteger bi2) {
	if (BI_Sign(bi1) && BI_Sign(bi2)) return BI_GreaterEq(BI_Neg(bi1), BI_Neg(bi2));
	if (BI_Sign(bi1)) return 1;
	if (BI_Sign(bi2)) return 0;
	BigInteger diff = BI_Sub(bi1, bi2);
	return BI_Sign(diff) || BI_IsZero(diff);
}

int BI_Above(BigInteger bi1, BigInteger bi2) {
	BigInteger diff = BI_Sub(bi1, bi2);
	return !BI_Sign(diff) && !BI_IsZero(diff);
}

int BI_AboveEq(BigInteger bi1, BigInteger bi2) {
	BigInteger diff = BI_Sub(bi1, bi2);
	return !BI_Sign(diff);
}

int BI_Below(BigInteger bi1, BigInteger bi2) {
	BigInteger diff = BI_Sub(bi1, bi2);
	return BI_Sign(diff);
}

int BI_BelowEq(BigInteger bi1, BigInteger bi2) {
	BigInteger diff = BI_Sub(bi1, bi2);
	return BI_Sign(diff) || BI_IsZero(diff);
}
