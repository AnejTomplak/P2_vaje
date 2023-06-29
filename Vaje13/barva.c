#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string2num(const char *s) {
	int n = 0;
	for (int i = 0; i < strlen(s); i++) {
		n = n * 10 + s[i] - '0';
	}
	return n;
}

int main(int argc, const char* argv[]) {
	if (argc != 4) return 1;
	
	FILE *inp = fopen(argv[1], "rb");
	int vrstica = string2num(argv[2]);
	int stolpec = string2num(argv[3]);
	getc(inp); getc(inp); getc(inp);

	int w, h;
	fscanf(inp, "%d %d ", &w, &h);
	getc(inp); getc(inp); getc(inp); getc(inp);

	unsigned char r, g, b;
	for (int i = 0; i < 3 * (vrstica * w + stolpec); i++) {
		fread(&r, sizeof(unsigned char), 1, inp);
	}

	fread(&r, sizeof(unsigned char), 1, inp);
	fread(&g, sizeof(unsigned char), 1, inp);
	fread(&b, sizeof(unsigned char), 1, inp);

	printf("%d %d %d\n", r, g, b);
	fclose(inp);
	return 0;
}

while(fread(&byte, sizeof(u.c.), 1, fptr) != 0);
while(fgets(tab, sizeof(tab), fptr) != NULL);
int num = atoi(argv[2]);