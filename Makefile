all:
	gcc -c -o BI_Structure.o BI_Structure.c
	gcc -c -o BI_BasicOps.o BI_BasicOps.c
	gcc -c -o BI_Logic.o BI_Logic.c
	gcc -c -o BI_BitwiseOps.o BI_BitwiseOps.c
	gcc -c -o BI_Math.o BI_Math.c
	gcc -c -o BI_InOut.o BI_InOut.c
	# To compile a program with the previous libraries change the following lines and uncomment them.
	# gcc -c /path/to/src.c -o /path/to/out.o
	# gcc BI_Structure.o BI_BasicOps.o BI_Logic.o BI_BitwiseOps.o BI_Math.o BI_InOut.o /path/to/out.o -o /path/to/out
