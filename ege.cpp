#include <graphics.h>

int main() {
    initgraph(640, 480);
    circle(320, 240, 100);
    getch();
    line(100, 200, 600, 100);
    getch();
    closegraph();
    return 0;
}