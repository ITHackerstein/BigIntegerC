#include "BI_Structure.h"
#include "BI_BasicOps.h"
#include "BI_Logic.h"
#include "BI_BitwiseOps.h"
#include <stdlib.h>

BigInteger BI_Mul(BigInteger bi1, BigInteger bi2) {
	BigInteger res = BI_Create(0, 0);
	for (int i = 0; i < 128; i++) {
		if (BI_IsZero(BI_And(BI_Shr(bi2, i), BI_Create(0, 1)))) continue;
		res = BI_Add(res, BI_Shl(bi1, i));
	}
	return res;
}

BigInteger* BI_Div(BigInteger bi1, BigInteger bi2) {
	BigInteger Q = BI_Create(0, 0);
	BigInteger R = BI_Create(0, 0);
	for (int i = 127; i >= 0; i--) {
		R = BI_Shl(R, 1);
		R = BI_Or(R, BI_And(BI_Shr(bi1, i), BI_Create(0, 1)));
		if (BI_GreaterEq(R, bi2)) {
			R = BI_Sub(R, bi2);
			Q = BI_Or(Q, BI_Shl(BI_Create(0, 1), i));
		}
	}
	BigInteger *res = malloc(2 * sizeof(BigInteger));
	res[0] = Q;
	res[1] = R;
	return res;
}

BigInteger BI_Pow(BigInteger base, BigInteger exp) {
	BigInteger res = BI_Create(0, 1);
	while (!BI_IsZero(exp)) {
		if (!BI_IsZero(BI_And(exp, BI_Create(0, 1)))) res = BI_Mul(res, base);
		exp = BI_Shr(exp, 1);
		base = BI_Mul(base, base);	
	}
	return res;
}

BigInteger BI_Mod(BigInteger bi1, BigInteger bi2) {
	return BI_Div(bi1, bi2)[1];
}

BigInteger BI_PowM(BigInteger base, BigInteger exp, BigInteger M) {
	if (BI_Eq(M, BI_Create(0, 1))) return BI_Create(0, 0);
	BigInteger res = BI_Create(0, 1);
	while (!BI_IsZero(exp)) {
		if (!BI_IsZero(BI_And(exp, BI_Create(0, 1)))) res = BI_Mod(BI_Mul(res, base), M);
		exp = BI_Shr(exp, 1);
		base = BI_Mod(BI_Mul(base, base), M);
	}
	return res;
}
