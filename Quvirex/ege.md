下面是 EGE（Easy Graphics Engine）中 `graphics.h` 的**完整语法表格**，按功能分类整理，方便查阅。

---

## 📐 一、窗口与系统控制

| 函数 | 参数说明 | 功能 |
| :--- | :--- | :--- |
| `initgraph(int width, int height)` | `width`：窗口宽度；`height`：窗口高度 | 初始化绘图窗口 |
| `initgraph(int width, int height, int flag)` | `flag`：窗口标志（如 `INIT_RENDERMANUAL` 等） | 初始化绘图窗口（带标志） |
| `closegraph()` | 无 | 关闭图形环境，释放资源 |
| `cleardevice()` | 无 | 清屏（用当前背景色填充） |
| `getwidth()` | 无 | 获取当前窗口宽度 |
| `getheight()` | 无 | 获取当前窗口高度 |
| `delay(int ms)` | `ms`：毫秒数 | 延迟指定毫秒 |
| `getch()` | 无 | 等待并返回一个键盘输入的字符 |
| `kbhit()` | 无 | 检测是否有键盘输入（有则返回非0） |
| `sleep(int ms)` | `ms`：毫秒数 | 暂停程序执行指定毫秒 |
| `random(int n)` | `n`：上限 | 生成 0 到 n-1 的随机整数 |
| `randomize()` | 无 | 初始化随机数种子 |

---

## 🎨 二、颜色与样式设置

| 函数 | 参数说明 | 功能 |
| :--- | :--- | :--- |
| `setcolor(color_t color)` | `color`：颜色值 | 设置前景色（线条/边框颜色） |
| `setfillcolor(color_t color)` | `color`：颜色值 | 设置填充色 |
| `setbkcolor(color_t color)` | `color`：颜色值 | 设置背景色 |
| `setlinestyle(int style)` | `style`：线条样式（如 `SOLID_LINE`, `DASHED_LINE`） | 设置线条样式 |
| `setlinewidth(int width)` | `width`：线条宽度（像素） | 设置线条宽度 |
| `setbkmode(int mode)` | `mode`：`OPAQUE`（不透明）或 `TRANSPARENT`（透明） | 设置背景模式 |
| `setfont(int height, int width, const char* name)` | `height`：字体高度；`width`：字体宽度；`name`：字体名称 | 设置字体 |
| `setfont(const LOGFONT* font)` | `font`：逻辑字体结构体指针 | 通过结构体设置字体 |
| `setfontcolor(color_t color)` | `color`：颜色值 | 设置文字颜色 |
| `setfontbkcolor(color_t color)` | `color`：颜色值 | 设置文字背景色 |
| `setfontbkmode(int mode)` | `mode`：`OPAQUE` 或 `TRANSPARENT` | 设置文字背景模式 |
| `setlinewidth_f(float width)` | `width`：浮点数线宽 | 设置浮点数线条宽度（抗锯齿） |

### 预定义颜色常量

| 常量 | 值 |
| :--- | :--- |
| `BLACK`, `BLUE`, `GREEN`, `CYAN`, `RED`, `MAGENTA`, `BROWN`, `LIGHTGRAY`, `DARKGRAY`, `LIGHTBLUE`, `LIGHTGREEN`, `LIGHTCYAN`, `LIGHTRED`, `LIGHTMAGENTA`, `YELLOW`, `WHITE` | 16种标准色 |
| `EGERGB(r, g, b)` | 宏：自定义RGB颜色（r,g,b 范围 0-255） |

---

## ✏️ 三、基本绘图函数（整数版本）

| 函数 | 参数说明 | 功能 |
| :--- | :--- | :--- |
| `putpixel(int x, int y, color_t color)` | 坐标 + 颜色 | 画一个像素点 |
| `getpixel(int x, int y)` | 坐标 | 获取指定坐标点的颜色 |
| `line(int x1, int y1, int x2, int y2)` | 起点坐标 + 终点坐标 | 画直线 |
| `rectangle(int left, int top, int right, int bottom)` | 左上角 + 右下角坐标 | 画空心矩形 |
| `bar(int left, int top, int right, int bottom)` | 左上角 + 右下角坐标 | 画填充矩形（无边框） |
| `circle(int x, int y, int radius)` | 圆心坐标 + 半径 | 画空心圆 |
| `fillellipse(int x, int y, int xradius, int yradius)` | 圆心 + 水平半径 + 垂直半径 | 画填充椭圆 |
| `ellipse(int x, int y, int stangle, int endangle, int xradius, int yradius)` | 圆心 + 起始角 + 结束角 + 水平/垂直半径 | 画椭圆弧 |
| `sector(int x, int y, int stangle, int endangle, int xradius, int yradius)` | 圆心 + 起始角 + 结束角 + 水平/垂直半径 | 画填充椭圆扇形（有边框） |
| `pieslice(int x, int y, int stangle, int endangle, int radius)` | 圆心 + 起始角 + 结束角 + 半径 | 画填充扇形（圆） |
| `arc(int x, int y, int stangle, int endangle, int radius)` | 圆心 + 起始角 + 结束角 + 半径 | 画圆弧 |
| `polygon(int points[], int num)` | 点数组 + 点数 | 画空心多边形 |
| `fillpoly(int points[], int num)` | 点数组 + 点数 | 画填充多边形 |
| `drawpoly(int num, int points[])` | 点数 + 点数组 | 画多段线（折线） |

---

## ✏️ 四、基本绘图函数（浮点数版本）

| 函数 | 参数说明 | 功能 |
| :--- | :--- | :--- |
| `putpixel_f(float x, float y, color_t color)` | 坐标 + 颜色 | 画一个像素点（浮点坐标） |
| `getpixel_f(float x, float y)` | 坐标 | 获取指定坐标点的颜色 |
| `line_f(float x1, float y1, float x2, float y2)` | 起点 + 终点 | 画直线（浮点坐标） |
| `rectangle_f(float x1, float y1, float x2, float y2)` | 左上角 + 右下角 | 画空心矩形 |
| `bar_f(float x1, float y1, float x2, float y2)` | 左上角 + 右下角 | 画填充矩形 |
| `circle_f(float x, float y, float radius)` | 圆心 + 半径 | 画空心圆 |
| `fillellipse_f(float x, float y, float xradius, float yradius)` | 圆心 + 水平/垂直半径 | 画填充椭圆 |
| `ellipse_f(float x, float y, float stangle, float endangle, float xradius, float yradius)` | 圆心 + 角度 + 半径 | 画椭圆弧 |
| `sector_f(float x, float y, float stangle, float endangle, float xradius, float yradius)` | 圆心 + 角度 + 半径 | 画填充椭圆扇形 |
| `pieslice_f(float x, float y, float stangle, float endangle, float radius)` | 圆心 + 角度 + 半径 | 画填充扇形 |
| `arc_f(float x, float y, float stangle, float endangle, float radius)` | 圆心 + 角度 + 半径 | 画圆弧 |
| `polygon_f(const float points[], int num)` | 点数组 + 点数 | 画空心多边形 |
| `fillpoly_f(const float points[], int num)` | 点数组 + 点数 | 画填充多边形 |
| `drawpoly_f(int num, const float points[])` | 点数 + 点数组 | 画多段线 |

---

## ⌨️ 五、文本输出

| 函数 | 参数说明 | 功能 |
| :--- | :--- | :--- |
| `outtextxy(int x, int y, const char* str)` | 坐标 + 字符串 | 在指定位置输出文本 |
| `outtextxy(int x, int y, const wchar_t* str)` | 坐标 + 宽字符串 | 在指定位置输出宽字符文本 |
| `outtext(const char* str)` | 字符串 | 在当前坐标输出文本 |
| `outtext(const wchar_t* str)` | 宽字符串 | 在当前坐标输出宽字符文本 |
| `xyprintf(int x, int y, const char* format, ...)` | 坐标 + 格式化字符串 + 参数 | 格式化输出文本 |
| `xyprintf(int x, int y, const wchar_t* format, ...)` | 坐标 + 格式化宽字符串 + 参数 | 格式化输出宽文本 |
| `textwidth(const char* str)` | 字符串 | 获取文本宽度（像素） |
| `textwidth(const wchar_t* str)` | 宽字符串 | 获取宽文本宽度 |
| `textheight(const char* str)` | 字符串 | 获取文本高度 |
| `textheight(const wchar_t* str)` | 宽字符串 | 获取宽文本高度 |
| `settextjustify(int horiz, int vert)` | `horiz`：水平对齐（`LEFT_TEXT`, `CENTER_TEXT`, `RIGHT_TEXT`）；`vert`：垂直对齐（`TOP_TEXT`, `CENTER_TEXT`, `BOTTOM_TEXT`） | 设置文本对齐方式 |

---

## 🖱️ 六、鼠标交互

| 函数/类型 | 说明 | 功能 |
| :--- | :--- | :--- |
| `MOUSEMSG` | 结构体，包含 `x`, `y`, `uMsg`, `flags` 等成员 | 存储鼠标消息 |
| `GetMouseMsg()` | 无参数 | 获取鼠标消息（阻塞，等待鼠标事件） |
| `GetMouseMsg()` | 无参数 | 获取鼠标消息（阻塞） |
| `peekmouse()` | 无参数 | 检测是否有鼠标消息（非阻塞） |
| `flushmouse()` | 无参数 | 清空鼠标消息队列 |

### MOUSEMSG 结构体成员

| 成员 | 说明 |
| :--- | :--- |
| `msg.x` | 鼠标X坐标 |
| `msg.y` | 鼠标Y坐标 |
| `msg.uMsg` | 消息类型（`WM_LBUTTONDOWN`, `WM_LBUTTONUP`, `WM_RBUTTONDOWN`, `WM_RBUTTONUP`, `WM_MOUSEMOVE` 等） |
| `msg.flags` | 键盘状态（`MK_CONTROL`, `MK_SHIFT` 等） |

---

## 🖼️ 七、图像操作

| 函数 | 参数说明 | 功能 |
| :--- | :--- | :--- |
| `newimage()` | 无参数 | 创建图像对象（返回 `PIMAGE`） |
| `newimage(int width, int height)` | 宽 + 高 | 创建指定大小的图像对象 |
| `delimage(PIMAGE pImg)` | 图像对象指针 | 释放图像对象 |
| `getimage(PIMAGE pImg, const char* filename)` | 图像对象 + 文件名 | 从文件加载图片 |
| `getimage(PIMAGE pImg, int x, int y, int width, int height)` | 图像对象 + 坐标 + 宽高 | 从屏幕截取区域到图像对象 |
| `putimage(int x, int y, PIMAGE pImg)` | 坐标 + 图像对象 | 在指定位置显示图像 |
| `putimage(int x, int y, PIMAGE pImg, int op)` | 坐标 + 图像对象 + 操作模式 | 带操作模式显示图像（如 `SRCCOPY`, `NOTSRCCOPY` 等） |
| `putimage_alpha(int x, int y, PIMAGE pImg, int alpha)` | 坐标 + 图像对象 + 透明度（0-255） | 带透明度显示图像 |
| `putimage_transparent(int x, int y, PIMAGE pImg, color_t transColor)` | 坐标 + 图像对象 + 透明色 | 指定一种颜色作为透明色显示 |
| `putimage_rotate(int x, int y, PIMAGE pImg, double angle, ...)` | 坐标 + 图像对象 + 角度等 | 旋转显示图像 |
| `getpixel(PIMAGE pImg, int x, int y)` | 图像对象 + 坐标 | 获取图像某像素颜色 |
| `putpixel(PIMAGE pImg, int x, int y, color_t color)` | 图像对象 + 坐标 + 颜色 | 设置图像某像素颜色 |
| `resize(PIMAGE pImg, int width, int height)` | 图像对象 + 新宽高 | 调整图像尺寸 |
| `saveimage(PIMAGE pImg, const char* filename)` | 图像对象 + 文件名 | 保存图像到文件 |

---

## 📐 八、坐标变换

| 函数 | 参数说明 | 功能 |
| :--- | :--- | :--- |
| `setorigin(int x, int y)` | 坐标 | 设置坐标系原点 |
| `setaspectratio(float xasp, float yasp)` | X方向比例 + Y方向比例 | 设置坐标轴缩放比例 |
| `getx()` | 无 | 获取当前画笔X坐标 |
| `gety()` | 无 | 获取当前画笔Y坐标 |
| `moveto(int x, int y)` | 坐标 | 移动画笔到指定位置（不画线） |
| `lineto(int x, int y)` | 坐标 | 从当前画笔位置画线到指定位置 |
| `getcolor()` | 无 | 获取当前前景色 |
| `getfillcolor()` | 无 | 获取当前填充色 |
| `getbkcolor()` | 无 | 获取当前背景色 |
| `getlinestyle()` | 无 | 获取当前线条样式 |
| `getlinewidth()` | 无 | 获取当前线条宽度 |

---

## 🔧 九、系统与控制

| 函数 | 参数说明 | 功能 |
| :--- | :--- | :--- |
| `SetWindowTitle(const char* title)` | 窗口标题字符串 | 设置窗口标题 |
| `SetWindowTitle(const wchar_t* title)` | 窗口标题宽字符串 | 设置窗口标题（宽字符） |
| `GetHWnd()` | 无 | 获取绘图窗口的句柄（HWND） |
| `setcaption(const char* title)` | 窗口标题 | 设置窗口标题（旧版） |
| `setcaption(const wchar_t* title)` | 窗口标题宽字符 | 设置窗口标题（旧版） |
| `BeginBatchDraw()` | 无 | 开始批量绘图（双缓冲） |
| `FlushBatchDraw()` | 无 | 刷新批量绘图（将缓冲内容显示到屏幕） |
| `EndBatchDraw()` | 无 | 结束批量绘图 |
| `setrender(RENDER_MODE mode)` | 渲染模式 | 设置渲染模式 |
| `setactivepage(int page)` | 页号 | 设置活动绘图页（用于双缓冲） |
| `setvisualpage(int page)` | 页号 | 设置可见绘图页 |
| `EnumDisplaySettings(int mode)` | 显示模式 | 枚举显示模式（全屏相关） |

---

## 📦 十、其他工具函数

| 函数 | 参数说明 | 功能 |
| :--- | :--- | :--- |
| `srand(unsigned int seed)` | 随机种子 | 设置随机数种子 |
| `rand()` | 无 | 生成随机整数（标准C库） |
| `abs(int x)` | 整数 | 取绝对值 |
| `fabs(double x)` | 浮点数 | 取浮点绝对值 |

---

### 💎 补充说明

- 所有 `_f` 结尾的浮点版本函数支持抗锯齿和亚像素精度。
- `PIMAGE` 是图像对象指针类型，用 `newimage()` 创建，用 `delimage()` 释放。
- 角度参数（如 `stangle`, `endangle`）单位是**度**（`0°` 为水平向右，顺时针为正）。
- 颜色可用 `EGERGB(r, g, b)` 宏自定义。

如果某个函数的具体用法不清楚，可以告诉我函数名，我给你示例代码。😊