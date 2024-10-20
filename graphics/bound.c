#include <stdio.h>
	#include <graphics.h>

	void boundaryFill4(int x, int y, int fill_color, int boundary_color) {
	    int current_color = getpixel(x, y);
	    if (current_color != boundary_color && current_color != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill4(x + 1, y, fill_color, boundary_color);
        boundaryFill4(x - 1, y, fill_color, boundary_color);
        boundaryFill4(x, y + 1, fill_color, boundary_color);
        boundaryFill4(x, y - 1, fill_color, boundary_color);
    }
	}

      int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw a rectangle
    rectangle(100, 100, 200, 200);

    // Fill the rectangle with a color
    boundaryFill4(150, 150, RED, WHITE);

    getch();
    closegraph();
    return 0;
}
