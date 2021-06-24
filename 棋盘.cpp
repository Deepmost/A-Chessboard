#include <graphics.h>
#include <conio.h>
#include<iostream>
void drawstart();
void firsthand();
void secondhand();
void drawboard();
TCHAR a[] = _T("0");
TCHAR b[] = _T("1");
TCHAR c[] = _T("2");
TCHAR d[] = _T("3");
TCHAR e[] = _T("4");
TCHAR f[] = _T("5");
TCHAR g[] = _T("6");
TCHAR h[] = _T("7");
TCHAR i[] = _T("8");
TCHAR second[] = _T("后手");
TCHAR first[] = _T("先手");
int count = 0;
void drawstart()
{
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 5);
	rectangle(150, 200, 550, 300);
	settextstyle(50, 0, _T("宋体"));
	settextcolor(BLACK);
	outtextxy(300, 220, first);
	rectangle(150, 400, 550, 500);
	outtextxy(300, 420, second);
}
int start()
{
	MOUSEMSG m;
	while (true)
	{
		m = GetMouseMsg();
		switch(m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (m.x > 150 && m.x < 550 && m.y>200 && m.y < 300)
			{
				setfillcolor(RGB(66, 76, 78));
				fillrectangle(150, 200, 550, 300);
				outtextxy(300, 220, first);
				return 1;
			}
			if(m.x>150&&m.x<550&&m.y>400&&m.y<500)
			{
				setfillcolor(RGB(66, 76, 78));
				fillrectangle(150, 400, 550, 500);
				outtextxy(300, 420, second);
				return 2;
			}
		case WM_RBUTTONDOWN:
			exit(1);
		}
	}
	return 0;
}
void firsthand()
{
	MOUSEMSG m;
	while (true)
	{
		// 获取一条鼠标消息
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			// 如果点左键落子
			count++;
			if ((count % 2) == 0)
			{
				setlinecolor(WHITE);
				circle(m.x, m.y, 30);
				setfillcolor(WHITE);
				fillcircle(m.x, m.y, 30);
				settextstyle(16, 0, _T("宋体"));
				TCHAR s[5], s_1[] = _T("当前棋子数为：");
				_stprintf_s(s, _T("%d"), count);
				outtextxy(100, 4, s_1);
				outtextxy(210, 4, s);
			}
			else
			{
				setlinecolor(BLACK);
				circle(m.x, m.y, 30);
				setfillcolor(BLACK);
				fillcircle(m.x, m.y, 30);
				settextstyle(16, 0, _T("宋体"));
				TCHAR s[5], s_1[] = _T("当前棋子数为：");
				_stprintf_s(s, _T("%d"), count);
				outtextxy(100, 4, s_1);
				outtextxy(210, 4, s);
			}
			break;
		}
	}
}
void secondhand()
{
	MOUSEMSG m;
	while (true)
	{
		// 获取一条鼠标消息
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			// 如果点左键落子
			count++;
			if ((count % 2) == 0)
			{
				setlinecolor(BLACK);
				circle(m.x, m.y, 30);
				setfillcolor(BLACK);
				fillcircle(m.x, m.y, 30);
				settextstyle(16, 0, _T("宋体"));
				TCHAR s[5], s_1[] = _T("当前棋子数为：");
				_stprintf_s(s, _T("%d"), count);
				outtextxy(100, 4, s_1);
				outtextxy(210, 4, s);
			}
			else
			{
				setlinecolor(WHITE);
				circle(m.x, m.y, 30);
				setfillcolor(WHITE);
				fillcircle(m.x, m.y, 30);
				settextstyle(16, 0, _T("宋体"));
				TCHAR s[5], s_1[] = _T("当前棋子数为：");
				_stprintf_s(s, _T("%d"), count);
				outtextxy(100, 4, s_1);
				outtextxy(210, 4, s);
			}
			break;

		}
	}
}
void drawboard()
{
	setbkcolor(RGB(239, 222, 176));
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
	outtextxy(45 + 68.75, 630, b);
	outtextxy(45 + 68.75 * 2, 630, c);
	outtextxy(45 + 68.75 * 3, 630, d);
	outtextxy(45 + 68.75 * 4, 630, e);
	outtextxy(45 + 68.75 * 5, 630, f);
	outtextxy(45 + 68.75 * 6, 630, g);
	outtextxy(45 + 68.75 * 7, 630, h);
	outtextxy(45 + 68.75 * 8, 630, i);
	outtextxy(640, 40, a);
	outtextxy(640, 40 + 68.75, b);
	outtextxy(640, 40 + 68.75 * 2, c);
	outtextxy(640, 40 + 68.75 * 3, d);
	outtextxy(640, 40 + 68.75 * 4, e);
	outtextxy(640, 40 + 68.75 * 5, f);
	outtextxy(640, 40 + 68.75 * 6, g);
	outtextxy(640, 40 + 68.75 * 7, h);
	outtextxy(640, 40 + 68.75 * 8, i);
}
int main()
{
	initgraph(700, 700);// 初始化图形窗口
	drawstart();// 加载开始界面
	if (start() == 1)
	{
		Sleep(200);
		drawboard();
		firsthand();//返回值为1则先手（先落黑子）
	}
	if (start() == 2)
	{
		Sleep(200);
		drawboard();
		secondhand();//返回值为2则后手（先落白子）
	}
	closegraph();// 关闭图形窗口
	return 0;
}