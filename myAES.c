#pragma once
#include "MyAES.h"

const u32 RCon[10] = { 0x01000000, 0x02000000, 0x04000000, 0x08000000,
0x10000000, 0x20000000, 0x40000000, 0x80000000,
0x1B000000, 0x36000000
};

unsigned char s[256] =
{
	0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
	0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
	0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
	0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
	0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
	0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
	0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
	0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
	0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
	0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
	0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
	0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
	0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
	0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
	0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
	0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
};

unsigned char inv_s[256] =
{
	0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
	0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
	0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
	0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
	0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
	0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
	0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
	0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
	0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
	0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
	0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
	0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
	0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
	0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
	0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
	0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D
};


u32 RotWord(u32 in) {
	u8 k = in >> 24;
	in = (in << 8) + k;
	return in;
}

u32 InvRotWord(u32 in) {
	u8 k = in & 0xff;
	in = (in >> 8) | (k << 24);
}
u32 SubWord(u32 word) {
	u32 result;

	result = ((s[word >> 24]) << 24) | (s[(u8)(word >> 16)] << 16) | (s[(u8)(word >> 8)] << 8)
		| (s[(u8)(word)]);
	return result;
}

u32 InvSubWord(u32 word) {
	u32 result;

	result = ((inv_s[word >> 24]) << 24) | (inv_s[(u8)(word >> 16)] << 16) | (inv_s[(u8)(word >> 8)] << 8)
		| (inv_s[(u8)(word)]);
	return result;
}

void ShiftRow(u32 *in) {
	u32 out[4];
	for (int i = 0; i<4; i++)
		out[i] = (in[i % 4] & 0xFF000000) | in[(i + 1) % 4] & 0x00FF0000 | in[(i + 2) % 4] & 0x0000FF00 | in[(i + 3) % 4] & 0x000000FF;
	for (int i = 0; i < 4; i++) in[i] = out[i];
}

void InvShiftRow(u32 *in) {
	u32 out[4];
	for (int i = 0; i<4; i++)
		out[i] = (in[i % 4] & 0xFF000000) | in[(i + 3) % 4] & 0x00FF0000 | in[(i + 2) % 4] & 0x0000FF00 | in[(i + 1) % 4] & 0x000000FF;
	for (int i = 0; i < 4; i++) in[i] = out[i];
}

u8 Mul2(u8 in) {
	return ((in << 1) & 0xFF) ^ ((in & 0x80) ? 0x1b : 0);
}

u8 Mul3(u8 in) {
	return Mul2(in) ^ in;
}

u8 Mul4(u8 in) {
	return Mul2(Mul2(in));
}
u8 Mul8(u8 in) {
	return Mul4(Mul2(in));
}

u8 Mul9(u8 in) {
	return Mul8(in) ^ in;
}

u8 Mulb(u8 in) {
	return Mul8(in) ^ Mul2(in) ^ in;
}
u8 Muld(u8 in) {
	return Mul8(in) ^ Mul4(in) ^ in;
}
u8 Mule(u8 in) {
	return Mul8(in) ^ Mul4(in) ^ Mul2(in);
}

void MixColumn(u32 *in) {
	u32 out[4];
	for (int i = 0; i < 4; i++)
		out[i] = (Mul2((in[i] >> 24)) ^ Mul3(((in[i] >> 16) & 0xFF)) ^ ((in[i] >> 8) & 0xFF) ^ (in[i] & 0xFF)) << 24 |
		((in[i] >> 24) ^ Mul2((in[i] >> 16) & 0xFF) ^ Mul3(((in[i] >> 8) & 0xFF)) ^ (in[i] & 0xFF)) << 16 |
		((in[i] >> 24) ^ ((in[i] >> 16) & 0xFF) ^ Mul2(((in[i] >> 8) & 0xFF)) ^ Mul3((in[i] & 0xFF))) << 8 |
		Mul3((in[i] >> 24)) ^ ((in[i] >> 16) & 0xFF) ^ ((in[i] >> 8) & 0xFF) ^ Mul2((in[i] & 0xFF));
	for (int i = 0; i < 4; i++) in[i] = out[i];
}

void InvMixColumn(u32 *in) {
	u32 out[4];
	for (int i = 0; i < 4; i++)
		out[i] = (Mule((in[i] >> 24)) ^ Mulb(((in[i] >> 16) & 0xFF)) ^ Muld((in[i] >> 8) & 0xFF) ^ Mul9(in[i] & 0xFF)) << 24 |
		(Mul9(in[i] >> 24) ^ Mule((in[i] >> 16) & 0xFF) ^ Mulb(((in[i] >> 8) & 0xFF)) ^ Muld(in[i] & 0xFF)) << 16 |
		(Muld(in[i] >> 24) ^ Mul9((in[i] >> 16) & 0xFF) ^ Mule(((in[i] >> 8) & 0xFF)) ^ Mulb((in[i] & 0xFF))) << 8 |
		Mulb((in[i] >> 24)) ^ Muld((in[i] >> 16) & 0xFF) ^ Mul9((in[i] >> 8) & 0xFF) ^ Mule((in[i] & 0xFF));
	for (int i = 0; i < 4; i++) in[i] = out[i];
}
void AddRoundKey(u32 *in, u32 *w, int r) {
	in[0] ^= w[4 * r];
	in[1] ^= w[4 * r + 1];
	in[2] ^= w[4 * r + 2];
	in[3] ^= w[4 * r + 3];
}

void AES_Encryption(u32 *in, u32 *w, int round) {
	//Pre-Round
	AddRoundKey(in, w, 0);
	for (int r = 1; r < round; r++) {
		for (int i = 0; i < 4; i++) in[i] = SubWord(in[i]);	//SubBytes
		ShiftRow(in);									//ShiftRow
		MixColumn(in);									//MixColumn
		AddRoundKey(in, w, r);							//AddRoundKey
														//printf("%x %x %x %x\n", in[0], in[1], in[2], in[3]);
	}
	//Final Round 
	for (int i = 0; i < 4; i++) in[i] = SubWord(in[i]);	//SubBytes
	ShiftRow(in);									//ShiftRow
	AddRoundKey(in, w, round);							//AddRoundKey

}

void AES_Decryption(u32 *in, u32 *w, int round) {
	//Pre-Round
	AddRoundKey(in, w, round);
	for (int r = 1; r < round; r++) {
		InvShiftRow(in);
		for (int i = 0; i < 4; i++) in[i] = InvSubWord(in[i]);
		AddRoundKey(in, w, round - r);
		InvMixColumn(in);
	}

	InvShiftRow(in);
	for (int i = 0; i < 4; i++) in[i] = InvSubWord(in[i]);
	AddRoundKey(in, w, 0);
}

void KeyExpansion(u32 * key, u32 * w, int N) {

	u32 temp;

	for (int i = 0; i < N; i++)
		w[i] = key[i];
	for (int i = N; i < 4 * (N + 7); i++) {
		temp = w[i - 1];
		if (i % N == 0) {
			temp = SubWord(RotWord(temp));
			temp = temp ^ RCon[i / N - 1];
		}
		else if (N > 6 && i%N == 4)
			temp = SubWord(temp);
		w[i] = w[i - N] ^ temp;
	}
}

void XOR_State(u32 out[], u32 in[])
{
	u8 i;
	for (i = 0; i<16; ++i)	out[i] ^= in[i];
}

void KeyRecovery128(u32 *w) {
	//10Round 
	w[40] = 0xF2983F40;
	w[41] = 0x30EDF633;
	w[42] = 0x0491103F;
	w[43] = 0xD1B13FA1;
	unsigned int temp;
	for (int i = 39; i >= 0; i--) {
		if (i % 4 == 0) {
			temp = SubWord(RotWord(w[i + 3])) ^ RCon[i / 4];
			w[i] = w[i + 4] ^ temp;
		}
		else
			w[i] = w[i + 4] ^ w[i + 3];
	}
}