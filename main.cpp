#include"user.h"
#include<iostream>
#include<fstream>

using namespace std;
void Register(Passenger*, Passenger);//�˿�ע�ᣬ�������
void Register(Driver*, Driver);//˾��ע�ᣬ�������
void Register(Order_form*, Order_form);//����ע�ᣬ�������

Passenger* Login(Passenger*, string, string);//�˿͵�¼
Driver* Login(Driver*, string, string);//˾����¼

Passenger* Find(Passenger*, string, string);//�˿Ͳ�ѯ
Driver* Find(Driver*, string, string);//˾����ѯ
Order_form* Find(Order_form* , int );//������ѯ

int delet(Passenger*, int);//ɾ���˿���Ϣ
int delet(Driver*, int);//ɾ��˾����Ϣ
int delet(Order_form*, int);//ɾ��������Ϣ

Passenger* Check(Passenger* , string );//���˿���Ϣ,�����򷵻�ָ��
Driver* Check(Driver* , string );//���˾����Ϣ,�����򷵻�ָ��
bool Check(string);//��������Ƿ���Ϲ淶

void writeto(string, Passenger*, int);//�˿���Ϣд���ļ�
int readfrom(string, Passenger*);//�˿���Ϣ��ȡ�ļ�
void writeto(string, Driver*, int);//˾����Ϣд���ļ�
int readfrom(string, Driver*);//˾����Ϣ��ȡ�ļ�
void writeto(string, Order_form*, int);//������Ϣд���ļ�
int readfrom(string, Order_form*);//������Ϣ��ȡ�ļ�

void dijkstra(int start, vector<int>& dist, vector<int>& prev);
vector<int> getPath(int start, int goal, const vector<int>& prev);
int main()
{
	//���ӻ�����
	//����׼��
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
	//����ͷָ��ͼ��������Լ��ļ�����
	Passenger* cur_passenger = Phead; Driver* cur_driver = Dhead; Order_form* cur_order = Ohead;//��ǰָ��
	Order_form* temp_order = NULL;	Order_form* all_order = NULL;
	Passenger* foundPassenger = NULL; Driver* foundDriver = NULL;
	Order_form from;
	int xx1 = 60, yy1 = 40;
	int checknum = 0, num2 = 0, num1 = 0;
	const int N = 5; // ͼ�Ľڵ�����
	string nodeNames[N] = { "����У��", "��У��", "����У��", "��У��", "У����" };

	//��ʼ
	Widget w(352, 288);


login_window://��¼����

	MOUSEMSG mouse, mouse1;
	int b1, b2, b3;
	b1 = b2 = b3 = 0;
	string user = "", password = "", name = "", sex = "", age = "", tel = "", payPassword = "",vehicle_type="", dis = "", s1, s2, s3, s4, s5, s6, s7, s8;
	string start = "", end = "", temp_string = "",temp_string_2="", vehicle_type_1 = "";
	int int_start = 0, int_end = 0;
	double cost;
	string order_flag = "";
	IMAGE img;
	char a[10];//�ַ��������������洢������ַ���
	int checkbox_flag = 0, check = 0;
	for (; 1;)
	{
		mouse = GetMouseMsg();//��ȡ�����Ϣ
		cout << mouse.x << "/" << mouse.y << endl;
		w.set_title("��½");
		w.output("�û�����", 70, 80);
		w.output("��    �룺", 70, 125);
		s1 = w.cinbox(mouse, 130, 78, 266, 98, user);//�����û�������򣬷���������ַ���
		if (s1 != "")
		{
			user = s1;
			//cout << user;
		}
		s1 = w.cinbox(mouse, 130, 123, 266, 143, password);//������������򣬷���������ַ���
		if (s1 != "")
		{
			password = s1;
			//cout << password;
		}
		//���û���˺ţ�����Ҫע��
		if (w.set_button(mouse, 100, 170, 250, 190, "û���˺ţ����ע��"))
		{
			string message;
			//message = 1;
			message = w.message_info(a, 10, "��������Ҫע������1�˿�2˾��");
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
		//���õ�¼��ť���������������Ϣ��ת����Ӧ�Ľ���
		mouse1.x = 64; mouse1.y = 214; mouse1.mkLButton = true;
		if (w.set_button(mouse, 64, 214, 136, 234, "    �� ½    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "")
				{
					w.message_warn(a, 20, "�˺Ż����벻��Ϊ��");
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
				message = w.message_info(a, 10, "�����������1�˿�2˾��");
				if (message == "1")
				{
					//ͨ��Login����������һ��ָ��˿͵�ָ��
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
						w.message_warn(a, 20, "�˺Ż��������");
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
						w.message_warn(a, 20, "�˺Ż��������");
						goto login_window;
					}
				}
			}
			check++;
		}

		if (w.set_button(mouse, 200, 214, 272, 234, "    �� ��    "))
		{
			if (check % 4 == 0)
			{
				if (w.message_question(a, 10, "ȷ���˳���"))
				{
					w.delet();
					goto end;
				}
			}
			check++;

		}


	}


root://����Ա��½����
	w.set_title("�𾴵Ĺ���Ա������");
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("ѡ����Ҫ�鿴������", 100, 80);
		int rx1 = 126, rx2 = rx1 + 85, ry1 = 120, ry2 = ry1 + 20;
		if (w.set_button(mouse, rx1, ry1, rx2, ry2, " �鿴  �˿� "))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto show_passengers;
			}
			check++;
		}
		if (w.set_button(mouse, rx1, ry1 += 50, rx2, ry2 += 50, " �鿴  ˾��"))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto show_drivers;
			}
			check++;
		}
		mouse1.x = 126; mouse1.y = 220; mouse1.mkLButton = true;
		if (w.set_button(mouse, rx1, ry1 += 50, rx2, ry2 += 50, " �鿴  ���� "))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto show_orders;
			}
			check++;
		}
		if (w.set_button(mouse, rx1, ry1 += 50, rx2, ry2 += 50, "     ��  ��     "))
		{

			w.clear();
			Widget w(352, 288);
			goto login_window;

		}
	}
	getchar();

show_passengers://���г˿���Ϣ
	w.set_title("�鿴�˿�");
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
				cout << "ע��";
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
		w.set_button(mouse, 90, 40, 157, 60, "�˺�");
		w.set_button(mouse, 215, 40, 250, 60, "����");
		w.output("����", 218, 4);
		s1 = w.cinbox(mouse, 253, 1, 353, 21, user);
		if (s1 != "")
		{
			user = s1;
			if (Find(Phead, user,"name") == NULL)
			{
				user = "δ��ѯ��";

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

			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));//�����������
			if (w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, cur_passenger->Getuserid()))//���ó˿��˺Ű�ť
			{
				Widget w2(352, 469);
				goto show_passenger;
			}
			if (w.set_button(mouse, xx1 + 140, 40 + 40 * i, xx1 + 210, 40 * i + 60, cur_passenger->Getname()))//���ó˿�����
			{
				Widget w2(352, 469);
				goto show_passenger;
			}
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "ɾ��"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "ȷ��ɾ��"))
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
		if (w.set_button(mouse, 40, 400, 110, 420, "  ��һҳ  "))
		{
			if (checknum % 2 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  ��һҳ  "))
		{
			if (checknum % 2 == 0 && (8 * num2 < PN - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   �� ��   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();
show_passenger://�鿴ĳһ�˿���Ϣ
	w.set_title("�˿���Ϣ");
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
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("֧�����룺", 70, 350);
		//���Ը����û�����Ϣ
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
				w.message_warn(a, 20, "���˺��Ѵ���");
			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ĸ��������Ϊ����");
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
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "Ů" || s1 == "��" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�Ա�");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (unsigned int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)//�ж��Ƿ�Ϊ����
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�ֻ���");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, payPassword);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				payPassword = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ĸ��������Ϊ����");
			}
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    �� ��    "))
		{
			if (check % 4 == 0)
			{
				int iage = stoi(age);//stoi()�������ַ���ת��Ϊ����
				//password = cur_passenger->Getpassword(567);
				Passenger passenger(user, password, 1, name, sex, iage, tel, payPassword);
				//passenger.Show();
				cur_passenger->SetData(passenger);//ֱ�ӽ����ĺ�����ݸ�ֵ����ǰ�˿�
				w.message_info(a, 20, "�ѳɹ��޸�");
				//cur_passenger->Show();
				//passenger.Show();
				//pcus->Show();
			}
			check++;
			
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    �� ��    "))
		{
			Widget w2(352, 469);
			user = password = name = age = sex = tel = payPassword = "";
			goto show_passengers;
		}

	}
	getchar();

show_drivers://����˾����Ϣ
	w.set_title("�鿴˾��");
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
				cout << "ע��";
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
		w.set_button(mouse, 90, 40, 157, 60, "��Ա����");
		w.set_button(mouse, 200, 40, 270, 60, "��������");
		w.output("����", 218, 4);
		s1 = w.cinbox(mouse, 253, 1, 353, 21, user);
		if (s1 != "")
		{
			user = s1;
			if (Find(Dhead, user,"name") == NULL)
			{
				user = "δ��ѯ��";

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
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "ɾ��"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "ȷ��ɾ��"))
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
		if (w.set_button(mouse, 40, 400, 110, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < DN - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   �� ��   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();
show_driver://��ʾĳһ˾����Ϣ
	w.set_title("˾����Ϣ");
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
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("�������ͣ�", 70, 350);
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
				w.message_warn(a, 20, "���˺��Ѵ���");
			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ĸ��������Ϊ����");
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
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "Ů" || s1 == "��" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�Ա�");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (unsigned int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)//�ж��Ƿ�Ϊ����
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�ֻ���");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, vehicle_type);
		if (s1 != "")
		{
			if (s1 == "�ػݿ쳵" || s1 == "�ε�ר��")
			{
				vehicle_type = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�������ͣ��ػݿ쳵��ε�ר��");
			}
			
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    �� ��    "))
		{
			if (check % 4 == 0)
			{
				int iage = stoi(age);
				//password = cur_driver->Getpassword(567);
				Driver driver(user, password, 2, name, sex, iage, tel, 2.5, vehicle_type);
				//passenger.Show();
				cur_driver->SetData(driver);
				w.message_info(a, 20, "�ѳɹ��޸�");
				//cur_shop->Show();
				//Driver* pcus = &passenger;
				//passenger.Show();
				//pcus->Show();
			}
			check++;
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    �� ��    "))
		{
			Widget w2(352, 469);
			user = password = name = age = sex = tel = payPassword = "";
			goto show_drivers;
		}
	}
	getchar();
passenger://�˿͵�½����
	w.set_title("�װ��ĳ˿ͣ�����");
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
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("֧�����룺", 70, 350);
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
				w.message_warn(a, 20, "���˺��Ѵ���");
			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ĸ��������Ϊ����");
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
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "Ů" || s1 == "��" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�Ա�");
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
			else w.message_warn(a, 20, "��������ȷ�ֻ���");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, payPassword);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				payPassword = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ĸ��������Ϊ����");
			}
		}
		

		if (w.set_button(mouse, 64, 395, 136, 415, "    �� ��    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || payPassword == "")
				{
					w.message_warn(a, 20, "�벻Ҫ©��");
					goto passenger;
				}
				int iage = stoi(age);
				//password = cur_passenger->Getpassword(567);
				Passenger passenger(user, password, 1, name, sex, iage, tel, payPassword);
				//passenger.Show();
				cur_passenger->SetData(passenger);
				w.message_info(a, 20, "�ѳɹ��޸�");
				//cur_passenger->Show();
				//passenger.Show();
				//pcus->Show();
				/*Widget w(352, 288);
				goto login_window;*/
			}
			check++;
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    �� ��    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = payPassword = "";
			goto login_window;
		}
		mouse1.x = 126;mouse1.y = 35;mouse1.mkLButton = true;
		if (w.set_button(mouse, 126, 35, 210, 55, "     ��  ��     "))
		{
			Widget w(790, 300);
			goto MakeOrder;
		}
		mouse1.x = 283; mouse1.y = 0; mouse1.mkLButton = true;
		if (w.set_button(mouse, 283, 0, 469, 20, "�鿴����"))
		{
			Widget w2(800, 500);
			goto orderfrom_passenger;
		}
	}
	getchar();



driver://˾����½����
	//����˾����Ϣ
	w.set_title("�װ���˾��������");
	user = cur_driver->Getuserid();
	//cout << user;
	password = cur_driver->Getpassword(567);
	name = cur_driver->Getname();
	age = to_string(cur_driver->Getage());
	sex = cur_driver->Getsex();
	tel = cur_driver->Gettel();
	payPassword = cur_driver->Get_vehicle_type();

	//����˾������
	temp_order = new Order_form;
	all_order = Ohead->next;
	TEMP_ON=0;
	while (all_order != NULL)
	{
		if (all_order->Getdriverid() == cur_driver->Getuserid() )
		{
			cout << "ע��";
			Order_form orderform = *all_order;
			Register(temp_order, orderform);
			TEMP_ON++;
		}
		all_order = all_order->next;
	}
	//temp_order->next = NULL;
	if (temp_order->next == NULL)
	{

		w.output("���������ڴ˴���ʾ...", 340, 70);
	}
	

	num2 = 0;
	xx1 = 370;
	yy1=40;	

	for (; 1;)
	{	

		mouse = GetMouseMsg();
		cout<<mouse.x<<"/" << mouse.y<<endl;
		//����˾����Ϣ
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("�������ͣ�", 70, 350);
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
				
				w.message_warn(a, 20, "���˺��Ѵ���");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ĸ��������Ϊ����");
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
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "Ů" || s1 == "��" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�Ա�");
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
			else w.message_warn(a, 20, "��������ȷ�ֻ���");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, payPassword);
		if (s1 != "")
		{
			payPassword = s1;
		}
		
		//����˾������
		if (temp_order->next != NULL)
		{
			cur_order = temp_order->next;
			// ��������� 8 * num2 ���ڵ㣬���ڷ�ҳ
			for (int i = 1; i <= 8 * num2 && cur_order != NULL; i++)
			{
				cur_order = cur_order->next; // �ƶ�����һ���ڵ�
			}
			w.set_button(mouse, xx1, 40, xx1 + 35, 60, "�˿�");
			w.set_button(mouse, xx1 + 100, 40, xx1 + 100 + 35, 60, "���");
			w.set_button(mouse, xx1 + 100 * 2, 40, xx1 + 100 * 2 + 35, 60, "�յ�");
			w.set_button(mouse, xx1 + 100 * 3, 40, xx1 + 100 * 3 + 35, 60, "״̬");
			for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && cur_order != NULL; num1++, i++, cur_order = cur_order->next)
			{

				w.set_button(mouse, xx1 - 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
				w.set_button(mouse, xx1 - 20, 40 + 40 * i, xx1 - 20 + 90, 40 * i + 60, cur_order->Getpasname());
				w.set_button(mouse, xx1 + 80, 40 + 40 * i, xx1 + 80 + 90, 40 * i + 60, cur_order->Getstart());
				w.set_button(mouse, xx1 + 180, 40 + 40 * i, xx1 + 180 + 90, 40 * i + 60, cur_order->Getend());
				switch (cur_order->Getflag())
				{
				case 2:
					temp_string = "����";
					mouse1.x = xx1 + 280; mouse1.y = 40 + 40 * i; mouse1.mkLButton = true;
					if (w.set_button(mouse, xx1 + 280, 40 + 40 * i, xx1 + 280 + 90, 40 * i + 60, temp_string))
					{
						if (check % 4 == 0)
						{
							//Find(Ohead, cur_order->Getnumber())->next->change_driver(cur_driver->Getname());
							//��ȡ�绰����
							temp_string = Find(Phead, cur_order->Getpasid(), "id")->next->Gettel();

							// ����ַ������ȣ�ȷ��������4λ
							if (temp_string.length() >= 4)
							{
								// ��ȡ�ַ����ĺ���λ
								temp_string = temp_string.substr(temp_string.length() - 4);
								temp_string_2 = w.message_info(a, 20, "������˿ͺ���λ�ֻ��ţ�");
								// ���������ַ����Ƿ���绰����ĺ���λ��ͬ
								if (temp_string_2 == temp_string)
								{
									Find(Ohead, cur_order->Getnumber())->next->mark(3);
									Find(temp_order, cur_order->Getnumber())->next->mark(3);
									//"����У��", "��У��", "����У��", "��У��", "У����"
									if (cur_order->Getstart() == "����У��")
									{
										int_start = 0;
									}
									else if(cur_order->Getstart() == "��У��")
									{
										int_start = 1;
									}
									else if (cur_order->Getstart() == "����У��")
									{
										int_start = 2;
									}
									else if (cur_order->Getstart() == "��У��")
									{
										int_start = 3;
									}
									else if (cur_order->Getstart() == "У����")
									{
										int_start = 4;
									}
									if (cur_order->Getend()== "����У��")
									{
										int_end = 0;
									}
									else if(cur_order->Getend() == "��У��")
									{
										int_end = 1;
									}
									else if (cur_order->Getend() == "����У��")
									{
										int_end = 2;
									}
									else if (cur_order->Getend() == "��У��")
									{
										int_end = 3;
									}
									else if (cur_order->Getend() == "У����")
									{
										int_end = 4;
									}

									vector<int> dist, prev;
									dijkstra(int_start, dist, prev);
									vector<int> path = getPath(int_start, int_end, prev);
									temp_string = "��Ϊ���滮·����";
									if (!path.empty()) {
										
										for (int node : path) {
											temp_string += nodeNames[node] + "->";
											//ȥ�����һ����ͷ
											if (node == path.back()) {
												temp_string = temp_string.substr(0, temp_string.length() - 2);
											}
										}
										temp_string=temp_string + "��ȫ�̣�" + to_string(dist[int_end]) + "����";
										//cout << "�ӽڵ�" << nodeNames[int_start] << "���ڵ�" << nodeNames[int_end] << "�ľ�����: " << dist[int_end] << endl;

									}

									//temp_string = "��ǰ��" + cur_order->Getend() + "���յ㣩";
									w.message_info(a, 20, temp_string.c_str());

								}
								else {
									w.message_warn(a, 20, "����λ�ֻ��Ų�����");
								}

							}
							else {
								w.message_warn(a, 20, "�绰����̫�̣��޷���ȡ����λ��");
							}

						}
						check++;
						//cout << check;
					}
					break;
				case 3:
					temp_string = "����";
					//w.set_button(mouse1, xx1 + 140 * 4, 40 + 40 * i, xx1 + 140 * 4 + 35, 40 * i + 60, "�ѽӵ�");
					mouse1.x = xx1 + 280; mouse1.y = 40 + 40 * i; mouse1.mkLButton = true;
					if (w.set_button(mouse, xx1 + 280, 40 + 40 * i, xx1 + 280 + 90, 40 * i + 60, temp_string))
					{
						if (check % 4 == 0)
						{
							temp_string = "�˿��Ƿ�������" + cur_order->Getend() + "?";
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
					temp_string = "δ֧��";
					if (w.set_button(mouse, xx1 + 280, 40 + 40 * i, xx1 + 280 + 90, 40 * i + 60, temp_string))
					{
						if (check % 4 == 0)
						{
							temp_string = "��ȴ��˿�֧��...";
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
					temp_string = "���";
					if (w.set_button(mouse, xx1 + 280, 40 + 40 * i, xx1 + 280 + 90, 40 * i + 60, temp_string))
					{
						if (check % 4 == 0)
						{
							temp_string = "��������ɣ�";
							w.message_question(a, 20, temp_string.c_str());
						}
						check++;
					}
					break;


				}

				//mouse1.x = xx1 + 140 * 4; mouse1.y = 40 + 40 * i; mouse1.mkLButton = true;


			}
			if (w.set_button(mouse, xx1, 400, xx1 + 70, 420, "  ��һҳ  "))
			{
				if (checknum % 4 == 0 && num2 > 0)
				{
					w.clear();

					num2--;
					//cout << num2;
				}
				checknum++;
			}
			if (w.set_button(mouse, 705 - 70, 400, 705, 420, "  ��һҳ  "))
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
		

		
		
		if (w.set_button(mouse, 64, 400, 136, 420, "    �� ��    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || payPassword == "")
				{
					w.message_warn(a, 20, "�벻Ҫ©��");
					goto driver;
				}
				int iage = stoi(age);
				//password = cur_driver->Getpassword(567);
				Driver customer(user, password, 1, name, sex, iage, tel, 2.5, payPassword);
				//passenger.Show();
				cur_driver->SetData(customer);
				w.message_info(a, 20, "�ѳɹ��޸�");
				//cur_shop->Show();
				//Driver* pcus = &passenger;
				//passenger.Show();
				//pcus->Show();
				/*Widget w(352, 288);
				goto login_window;*/
			}
		}




		if (w.set_button(mouse, 200, 400, 272, 420, "    �� ��    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = payPassword = "";
			goto login_window;
		}
		mouse1.x = 283; mouse1.y = 0; mouse1.mkLButton = true;
		if (w.set_button(mouse, 510, 1, 580, 21, "���ҳ˿�"))
		{
			Widget w2(700, 469);
			goto orderfrom_driver;
		}

	}
	getchar();

show_orders://���ж���
	w.set_title("�鿴����");
	num2 = 0;
	for (; 1;)
	{
		//������ʾĳһ����
		temp_order = new Order_form;//�˴������Ƿ��ܷ����棬���������temp_order->next=NULL;
		cur_order = Ohead->next;
		while (cur_order != NULL )
		{
			if (cur_order->Getnumber() == ("9999999" <= user || user == "" ? 0 : stoi(user)))
			{
				cout << user;
				cout << "ע��";
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
		// ��������� 8 * num2 ���ڵ㣬���ڷ�ҳ
		for (int i = 1; i <= 8 * num2 && cur_order != NULL; i++)
		{
			cur_order = cur_order->next; // �ƶ�����һ���ڵ�
		}
		mouse = GetMouseMsg();
		w.set_button(mouse, 90, 40, 157, 60, "���û�");
		w.set_button(mouse, 215, 40, 250, 60, "˾��");
		w.output("����", 218, 4);
		s1 = w.cinbox(mouse, 253, 1, 351, 21, user);
		if (s1 != "")
		{
			user = s1;

			//cout<< stoi(user);
			if (Find(Ohead, ("9999999" <= user || user == "" ? 0 : stoi(user))) == NULL)
			{
				user = "δ��ѯ��";

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
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "ɾ��"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "ȷ��ɾ��"))
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
		if (w.set_button(mouse, 40, 400, 110, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   �� ��   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();

show_order://�鿴ĳһ����
	w.set_title("�鿴����" + to_string(cur_order->Getnumber()));
	if (cur_order->Getflag() == 1)
	{
		order_flag = "���ں���...";
	}
	if (cur_order->Getflag() == 2)
	{
		order_flag = "˾���ѽӵ�";
	}
	if (cur_order->Getflag() == 3)
	{
		order_flag = "�г̿�ʼ";
	}
	if (cur_order->Getflag() == 4)
	{
		order_flag = "�г̽�����δ֧��";
	}
	if (cur_order->Getflag() == 5)
	{
		order_flag = "���������";
	}
	
	for (; 1;)//��ʾ������Ϣ
	{
		mouse = GetMouseMsg();
		w.output("�µ��˿ͣ�", 70, 80);
		s1 = w.cinbox(mouse, 145, 78, 350, 98, cur_order->Getpasname());
		w.output("�ӵ�˾����", 70, 125);
		s1 = w.cinbox(mouse, 145, 123, 350, 143, cur_order->Getdrivername());
		w.output("��ʼ�ص㣺", 70, 170);
		s1 = w.cinbox(mouse, 145, 168, 350, 188, cur_order->Getstart());
		w.output("Ŀ�ĵص㣺", 70, 215);
		s1 = w.cinbox(mouse, 145, 214, 350, 234, cur_order->Getend());
		w.output("��������", 70, 260);
		s1 = w.cinbox(mouse, 145, 258, 350, 278, cur_order->Getvehicle_type());
		w.output("�������ѣ�", 70, 305);
		s1 = w.cinbox(mouse, 145, 302, 350, 322, to_string(cur_order->Getcost()).substr(0,5));
		w.output("����״̬",70, 350);
		s1=w.cinbox(mouse, 145, 346, 350, 366, order_flag);
		if (w.set_button(mouse, 114-40, 440, 186-40, 460, "    ȷ ��    "))
		{
			Widget w2(352, 469);
			w2.clear();
			goto show_orders;
		}
		if (w.set_button(mouse, 500-250, 440, 572-250, 460, "    �� ��    "))
		{
			Widget w2(352, 469);
			w2.clear();
			goto show_orders;
		}
	}
	
	getchar();

orderfrom_passenger://�˿��йض���
	w.set_title("�鿴����");

	//cout << cur_passenger->Getname();

	temp_order = new Order_form;
	all_order = Ohead->next;
	TEMP_ON = 0;
	while(all_order != NULL)
	{
		if (all_order->Getpasid() == cur_passenger->Getuserid())
		{
			//cout << "ע��";
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
			w.message_warn(a, 20, "����û���µ�");
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
		w.set_button(mouse, xx1, 40, xx1+50, 60, "���");
		w.set_button(mouse, xx1+120, 40, xx1+120+50, 60, "�յ�");
		w.set_button(mouse, xx1 + 120*2, 40, xx1 + 120*2 + 50, 60, "˾��");
		w.set_button(mouse, xx1 + 120 * 3, 40, xx1 + 120 * 3 + 50,60 , "����");
		w.set_button(mouse, xx1 + 120 * 4, 40, xx1 + 120 * 4 + 50, 60, "״̬");
		w.set_button(mouse, xx1 + 120 * 5, 40, xx1 + 120 * 5 + 50, 60, "����");

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
				temp_string = "�ȴ��ӵ�";
				w.set_button(mouse, xx1 + 430+20, 40 + 40 * i, xx1 + 450 + 100, 40 * i + 60, temp_string);
				if (w.set_button(mouse, xx1 + 550 + 20, 40 + 40 * i, xx1 + 570 + 100, 40 * i + 60, "ȡ��"))
				{
					if (check % 4 == 0)
					{
						if (w.message_question(a, 20, "ȷ��ȡ��������"))
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
				temp_string = "˾�����ڸ���...";
				mouse1.x = xx1 + 280; mouse1.y = 40 + 40 * i; mouse1.mkLButton = true;
				w.set_button(mouse, xx1 + 430 + 20, 40 + 40 * i, xx1 + 450 + 100, 40 * i + 60, temp_string);
				if (w.set_button(mouse, xx1 + 550 + 20, 40 + 40 * i, xx1 + 570 + 100, 40 * i + 60, "ȡ��"))
				{
					if (check % 4 == 0)
					{
						if (w.message_question(a, 20, "ȷ��ȡ��������"))
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
				//	//��ȡ�绰����
				//	temp_string = Find(Phead, cur_order->Getpasid(), "id")->next->Gettel();

				//	// ����ַ������ȣ�ȷ��������4λ
				//	if (temp_string.length() >= 4)
				//	{
				//		// ��ȡ�ַ����ĺ���λ
				//		temp_string = temp_string.substr(temp_string.length() - 4);
				//		temp_string_2 = w.message_info(a, 20, "������˿ͺ���λ�ֻ��ţ�");
				//		// ���������ַ����Ƿ���绰����ĺ���λ��ͬ
				//		if (temp_string_2 == temp_string)
				//		{
				//			Find(Ohead, cur_order->Getnumber())->next->mark(3);
				//			Find(temp_order, cur_order->Getnumber())->next->mark(3);
				//			temp_string = "��ǰ��" + cur_order->Getend() + "���յ㣩";

				//		}
				//		else {
				//			w.message_warn(a, 20, "����λ�ֻ��Ų�����");
				//		}

				//	}
				//	else {
				//		w.message_warn(a, 20, "�绰����̫�̣��޷���ȡ����λ��");
				//	}

				//}
				//check++;
				//cout << check;
				
				
			case 3:
				temp_string = "�г��ѿ�ʼ";
				//w.set_button(mouse1, xx1 + 140 * 4, 40 + 40 * i, xx1 + 140 * 4 + 35, 40 * i + 60, "�ѽӵ�");
				mouse1.x = xx1 + 280; mouse1.y = 40 + 40 * i; mouse1.mkLButton = true;
				w.set_button(mouse, xx1 + 430 + 20, 40 + 40 * i, xx1 + 450 + 100, 40 * i + 60, temp_string);
				if (w.set_button(mouse, xx1 + 550 + 20, 40 + 40 * i, xx1 + 570 + 100, 40 * i + 60, "ȡ��"))
				{
					if (check % 4 == 0)
					{
						w.message_warn(a, 20, "�г��ѿ�ʼ���޷�ȡ��");
					}
					check++;
					
				}
				break;

			case 4:
				temp_string = "δ֧��";
				w.set_button(mouse, xx1 + 430 + 20, 40 + 40 * i, xx1 + 450 + 100, 40 * i + 60, temp_string);
				if (w.set_button(mouse, xx1 + 550 + 20, 40 + 40 * i, xx1 + 570 + 100, 40 * i + 60, "���֧��"))
				{
					if (check % 4 == 0)
					{
						
						temp_string=w.message_info(a, 20, "������֧������");
						temp_string_2=cur_passenger->Get_payPassword();
						if(temp_string==temp_string_2)
						{
							Find(Ohead, cur_order->Getnumber())->next->mark(5);
							Find(temp_order, cur_order->Getnumber())->next->mark(5);
							w.clear();
						}
						else
						{
							w.message_warn(a, 20, "֧���������");
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

				temp_string = "�������";
				w.set_button(mouse, xx1 + 430 + 20, 40 + 40 * i, xx1 + 450 + 100, 40 * i + 60, temp_string);
				break;

			}
			

			//{
			//	if (check % 4 == 0)
			//	{
			//		if (cur_order->Getflag() == 2)
			//		{
			//			Find(Ohead, cur_order->Getnumber())->next->mark(3);
			//			w.message_warn(a, 20, "��ǩ��");
			//		}
			//		else
			//		{
			//			w.message_warn(a, 20, "˾����δ����");
			//		}
			//	}
			//	check++;
			//	//cout << check;
			//}
		}
		w.output("�������ѣ�", 40, 440);
		w.output(to_string(allcost).substr(0, 5), 130, 440);
		if (w.set_button(mouse, 40, 400, 110, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 630-70, 400, 630, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < TEMP_ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 300, 400, 300+65, 420, "   �� ��   "))
		{


			Widget w2(352, 469);
			w2.clear();
			goto passenger;

		}


	}

	getchar();





orderfrom_driver://˾���йض���
	w.set_title("���ҳ˿�");

	//cout << cur_passenger->Getname();
	temp_order = new Order_form;
	all_order = Ohead->next;
	while (all_order != NULL)
	{
		if (all_order->Getvehicle_type() == cur_driver->Get_vehicle_type())
		{
			cout << "ע��";
			Order_form orderform = *all_order;
			Register(temp_order, orderform);
		}
		all_order = all_order->next;
	}
	num2 = 0;
	xx1 = 60;
	if (temp_order->next == NULL)
	{
		w.message_warn(a, 20, "���޶���");
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
		
		// ��������� 8 * num2 ���ڵ㣬���ڷ�ҳ
		for (int i = 1; i <= 8 * num2 && cur_order != NULL; i++)
		{
			cur_order = cur_order->next; // �ƶ�����һ���ڵ�
		}
		mouse = GetMouseMsg();
		cout<<mouse.x<<"/" << mouse.y<<endl;
		w.set_button(mouse, 100, 40, 100 + 35, 60, "�˿�");
		w.set_button(mouse, 100 + 150, 40, 100 + 150 + 35, 60, "���");
		w.set_button(mouse, 100 + 150 * 2, 40, 100 + 150 * 2 + 35, 60, "�յ�");
		w.set_button(mouse, 100 + 150 * 3, 40, 100 + 150 * 3 + 35, 60, "����");


		for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && cur_order != NULL; num1++, i++, cur_order = cur_order->next)
		{

			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, cur_order->Getpasname());
			w.set_button(mouse, xx1 + 140, 40 + 40 * i, xx1+ 140 + 120, 40 * i + 60, cur_order->Getstart());
			w.set_button(mouse, xx1 + 140*2, 40 + 40 * i, xx1 + 140*2 + 120, 40 * i + 60, cur_order->Getend());
			w.set_button(mouse, xx1 + 140 * 3, 40 + 40 * i, xx1 + 140 * 3 + 120, 40 * i + 60, to_string(cur_order->Getcost()).substr(0,5));
			mouse1.x=xx1 + 140 * 4; mouse1.y = 40 + 40 * i; mouse1.mkLButton = true;
			temp_string= cur_order->Getflag() == 1 ? "�ӵ�" : "�ѽӵ�";
			if (w.set_button(mouse, xx1 + 140*4, 40 + 40 * i, xx1 + 140 * 4+55, 40 * i + 60,temp_string))
			{
				if (check % 4 == 0)
				{
					if (temp_string == "�ӵ�")
					{
						Find(Ohead, cur_order->Getnumber())->next->mark(2);
						Find(temp_order, cur_order->Getnumber())->next->mark(2);
						Find(Ohead, cur_order->Getnumber())->next->change_driver(cur_driver->Getname());
						Find(temp_order, cur_order->Getnumber())->next->change_driver(cur_driver->Getname());
						Find(Ohead, cur_order->Getnumber())->next->change_driver_id(cur_driver->Getuserid());
						Find(temp_order, cur_order->Getnumber())->next->change_driver_id(cur_driver->Getuserid());
						temp_string = "�ѽӵ�������10������ǰ��" + cur_order->Getstart() + "����㣩";
						//w.set_button(mouse1, xx1 + 140 * 4, 40 + 40 * i, xx1 + 140 * 4 + 35, 40 * i + 60, "�ѽӵ�");
						w.message_info(a, 20, temp_string.c_str());
					}
					
				}
				check++;
				//cout << check;
			}
		}
		if (w.set_button(mouse, 40, 400, 110, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 590, 400, 660, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 310, 400, 195+180, 420, "   �� ��   "))
		{


			Widget w2(800, 469);
			w2.clear();
			goto driver;

		}


	}

	getchar();


	
register_passenger://�˿�ע��
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.set_title("�˿�ע��");
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("֧�����룺", 70, 350);
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
				w.message_warn(a, 20, "���˺��Ѵ���");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ĸ��������Ϊ����");
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
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "Ů" || s1 == "��" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�Ա�");
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
			else w.message_warn(a, 20, "��������ȷ�ֻ���");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, payPassword);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				payPassword = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ĸ��������Ϊ����");
			}
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    ע ��    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || payPassword == "")
				{
					
					w.message_warn(a, 20, "�벻Ҫ©��");
					goto register_passenger;
				}

				int iage = stoi(age);
				Passenger customer(user, password, 1, name, sex, iage, tel, payPassword);
				//Driver* pcus = &passenger;
				//passenger.Show();
				Register(Phead, customer);//����ֵĶ������⣬����iageȫ��д���ļ���ʧ���ݡ�
				//pcus->Show();
				PN++;
				w.message_info(a, 20, "ע��ɹ�");
				Widget w(352, 288);
				goto login_window;
			}
			check++;
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    �� ��    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = payPassword = "";
			goto login_window;
		}
	}
	getchar();



register_driver://˾��ע��
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.set_title("˾��ע��");
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("�������ͣ�", 70, 350);
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
				
				w.message_warn(a, 20, "���˺��Ѵ���");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ĸ��������Ϊ����");
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
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "Ů" || s1 == "��" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�Ա�");
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
			else w.message_warn(a, 20, "��������ȷ�ֻ���");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, payPassword);
		if (s1 != "")
		{
			payPassword = s1;
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    ע ��    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || payPassword == "")
				{
					
					w.message_warn(a, 20, "�벻Ҫ©��");
					goto register_driver;
				}
				int iage = stoi(age);
				Driver customer(user, password, 2, name, sex, iage, tel, 2.5, payPassword);
				//Driver* pcus = &customer;
				//passenger.Show();
				Register(Dhead, customer);
				//pcus->Show();
				DN++;
				w.message_info(a,20,"ע��ɹ�");
				Widget w(352, 288);
				goto login_window;
			}
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    �� ��    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = payPassword = "";
			goto login_window;
		}
	}
	getchar();



MakeOrder://���µ���ѡ����㡢�յ�
	w.set_title("��");
	

	// ����ͼ���ļ����ļ���Ϊ "example.jpg"
	// ��ȷ��ͼ���ļ����ִ���ļ���ͬһĿ¼����ʹ������·��
	loadimage(&img, _T("./Location.png"));

	// ��ͼ����ʾ�ڴ����е� (0, 0) λ��
	putimage(0, 0, &img);
	start = end = vehicle_type_1 = "";
	int_start = 0; int_end = 0;
	cost = 0;
	for (; 1;)
	{
		
		/*start = "����У��";
		end="��У��";
		vehicle_type_1="�ε�ר��";*/
		mouse = GetMouseMsg();
		cout<<mouse.x<<'/'<<mouse.y<<endl;
		w.set_title("��");
		w.output("��㣺", 70+420 + 76, 80);
		temp_string = w.cinbox(mouse, 130+420 + 76, 78, 266+420 + 76, 98, start);//�����������򣬷���������ַ���
		if (temp_string != "")
		{
			// "����У��", "��У��", "����У��", "��У��", "У����"
			if (temp_string == "����У��")
			{
				start = temp_string;
				int_start = 0;
			}
			else if(temp_string == "��У��")
			{
				start = temp_string;
				int_start = 1;
			}
			else if (temp_string == "����У��")
			{
				start = temp_string;
				int_start = 2;
			}
			else if (temp_string == "��У��")
			{
				start = temp_string;
				int_start = 3;
			}
			else if (temp_string == "У����")
			{
				start = temp_string;
				int_start = 4;
			}
			else
			{
				w.message_warn(a, 20, "��Ǹ��Ŀǰֻ�ṩ���У���Ĵ򳵷���");
			}
		}
		w.output("�յ㣺", 70+420 + 76, 125);
		temp_string = w.cinbox(mouse, 130 + 420 + 76, 123, 266 + 420 + 76, 143, end);//
		if (temp_string != "")
		{
			if(temp_string == "����У��")
			{
				end = temp_string;
				int_end = 0;
			}
			else if (temp_string == "��У��")
			{
				end = temp_string;
				int_end = 1;
			}
			else if (temp_string == "����У��")
			{
				end = temp_string;
				int_end = 2;
			}
			else if (temp_string == "��У��")
			{
				end = temp_string;
				int_end = 3;
			}
			else if (temp_string == "У����")
			{
				end = temp_string;
				int_end = 4;
			}
			else
			{
				w.message_warn(a, 20, "��Ǹ��Ŀǰֻ�ṩ���У���Ĵ򳵷���");
			}
		}
		w.output("���ͣ�", 70 + 420 + 76, 125-80+125);
		temp_string = w.cinbox(mouse, 130 + 420 + 76, 123 - 78 + 123, 266 + 420 + 76, 143 + 143 - 98, vehicle_type_1);
		if (temp_string != "")
		{
			if (temp_string == "�ػݿ쳵" || temp_string == "�ε�ר��")
			{
				vehicle_type_1 = temp_string;
			}
			else
			{
				 w.message_warn(a, 20, "��Ǹ��Ŀǰֻ�ṩ�ε�ר�����ػݿ쳵");
			}
			
		}
		
		
		mouse1.x = 64; mouse1.y = 214; mouse1.mkLButton = true;
		if (w.set_button(mouse, 64 + 420+76, 214, 136 + 420 + 76, 234, "    �� ��    "))
		{
			if (check % 4 == 0)
			{
				if (start == "" || end == "" || vehicle_type_1 == "")
				{
					w.message_warn(a, 20, "�벻Ҫ©��");
					goto MakeOrder;
				}
				if (vehicle_type_1 == "�ػݿ쳵")
				{
					vector<int> dist, prev;
					dijkstra(int_start, dist, prev);
					cost = dist[int_end] * 1.5;
					temp_string = "��㣺" + start + " �յ㣺" + end + " ���ͣ�" + vehicle_type_1 + " ���ã�" + to_string(cost) + "Ԫ";
					if (w.message_question(a, 20, temp_string.c_str()))
					{
						Order_form orderform(ON + 1, cur_passenger->Getuserid(), cur_passenger->Getname(), "*", "*", start, end, vehicle_type_1, 1, cost);
						Register(Ohead, orderform);
						ON++;
						w.message_info(a, 20, "���µ�����ȴ�˾���ӵ�");
						Widget w2(352, 469);
						goto passenger;
					}
					
				}
				else if(vehicle_type_1 == "�ε�ר��")
				{
					vector<int> dist, prev;
					dijkstra(int_start, dist, prev);
					cost = dist[int_end] * 2;
					temp_string = "��㣺" + start + " �յ㣺" + end + " ���ͣ�" + vehicle_type_1 + " ���ã�" + to_string(cost) + "Ԫ";
					if (w.message_question(a, 20, temp_string.c_str()))
					{
						Order_form orderform(ON + 1, cur_passenger->Getuserid(), cur_passenger->Getname(), "*", "*", start, end, vehicle_type_1, 1, cost);
						Register(Ohead, orderform);
						ON++;
						w.message_info(a, 20, "���µ�����ȴ�˾���ӵ�");
						Widget w2(352, 469);
						goto passenger;
					}
				}
			}
			check++;
		}

		if (w.set_button(mouse, 200 + 420 + 76, 214, 272 + 420 + 76, 234, "    �� ��    "))
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


end://����¼���ļ�
	writeto("passenger.txt", Phead, PN);
	writeto("driver.txt", Dhead, DN);
	writeto("order.txt", Ohead, ON);
	return 0;
}