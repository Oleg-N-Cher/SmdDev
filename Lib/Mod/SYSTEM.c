#include "SYSTEM.oh"

/* runtime system routines */
extern int SYSTEM_STRCMP (CHAR *x, CHAR *y);
extern void SYSTEM_STRAPND (CHAR *from, CHAR *to) __z88dk_callee;
extern void SYSTEM_STRCOPY (CHAR *to, CHAR *from) __z88dk_callee;
extern SHORTINT SYSTEM_STRLEN (CHAR *str) __z88dk_fastcall;
extern long SYSTEM_ENTIER (float x);
extern SHORTINT SYSTEM_ASH (SHORTINT x, BYTE n);
extern INTEGER SYSTEM_ASHL (INTEGER x, BYTE n);
extern SYSTEM_PTR SYSTEM_NEWBLK (__U_SHORTINT size);

#define SYSTEM_malloc(size)	(SYSTEM_PTR)malloc(size)
/*================================== Header ==================================*/

/*--------------------------------- Cut here ---------------------------------*/
int SYSTEM_XCHK (int i, int ub) { return __X(i, ub, "", 0); }

/*--------------------------------- Cut here ---------------------------------*/
int SYSTEM_STRCMP (CHAR *x, CHAR *y)
{int i = 0; CHAR ch1, ch2;
	do {ch1 = x[i]; ch2 = y[i]; i++;
		if (!ch1) return -(int)ch2;
	} while (ch1==ch2);
	return (int)ch1 - (int)ch2;
}

/*--------------------------------- Cut here ---------------------------------*/
long SYSTEM_ENTIER (float x)
{
	if (x >= 0)
		return (long)x;
	else {
   	long y;
		y = (long)x;
		if (y <= x) return y; else return y - 1;
	}
}

/*--------------------------------- Cut here ---------------------------------*/
SHORTINT SYSTEM_ASH (SHORTINT x, BYTE n)
{
	if (n >= 0) return x << n;
	return x >> (-n);
} //SYSTEM_ASH

/*--------------------------------- Cut here ---------------------------------*/
INTEGER SYSTEM_ASHL (INTEGER x, BYTE n)
{
	if (n >= 0) return x << n;
	return x >> (-n);
} //SYSTEM_ASHL

/*--------------------------------- Cut here ---------------------------------*/
SHORTINT  SYSTEM_ABSS (SHORTINT x) { return __ABS(x); }
/*--------------------------------- Cut here ---------------------------------*/
INTEGER   SYSTEM_ABS  (INTEGER x)  { return __ABS(x); }
/*--------------------------------- Cut here ---------------------------------*/
LONGINT   SYSTEM_ABSL (LONGINT x)  { return __ABS(x); }
/*--------------------------------- Cut here ---------------------------------*/
SHORTREAL SYSTEM_ABSF (REAL x)     { return __ABS(x); }

/*--------------------------------- Cut here ---------------------------------*/
SHORTINT SYSTEM_DIVS (SHORTINT x, SHORTINT y)
{
  if (y > 0) {
    if (x < 0) return -1 - (-1 - x) / y;
    else       return x / y;
  }
  if (y < 0) {
    if (x > 0) return -1 + (x - 1) / y;
    else       return x / y;
  }
  __HALT(6, "SYSTEM.c", 133);
}

/*--------------------------------- Cut here ---------------------------------*/
INTEGER SYSTEM_DIV (INTEGER x, INTEGER y)
{
  if (y > 0) {
    if (x < 0) return -1 - (-1 - x) / y;
    else       return x / y;
  }
  if (y < 0) {
    if (x > 0) return -1 + (x - 1) / y;
    else       return x / y;
  }
  __HALT(6, "SYSTEM.c", 148);
}

/*--------------------------------- Cut here ---------------------------------*/
LONGINT SYSTEM_DIVL (LONGINT x, LONGINT y)
{
  if (y > 0) {
    if (x < 0) return -1 - (-1 - x) / y;
    else       return x / y;
  }
  if (y < 0) {
    if (x > 0) return -1 + (x - 1) / y;
    else       return x / y;
  }
  __HALT(6, "SYSTEM.c", 161);
}

/*--------------------------------- Cut here ---------------------------------*/
SHORTINT SYSTEM_MODS (SHORTINT x, SHORTINT y)
{
  if (y > 0) {
    if (x < 0) return y - 1 + (x + 1) % y;
    else       return x % y;
  }
  if (y < 0) {
    if (x > 0) return y + 1 + (x - 1) % y;
    else       return x % y;
  }
  __HALT(6, "SYSTEM.c", 175);
}

/*--------------------------------- Cut here ---------------------------------*/
INTEGER SYSTEM_MOD (INTEGER x, INTEGER y)
{
  if (y > 0) {
    if (x < 0) return y - 1 + (x + 1) % y;
    else       return x % y;
  }
  if (y < 0) {
    if (x > 0) return y + 1 + (x - 1) % y;
    else       return x % y;
  }
  __HALT(6, "SYSTEM.c", 189);
}

/*--------------------------------- Cut here ---------------------------------*/
LONGINT SYSTEM_MODL (LONGINT x, LONGINT y)
{
  if (y > 0) {
    if (x < 0) return y - 1 + (x + 1) % y;
    else       return x % y;
  }
  if (y < 0) {
    if (x > 0) return y + 1 + (x - 1) % y;
    else       return x % y;
  }
  __HALT(6, "SYSTEM.c", 203);
}

/*--------------------------------- Cut here ---------------------------------*/
SHORTINT SYSTEM_MINS (SHORTINT x, SHORTINT y) { return __MIN(x, y); }
/*--------------------------------- Cut here ---------------------------------*/
INTEGER SYSTEM_MIN (INTEGER x, INTEGER y)     { return __MIN(x, y); }
/*--------------------------------- Cut here ---------------------------------*/
LONGINT SYSTEM_MINL (LONGINT x, LONGINT y)    { return __MIN(x, y); }
/*--------------------------------- Cut here ---------------------------------*/
SHORTREAL SYSTEM_MINF (REAL x, REAL y)        { return __MIN(x, y); }
/*--------------------------------- Cut here ---------------------------------*/

SHORTINT SYSTEM_MAXS (SHORTINT x, SHORTINT y) { return __MAX(x, y); }
/*--------------------------------- Cut here ---------------------------------*/
INTEGER SYSTEM_MAX (INTEGER x, INTEGER y)     { return __MAX(x, y); }
/*--------------------------------- Cut here ---------------------------------*/
LONGINT SYSTEM_MAXL (LONGINT x, LONGINT y)    { return __MAX(x, y); }
/*--------------------------------- Cut here ---------------------------------*/
SHORTREAL SYSTEM_MAXF (REAL x, REAL y)        { return __MAX(x, y); }

/*--------------------------------- Cut here ---------------------------------*/
SYSTEM_PTR SYSTEM_NEWBLK (__U_SHORTINT size)
{
  SYSTEM_PTR mem = SYSTEM_malloc(size);
//  __ASSERT(mem != NIL, 0xFF);
  return mem;
}

/*--------------------------------- Cut here ---------------------------------*/
/*
#define _DYNARRAY struct {
  SHORTINT len[1]; // Length of allocated memory: LEN()
  CHAR data[1];   // Array data
} */
SYSTEM_PTR SYSTEM_NEWARR (__U_SHORTINT size)
{
  SYSTEM_PTR arrPtr = SYSTEM_NEWBLK(sizeof(INTEGER) + size);
  *((SHORTINT*)arrPtr) = size;
  return arrPtr;
}
