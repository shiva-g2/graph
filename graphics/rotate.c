#include <graphics.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265
void rotatePoint(float* x, float* y, float cx, float cy, float angle) 
{    float radians = angle * 3.142 / 180.0;
    float sin_angle = sin(radians);
    float cos_angle = cos(radians);
    float tx = *x - cx;
    float ty = *y - cy;
    *x = cx + tx * cos_angle - ty * sin_angle;
    *y = cy + tx * sin_angle + ty * cos_angle;
}
int main() 
{    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
        float x1 = 100.0, y1 = 100.0;
    float x2 = 150.0, y2 = 50.0;
    float x3 = 200.0, y3 = 100.0;
    setcolor(WHITE);
    line((int)x1, (int)y1, (int)x2, (int)y2);
    line((int)x2, (int)y2, (int)x3, (int)y3);
    line((int)x3, (int)y3, (int)x1, (int)y1);
    float angle = 45.0;
    float cx = (x1 + x2 + x3) / 3.0;
    float cy = (y1 + y2 + y3) / 3.0;
    rotatePoint(&x1, &y1, cx, cy, angle);
    rotatePoint(&x2, &y2, cx, cy, angle);
    rotatePoint(&x3, &y3, cx, cy, angle);
    setcolor(YELLOW);
    line((int)x1, (int)y1, (int)x2, (int)y2);
    line((int)x2, (int)y2, (int)x3, (int)y3);
    line((int)x3, (int)y3, (int)x1, (int)y1);
      getch();
    closegraph();
    return 0;
}
