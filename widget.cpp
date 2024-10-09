#include"widget.h"
#include"iostream"

string Widget::input(char* str, int max, LPCTSTR message, LPCTSTR title, LPCTSTR def, int wideth, int height, bool b)
{
	string s;
	InputBox(str, max, message, title, def, wideth, height, b);//����InputBox����,���������,��������ݴ���str��,maxΪ��������ַ���
	s = str;
	return s;
}
void Widget::output(string st, int x, int y)
{
	const char* c;
	c = st.c_str();//c_str()��������һ��ָ������C�ַ�����ָ�볣���������뱾string����ͬ��
	settextcolor(RGB(0, 0, 0));//�����ı���ɫ
	outtextxy(x, y, c);//��ָ��λ������ı�
}
void Widget::set_title(string str)
{
	const char* c;
	c = str.c_str();
	// ��ô��ھ��
	HWND hWnd = GetHWnd();
	// ʹ�� Windows API �޸Ĵ�������
	SetWindowText(hWnd, c);
}
bool Widget::set_button(MOUSEMSG mouse, int x1, int y1, int x2, int y2, string str)
{
	if (mouse.x >= x1 && mouse.y >= y1 && mouse.x <= x2 && mouse.y <= y2)//����ڰ�ť��Χ��
	{
		setlinecolor(RGB(131, 185, 228));
		setfillcolor(RGB(229, 241, 251));
		fillrectangle(x1, y1, x2, y2);
		this->output(str, x1 + 3, y1 + 3);
		if (mouse.mkLButton == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		setlinecolor(RGB(173, 173, 173));
		setfillcolor(RGB(225, 225, 225));
		fillrectangle(x1, y1, x2, y2);
		this->output(str, x1 + 3, y1 + 3);
		return false;
	}
}
bool Widget::set_checkbox(MOUSEMSG mouse, int x1, int y1, int x2, int y2, string str)
{
	if (mouse.x >= x1 && mouse.y >= y1 && mouse.x <= x2 && mouse.y <= y2)
	{
		setlinecolor(RGB(131, 185, 228));
		setfillcolor(RGB(229, 241, 251));
		rectangle(x1, y1, x2, y2);
		this->output(str, x2 + 3, y1 + 3);
		if (mouse.mkLButton == true)
		{
			setlinecolor(RGB(255, 255, 255));
			if (this->check_checkbox % 2 == 0)
			{
				setfillcolor(RGB(0, 0, 0));
				fillrectangle(x1 + 2, y1 + 2, x2 - 2, y2 - 2);
				this->check_checkbox++;
				return true;
			}
			else
			{
				setfillcolor(RGB(255, 255, 255));
				fillrectangle(x1 + 2, y1 + 2, x2 - 2, y2 - 2);
				this->check_checkbox++;
				return false;
			}

		}
		else
		{
			return false;
		}
	}
	else
	{
		setlinecolor(RGB(173, 173, 173));
		setfillcolor(RGB(225, 225, 225));
		rectangle(x1, y1, x2, y2);
		this->output(str, x2 + 3, y1 + 3);
		return false;
	}
}
string Widget::cinbox(MOUSEMSG mouse, int x1, int y1, int x2, int y2, string str)
{
	setlinecolor(RGB(0, 0, 0));
	setfillcolor(RGB(255, 255, 255));
	fillrectangle(x1, y1, x2, y2);
	this->output(str, x1 + 3, y1 + 3);
	/*if (this->check_cinbox % 2 == 0)
	{
		setlinecolor(RGB(0, 0, 0));
		line(x1 + 5, y1, x1 + 5, y2);
	}
	else
	{
		setlinecolor(RGB(255, 255, 255));
		line(x1 + 5, y1, x1 + 5, y2);
		setlinecolor(RGB(0, 0, 0));
	}
	Sleep(500);*/
	string s = "";
	if (mouse.x >= x1 && mouse.y >= y1 && mouse.x <= x2 && mouse.y <= y2 && mouse.mkLButton == true)
	{
		if (this->check_cinbox % 4 == 0)
		{
			char* c = new char[20];
			s = this->input(c, 17);
		}
		this->check_cinbox++;

	}
	return s;
}
void Widget::message_warn(char* str, int max, LPCTSTR message, LPCTSTR title, LPCTSTR def, int wideth, int height, bool b)
{
	InputBox(str, max, message, title, def, wideth, height, b);
}
string Widget::message_info(char* str, int max, LPCTSTR message, LPCTSTR title, LPCTSTR def, int wideth, int height, bool b)
{
	string s;
	InputBox(str, max, message, title, def, wideth, height, b);
	s = str;
	return s;

}
bool Widget::message_question(char* str, int max, LPCTSTR message, LPCTSTR title, LPCTSTR def, int wideth, int height, bool b)
{

	return InputBox(str, max, message, title, def, wideth, height, b);


}
