#ifndef _SCRIMAGE_H_
#define _SCRIMAGE_H_
#define WIDTH 1920
#define HEIGHT 1080
typedef uint32_t Canvas[HEIGHT*WIDTH];
typedef struct
{
		int x;
		int y;
} Pixel;
//void set_pixel(Canvas image, uint32_t color, Pixel p);
void fill(Canvas image, uint32_t color);
int save(Canvas image, char *filename);
void bresenham(Canvas image, uint32_t color, Pixel p0, Pixel p1);
void rectangle(Canvas image, uint32_t color, Pixel p, int w, int h);
#endif
