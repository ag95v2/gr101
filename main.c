#include <sys/time.h>
#include <stdio.h>
#include <math.h>
#include "fdf.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 900

#define WIDTH_RCT 500
#define LEN_RCT 500

void *mlx_ptr;
void *win_ptr;

struct timeval latest_event;
struct timeval now;

unsigned long usec_total(struct timeval start, struct timeval end)
{
        return (1000000 * (end.tv_sec - start.tv_sec) +
                (end.tv_usec - start.tv_usec));
}

void draw_rectangle(int x, int y, int x_len, int y_len, int color)
{
	int end_x;
	int end_y;
	int start_y;

	end_x = x + x_len;
	end_y = y + y_len;
	start_y = y;
	while (x < end_x) {
		y = start_y;
		while (y < end_y) {
			mlx_pixel_put (mlx_ptr, win_ptr, x, y, color);
			y++;
		}
		x++;
	}
}

int get_color(char r, char g, char b, char t)
{
	int res;

	((char *)(&res))[0] = b;
	((char *)(&res))[1] = g;
	((char *)(&res))[2] = r;
	((char *)(&res))[3] = t;

	// Debug!
	res &= 0x00ffffff;
	return (res);

}

int key_press(int key, void *param)
{
	gettimeofday(&now, NULL);
	printf("Key pressed: %c (%d). Passed %u usec\n", key, key,
			(unsigned int)usec_total(latest_event, now));
	latest_event = now;
	fflush(stdout);
	draw_rectangle(0, 0, WIDTH_RCT, LEN_RCT,
			get_color((char)255, 0, 0, (char)255));
	return (0);
}

int key_release(int key, void *param)
{
	gettimeofday(&now, NULL);
	printf("Key released: %c. Passed %u usec\n", key,
			(unsigned int)usec_total(latest_event, now));
	latest_event = now;
	fflush(stdout);
	draw_rectangle(0, 0, WIDTH_RCT, LEN_RCT, get_color(0, 0, 0, (char)255));
	return (0);
}


//expose_hook(void *param);
//key_hook(int keycode,void *param);
//mouse_hook(int button,int x,int y,void *param);
//loop_hook(void *param);
void draw_horisontal_line(int x0, int y0, int x1, int y1, int color)
{
	while (x0 != x1) {
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);
		x0 += x1 > x0 ? 1 : -1;
	}
}

void draw_vertical_line(int x0, int y0, int x1, int y1, int color)
{
	while (y0 != y1) {
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);
		y0 += y1 > y0 ? 1 : -1;
	}
}

int nearest_int(double x) {
	if (x - floor(x) < 0.5) {
		return ((int)floor(x));
	}
	return ((int)floor(x) + 1);
}

/*
 * red = 0
 * green = 1
 */
int gradient_color(pos, len)
{
	return (get_color(floor(255 * (double)pos / (double)len),
				      floor(255 * (1 - (double)pos /(double) len)), 0, 0));
}

void draw_line(int x0, int y0, int x1, int y1)
{
	int x_offset;
	int y_offset;
	int current_y;
	int color;
	float coef;

	color = get_color((char)255, 0, 0, (char)255);
	if (y1 == y0) {
		draw_horisontal_line(x0, y0, x1, y1, color);
		return ;
	}
	if (x1 == x0) {
		draw_vertical_line(x0, y0, x1, y1, color);
		return ;
	}
	coef = (double)(y1 - y0) / (double)(x1 - x0);

	printf("Drawing line from (%d, %d) to (%d %d); coef = %f\n",
			x0, y0, x1, y1, coef);
	x_offset = 0;
	current_y = y0;
	while (x0 + x_offset != x1) {
		y_offset = nearest_int(coef * x_offset);
		while ((current_y != y0 + y_offset) && current_y != y1) {
			mlx_pixel_put(mlx_ptr, win_ptr, x0 + x_offset,
					current_y, color);
			current_y += current_y < y0 + y_offset ? 1 : -1;
		}
		mlx_pixel_put(mlx_ptr, win_ptr, x0 + x_offset, 
				y0 + y_offset, color);
		printf("Putting pixel (%d %d)\n", x0 + x_offset, y0 + y_offset);
		x_offset += x1 > x0 ? 1 : -1;
	}
}

int mouse_press(int button,int x,int y,void *param)
{
	static int old_x = -1;
	static int old_y = -1;

	(void)param;
	printf("Pressed mouse button %d at (%d, %d)\n", button, x, y);
	//draw_rectangle(x, y, 50, 50, get_color(0, 255, 0, 255));
	fflush(stdout);

	if (old_x < 0) {
		old_x = x;
		old_y = y;
		return (0);
	}
	draw_line(old_x, old_y, x, y);
	old_y = -1;
	old_x = -1;
	return (0);
}

int mouse_release(int button,int x,int y,void *param)
{
	(void)param;
	printf("Released mouse button %d at (%d, %d)\n", button, x, y);
	//draw_rectangle(x, y, 50, 50, get_color(0, 0, 0, 255));
	fflush(stdout);
	return (0);
}

int mouse_move(int x,int y,void *param)
{
	(void)param;
	printf("Moved mouse (%d, %d)\n", x, y);
	fflush(stdout);
	return (0);
}


int main()
{
	int x_max = SCREEN_WIDTH;
	int y_max = SCREEN_HEIGHT;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, x_max, y_max, "W1");

	mlx_hook(win_ptr, KeyPress, KeyPressMask, key_press, NULL);
	mlx_hook(win_ptr, KeyRelease, KeyReleaseMask, key_release, NULL);
	mlx_hook(win_ptr, ButtonPress, ButtonPressMask, mouse_press, NULL);
	mlx_hook(win_ptr, ButtonRelease, ButtonReleaseMask, mouse_release, NULL);
	mlx_hook(win_ptr, MotionNotify, ButtonMotionMask, mouse_move, NULL);
	//mlx_key_hook(win_ptr, deal_key, NULL);

	mlx_loop(mlx_ptr);
}
