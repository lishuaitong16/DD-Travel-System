#include"user.h"
#include<iostream>
#include<fstream>

using namespace std;
void Register(Passenger*, Passenger);//乘客注册，数据添加
void Register(Driver*, Driver);//司机注册，数据添加
void Register(Order_form*, Order_form);//订单注册，数据添加

Passenger* Login(Passenger*, string, string);//乘客登录
Driver* Login(Driver*, string, string);//司机登录

Passenger* Find(Passenger*, string, string);//乘客查询
Driver* Find(Driver*, string, string);//司机查询
Order_form* Find(Order_form* , int );//订单查询

int delet(Passenger*, int);//删除乘客信息
int delet(Driver*, int);//删除司机信息
int delet(Order_form*, int);//删除订单信息

Passenger* Check(Passenger* , string );//检查乘客信息,如有则返回指针
Driver* Check(Driver* , string );//检查司机信息,如有则返回指针
bool Check(string);//检查密码是否符合规范

void writeto(string, Passenger*, int);//乘客信息写入文件
int readfrom(string, Passenger*);//乘客信息读取文件
void writeto(string, Driver*, int);//司机信息写入文件
int readfrom(string, Driver*);//司机信息读取文件
void writeto(string, Order_form*, int);//订单信息写入文件
int readfrom(string, Order_form*);//订单信息读取文件

void dijkstra(int start, vector<int>& dist, vector<int>& prev);
vector<int> getPath(int start, int goal, const vector<int>& prev);
int main()
{
	//可视化操作
	//数据准备
	Passenger* Phead = NULL; Driver* Dhead = NULL; Order_form* Ohead = NULL;
	Phead = new Passenger;
	Dhead = new Driver;
	Ohead = new Order_form;
	Order_form* p = new Order_form;
	if (Phead == NULL || Dhead == NULL || Ohead == NULL)
	{
		cout << "head->error" << endl;
	}
	int PN, DN, ON, TEMP_ON; PN = DN = ON = TEMP_ON = 0;
	PN = readfrom("passenger.txt", Phead);
	DN = readfrom("driver.txt", Dhead);
	ON = readfrom("order.txt", Ohead);
	//以上头指针和计数定义以及文件读入
	Passenger* cur_passenger = Phead; Driver* cur_driver = Dhead; Order_form* cur_order = Ohead;//当前指向
	Order_form* temp_order = NULL;	Order_form* all_order = NULL;
	Passenger* foundPassenger = NULL; Driver* foundDriver = NULL;
	Order_form from;
	int xx1 = 60, yy1 = 40;
	int checknum = 0, num2 = 0, num1 = 0;
	const int N = 5; // 图的节点数量
	string nodeNames[N] = { "铁道校区", "新校区", "湘雅校区", "南校区", "校本部" };

	//开始
	Widget w(352, 288);


login_window://登录窗口

	MOUSEMSG mouse, mouse1;
	int b1, b2, b3;
	b1 = b2 = b3 = 0;
	string user = "", password = "", name = "", sex = "", age = "", tel = "", payPassword = "",vehicle_type="", dis = "", s1, s2, s3, s4, s5, s6, s7, s8;
	string start = "", end = "", temp_string = "",temp_string_2="", vehicle_type_1 = "";
	int int_start = 0, int_end = 0;
	double cost;
	string order_flag = "";
	IMAGE img;
	char a[10];//字符缓冲区，用来存储输入的字符串
	int checkbox_flag = 0, check = 0;
	for (; 1;)
	{
		mouse = GetMouseMsg();//获取鼠标消息
		cout << mouse.x << "/" << mouse.y << endl;
		w.set_title("登陆");
		w.output("用户名：", 70, 80);
		w.output("密    码：", 70, 125);
		s1 = w.cinbox(mouse, 130, 78, 266, 98, user);//设置用户名输入框，返回输入的字符串
		if (s1 != "")
		{
			user = s1;
			//cout << user;
		}
		s1 = w.cinbox(mouse, 130, 123, 266, 143, password);//设置密码输入框，返回输入的字符串
		if (s1 != "")
		{
			password = s1;
			//cout << password;
		}
		//如果没有账号，则需要注册
		if (w.set_button(mouse, 100, 170, 250, 190, "没有账号？点击注册"))
		{
			string message;
			//message = 1;
			message = w.message_info(a, 10, "输入您想要注册的身份1乘客2司机");
			if (message == "1")
			{
				w.clear(); user = password = "";
				Widget w2(352, 469);
				goto register_passenger;
			}
			if (message == "2")
			{
				w.clear(); user = password = "";
				Widget w2(352, 469);
				goto register_driver;
			}
		}
		//设置登录按钮，并根据输入的信息，转入相应的界面
		mouse1.x = 64; mouse1.y = 214; mouse1.mkLButton = true;
		if (w.set_button(mouse, 64, 214, 136, 234, "    登 陆    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "")
				{
					w.message_warn(a, 20, "账号或密码不能为空");
					check++;
					continue;
				}
				if (user == "root" && password == "root")
				{
					user = password = "";

					Widget w2(352, 469);
					goto root;
				}
				string message;
				//message = "1";
				message = w.message_info(a, 10, "输入您的身份1乘客2司机");
				if (message == "1")
				{
					//通过Login函数，返回一个指向乘客的指针
					if ((cur_passenger = Login(Phead, user, password))->Getname() != "")
					{
						cur_passenger = Login(Phead, user, password);
						//cur_passenger->Show();
						user = password = "";
						w.clear();
						Widget w2(352, 469);
						goto passenger;
					}
					else
					{
						w.message_warn(a, 20, "账号或密码错误");
						goto login_window;
					}
				}
				if (message == "2")
				{
					if ((cur_driver = Login(Dhead, user, password))->Getname() != "")
					{

						cur_driver = Login(Dhead, user, password);
						user = password = "";
						w.clear();
						Widget w2(800, 469);
						goto driver;
					}
					else
					{
						w.message_warn(a, 20, "账号或密码错误");
						goto login_window;
					}
				}
			}
			check++;
		}

		if (w.set_button(mouse, 200, 214, 272, 234, "    退 出    "))
		{
			if (check % 4 == 0)
			{
				if (w.message_question(a, 10, "确认退出？"))
				{
					w.delet();
					goto end;
				}
			}
			check++;

		}


	}


root://管理员登陆界面
	w.set_title("尊敬的管理员，您好");
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("选择你要查看的类型", 100, 80);
		int rx1 = 126, rx2 = rx1 + 85, ry1 = 120, ry2 = ry1 + 20;
		if (w.set_button(mouse, rx1, ry1, rx2, ry2, " 查看  乘客 "))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto show_passengers;
			}
			check++;
		}
		if (w.set_button(mouse, rx1, ry1 += 50, rx2, ry2 += 50, " 查看  司机"))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto show_drivers;
			}
			check++;
		}
		mouse1.x = 126; mouse1.y = 220; mouse1.mkLButton = true;
		if (w.set_button(mouse, rx1, ry1 += 50, rx2, ry2 += 50, " 查看  订单 "))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto show_orders;
			}
			check++;
		}
		if (w.set_button(mouse, rx1, ry1 += 50, rx2, ry2 += 50, "     返  回     "))
		{

			w.clear();
			Widget w(352, 288);
			goto login_window;

		}
	}
	getchar();

show_passengers://所有乘客信息
	w.set_title("查看乘客");
	num2 = 0;
	xx1 = 60;

	for (; 1;)
	{

		foundPassenger = new Passenger;
		cur_passenger = Phead->next;
		while (cur_passenger != NULL )
		{
			if (cur_passenger->Getname() == user)
			{
				cout << user;
				cout << "注册";
				Passenger TempPassenger = *cur_passenger;
				Register(foundPassenger, TempPassenger);
			}
			cur_passenger = cur_passenger->next;
		}
		if (foundPassenger->next == NULL)
		{
			cur_passenger = Phead->next;
		}
		else
		{
			cur_passenger = foundPassenger->next;
		}
		for (int i = 1; i <= 8 * num2; i++, cur_passenger = cur_passenger->next)
		{

		}
		mouse = GetMouseMsg();
		w.set_button(mouse, 90, 40, 157, 60, "账号");
		w.set_button(mouse, 215, 40, 250, 60, "姓名");
		w.output("搜索", 218, 4);
		s1 = w.cinbox(mouse, 253, 1, 353, 21, user);
		if (s1 != "")
		{
			user = s1;
			if (Find(Phead, user,"name") == NULL)
			{
				user = "未查询到";

			}
			else
			{
				w.clear();
				Widget w2(352, 469);
				goto show_passengers;
			}
		}
		for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && cur_passenger != NULL; num1++, i++, cur_passenger = cur_passenger->next)
		{

			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));//设置数字序号
			if (w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, cur_passenger->Getuserid()))//设置乘客账号按钮
			{
				Widget w2(352, 469);
				goto show_passenger;
			}
			if (w.set_button(mouse, xx1 + 140, 40 + 40 * i, xx1 + 210, 40 * i + 60, cur_passenger->Getname()))//设置乘客姓名
			{
				Widget w2(352, 469);
				goto show_passenger;
			}
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "删除"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "确认删除"))
					{
						PN=delet(Find(Phead, cur_passenger->Getuserid(),"id"), PN);
						w.clear();
						check++;
						break;
						//Widget w2(352, 469);
						//goto show_passengers;

					}
					//cout << num1;
				}
				check++;
				//cout << check;
			}
		}
		if (w.set_button(mouse, 40, 400, 110, 420, "  上一页  "))
		{
			if (checknum % 2 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  下一页  "))
		{
			if (checknum % 2 == 0 && (8 * num2 < PN - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   返 回   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();
show_passenger://查看某一乘客信息
	w.set_title("乘客信息");
	user = cur_passenger->Getuserid();
	password = cur_passenger->Getpassword(567);
	name = cur_passenger->Getname();
	age = to_string(cur_passenger->Getage());
	sex = cur_passenger->Getsex();
	tel = cur_passenger->Gettel();
	payPassword = cur_passenger->Get_payPassword();
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("支付密码：", 70, 350);
		//可以更改用户的信息
		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			if (Check(Phead, s1) == NULL)
			{
				//cout << Check(Phead, s1)->next->Getuser();
				user = s1;
			}
			else
			{
				w.message_warn(a, 20, "该账号已存在");
			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入字母或数字作为密码");
			}
		}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{
			name = s1;
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "请输入正确年龄");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "女" || s1 == "男" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "请输入正确性别");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (unsigned int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)//判断是否为数字
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "请输入正确手机号");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, payPassword);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				payPassword = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入字母或数字作为密码");
			}
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    修 改    "))
		{
			if (check % 4 == 0)
			{
				int iage = stoi(age);//stoi()函数将字符串转换为整数
				//password = cur_passenger->Getpassword(567);
				Passenger passenger(user, password, 1, name, sex, iage, tel, payPassword);
				//passenger.Show();
				cur_passenger->SetData(passenger);//直接将更改后的数据赋值给当前乘客
				w.message_info(a, 20, "已成功修改");
				//cur_passenger->Show();
				//passenger.Show();
				//pcus->Show();
			}
			check++;
			
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    返 回    "))
		{
			Widget w2(352, 469);
			user = password = name = age = sex = tel = payPassword = "";
			goto show_passengers;
		}

	}
	getchar();

show_drivers://所有司机信息
	w.set_title("查看司机");
	num2 = 0;
	xx1 = 60;
	for (; 1;)
	{
		foundDriver = new Driver;
		cur_driver = Dhead->next;
		while ( cur_driver != NULL )
		{
			if (cur_driver->Getname() == user)
			{
				cout << user;
				cout << "注册";
				Driver orderform = *cur_driver;
				Register(foundDriver, orderform);
			}
			cur_driver = cur_driver->next;
		}
		if (foundDriver->next == NULL)
		{
			cur_driver = Dhead->next;
		}
		else
		{
			cur_driver = foundDriver->next;
		}
		for (int i = 1; i <= 8 * num2; i++, cur_driver = cur_driver->next)
		{

		}


		mouse = GetMouseMsg();
		w.set_button(mouse, 90, 40, 157, 60, "人员名称");
		w.set_button(mouse, 200, 40, 270, 60, "车辆类型");
		w.output("搜索", 218, 4);
		s1 = w.cinbox(mouse, 253, 1, 353, 21, user);
		if (s1 != "")
		{
			user = s1;
			if (Find(Dhead, user,"name") == NULL)
			{
				user = "未查询到";

			}
			else
			{
				w.clear();
				Widget w2(352, 469);
				goto show_drivers;



			}
		}
		for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && cur_driver != NULL; num1++, i++, cur_driver = cur_driver->next)
		{

			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			if (w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, cur_driver->Getname()))
			{
				Widget w2(352, 469);
				goto show_driver;
			}
			if (w.set_button(mouse, xx1 + 140, 40 + 40 * i, xx1 + 210, 40 * i + 60, cur_driver->Get_vehicle_type()))
			{
				Widget w2(352, 469);
				goto show_driver;
			}
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "删除"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "确认删除"))
					{
						DN=delet(Find(Dhead, cur_driver->Getuserid(),"id"), DN);
						w.clear();
						check++;
						break;
						//Widget w2(352, 469);
						//goto show_passengers;

					}
					//cout << num1;
				}
				check++;
				//cout << check;
			}
		}
		if (w.set_button(mouse, 40, 400, 110, 420, "  上一页  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  下一页  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < DN - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   返 回   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();
show_driver://显示某一司机信息
	w.set_title("司机信息");
	user = cur_driver->Getuserid();
	password = cur_driver->Getpassword(567);
	name = cur_driver->Getname();
	age = to_string(cur_driver->Getage());
	sex = cur_driver->Getsex();
	tel = cur_driver->Gettel();
	vehicle_type = cur_driver->Get_vehicle_type();
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("车辆类型：", 70, 350);
		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			if (Check(Dhead, s1) == NULL)
			{
				//cout << Check(Phead, s1)->next->Getuser();
				user = s1;
			}
			else
			{
				w.message_warn(a, 20, "该账号已存在");
			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入字母或数字作为密码");
			}
		}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{
			
			name = s1;
			
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "请输入正确年龄");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "女" || s1 == "男" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "请输入正确性别");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (unsigned int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)//判断是否为数字
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "请输入正确手机号");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, vehicle_type);
		if (s1 != "")
		{
			if (s1 == "特惠快车" || s1 == "滴滴专车")
			{
				vehicle_type = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入正确车辆类型：特惠快车或滴滴专车");
			}
			
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    修 改    "))
		{
			if (check % 4 == 0)
			{
				int iage = stoi(age);
				//password = cur_driver->Getpassword(567);
				Driver driver(user, password, 2, name, sex, iage, tel, 2.5, vehicle_type);
				//passenger.Show();
				cur_driver->SetData(driver);
				w.message_info(a, 20, "已成功修改");
				//cur_shop->Show();
				//Driver* pcus = &passenger;
				//passenger.Show();
				//pcus->Show();
			}
			check++;
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    返 回    "))
		{
			Widget w2(352, 469);
			user = password = name = age = sex = tel = payPassword = "";
			goto show_drivers;
		}
	}
	getchar();
passenger://乘客登陆界面
	w.set_title("亲爱的乘客，您好");
	user = cur_passenger->Getuserid();
	password = cur_passenger->Getpassword(567);
	name = cur_passenger->Getname();
	age = to_string(cur_passenger->Getage());
	sex = cur_passenger->Getsex();
	tel = cur_passenger->Gettel();
	payPassword = cur_passenger->Get_payPassword();//payPassword
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("支付密码：", 70, 350);
		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			if (Check(Phead, s1) == NULL)
			{
				//cout << Check(Phead, s1)->next->Getuser();
				user = s1;
			}
			else
			{
				w.message_warn(a, 20, "该账号已存在");
			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入字母或数字作为密码");
			}
		}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{
			
			name = s1;
			
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "请输入正确年龄");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "女" || s1 == "男" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "请输入正确性别");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (unsigned int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "请输入正确手机号");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, payPassword);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				payPassword = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入字母或数字作为密码");
			}
		}
		

		if (w.set_button(mouse, 64, 395, 136, 415, "    修 改    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || payPassword == "")
				{
					w.message_warn(a, 20, "请不要漏填");
					goto passenger;
				}
				int iage = stoi(age);
				//password = cur_passenger->Getpassword(567);
				Passenger passenger(user, password, 1, name, sex, iage, tel, payPassword);
				//passenger.Show();
				cur_passenger->SetData(passenger);
				w.message_info(a, 20, "已成功修改");
				//cur_passenger->Show();
				//passenger.Show();
				//pcus->Show();
				/*Widget w(352, 288);
				goto login_window;*/
			}
			check++;
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    登 出    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = payPassword = "";
			goto login_window;
		}
		mouse1.x = 126;mouse1.y = 35;mouse1.mkLButton = true;
		if (w.set_button(mouse, 126, 35, 210, 55, "     打  车     "))
		{
			Widget w(790, 300);
			goto MakeOrder;
		}
		mouse1.x = 283; mouse1.y = 0; mouse1.mkLButton = true;
		if (w.set_button(mouse, 283, 0, 469, 20, "查看订单"))
		{
			Widget w2(800, 500);
			goto orderfrom_passenger;
		}
	}
	getchar();



driver://司机登陆界面
	//设置司机信息
	w.set_title("亲爱的司机，您好");
	user = cur_driver->Getuserid();
	//cout << user;
	password = cur_driver->Getpassword(567);
	name = cur_driver->Getname();
	age = to_string(cur_driver->Getage());
	sex = cur_driver->Getsex();
	tel = cur_driver->Gettel();
	payPassword = cur_driver->Get_vehicle_type();

	//设置司机订单
	temp_order = new Order_form;
	all_order = Ohead->next;
	TEMP_ON=0;
	while (all_order != NULL)
	{
		if (all_order->Getdriverid() == cur_driver->Getuserid() )
		{
			cout << "注册";
			Order_form orderform = *all_order;
			Register(temp_order, orderform);
			TEMP_ON++;
		}
		all_order = all_order->next;
	}
	//temp_order->next = NULL;
	if (temp_order->next == NULL)
	{

		w.output("订单将会在此处显示...", 340, 70);
	}
	

	num2 = 0;
	xx1 = 370;
	yy1=40;	

	for (; 1;)
	{	

		mouse = GetMouseMsg();
		cout<<mouse.x<<"/" << mouse.y<<endl;
		//设置司机信息
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("车辆类型：", 70, 350);
		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			if (Check(Dhead, s1) == NULL)
			{
				//cout << Check(Phead, s1)->next->Getuser();
				user = s1;
			}
			else
			{
				
				w.message_warn(a, 20, "该账号已存在");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入字母或数字作为密码");
			}
		}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{
			
			name = s1;
			
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "请输入正确年龄");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "女" || s1 == "男" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "请输入正确性别");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (unsigned int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "请输入正确手机号");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, payPassword);
		if (s1 != "")
		{
			payPassword = s1;
		}
		
		//设置司机订单
		if (temp_order->next != NULL)
		{
			cur_order = temp_order->next;
			// 遍历链表的 8 * num2 个节点，用于翻页
			for (int i = 1; i <= 8 * num2 && cur_order != NULL; i++)
			{
				cur_order = cur_order->next; // 移动到下一个节点
			}
			w.set_button(mouse, xx1, 40, xx1 + 35, 60, "乘客");
			w.set_button(mouse, xx1 + 100, 40, xx1 + 100 + 35, 60, "起点");
			w.set_button(mouse, xx1 + 100 * 2, 40, xx1 + 100 * 2 + 35, 60, "终点");
			w.set_button(mouse, xx1 + 100 * 3, 40, xx1 + 100 * 3 + 35, 60, "状态");
			for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && cur_order != NULL; num1++, i++, cur_order = cur_order->next)
			{

				w.set_button(mouse, xx1 - 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
				w.set_button(mouse, xx1 - 20, 40 + 40 * i, xx1 - 20 + 90, 40 * i + 60, cur_order->Getpasname());
				w.set_button(mouse, xx1 + 80, 40 + 40 * i, xx1 + 80 + 90, 40 * i + 60, cur_order->Getstart());
				w.set_button(mouse, xx1 + 180, 40 + 40 * i, xx1 + 180 + 90, 40 * i + 60, cur_order->Getend());
				switch (cur_order->Getflag())
				{
				case 2:
					temp_string = "出发";
					mouse1.x = xx1 + 280; mouse1.y = 40 + 40 * i; mouse1.mkLButton = true;
					if (w.set_button(mouse, xx1 + 280, 40 + 40 * i, xx1 + 280 + 90, 40 * i + 60, temp_string))
					{
						if (check % 4 == 0)
						{
							//Find(Ohead, cur_order->Getnumber())->next->change_driver(cur_driver->Getname());
							//获取电话号码
							temp_string = Find(Phead, cur_order->Getpasid(), "id")->next->Gettel();

							// 检查字符串长度，确保至少有4位
							if (temp_string.length() >= 4)
							{
								// 提取字符串的后四位
								temp_string = temp_string.substr(temp_string.length() - 4);
								temp_string_2 = w.message_info(a, 20, "请输入乘客后四位手机号：");
								// 检查输入的字符串是否与电话号码的后四位相同
								if (temp_string_2 == temp_string)
								{
									Find(Ohead, cur_order->Getnumber())->next->mark(3);
									Find(temp_order, cur_order->Getnumber())->next->mark(3);
									//"铁道校区", "新校区", "湘雅校区", "南校区", "校本部"
									if (cur_order->Getstart() == "铁道校区")
									{
										int_start = 0;
									}
									else if(cur_order->Getstart() == "新校区")
									{
										int_start = 1;
									}
									else if (cur_order->Getstart() == "湘雅校区")
									{
										int_start = 2;
									}
									else if (cur_order->Getstart() == "南校区")
									{
										int_start = 3;
									}
									else if (cur_order->Getstart() == "校本部")
									{
										int_start = 4;
									}
									if (cur_order->Getend()== "铁道校区")
									{
										int_end = 0;
									}
									else if(cur_order->Getend() == "新校区")
									{
										int_end = 1;
									}
									else if (cur_order->Getend() == "湘雅校区")
									{
										int_end = 2;
									}
									else if (cur_order->Getend() == "南校区")
									{
										int_end = 3;
									}
									else if (cur_order->Getend() == "校本部")
									{
										int_end = 4;
									}

									vector<int> dist, prev;
									dijkstra(int_start, dist, prev);
									vector<int> path = getPath(int_start, int_end, prev);
									temp_string = "已为您规划路径：";
									if (!path.empty()) {
										
										for (int node : path) {
											temp_string += nodeNames[node] + "->";
											//去掉最后一个箭头
											if (node == path.back()) {
												temp_string = temp_string.substr(0, temp_string.length() - 2);
											}
										}
										temp_string=temp_string + "，全程：" + to_string(dist[int_end]) + "公里";
										//cout << "从节点" << nodeNames[int_start] << "到节点" << nodeNames[int_end] << "的距离是: " << dist[int_end] << endl;

									}

									//temp_string = "请前往" + cur_order->Getend() + "（终点）";
									w.message_info(a, 20, temp_string.c_str());

								}
								else {
									w.message_warn(a, 20, "后四位手机号不符！");
								}

							}
							else {
								w.message_warn(a, 20, "电话号码太短，无法获取后四位。");
							}

						}
						check++;
						//cout << check;
					}
					break;
				case 3:
					temp_string = "结束";
					//w.set_button(mouse1, xx1 + 140 * 4, 40 + 40 * i, xx1 + 140 * 4 + 35, 40 * i + 60, "已接单");
					mouse1.x = xx1 + 280; mouse1.y = 40 + 40 * i; mouse1.mkLButton = true;
					if (w.set_button(mouse, xx1 + 280, 40 + 40 * i, xx1 + 280 + 90, 40 * i + 60, temp_string))
					{
						if (check % 4 == 0)
						{
							temp_string = "乘客是否已送至" + cur_order->Getend() + "?";
							if (w.message_question(a, 20, temp_string.c_str()))
							{
								Find(Ohead, cur_order->Getnumber())->next->mark(4);
								Find(temp_order, cur_order->Getnumber())->next->mark(4);
							}
						}
						check++;

					}

					break;
				case 4:
					temp_string = "未支付";
					if (w.set_button(mouse, xx1 + 280, 40 + 40 * i, xx1 + 280 + 90, 40 * i + 60, temp_string))
					{
						if (check % 4 == 0)
						{
							temp_string = "请等待顾客支付...";
							w.message_question(a, 20, temp_string.c_str());
							/*{
								Find(Ohead, cur_order->Getnumber())->next->mark(4);
								cur_order->mark(4);
							}*/
						}
						check++;

					}
					break;
				case 5:
					temp_string = "完成";
					if (w.set_button(mouse, xx1 + 280, 40 + 40 * i, xx1 + 280 + 90, 40 * i + 60, temp_string))
					{
						if (check % 4 == 0)
						{
							temp_string = "订单已完成！";
							w.message_question(a, 20, temp_string.c_str());
						}
						check++;
					}
					break;


				}

				//mouse1.x = xx1 + 140 * 4; mouse1.y = 40 + 40 * i; mouse1.mkLButton = true;


			}
			if (w.set_button(mouse, xx1, 400, xx1 + 70, 420, "  上一页  "))
			{
				if (checknum % 4 == 0 && num2 > 0)
				{
					w.clear();

					num2--;
					//cout << num2;
				}
				checknum++;
			}
			if (w.set_button(mouse, 705 - 70, 400, 705, 420, "  下一页  "))
			{
				if (checknum % 4 == 0 && (8 * num2 < TEMP_ON - 8))
				{
					w.clear();
					num2++;
					//cout << num2;
				}
				checknum++;
			}

		}
		

		
		
		if (w.set_button(mouse, 64, 400, 136, 420, "    修 改    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || payPassword == "")
				{
					w.message_warn(a, 20, "请不要漏填");
					goto driver;
				}
				int iage = stoi(age);
				//password = cur_driver->Getpassword(567);
				Driver customer(user, password, 1, name, sex, iage, tel, 2.5, payPassword);
				//passenger.Show();
				cur_driver->SetData(customer);
				w.message_info(a, 20, "已成功修改");
				//cur_shop->Show();
				//Driver* pcus = &passenger;
				//passenger.Show();
				//pcus->Show();
				/*Widget w(352, 288);
				goto login_window;*/
			}
		}




		if (w.set_button(mouse, 200, 400, 272, 420, "    返 回    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = payPassword = "";
			goto login_window;
		}
		mouse1.x = 283; mouse1.y = 0; mouse1.mkLButton = true;
		if (w.set_button(mouse, 510, 1, 580, 21, "查找乘客"))
		{
			Widget w2(700, 469);
			goto orderfrom_driver;
		}

	}
	getchar();

show_orders://所有订单
	w.set_title("查看订单");
	num2 = 0;
	for (; 1;)
	{
		//用于显示某一订单
		temp_order = new Order_form;//此处考虑是否能放外面，并在里面加temp_order->next=NULL;
		cur_order = Ohead->next;
		while (cur_order != NULL )
		{
			if (cur_order->Getnumber() == ("9999999" <= user || user == "" ? 0 : stoi(user)))
			{
				cout << user;
				cout << "注册";
				Order_form orderform = *cur_order;
				Register(temp_order, orderform);
			}
			cur_order = cur_order->next;
		}
		if (temp_order->next == NULL)
		{
			cur_order = Ohead->next;
		}
		else
		{
			cur_order = temp_order->next;
		}
		// 遍历链表的 8 * num2 个节点，用于翻页
		for (int i = 1; i <= 8 * num2 && cur_order != NULL; i++)
		{
			cur_order = cur_order->next; // 移动到下一个节点
		}
		mouse = GetMouseMsg();
		w.set_button(mouse, 90, 40, 157, 60, "打车用户");
		w.set_button(mouse, 215, 40, 250, 60, "司机");
		w.output("搜索", 218, 4);
		s1 = w.cinbox(mouse, 253, 1, 351, 21, user);
		if (s1 != "")
		{
			user = s1;

			//cout<< stoi(user);
			if (Find(Ohead, ("9999999" <= user || user == "" ? 0 : stoi(user))) == NULL)
			{
				user = "未查询到";

			}
			else
			{
				w.clear();
				Widget w2(352, 469);
				goto show_orders;



			}
		}
		xx1 = 60;
		for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && cur_order != NULL; num1++, i++, cur_order = cur_order->next)
		{

			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			mouse1.x = xx1; mouse1.y = 40 + 40 * i; mouse1.mkLButton = true;
			if (w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, cur_order->Getpasname()))
			{
				w.clear();
				Widget w2(700-270, 514);
				goto show_order;
			}
			if (w.set_button(mouse, xx1+140, 40 + 40 * i, xx1 + 210, 40 * i + 60, cur_order->Getdrivername()))
			{
				w.clear();
				Widget w2(700-270, 514);
				goto show_order;
			}
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "删除"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "确认删除"))
					{
						ON=delet(Find(Ohead, cur_order->Getnumber()), ON);
						w.clear();
						check++;
						break;

					}
					//cout << num1;
				}
				check++;
				//cout << check;
			}
		}
		if (w.set_button(mouse, 40, 400, 110, 420, "  上一页  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  下一页  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   返 回   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();

show_order://查看某一订单
	w.set_title("查看订单" + to_string(cur_order->Getnumber()));
	if (cur_order->Getflag() == 1)
	{
		order_flag = "正在呼叫...";
	}
	if (cur_order->Getflag() == 2)
	{
		order_flag = "司机已接单";
	}
	if (cur_order->Getflag() == 3)
	{
		order_flag = "行程开始";
	}
	if (cur_order->Getflag() == 4)
	{
		order_flag = "行程结束，未支付";
	}
	if (cur_order->Getflag() == 5)
	{
		order_flag = "订单已完成";
	}
	
	for (; 1;)//显示订单信息
	{
		mouse = GetMouseMsg();
		w.output("下单乘客：", 70, 80);
		s1 = w.cinbox(mouse, 145, 78, 350, 98, cur_order->Getpasname());
		w.output("接单司机：", 70, 125);
		s1 = w.cinbox(mouse, 145, 123, 350, 143, cur_order->Getdrivername());
		w.output("起始地点：", 70, 170);
		s1 = w.cinbox(mouse, 145, 168, 350, 188, cur_order->Getstart());
		w.output("目的地点：", 70, 215);
		s1 = w.cinbox(mouse, 145, 214, 350, 234, cur_order->Getend());
		w.output("车辆类型", 70, 260);
		s1 = w.cinbox(mouse, 145, 258, 350, 278, cur_order->Getvehicle_type());
		w.output("订单花费：", 70, 305);
		s1 = w.cinbox(mouse, 145, 302, 350, 322, to_string(cur_order->Getcost()).substr(0,5));
		w.output("订单状态",70, 350);
		s1=w.cinbox(mouse, 145, 346, 350, 366, order_flag);
		if (w.set_button(mouse, 114-40, 440, 186-40, 460, "    确 认    "))
		{
			Widget w2(352, 469);
			w2.clear();
			goto show_orders;
		}
		if (w.set_button(mouse, 500-250, 440, 572-250, 460, "    返 回    "))
		{
			Widget w2(352, 469);
			w2.clear();
			goto show_orders;
		}
	}
	
	getchar();

orderfrom_passenger://乘客有关订单
	w.set_title("查看订单");

	//cout << cur_passenger->Getname();

	temp_order = new Order_form;
	all_order = Ohead->next;
	TEMP_ON = 0;
	while(all_order != NULL)
	{
		if (all_order->Getpasid() == cur_passenger->Getuserid())
		{
			//cout << "注册";
			Order_form orderform = *all_order;
			Register(temp_order, orderform);
			TEMP_ON++;
		}
		all_order = all_order->next;
	}
	num2 = 0;
	xx1 = 80;
	double allcost;

	for (; 1;)
	{
		allcost = 0;
		if (temp_order->next == NULL)
		{
			w.message_warn(a, 20, "您还没有下单");
			Widget w2(352, 469);
			w2.clear();
			goto passenger;
		}
		else
		{
			cur_order = temp_order->next;
		}
		for (int i = 1; i <= 8 * num2; i++, cur_order = cur_order->next)
		{

		}
		mouse = GetMouseMsg();
		cout << mouse.x << "/" << mouse.y<<endl;
		w.set_button(mouse, xx1, 40, xx1+50, 60, "起点");
		w.set_button(mouse, xx1+120, 40, xx1+120+50, 60, "终点");
		w.set_button(mouse, xx1 + 120*2, 40, xx1 + 120*2 + 50, 60, "司机");
		w.set_button(mouse, xx1 + 120 * 3, 40, xx1 + 120 * 3 + 50,60 , "费用");
		w.set_button(mouse, xx1 + 120 * 4, 40, xx1 + 120 * 4 + 50, 60, "状态");
		w.set_button(mouse, xx1 + 120 * 5, 40, xx1 + 120 * 5 + 50, 60, "操作");

		for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && cur_order != NULL; num1++, i++, cur_order = cur_order->next)
		{
			allcost += cur_order->Getcost();
			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			w.set_button(mouse, xx1 - 25, 40 + 40 * i, xx1 + 70, 40 * i + 60, cur_order->Getstart());
			w.set_button(mouse, xx1 + 90, 40 + 40 * i, xx1 + 190, 40 * i + 60, cur_order->Getend());
			w.set_button(mouse, xx1 + 190+20, 40 + 40 * i, xx1 + 190+20+100, 40 * i + 60, cur_order ->Getdrivername());
			w.set_button(mouse, xx1 + 310 + 20, 40 + 40 * i, xx1 + 410 + 20 , 40 * i + 60, to_string(cur_order->Getcost()).substr(0,5));
			switch (cur_order->Getflag())
			{
			case 1:
				temp_string = "等待接单";
				w.set_button(mouse, xx1 + 430+20, 40 + 40 * i, xx1 + 450 + 100, 40 * i + 60, temp_string);
				if (w.set_button(mouse, xx1 + 550 + 20, 40 + 40 * i, xx1 + 570 + 100, 40 * i + 60, "取消"))
				{
					if (check % 4 == 0)
					{
						if (w.message_question(a, 20, "确认取消订单？"))
						{
							ON = delet(Find(Ohead, cur_order->Getnumber()), ON);
							Widget w2(800, 500);
							check++;
							goto orderfrom_passenger;

						}
					}
					check++;
					
				}



				break;
			case 2:
				temp_string = "司机正在赶来...";
				mouse1.x = xx1 + 280; mouse1.y = 40 + 40 * i; mouse1.mkLButton = true;
				w.set_button(mouse, xx1 + 430 + 20, 40 + 40 * i, xx1 + 450 + 100, 40 * i + 60, temp_string);
				if (w.set_button(mouse, xx1 + 550 + 20, 40 + 40 * i, xx1 + 570 + 100, 40 * i + 60, "取消"))
				{
					if (check % 4 == 0)
					{
						if (w.message_question(a, 20, "确认取消订单？"))
						{
							ON = delet(Find(Ohead, cur_order->Getnumber()), ON);
							Widget w2(800, 500);
							goto orderfrom_passenger;

						}
					}
					check++;
					
				}
				break;
				//if (check % 4 == 0)
				//{
				//	//Find(Ohead, cur_order->Getnumber())->next->change_driver(cur_driver->Getname());
				//	//获取电话号码
				//	temp_string = Find(Phead, cur_order->Getpasid(), "id")->next->Gettel();

				//	// 检查字符串长度，确保至少有4位
				//	if (temp_string.length() >= 4)
				//	{
				//		// 提取字符串的后四位
				//		temp_string = temp_string.substr(temp_string.length() - 4);
				//		temp_string_2 = w.message_info(a, 20, "请输入乘客后四位手机号：");
				//		// 检查输入的字符串是否与电话号码的后四位相同
				//		if (temp_string_2 == temp_string)
				//		{
				//			Find(Ohead, cur_order->Getnumber())->next->mark(3);
				//			Find(temp_order, cur_order->Getnumber())->next->mark(3);
				//			temp_string = "请前往" + cur_order->Getend() + "（终点）";

				//		}
				//		else {
				//			w.message_warn(a, 20, "后四位手机号不符！");
				//		}

				//	}
				//	else {
				//		w.message_warn(a, 20, "电话号码太短，无法获取后四位。");
				//	}

				//}
				//check++;
				//cout << check;
				
				
			case 3:
				temp_string = "行程已开始";
				//w.set_button(mouse1, xx1 + 140 * 4, 40 + 40 * i, xx1 + 140 * 4 + 35, 40 * i + 60, "已接单");
				mouse1.x = xx1 + 280; mouse1.y = 40 + 40 * i; mouse1.mkLButton = true;
				w.set_button(mouse, xx1 + 430 + 20, 40 + 40 * i, xx1 + 450 + 100, 40 * i + 60, temp_string);
				if (w.set_button(mouse, xx1 + 550 + 20, 40 + 40 * i, xx1 + 570 + 100, 40 * i + 60, "取消"))
				{
					if (check % 4 == 0)
					{
						w.message_warn(a, 20, "行程已开始，无法取消");
					}
					check++;
					
				}
				break;

			case 4:
				temp_string = "未支付";
				w.set_button(mouse, xx1 + 430 + 20, 40 + 40 * i, xx1 + 450 + 100, 40 * i + 60, temp_string);
				if (w.set_button(mouse, xx1 + 550 + 20, 40 + 40 * i, xx1 + 570 + 100, 40 * i + 60, "点击支付"))
				{
					if (check % 4 == 0)
					{
						
						temp_string=w.message_info(a, 20, "请输入支付密码");
						temp_string_2=cur_passenger->Get_payPassword();
						if(temp_string==temp_string_2)
						{
							Find(Ohead, cur_order->Getnumber())->next->mark(5);
							Find(temp_order, cur_order->Getnumber())->next->mark(5);
							w.clear();
						}
						else
						{
							w.message_warn(a, 20, "支付密码错误");
						}
						/*{
							Find(Ohead, cur_order->Getnumber())->next->mark(4);
							cur_order->mark(4);
						}*/
					}
					check++;

				}
				break;
			case 5:

				temp_string = "订单完成";
				w.set_button(mouse, xx1 + 430 + 20, 40 + 40 * i, xx1 + 450 + 100, 40 * i + 60, temp_string);
				break;

			}
			

			//{
			//	if (check % 4 == 0)
			//	{
			//		if (cur_order->Getflag() == 2)
			//		{
			//			Find(Ohead, cur_order->Getnumber())->next->mark(3);
			//			w.message_warn(a, 20, "已签收");
			//		}
			//		else
			//		{
			//			w.message_warn(a, 20, "司机尚未接受");
			//		}
			//	}
			//	check++;
			//	//cout << check;
			//}
		}
		w.output("您已消费：", 40, 440);
		w.output(to_string(allcost).substr(0, 5), 130, 440);
		if (w.set_button(mouse, 40, 400, 110, 420, "  上一页  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 630-70, 400, 630, 420, "  下一页  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < TEMP_ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 300, 400, 300+65, 420, "   返 回   "))
		{


			Widget w2(352, 469);
			w2.clear();
			goto passenger;

		}


	}

	getchar();





orderfrom_driver://司机有关订单
	w.set_title("查找乘客");

	//cout << cur_passenger->Getname();
	temp_order = new Order_form;
	all_order = Ohead->next;
	while (all_order != NULL)
	{
		if (all_order->Getvehicle_type() == cur_driver->Get_vehicle_type())
		{
			cout << "注册";
			Order_form orderform = *all_order;
			Register(temp_order, orderform);
		}
		all_order = all_order->next;
	}
	num2 = 0;
	xx1 = 60;
	if (temp_order->next == NULL)
	{
		w.message_warn(a, 20, "暂无订单");
		Widget w2(800, 469);
		w2.clear();
		goto driver;
	}
	
	for (; 1;)
	{
		if (temp_order->next != NULL)
		{
			cur_order = temp_order->next;
		}
		
		// 遍历链表的 8 * num2 个节点，用于翻页
		for (int i = 1; i <= 8 * num2 && cur_order != NULL; i++)
		{
			cur_order = cur_order->next; // 移动到下一个节点
		}
		mouse = GetMouseMsg();
		cout<<mouse.x<<"/" << mouse.y<<endl;
		w.set_button(mouse, 100, 40, 100 + 35, 60, "乘客");
		w.set_button(mouse, 100 + 150, 40, 100 + 150 + 35, 60, "起点");
		w.set_button(mouse, 100 + 150 * 2, 40, 100 + 150 * 2 + 35, 60, "终点");
		w.set_button(mouse, 100 + 150 * 3, 40, 100 + 150 * 3 + 35, 60, "费用");


		for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && cur_order != NULL; num1++, i++, cur_order = cur_order->next)
		{

			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, cur_order->Getpasname());
			w.set_button(mouse, xx1 + 140, 40 + 40 * i, xx1+ 140 + 120, 40 * i + 60, cur_order->Getstart());
			w.set_button(mouse, xx1 + 140*2, 40 + 40 * i, xx1 + 140*2 + 120, 40 * i + 60, cur_order->Getend());
			w.set_button(mouse, xx1 + 140 * 3, 40 + 40 * i, xx1 + 140 * 3 + 120, 40 * i + 60, to_string(cur_order->Getcost()).substr(0,5));
			mouse1.x=xx1 + 140 * 4; mouse1.y = 40 + 40 * i; mouse1.mkLButton = true;
			temp_string= cur_order->Getflag() == 1 ? "接单" : "已接单";
			if (w.set_button(mouse, xx1 + 140*4, 40 + 40 * i, xx1 + 140 * 4+55, 40 * i + 60,temp_string))
			{
				if (check % 4 == 0)
				{
					if (temp_string == "接单")
					{
						Find(Ohead, cur_order->Getnumber())->next->mark(2);
						Find(temp_order, cur_order->Getnumber())->next->mark(2);
						Find(Ohead, cur_order->Getnumber())->next->change_driver(cur_driver->Getname());
						Find(temp_order, cur_order->Getnumber())->next->change_driver(cur_driver->Getname());
						Find(Ohead, cur_order->Getnumber())->next->change_driver_id(cur_driver->Getuserid());
						Find(temp_order, cur_order->Getnumber())->next->change_driver_id(cur_driver->Getuserid());
						temp_string = "已接单，请在10分钟内前往" + cur_order->Getstart() + "（起点）";
						//w.set_button(mouse1, xx1 + 140 * 4, 40 + 40 * i, xx1 + 140 * 4 + 35, 40 * i + 60, "已接单");
						w.message_info(a, 20, temp_string.c_str());
					}
					
				}
				check++;
				//cout << check;
			}
		}
		if (w.set_button(mouse, 40, 400, 110, 420, "  上一页  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 590, 400, 660, 420, "  下一页  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 310, 400, 195+180, 420, "   返 回   "))
		{


			Widget w2(800, 469);
			w2.clear();
			goto driver;

		}


	}

	getchar();


	
register_passenger://乘客注册
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.set_title("乘客注册");
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("支付密码：", 70, 350);
		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			if (Check(Phead, s1) == NULL)
			{
				//cout << Check(Phead, s1)->next->Getuser();
				user = s1;
			}
			else
			{
				w.message_warn(a, 20, "该账号已存在");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入字母或数字作为密码");
			}
		}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{

			name = s1;

		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "请输入正确年龄");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "女" || s1 == "男" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "请输入正确性别");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (unsigned int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "请输入正确手机号");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, payPassword);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				payPassword = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入字母或数字作为密码");
			}
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    注 册    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || payPassword == "")
				{
					
					w.message_warn(a, 20, "请不要漏填");
					goto register_passenger;
				}

				int iage = stoi(age);
				Passenger customer(user, password, 1, name, sex, iage, tel, payPassword);
				//Driver* pcus = &passenger;
				//passenger.Show();
				Register(Phead, customer);//很奇怪的读入问题，除了iage全部写入文件丢失数据。
				//pcus->Show();
				PN++;
				w.message_info(a, 20, "注册成功");
				Widget w(352, 288);
				goto login_window;
			}
			check++;
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    返 回    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = payPassword = "";
			goto login_window;
		}
	}
	getchar();



register_driver://司机注册
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.set_title("司机注册");
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("车辆类型：", 70, 350);
		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			if (Check(Dhead, s1) == NULL)
			{
				//cout << Check(Phead, s1)->next->Getuser();
				user = s1;
			}
			else
			{
				
				w.message_warn(a, 20, "该账号已存在");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入字母或数字作为密码");
			}
		}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{
			
			name = s1;
			
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "请输入正确年龄");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "女" || s1 == "男" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "请输入正确性别");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (unsigned i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "请输入正确手机号");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, payPassword);
		if (s1 != "")
		{
			payPassword = s1;
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    注 册    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || payPassword == "")
				{
					
					w.message_warn(a, 20, "请不要漏填");
					goto register_driver;
				}
				int iage = stoi(age);
				Driver customer(user, password, 2, name, sex, iage, tel, 2.5, payPassword);
				//Driver* pcus = &customer;
				//passenger.Show();
				Register(Dhead, customer);
				//pcus->Show();
				DN++;
				w.message_info(a,20,"注册成功");
				Widget w(352, 288);
				goto login_window;
			}
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    返 回    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = payPassword = "";
			goto login_window;
		}
	}
	getchar();



MakeOrder://打车下单，选择起点、终点
	w.set_title("打车");
	

	// 加载图像文件，文件名为 "example.jpg"
	// 请确保图像文件与可执行文件在同一目录，或使用完整路径
	loadimage(&img, _T("./Location.png"));

	// 将图像显示在窗口中的 (0, 0) 位置
	putimage(0, 0, &img);
	start = end = vehicle_type_1 = "";
	int_start = 0; int_end = 0;
	cost = 0;
	for (; 1;)
	{
		
		/*start = "铁道校区";
		end="南校区";
		vehicle_type_1="滴滴专车";*/
		mouse = GetMouseMsg();
		cout<<mouse.x<<'/'<<mouse.y<<endl;
		w.set_title("打车");
		w.output("起点：", 70+420 + 76, 80);
		temp_string = w.cinbox(mouse, 130+420 + 76, 78, 266+420 + 76, 98, start);//设置起点输入框，返回输入的字符串
		if (temp_string != "")
		{
			// "铁道校区", "新校区", "湘雅校区", "南校区", "校本部"
			if (temp_string == "铁道校区")
			{
				start = temp_string;
				int_start = 0;
			}
			else if(temp_string == "新校区")
			{
				start = temp_string;
				int_start = 1;
			}
			else if (temp_string == "湘雅校区")
			{
				start = temp_string;
				int_start = 2;
			}
			else if (temp_string == "南校区")
			{
				start = temp_string;
				int_start = 3;
			}
			else if (temp_string == "校本部")
			{
				start = temp_string;
				int_start = 4;
			}
			else
			{
				w.message_warn(a, 20, "抱歉，目前只提供五个校区的打车服务");
			}
		}
		w.output("终点：", 70+420 + 76, 125);
		temp_string = w.cinbox(mouse, 130 + 420 + 76, 123, 266 + 420 + 76, 143, end);//
		if (temp_string != "")
		{
			if(temp_string == "铁道校区")
			{
				end = temp_string;
				int_end = 0;
			}
			else if (temp_string == "新校区")
			{
				end = temp_string;
				int_end = 1;
			}
			else if (temp_string == "湘雅校区")
			{
				end = temp_string;
				int_end = 2;
			}
			else if (temp_string == "南校区")
			{
				end = temp_string;
				int_end = 3;
			}
			else if (temp_string == "校本部")
			{
				end = temp_string;
				int_end = 4;
			}
			else
			{
				w.message_warn(a, 20, "抱歉，目前只提供五个校区的打车服务");
			}
		}
		w.output("车型：", 70 + 420 + 76, 125-80+125);
		temp_string = w.cinbox(mouse, 130 + 420 + 76, 123 - 78 + 123, 266 + 420 + 76, 143 + 143 - 98, vehicle_type_1);
		if (temp_string != "")
		{
			if (temp_string == "特惠快车" || temp_string == "滴滴专车")
			{
				vehicle_type_1 = temp_string;
			}
			else
			{
				 w.message_warn(a, 20, "抱歉，目前只提供滴滴专车或特惠快车");
			}
			
		}
		
		
		mouse1.x = 64; mouse1.y = 214; mouse1.mkLButton = true;
		if (w.set_button(mouse, 64 + 420+76, 214, 136 + 420 + 76, 234, "    呼 叫    "))
		{
			if (check % 4 == 0)
			{
				if (start == "" || end == "" || vehicle_type_1 == "")
				{
					w.message_warn(a, 20, "请不要漏填");
					goto MakeOrder;
				}
				if (vehicle_type_1 == "特惠快车")
				{
					vector<int> dist, prev;
					dijkstra(int_start, dist, prev);
					cost = dist[int_end] * 1.5;
					temp_string = "起点：" + start + " 终点：" + end + " 车型：" + vehicle_type_1 + " 费用：" + to_string(cost) + "元";
					if (w.message_question(a, 20, temp_string.c_str()))
					{
						Order_form orderform(ON + 1, cur_passenger->Getuserid(), cur_passenger->Getname(), "*", "*", start, end, vehicle_type_1, 1, cost);
						Register(Ohead, orderform);
						ON++;
						w.message_info(a, 20, "已下单，请等待司机接单");
						Widget w2(352, 469);
						goto passenger;
					}
					
				}
				else if(vehicle_type_1 == "滴滴专车")
				{
					vector<int> dist, prev;
					dijkstra(int_start, dist, prev);
					cost = dist[int_end] * 2;
					temp_string = "起点：" + start + " 终点：" + end + " 车型：" + vehicle_type_1 + " 费用：" + to_string(cost) + "元";
					if (w.message_question(a, 20, temp_string.c_str()))
					{
						Order_form orderform(ON + 1, cur_passenger->Getuserid(), cur_passenger->Getname(), "*", "*", start, end, vehicle_type_1, 1, cost);
						Register(Ohead, orderform);
						ON++;
						w.message_info(a, 20, "已下单，请等待司机接单");
						Widget w2(352, 469);
						goto passenger;
					}
				}
			}
			check++;
		}

		if (w.set_button(mouse, 200 + 420 + 76, 214, 272 + 420 + 76, 234, "    返 回    "))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto passenger;
			}
			check++;

		}
		
	}
	getchar();


end://结束录入文件
	writeto("passenger.txt", Phead, PN);
	writeto("driver.txt", Dhead, DN);
	writeto("order.txt", Ohead, ON);
	return 0;
}