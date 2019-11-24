#include "BI_Structure.h"

BigInteger BI_Shr(BigInteger bi, int shift) {
	if (shift == 0) return bi;
	if (shift >= 64) return BI_Create(0, bi.MSBs >> (shift - 64));
	if (shift >= 128) return BI_Create(0, 0);
	return BI_Create(bi.MSBs >> shift, (bi.LSBs >> shift) | ((bi.MSBs & ((1 << (shift - 1)) - 1)) << shift));
}

BigInteger BI_Shl(BigInteger bi, int shift) {
	if (shift == 0) return bi;
	if (shift >= 64) return BI_Create(bi.LSBs << (shift - 64), 0);
	if (shift >= 128) return BI_Create(0, 0);
	return BI_Create(bi.MSBs << shift | ((bi.LSBs >> (64 - shift)) & ((1 << (shift)) - 1)), bi.LSBs << shift);
}

BigInteger BI_Not(BigInteger bi) {
	return BI_Create(~bi.MSBs, ~bi.LSBs);
}

BigInteger BI_Or(BigInteger bi1, BigInteger bi2) {
	return BI_Create(bi1.MSBs | bi2.MSBs, bi1.LSBs | bi2.LSBs);
}

BigInteger BI_And(BigInteger bi1, BigInteger bi2) {
	return BI_Create(bi1.MSBs & bi2.MSBs, bi1.LSBs & bi2.LSBs);
}

BigInteger BI_Xor(BigInteger bi1, BigInteger bi2) {
	return BI_Create(bi1.MSBs ^ bi2.MSBs, bi1.LSBs ^ bi2.LSBs);
}
