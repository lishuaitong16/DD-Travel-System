#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"widget.h"
#include <vector>
#include <queue>

using namespace std;
class User//�˺��������
{
protected:
	string userid, password;
	int kind;
public:
	User() { userid = " "; password = " "; kind = 0; };
	User(string userid, string password, int kind) { this->userid = userid, this->password = password, this->kind = kind; };
	void SetData(int kind);
	void Show();
	string Getuserid() { return this->userid; };
	int Getkind() { return this->kind; };
	string Getpassword(int i) { if (i == 567)return this->password; else return ""; };
	int Login(string username, string password);
};
class Person :public User//������Ϣ����
{
protected:
	string name;
	string sex;
	int age;
	string tel;//��ϵ��ʽ
public:
	Person(string username, string password, int kind, string name, string sex, int age, string tel) :User(username, password, kind) { this->name = name; this->sex = sex, this->age = age, this->tel = tel; };
	Person() :User() { name = ""; sex = ""; age = 0; tel = "00000000000"; };
	void SetData(int kind);
	void Show();
	string Getname() { return this->name; };
	string Getsex() { return this->sex; };
	string Gettel() { return this->tel; };
	int Getage() { return this->age; };
	~Person() { cout << "������������ͭ8205210820��д" << endl; };
};

class Passenger :virtual public Person//�˿���
{
	//friend class Order_form;//�����������������Ԫ��������ʵ�ǰ���˽�У�private���ͱ�����protected����Ա��
	string payPassword;//֧������
public:
	Passenger* next;
	Passenger(string username, string password, int kind, string name, string sex, int age, string tel, string add) :Person(username, password, kind, name, sex, age, tel) { payPassword = add; next = NULL; };
	Passenger() :Person() { payPassword = "  "; next = NULL; };
	void SetData(int kind);
	void SetData(Passenger cus);
	void Show();
	string Get_payPassword() { return this->payPassword; };
	friend ifstream& operator>>(ifstream& scin, Passenger& obj)
	{
		scin >> obj.userid;
		scin >> obj.name;
		scin >> obj.age;
		scin >> obj.sex;
		scin >> obj.tel;
		scin >> obj.payPassword;
		scin >> obj.password;
		scin >> obj.kind;
		return scin;
	};
	friend ofstream& operator<<(ofstream& scout, Passenger& obi)
	{
		scout << obi.userid << " ";
		scout << obi.name << " ";
		scout << obi.age << " ";
		scout << obi.sex << " ";
		scout << obi.tel << " ";
		scout << obi.payPassword << " ";
		scout << obi.password << " ";
		scout << obi.kind << endl;
		return scout;
	};
};
class Driver :virtual public Person//˾����
{
	//friend class Order_form;
	float score;//����
	string vehicle_type;//����
public:
	Driver* next;
	Driver(string username, string password, int kind, string name, string sex, int age, string tel, float score, string vehicle_type) :Person(username, password, kind, name, sex, age, tel) { this->score = score; this->vehicle_type = vehicle_type; next = NULL; };
	Driver() :Person() { score = 0.0; next = NULL; vehicle_type = ""; };
	void SetData(int kind);
	void SetData(Driver obj);
	void Show();
	string Get_vehicle_type() { return this->vehicle_type; };
	float Getscore() { return this->score; };
	friend ifstream& operator>>(ifstream& scin, Driver& obj)
	{
		scin >> obj.userid;
		scin >> obj.name;
		scin >> obj.age;
		scin >> obj.sex;
		scin >> obj.tel;
		scin >> obj.vehicle_type;
		scin >> obj.score;
		scin >> obj.password;
		scin >> obj.kind;
		return scin;
	};
	friend ofstream& operator<<(ofstream& scout, Driver& obj)
	{
		scout << obj.userid << " ";
		scout << obj.name << " ";
		scout << obj.age << " ";
		scout << obj.sex << " ";
		scout << obj.tel << " ";
		scout << obj.vehicle_type << " ";
		scout << obj.score << " ";
		scout << obj.password << " ";
		scout << obj.kind << endl;
		return scout;
	};
};

class Location//�ص�
{
	string name;
	double lat ;//ά��
	double lon;//����
public:
	Location* next;
	Location() { name = ""; lat = 0; lon = 0; next = NULL; }
	Location(string name, double lat, double lon) { this->name = name; this->lat = lat; this->lon = lon; next = NULL; }
	double get_lat() { return lat; }
	double get_lon() { return lon; }
};
class Order_form//������
{
	int number;
	int flag;//����״̬1�µ�2����3�յ�
	double cost;
	string passenger_name;
	string start;
	string end;
	string driver_name;
	string vehicle_type;
	string passenger_id;
	string driver_id;
	
public:
	Order_form* next;
	Order_form() { number = 0; cost = 0;  flag = 0;  passenger_name  = driver_name = start = end = vehicle_type = passenger_id = driver_id = ""; next = NULL; };
	Order_form(int number,string passenger_id,string passenger_name,string driver_id,string driver_name,string start,string end,string vehicle_type_1,int flag,double cost) 
	{
		this->number = number;
		this->passenger_id = passenger_id;
		this->passenger_name = passenger_name;
		this->driver_id = driver_id;
		this->driver_name = driver_name;
		this->start = start;
		this->end = end;
		this->vehicle_type = vehicle_type_1;
		this->flag = flag;
		this->cost = cost;
		next = NULL;
	};
	void mark(int i) { this->flag = i; };
	void change_driver(string driver_name) { this->driver_name = driver_name; };
	void change_driver_id(string driver_id) { this->driver_id = driver_id; };
	void change_number(int number) { this->number = number; };
	void SetData(Order_form o);
	string Getpasname() { return this->passenger_name; };
	string Getpasid() { return this->passenger_id; };
	string Getdrivername() { return this->driver_name; };
	string Getdriverid() { return this->driver_id; };
	string Getstart() { return this->start; };
	string Getend() { return this->end; };
	string Getvehicle_type() { return this->vehicle_type; };
	int Getnumber() { return this->number; };
	int Getflag() { return this->flag; };
	double Getcost() { return this->cost; };
	friend ifstream& operator>>(ifstream& scin, Order_form& obj)
	{
		scin >> obj.number;
		scin >> obj.flag;
		scin >> obj.cost;
		scin >> obj.passenger_id;
		scin >> obj.passenger_name;
		scin >> obj.start;
		scin >> obj.end;
		scin >> obj.driver_id;
		scin >> obj.driver_name;
		scin >> obj.vehicle_type;
		

		return scin;
	}
	friend ofstream& operator<<(ofstream& scout, Order_form& obj)
	{
		scout << obj.number << " ";
		scout << obj.flag << " ";
		scout << obj.cost << " ";
		scout << obj.passenger_id << " ";
		scout << obj.passenger_name << " ";
		scout << obj.start << " ";
		scout << obj.end << " ";
		scout << obj.driver_id << " ";
		scout << obj.driver_name << " ";
		scout << obj.vehicle_type << endl;
		

		return scout;
	}

};