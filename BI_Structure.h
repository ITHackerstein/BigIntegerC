#ifndef BI_STRUCTURE_HEADER
#define BI_STRUCTURE_HEADER

typedef unsigned long long int uint64;

struct BigInteger128_t {
	uint64 LSBs;
	uint64 MSBs;
};

typedef struct BigInteger128_t BigInteger;

extern BigInteger BI_Create(uint64 msbs, uint64 lsbs);

#endif
