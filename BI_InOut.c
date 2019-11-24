#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BI_Structure.h"
#include "BI_BasicOps.h"
#include "BI_Logic.h"
#include "BI_BitwiseOps.h"
#include "BI_Math.h"

void BI_UPrintHex(BigInteger bi) {
	printf("0x%016llx%016llx", bi.MSBs, bi.LSBs);
}

void BI_PrintHex(BigInteger bi) {
	if (BI_Sign(bi)) {
		BigInteger abs = BI_Neg(bi);
		printf("-0x%016llx%016llx", abs.MSBs, abs.LSBs);
	} else {
		BI_UPrintHex(bi);
	}
}

void BI_UPrint(BigInteger bi) {
	if (BI_IsZero(bi)) printf("0");
	char revDigits[39];
	int i = 0;
	while (!BI_IsZero(bi)) {
		BigInteger *res = BI_Div(bi, BI_Create(0, 10));
		BigInteger rem = res[1];
		revDigits[i++] = (char) (rem.LSBs + 0x30);
		bi = res[0];
	}
	char digits[i];
	for (int j = 0; j < i; j++) digits[j] = revDigits[i - j - 1];
	digits[i] = '\0';
	printf("%s", digits);
}

void BI_Print(BigInteger bi) {
	if (BI_IsZero(bi)) printf("0");
	if (!BI_Sign(bi)) BI_UPrint(bi);
	else {
		bi = BI_Neg(bi);
		printf("-");
		BI_UPrint(bi);
	}
}

BigInteger BI_FromStr(char *str) {
	BigInteger res = BI_Create(0, 0);
	BigInteger curPow = BI_Create(0, 1);
	BigInteger max = BI_Create(0x7fffffffffffffff, 0xffffffffffffffff);

	for (int i = strlen(str) - 1; i >= (str[0] == '-'); i--) {
		if (str[i] < 0x30 || str[i] > 0x39) {
			fprintf(stderr, "Invalid digit. (Allowed digits: 0-9)\n");
			exit(1);
		}

		BigInteger pos = BI_Create(0, (uint64) (str[i] - 0x30));
		pos = BI_Mul(pos, curPow);
		res = BI_Add(res, pos);
		BigInteger newMax = BI_Sub(max, pos);
		if (BI_Above(newMax, max)) {
			fprintf(stderr, "Too large number! (Min: -2^127 + 1 = -170141183460469231731687303715884105727, Max: 2^127 - 1 = 170141183460469231731687303715884105727)\n");
			exit(1);
		}
		max = newMax;
		curPow = BI_Mul(curPow, BI_Create(0, 10));
	}

	if (str[0] == '-') res = BI_Neg(res);

	return res;
}

BigInteger BI_UFromStr(char *str) {
	BigInteger res = BI_Create(0, 0);
	BigInteger curPow = BI_Create(0, 1);
	BigInteger max = BI_Create(0xffffffffffffffff, 0xffffffffffffffff);
	
	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (str[i] < 0x30 || str[i] > 0x39) {
			fprintf(stderr, "Invalid digit. (Allowed digits: 0-9)\n");
			exit(1);
		}

		BigInteger pos = BI_Create(0, (uint64) (str[i] - 0x30));
		pos = BI_Mul(pos, curPow);
		res = BI_Add(res, pos);
		BigInteger newMax = BI_Sub(max, pos);
		if (BI_Above(newMax, max)) {
			fprintf(stderr, "Too large number! (Min: 0, Max: 2^128 - 1 = 340282366920938463463374607431768211455)\n");
			exit(1);
		}
		max = newMax;
		curPow = BI_Mul(curPow, BI_Create(0, 10));
	}	
	
	return res;
}

char* BI_UToStrHex(BigInteger bi) {
	char* hex = malloc(35);
	sprintf(hex, "0x%016llx%016llx", bi.MSBs, bi.LSBs);
	return hex;
}

char* BI_ToStrHex(BigInteger bi) {
	char* hex = malloc(36);
	if (BI_Sign(bi))
		sprintf(hex, "0x%016llx%016llx", bi.MSBs, bi.LSBs);
	else {
		BigInteger neg = BI_Neg(bi);
		sprintf(hex, "-0x%016llx%016llx", neg.MSBs, neg.LSBs);
	}
	return hex;
}

char* BI_UToStr(BigInteger bi) {
	char* revDigits = malloc(40);
	int i = 0;
	do {
		BigInteger *divRes = BI_Div(bi, BI_Create(0, 10));
		bi = divRes[0];
		revDigits[i++] = (char) (divRes[1].LSBs + 0x30);
	} while(!BI_IsZero(bi));
	char* digits = malloc(40);
	for (int j = 0; j < i; j++) digits[j] = revDigits[i - j - 1];
	digits[i] = '\0';
	return digits;
}

char* BI_ToStr(BigInteger bi) {
	char* revDigits = malloc(40);
	if (!BI_Sign(bi)) return BI_UToStr(bi);
	BigInteger abs = BI_Neg(bi);
	int i = 0;
	do {
		BigInteger *divRes = BI_Div(abs, BI_Create(0, 10));
		abs = divRes[0];
		revDigits[i++] = (char) (divRes[1].LSBs + 0x30);
	} while(!BI_IsZero(abs));
	revDigits[i++] = '-';
	char* digits = malloc(40);
	for (int j = 0; j < i; j++) digits[j] = revDigits[i - j - 1];
	digits[i] = '\0';
	return digits;
}
