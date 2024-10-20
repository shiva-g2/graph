#include <stdio.h>
	      #include <stdlib.h>
	      #include <graphics.h>
	void drawLine(int x1, int y1, int x2, int y2) {
	    int dx = abs(x2 - x1);
	    int dy = abs(y2 - y1);
	    int sx = x1 < x2 ? 1 : -1;
	    int sy = y1 < y2 ? 1 : -1;
	    int err = dx - dy;
	    int e2;
	    while (1) {
	     putpixel(x1, y1, WHITE);
	      if (x1 == x2 && y1 == y2) {
                  break;
                 }
   	     e2 = err * 2;
      	  if (e2 > -dy) {
          	  err -= dy;
            x1 += sx;
   	     }
      	  if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int x1=100, y1=100, x2=200, y2=200;
    drawLine(x1, y1, x2, y2);
    delay(5000);
    closegraph();
    return 0;
}
