#include <stdio.h>
	#include <math.h>
	#include <graphics.h>
	void plotCirclePoints(int x_center, int y_center, int x, int y) 
	{
	 putpixel(x_center + x, y_center + y, WHITE);
   	 putpixel(x_center - x, y_center + y, WHITE);
   	 putpixel(x_center + x, y_center - y, WHITE);
   	 putpixel(x_center - x, y_center - y, WHITE);
   	 putpixel(x_center + y, y_center + x, WHITE);
   	 putpixel(x_center - y, y_center + x, WHITE);
  	  putpixel(x_center + y, y_center - x, WHITE);
    	putpixel(x_center - y, y_center - x, WHITE);
	}
	void drawCircle(int x_center, int y_center, int radius) {
  	  int x = 0;
  	  int y = radius;
   	 int p = 1 - radius;  // Initial decision parameter
    plotCirclePoints(x_center, y_center, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        plotCirclePoints(x_center, y_center, x, y);
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x_center = 200;
    int y_center = 200;
    int radius = 100;
    drawCircle(x_center, y_center, radius);
    getch();  // Wait for user input to close the graphics window
    closegraph();  // Close the graphics window
    return 0;
}
