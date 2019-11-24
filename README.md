BigInteger library
==================

BigInteger struct
-----------------

The BigInteger struct has two `unsigned long long int` representing the Most Signifcant Bits and Least Significant Bits:

```c
struct BigInteger128_t {
	uint64 LSBs;
	uint64 MSBs;
}

typedef struct BigInteger128_t BigInteger;
```
