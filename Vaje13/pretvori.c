#include <stdio.h>
#include <stdlib.h>

static const int r_weight = 30, g_weight = 59, b_weight = 11;

int main(int argc, const char *argv[]) {
	if (argc != 3) return 1;
	
	FILE *inp = fopen(argv[1], "rb");
	FILE *out = fopen(argv[2], "wb");

	fgetc(inp); fgetc(inp); fgetc(inp);
	fprintf(out, "P5\n");

	int sirina, visina;
	fscanf(inp, "%d %d ", &sirina, &visina);
	fprintf(out, "%d %d\n255\n", sirina, visina);

	fgetc(inp); fgetc(inp); fgetc(inp); fgetc(inp);

	unsigned char r, g, b;
	for (int i = 0; i < sirina * visina; i++) {
		fread(&r, sizeof(unsigned char), 1, inp);
		fread(&g, sizeof(unsigned char), 1, inp);
		fread(&b, sizeof(unsigned char), 1, inp);
		unsigned char sivinska_vrednost = (unsigned char)(((int)r * r_weight + (int)g * g_weight + (int)b * b_weight) / 100);
		fwrite(&sivinska_vrednost, sizeof(unsigned char), 1, out);
	}

	fclose(inp);
	fclose(out);
	return 0;
}