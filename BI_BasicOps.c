#include "BI_BasicOps.h"

BigInteger BI_Add(BigInteger bi1, BigInteger bi2) {
	uint64 lsbRes = 0;
	uint64 lsbCarry = 0;
	
	for (int i = 0; i < 64; i++) {
		int a = (bi1.LSBs >> i) & 1;
		int b = (bi2.LSBs >> i) & 1;	
		lsbRes |= ((a ^ b ^ lsbCarry) << i);
		lsbCarry = ((a & b) | ((a ^ b) & lsbCarry));
	}

	uint64 msbRes = 0;
	uint64 msbCarry = lsbCarry;
	
	for (int i = 0; i < 64; i++) {
		int a = (bi1.MSBs >> i) & 1;
		int b = (bi2.MSBs >> i) & 1;	
		msbRes |= ((a ^ b ^ msbCarry) << i);
		msbCarry = ((a & b) | ((a ^ b) & msbCarry));
	}

	BigInteger res = BI_Create(msbRes, lsbRes);
	return res;
}

BigInteger BI_Neg(BigInteger bi) {
	BigInteger neg = {~bi.LSBs, ~bi.MSBs};
	return BI_Add(neg, BI_Create(0, 1));
}

BigInteger BI_Sub(BigInteger bi1, BigInteger bi2) {
	return BI_Add(bi1, BI_Neg(bi2));
}
