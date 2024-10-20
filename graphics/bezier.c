#include <stdio.h>
#include <graphics.h>

int C(int n, int j);
float blend(int j, int n, float u);
void bezier(float u, int n, int p[4][2]);

int x, y;

int main() {
    float u;
    int gd, gm, ymax, i, n;
    int c[4][2] = {
        {100, 200}, 
        {150, 100}, 
        {200, 300}, 
        {250, 200}
    };

    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\Turboc3\\bgi");

    if (gd == DETECT) {
        printf("Graphics not initialized! Exiting.\n");
        return -1;
    }

    ymax = getmaxy();
    setcolor(13); 
    for (i = 0; i < 3; i++) {
        line(c[i][0], ymax - c[i][1], c[i + 1][0], ymax - c[i + 1][1]);
    }

    setcolor(3); 
    n = 3;
    for (i = 0; i < 40; i++) {
        u = (float)i / 40.0;
        bezier(u, n, c);
        if (i == 0) {
            moveto(x, ymax - y);
        } else {
            lineto(x, ymax - y);
        }
    }

    getch(); 
    closegraph(); 
    return 0; 
}

void bezier(float u, int n, int p[4][2]) {
    int j;
    float b;
    x = 0;
    y = 0;
    for (j = 0; j <= n; j++) {
        b = blend(j, n, u);
        x += (p[j][0] * b);
        y += (p[j][1] * b);
    }
}

float blend(int j, int n, float u) {
    int k;
    float v = C(n, j);
    for (k = 0; k < j; k++) {
        v *= u;
    }
    for (k = 1; k <= (n - j); k++) {
        v *= (1 - u);
    }
    return v;
}

int C(int n, int j) {
    int k, a = 1;
    for (k = j + 1; k <= n; k++) {
        a *= k;
    }
    for (k = 1; k <= (n - j); k++) {
        a /= k;
    }
    return a;
}

