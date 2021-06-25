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
	IMAGE img;
	loadimage(&img, _T("D:\\menu.jpg"), 700, 700);
	putimage(0, 0, &img);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 5);
	setbkmode(TRANSPARENT);
	rectangle(150, 200, 550, 300);
	settextstyle(50, 0, _T("宋体"));
	settextcolor(BLACK);
	outtextxy(300, 220, first);
	rectangle(150, 400, 550, 500);
	outtextxy(300, 420, second);
	settextstyle(30, 0, _T("宋体"));
	TCHAR EXIT[] = _T("点击右键退出");
	outtextxy(250, 550, EXIT);
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
				setfillcolor(WHITE);
				fillrectangle(150, 200, 550, 300);
				settextstyle(50, 0, _T("宋体"));
				outtextxy(300, 220, first);
				return 1;
			}
			if(m.x>150&&m.x<550&&m.y>400&&m.y<500)
			{
				setfillcolor(WHITE);
				fillrectangle(150, 400, 550, 500);
				settextstyle(50, 0, _T("宋体"));
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
	float x = 0, y = 0;
	MOUSEMSG m;
	while (true)
	{
		// 获取一条鼠标消息
		m = GetMouseMsg();
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (abs(m.x - i * 70) < 30 && abs(m.y - j * 70) < 30)
				{
					x = i * 70;
					y = j * 70;
				}
			}
		}
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			// 如果点左键落子
			count++;
			clearrectangle(210, 4, 230, 20);
			if ((count % 2) == 0)
			{
				setlinecolor(BLACK);
				//circle(m.x, m.y, 30);
				setfillcolor(WHITE);
				fillcircle(x, y, 30);
				settextstyle(16, 0, _T("宋体"));
				TCHAR s[5], s_1[] = _T("当前棋子数为：");
				_stprintf_s(s, _T("%d"), count);
				outtextxy(100, 4, s_1);
				outtextxy(210, 4, s);
			}
			else
			{
				setlinecolor(BLACK);
				//circle(m.x, m.y, 30);
				setfillcolor(BLACK);
				fillcircle(x, y, 30);
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
	float x = 0, y = 0;
	MOUSEMSG m;
	while (true)
	{
		// 获取一条鼠标消息
		m = GetMouseMsg();
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (abs(m.x - i * 70) < 30 && abs(m.y - j * 70) < 30)
				{
					x = i * 70;
					y = j * 70;
				}
			}
		}
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			// 如果点左键落子
			count++;
			clearrectangle(210, 4, 230, 20);
			if ((count % 2) == 0)
			{
				setlinecolor(BLACK);
				//circle(m.x, m.y, 30);
				setfillcolor(BLACK);
				fillcircle(x, y, 30);
				settextstyle(16, 0, _T("宋体"));
				TCHAR s[5], s_1[] = _T("当前棋子数为：");
				_stprintf_s(s, _T("%d"), count);
				outtextxy(100, 4, s_1);
				outtextxy(210, 4, s);
			}
			else
			{
				setlinecolor(BLACK);
				//circle(m.x, m.y, 30);
				setfillcolor(WHITE);
				fillcircle(x, y, 30);
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
	//setbkcolor(RGB(239, 222, 176));
	//cleardevice();
	IMAGE img;
	loadimage(&img, _T("D:\\qipan.jpg"), 700, 700);
	putimage(0, 0, &img);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 2);
	rectangle(70, 70, 630, 630);
	for (int x = 70; x <= 560; x += 70)
	{
		line(x, 70, x, 630);
		line(70, x, 630, x);
	}
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(40, 0, _T("宋体"));
	outtextxy(55, 650, a);
	outtextxy(55 + 72, 650, b);
	outtextxy(55 + 2 * 72, 650, c);
	outtextxy(55 + 72 * 3, 650, d);
	outtextxy(55 + 72 * 4, 650, e);
	outtextxy(55 + 72 * 5, 650, f);
	outtextxy(55 + 72 * 6, 650, g);
	outtextxy(55 + 72 * 7, 650, h);
	outtextxy(55 + 72 * 8, 650, i);
	outtextxy(660, 50, a);
	outtextxy(660, 50 + 70, b);
	outtextxy(660, 50 + 70 * 2, c);
	outtextxy(660, 50 + 70 * 3, d);
	outtextxy(660, 50 + 70 * 4, e);
	outtextxy(660, 50 + 70 * 5, f);
	outtextxy(660, 50 + 70 * 6, g);
	outtextxy(660, 50 + 70 * 7, h);
	outtextxy(660, 50 + 70 * 8, i);
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