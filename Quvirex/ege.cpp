#include <graphics.h>

int main() {
    initgraph(1000, 1000);
    PIMAGE img = newimage();
    getimage(img, "WIN.jpg");
    putimage(100, 100, img);
    getch();
    closegraph();
    return 0;
}