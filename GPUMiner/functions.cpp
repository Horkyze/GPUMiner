#include <Windows.h>
#include <stdio.h>
#include <string.h>

int is_print(unsigned char c) {
	return (c > 31 && c <= 127);
}

void dump(const unsigned char * p, int len) {
	int i, k = 0;
	unsigned char buff[17];
	memset(buff, 0, 17);
	for (i = 1; i < len + 1; ++i)
	{
		printf("%02x ", p[i - 1]);

		buff[(i - 1) % 16] = (is_print(p[i - 1])) ? p[i - 1] : '.';

		if (i % 8 == 0 && i) {
			printf(" ");
		}


		if (i % 16 == 0 && i) {

			printf(" | %s \n", buff);
			memset(buff, 0, 17);
			k = 0;
		}


	}
	printf("\n\n");
}

long MyGetFileSize(FILE * f) {
	LARGE_INTEGER out;
	GetFileSizeEx(f, &out);
	return (long) out.QuadPart;
}