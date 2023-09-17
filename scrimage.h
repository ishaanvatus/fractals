#ifndef _SCRIMAGE_H_
#define _SCRIMAGE_H_
#define WIDTH 1920
#define HEIGHT 1080
void fill(uint32_t *pixels, size_t height, size_t width, uint32_t color);
int save(uint32_t *pixels, size_t height, size_t width, char *filename);
#endif
