#pragma once
#include<stdint.h>
typedef unsigned int u32;
typedef uint8_t u8;

u32 RotWord(u32 in);
u32 InvRotWord(u32 in);
u32 InvSubWord(u32 word);
void ShiftRow(u32 *in);
void InvShiftRow(u32 *in);
u8 Mul2(u8 in);
u8 Mul3(u8 in);
u8 Mul4(u8 in);
u8 Mul8(u8 in);
u8 Mul9(u8 in);
u8 Mulb(u8 in);
u8 Muld(u8 in);
u8 Mule(u8 in);
void MixColumn(u32 *in);
void InvMixColumn(u32 *in);
void AddRoundKey(u32 *in, u32 *w, int r);
void AES_Encryption(u32 *in, u32 *w, int round);
void AES_Decryption(u32 *in, u32 *w, int round);
void KeyExpansion(u32 * key, u32 * w, int N);
void XOR_State(u32 out[], u32 in[]);
void KeyRecovery128(u32 *w);

