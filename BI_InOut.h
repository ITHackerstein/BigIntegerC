#ifndef BI_INOUT_HEADER
#define BI_INOUT_HEADER
#include "BI_Structure.h"

extern BigInteger BI_FromStr(char *str);
extern BigInteger BI_UFromStr(char *str);
extern char* BI_UToStrHex(BigInteger bi);
extern char* BI_ToStrHex(BigInteger bi);
extern char* BI_UToStr(BigInteger bi);
extern char* BI_ToStr(BigInteger bi);
extern void BI_UPrintHex(BigInteger bi);
extern void BI_PrintHex(BigInteger bi);
extern void BI_UPrint(BigInteger bi);
extern void BI_Print(BigInteger bi);

#endif
