#include <stdio.h>

typedef unsigned char uint8_t;

void byteToHex(uint8_t byte, char* result) {
	const char const alpha[] = "0123456789ABCDEF";
	result[1] = alpha[byte%16];
	result[0] = alpha[(byte>>4)%16];
	return;
}

void intToHex(int num, char* result) {
	result[8] = 0;
	for (int i = 0; i < 4; ++i) {
		byteToHex((uint8_t)(num>>(8*i)), &result[6-i*2]);
	}
	return;
}

int main(void) {
	char res[9];
	int num = 0xAABBCCDD;
	intToHex(num, res);
	printf("%ud in HEX: %s\n", num, res);
	int tmp1 = (num & 0x00FF0000) >> 8;
	num = (num & 0xFF0000FF) + ((num & 0x0000FF00) << 8) + tmp1;
	intToHex(num, res);
	printf("%ud in HEX: %s\n", num, res);
	return 0;
}
