#include <graphics.h>
#include <conio.h>
TCHAR a[] = _T("0");
TCHAR b[] = _T("1");
TCHAR c[] = _T("2");
TCHAR d[] = _T("3");
TCHAR e[] = _T("4");
TCHAR f[] = _T("5");
TCHAR g[] = _T("6");
TCHAR h[] = _T("7");
TCHAR i[] = _T("8");
int main()
{
	int count = 0;
	// 初始化图形窗口
	initgraph(700, 700);
	MOUSEMSG m;		// 定义鼠标消息
	setbkcolor(RGB(239,222,176));
	cleardevice();
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 2);
	rectangle(50, 50, 600, 600);
	for (float x = 50 + 68.75; x <= 600.0; x += 68.75)
	{
		line(x, 50, x, 600);
		line(50, x, 600, x);
	}
	settextcolor(BLACK);
	settextstyle(40, 0, _T("宋体"));
	outtextxy(45, 630, a);
	outtextxy(45+68.75, 630, b);
	outtextxy(45 + 68.75*2, 630, c);
	outtextxy(45 + 68.75*3, 630, d);
	outtextxy(45 + 68.75*4, 630, e);
	outtextxy(45 + 68.75*5, 630, f);
	outtextxy(45 + 68.75*6, 630, g);
	outtextxy(45 + 68.75*7, 630, h);
	outtextxy(45 + 68.75*8, 630, i);
	outtextxy(640, 40, a);
	outtextxy(640, 40 + 68.75, b);
	outtextxy(640, 40 + 68.75*2, c);
	outtextxy(640, 40 + 68.75*3, d);
	outtextxy(640, 40 + 68.75*4, e);
	outtextxy(640, 40 + 68.75*5, f);
	outtextxy(640, 40 + 68.75*6, g);
	outtextxy(640, 40 + 68.75*7, h);
	outtextxy(640, 40 + 68.75*8, i);
	while (true)
	{
		// 获取一条鼠标消息
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			// 如果点左键落子
			if ((count % 2) == 0)
			{
				setlinecolor(BLACK);
				circle(m.x, m.y, 30);
				setfillcolor(BLACK);
				fillcircle(m.x, m.y, 30);
			}
			else
			{
				setlinecolor(WHITE);
				circle(m.x, m.y, 30);
				setfillcolor(WHITE);
				fillcircle(m.x, m.y, 30);
			}
			count++;
			break;

		}
	}

	// 关闭图形窗口
	closegraph();
	return 0;
}