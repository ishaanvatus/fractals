#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int row, col;
	char r, g, b;
	FILE *fp = fopen("sample.ppm", "wb");
	fprintf(fp, "P6\n");
	fprintf(fp, "%d %d\n", width, height);
	fprintf(fp, "255\n");
	for (row = 0; row < height; row++) {
		for (col = 0; col < width; col++) {
			r = row*col;
			g = row^col;
			b = row*col;
			fwrite(&r, sizeof(char), 1, fp);
			fwrite(&g, sizeof(char), 1, fp);
			fwrite(&b, sizeof(char), 1, fp);
		}
	}
}
