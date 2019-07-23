#include "MyAES.h"
#include<stdio.h>
int main() {
	/* ---------------------------- Manual --------------------------
	l		KeyExpansion(key, w, KeyWordSize=4,6,8)				    l
	l		AES_Encryption(Plantext, w, rounds=10,12,14)			l
	------------------------------------------------------------------*/

	printf("D");

	u32 key[4] = { 0x2b7e1516, 0x28aed2a6, 0xabf71588, 0x09cf4f3c }; //128bit test key
	u32 w[60];
	u32 P[4] = { 0x4FEC6E2F, 0xE7FA701C, 0x42689843, 0x9AB6381E };

	KeyExpansion(key, w, 4); // 4: AES128
	AES_Encryption(P, w, 10);

	printf("%x %x %x %x", P[0], P[1], P[2], P[3]);
	return 0;
}