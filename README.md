BigInteger library
==================

BigInteger struct
-----------------

The BigInteger struct has two `unsigned long long int` representing the Most Signifcant Bits and Least Significant Bits:

```c
typedef unsigned long long uint64;

struct BigInteger128_t {
	uint64 LSBs;
	uint64 MSBs;
}

typedef struct BigInteger128_t BigInteger;
```

BigInteger methods
------------------

This library has a variety of methods to perform various operations.

#### Mathematical operations

Function | Returns | Description
-------- | ------- | -----------
BI_Add(BigInteger bi1, BigInteger bi2) | BigInteger | Computes the sum of two BigIntegers
BI_Sub(BigInteger bi1, BigInteger bi2) | BigInteger | Computes the subtraction of two BigIntegers
BI_Mul(BigInteger bi1, BigInteger bi2) | BigInteger | Computes the product of two BigIntegers
BI_Div(BigInteger bi1, BigInteger bi2) | BigInteger* | Computes the division of two BigIntegers (returns an array of two BigIntegers containing, respectively, the quotient and the remaineder of the division)
BI_Neg(BigInteger bi) | BigInteger | Computes the two's complement of a BigInteger
BI_Pow(BigInteger base, BigInteger exp) | BigInteger | Computes the following power `base ^ exp`
BI_Mod(BigInteger bi1, BigInteger bi2) | BigInteger | Computes the modulo of two BigIntegers
Bi_PowM(BigInteger base, BigInteger exp, BigInteger M) | BigInteger | Computes `base ^ exp (mod M)`

#### Bitwise operations

Function | Returns | Description
-------- | ------- | -----------
BI_Not(BigInteger bi) | BigInteger | Computes `~bi`
BI_And(BigInteger bi1, BigInteger bi2) | BigInteger | Computes `bi1 & bi2`
BI_Or(BigInteger bi1, BigInteger bi2) | BigInteger | Computes `bi1 | bi2`
BI_Xor(BigInteger bi1, BigInteger bi2) | BigInteger | Computes `bi1 ^ bi2`
BI_Shr(BigInteger bi, int shift) | BigInteger | Computes `bi1 >> shift`
BI_Shl(BigInteger bi, int shift) | BigInteger | Computes `bi1 << shift`

#### Boolean and logical operations

Function | Returns | Description
-------- | ------- | -----------
BI_Sign(BigInteger bi) | BigInteger | Returns `1` if the BigInteger is negative otherwise `0`
BI_IsZero(BigInteger bi) | BigInteger | Returns `1` if the BigIntegre is equal to zero otherwise `0`
BI_Eq(BigInteger bi1, BigInteger bi2) | BigInteger | Returns `1` if the two BigIntegers are equal otherwise `0`
BI_Greater(BigInteger bi1, BigInteger bi2) | BigInteger | (signed) Returns `1` if the first BigInteger is greater than the other one otherwise `0`
BI_GreaterEq(BigInteger bi1, BigInteger bi2) | BigInteger | (signed) Returns `1` if the first BigInteger is greater or equal to the other one otherwise `0`
BI_Less(BigInteger bi1, BigInteger bi2) | BigInteger | (signed) Returns `1` if the first BigInteger is less than the other one otherwise `0`
BI_LessEq(BigInteger bi1, BigInteger bi2) | BigInteger | (signed) Returns `1` if the first BigInteger is smaller or equal to the other one otherwise `0`
BI_Above(BigInteger bi1, BigInteger bi2) | BigInteger | (unsigned) Returns `1` if the first BigInteger is greater than the other one otherwise `0`
BI_AboveEq(BigInteger bi1, BigInteger bi2) | BigInteger | (unsigned) Returns `1` if the first BigInteger is greater or equal to the other one otherwise `0`
BI_Below(BigInteger bi1, BigInteger bi2) | BigInteger | (unsigned) Returns `1` if the first BigInteger is less than the other one otherwise `0`
BI_BelowEq(BigInteger bi1, BigInteger bi2) | BigInteger | (unsigned) Returns `1` if the first BigInteger is smaller or equal to the other one otherwise `0`

#### I/O operations

Function | Returns | Description
-------- | ------- | -----------
BI_Create(BigInteger msbs, BigInteger lsbs) | BigInteger | Returns a BigInteger given the values of the Most Signifcant Bits and the Least Signifcant Bits
BI_UFromStr(char *str) | BigInteger | (unsigned) Creates a BigInteger given the decimal string representation of it
BI_FromStr(char *str) | BigInteger | (signed) Creates a BigInteger given the decimal string representation of it
BI_UToStrHex(BigInteger bi) | char* | (unsigned) Returns a string containing the hexadecimal representation of the BigInteger
BI_ToStrHex(BigInteger bi) | char* | (signed) Returns a string containing the hexadecimal representation of the BigInteger
BI_UToStr(BigInteger bi) | char* | (unsigned) Returns a string containing the decimal representation of the BigInteger
BI_ToStr(BigInteger bi) | char* | (signed) Returns a string containing the decimal representation of the BigInteger
BI_UPrintHex(BigInteger bi) | void | (unsigned) Prints the hexadecimal representation of the BigInteger
BI_PrintHex(BigInteger bi) | void | (signed) Prints the hexadecimal representation of the BigInteger
BI_UPrint(BigInteger bi) | void | (unsigned) Prints the decimal representation of the BigInteger
BI_Print(BigInteger bi) | void | (signed) Prints the decimal representation of the BigInteger