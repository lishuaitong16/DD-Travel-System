#include"user.h"
#include<iostream>

using namespace std;
//�������ݴ���
void Passenger::SetData(Passenger obj)//�û���Ϣ���ƣ����ӻ�ʹ�ã�
{
	this->userid = obj.userid;
	this->password = obj.password;
	this->kind = obj.kind;
	this->name = obj.name;
	this->age = obj.age;
	this->sex = obj.sex;
	this->tel = obj.tel;
	this->payPassword = obj.payPassword;
}

void Driver::SetData(Driver obj)//˾�����ƺ��������ӻ�ʹ�ã�
{
	this->userid = obj.userid;
	this->password = obj.password;
	this->kind = obj.kind;
	this->name = obj.name;
	this->age = obj.age;
	this->sex = obj.sex;
	this->tel = obj.tel;
	this->vehicle_type = obj.vehicle_type;
	this->score = obj.score;
}

void Order_form::SetData(Order_form obj)//�������ƺ��������ӻ�ʹ�ã�
{
	this->number = obj.number;
	this->passenger_name = obj.passenger_name;
	this->driver_name = obj.driver_name;
	this->cost = obj.cost;
	this->flag = obj.flag;
	this->start = obj.start;
	this->end = obj.end;
	this->vehicle_type = obj.vehicle_type;
	this->driver_id = obj.driver_id;
	this->passenger_id = obj.passenger_id;
}//�������ڲ����ںڿ��²���������δ���������������ݺ���
//����Ϊչʾ������ϸ���ݵĺ���������δ��ƣ�
void User::Show()
{
	cout << "�ǳƣ�" << this->userid << endl;
	switch (this->kind)
	{
	case 1:cout << "�˿�" << endl; break;
	case 2:cout << "˾��" << endl; break;
	}
}
void Person::Show()
{
	this->User::Show();
	cout << "����" << this->name << endl;
	cout << "����" << this->age << endl;
	cout << "�Ա�" << this->sex << endl;
	cout << "��ϵ��ʽ" << this->tel << endl;
}
void Passenger::Show()
{
	this->Person::Show();
	cout << "��ַ" << this->payPassword << endl;
}
void Driver::Show()
{
	this->Person::Show();
	cout << "��������" << this->vehicle_type << endl;
}

int User::Login(string username, string password)//��½��֤����
{
	//cout << this->password << endl;
	if (this->userid == username && this->password == password)
	{
		return 1;
	}
	else return 0;
}

//--------------------------------------
//�������
void Register(Passenger* head, Passenger obj)
{
	Passenger* new_passenger, * q;
	q = new Passenger;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = head; q->next != NULL; q = q->next)
	{

	}
	new_passenger = new Passenger;
	if (new_passenger == NULL)
	{
		cout << "p->error" << endl;
	}
	new_passenger->SetData(obj);
	q->next = new_passenger;
}
void Register(Driver* head, Driver obj)
{
	Driver* new_driver, * q;
	q = new Driver;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = head; q->next != NULL; q = q->next)
	{

	}
	new_driver = new Driver;
	if (new_driver == NULL)
	{
		cout << "p->error" << endl;
	}
	new_driver->SetData(obj);
	q->next = new_driver;
}


void Register(Order_form* head, Order_form obj)
{
	Order_form* new_order, * q;
	q = new Order_form;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = head; q->next != NULL; q = q->next)
	{

	}
	new_order = new Order_form;
	if (new_order == NULL)
	{
		cout << "p->error" << endl;
	}
	new_order->SetData(obj);
	//cout << "re"<<endl;
	//p->Show();
	q->next = new_order;
}
//��¼��֤
Passenger* Login(Passenger* head, string user, string password)
{

	Passenger* q;
	q = new Passenger;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}

	for (q = head; q->next != NULL; q = q->next)
	{
		//cout << q->next->Getuser() << endl;
		if ((q->next->Login(user, password)) == 1)
		{

			return q->next;
		}
	}
	return head;
}

Driver* Login(Driver* head, string user, string password)
{
	Driver* q;
	q = new Driver;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = head; q->next != NULL; q = q->next)
	{
		if ((q->next->Login(user, password)) == 1)
		{
			//cout << 4;
			return q->next;
		}
	}
	return head;
}


//��Ӧ�Ĳ�ѯ����
Passenger* Find(Passenger* head, string user,string find_type)//ͨ���û����������û�id
{
	if (find_type == "name")
	{
		Passenger* q;
		q = new Passenger;
		if (q == NULL)
		{
			cout << "q->error" << endl;
		}

		for (q = head; q->next != NULL; q = q->next)
		{
			//cout << q->next->Getuser() << endl;
			if (q->next->Getname() == user)
			{

				return q;
			}
		}
		return NULL;
	}
	else if (find_type == "id")
	{
		Passenger* q;
		q = new Passenger;
		if (q == NULL)
		{
			cout << "q->error" << endl;
		}

		for (q = head; q->next != NULL; q = q->next)
		{
			//cout << q->next->Getuser() << endl;
			if (q->next->Getuserid() == user)
			{

				return q;
			}
		}
		return NULL;
	}
	return NULL;
}
Driver* Find(Driver* head, string user, string find_type)//ͨ��˾������
{
	if (find_type == "name")
	{
		Driver* q;
		q = new Driver;
		if (q == NULL)
		{
			cout << "q->error" << endl;
		}
		for (q = head; q->next != NULL; q = q->next)
		{
			if (q->next->Getname() == user)
			{
				return q;
			}
		}
		return NULL;
	}
	else if (find_type == "id")
	{
		Driver* q;
		q = new Driver;
		if (q == NULL)
		{
			cout << "q->error" << endl;
		}
		for (q = head; q->next != NULL; q = q->next)
		{
			if (q->next->Getuserid() == user)
			{
				return q;
			}
		}
		return NULL;
	}
	return NULL;
	
}

Order_form* Find(Order_form* head, int num)//ͨ���������
{
	Order_form* q;
	q = new Order_form;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = head; q->next != NULL; q = q->next)
	{
		if (q->next->Getnumber() == num)
		{
			return q;
		}
	}
	return NULL;
}
//�����麯��
Passenger* Check(Passenger* head, string user)
{
	Passenger* q;
	q = new Passenger;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}

	for (q = head; q->next != NULL; q = q->next)
	{
		//cout << q->next->Getuser() << endl;
		if (q->next->Getuserid() == user)
		{

			return q;
		}
	}
	return NULL;
}
Driver* Check(Driver* head, string user)
{
	Driver* q;
	q = new Driver;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = head; q->next != NULL; q = q->next)
	{
		if (q->next->Getuserid() == user)
		{
			return q;
		}
	}
	return NULL;
}
bool Check(string str) 
{
	for (unsigned int i = 0; i < str.length(); i++) 
	{
		// ����ַ��Ƿ�Ϊ����(0-9)����д��ĸ(A-Z)��Сд��ĸ(a-z)
		if (!((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))) 
		{
			// ����ַ��������ֻ���ĸ��������ַ�
			cout << str[i];
			// ���� false ��ʾ�ַ������Ϸ�
			return false;
		}
	}
	// ��������ַ����ǺϷ��ģ����� true
	return true;
}

//ɾ������
int delet(Passenger* p, int i)
{
	i--;
	if (p->next->next != NULL)
	{
		p->next = p->next->next;
	}
	else
	{
		p->next = NULL;
	}
	return i;
}

int delet(Driver* p, int i)
{
	i--;
	if (p->next->next != NULL)
	{
		p->next = p->next->next;
	}
	else
	{
		p->next = NULL;
	}
	return i;
}
int delet(Order_form* p, int i)
{
	i--;
	if (p->next->next != NULL)
	{
		p->next = p->next->next;
		p->next->change_number(p->next->Getnumber()-1);
	}
	else
	{
		p->next = NULL;
	}
	return i;
}
//�ļ�д��
void writeto(string filename, Passenger* head, int PN) {
	if (head == NULL) {
		cerr << "ͷָ��Ϊ��" << endl;
		return;
	}

	// ���ļ������������
	ofstream file1(filename, ios_base::out);
	if (!file1) {
		cerr << "���ļ�����: " << filename << endl;
		abort();
	}
	file1 << PN << endl;
	file1.close();

	// ��׷��ģʽ���ļ�
	ofstream file2(filename, ios::out | ios::app | ios::_Nocreate);
	if (!file2) {
		cerr << "���ļ�����: " << filename << endl;
		abort();
	}

	Passenger* p = head->next;
	while (p != NULL) {
		file2 << *p;
		p = p->next;
	}
	file2.close();
}

//void writeto(string filename, Passenger* head, int PN)
//{
//	Passenger* q, * p;
//	p = new Passenger;
//	if (p == NULL)
//	{
//		cout << "p->error" << endl;
//	}
//	ofstream file1(filename, ios_base::out);
//	if (!file1)
//	{
//		cerr << " open error!" << endl;
//		abort();//�˳�����
//	}
//	file1 << PN << endl;
//	file1.close();
//	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);//_Nocreate������,app׷��,out���
//	if (!file2)
//	{
//		cerr << " open error!" << endl;
//		abort();//�˳�����
//	}
//	Passenger cus;
//	p = head; q = head->next;
//	for (; q != NULL; q = q->next)
//	{
//		file2 << *q;
//	}
//	file2.close();
//}
void writeto(string filename, Driver* head, int DN) {
	if (head == NULL) {
		cerr << "ͷָ��Ϊ��" << endl;
		return;
	}

	// ���ļ������������
	ofstream file1(filename, ios_base::out);
	if (!file1) {
		cerr << "���ļ�����: " << filename << endl;
		abort();
	}
	file1 << DN << endl;
	file1.close();

	// ��׷��ģʽ���ļ�
	ofstream file2(filename, ios::out | ios::app | ios::_Nocreate);
	if (!file2) {
		cerr << "���ļ�����: " << filename << endl;
		abort();
	}

	Driver* p = head->next;
	while (p != NULL) {
		file2 << *p;
		p = p->next;
	}
	file2.close();
}

//void writeto(string filename, Driver* c, int i)
//{
//	Driver* q, * p;
//	p = new Driver;
//	if (p == NULL)
//	{
//		cout << "p->error" << endl;
//	}
//	ofstream file1(filename, ios_base::out);
//	if (!file1)
//	{
//		cerr << " open error!" << endl;
//		abort();//�˳�����
//	}
//	file1 << i << endl;
//	file1.close();
//	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);
//	if (!file2)
//	{
//		cerr << " open error!" << endl;
//		abort();//�˳�����
//	}
//	Driver cus;
//	p = c; q = c->next;
//	for (; q != NULL; q = q->next)
//	{
//		file2 << *q;
//	}
//	file2.close();
//}

void writeto(string filename, Order_form* head, int ON) {
	if (head == NULL) {
		cerr << "ͷָ��Ϊ��" << endl;
		return;
	}

	// ���ļ������������
	ofstream file1(filename, ios_base::out);
	if (!file1) {
		cerr << "���ļ�����: " << filename << endl;
		abort();
	}
	file1 << ON << endl;
	file1.close();

	// ��׷��ģʽ���ļ�
	ofstream file2(filename, ios::out | ios::app | ios::_Nocreate);
	if (!file2) {
		cerr << "���ļ�����: " << filename << endl;
		abort();
	}

	Order_form* p = head->next;
	while (p != NULL) {
		file2 << *p;
		p = p->next;
	}
	file2.close();
}


//void writeto(string filename, Order_form* c, int i)
//{
//	Order_form* q, * p;
//	p = new Order_form;
//	if (p == NULL)
//	{
//		cout << "p->error" << endl;
//	}
//	ofstream file1(filename, ios_base::out);
//	if (!file1)
//	{
//		cerr << " open error!" << endl;
//		abort();//�˳�����
//	}
//	file1 << i << endl;
//	file1.close();
//	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);
//	if (!file2)
//	{
//		cerr << " open error!" << endl;
//		abort();//�˳�����
//	}
//	Order_form cus;
//	p = c; q = c->next;
//	for (; q != NULL; q = q->next)
//	{
//		//cout << "write" << endl;
//		//q->Show();
//		file2 << *q;
//	}
//	file2.close();
//}
//�ļ���ȡ
int readfrom(string filename, Passenger* head)
{
	int PN;
	ifstream file(filename, ios::in);
	if (!file)
	{
		cerr << "���ļ�����!" << endl;
		abort(); // �˳�����
	}

	file >> PN;
	Passenger* cur_passenger = head;
	for (int i = 0; i < PN; ++i)
	{
		cur_passenger->next = new Passenger;
		if (cur_passenger->next == NULL)
		{
			cerr << "�ڴ�������!" << endl;
			abort();
		}
		file >> *(cur_passenger->next);
		cur_passenger = cur_passenger->next;
	}
	file.close();
	return PN;
}

//int readfrom(string filename, Passenger* head)
//{
//	int pn;
//	ifstream file(filename, ios::in | ios::_Nocreate);
//	if (!file)
//	{
//		cerr << " open error!" << endl;
//		abort();//�˳�����
//	}
//	file >> pn;
//	Passenger* cur_passenger, * p;
//	p = new Passenger;
//	if (p == NULL)
//	{
//		cout << "p->error" << endl;
//	}
//	p = head; int i;
//	for (i = 0; pn != 0; pn--, i++)
//	{
//		cur_passenger = new Passenger;
//		if (cur_passenger == NULL)
//		{
//			cout << "q->error" << endl;
//		}
//		file >> *cur_passenger;
//		p->next = cur_passenger;
//		p = cur_passenger;
//	}
//	pn = i;
//	file.close();
//	return pn;
//	
//}
int readfrom(string filename, Driver* head)
{
	int DN;
	ifstream file(filename, ios::in);
	if (!file)
	{
		cerr << "���ļ�����!" << endl;
		abort(); // �˳�����
	}

	file >> DN;
	Driver* cur_driver = head;
	for (int i = 0; i < DN; ++i)
	{
		cur_driver->next = new Driver;
		if (cur_driver->next == NULL)
		{
			cerr << "�ڴ�������!" << endl;
			abort();
		}
		file >> *(cur_driver->next);
		cur_driver = cur_driver->next;
	}
	file.close();
	return DN;
}
//int readfrom(string filename, Driver* c)
//{
//	int cn;
//	ifstream file(filename, ios::in | ios::_Nocreate);
//	if (!file)
//	{
//		cerr << " open error!" << endl;
//		abort();//�˳�����
//	}
//	file >> cn;
//	Driver* q, * p;
//	p = new Driver;
//	if (p == NULL)
//	{
//		cout << "p->error" << endl;
//	}
//	p = c; int i;
//	for (i = 0; cn != 0; cn--, i++)
//	{
//		q = new Driver;
//		if (q == NULL)
//		{
//			cout << "q->error" << endl;
//		}
//		file >> *q;
//		p->next = q;
//		p = q;
//	}
//	cn = i;
//	file.close();
//	return cn;
//}
int readfrom(string filename, Order_form* head)
{
	int ON;
	ifstream file(filename, ios::in);
	if (!file)
	{
		cerr << "���ļ�����!" << endl;
		abort(); // �˳�����
	}

	file >> ON;
	Order_form* cur_order = head;
	for (int i = 0; i < ON; ++i)
	{
		cur_order->next = new Order_form;
		if (cur_order->next == NULL)
		{
			cerr << "�ڴ�������!" << endl;
			abort();
		}
		file >> *(cur_order->next);
		cur_order = cur_order->next;
	}
	file.close();
	return ON;
}
//int readfrom(string filename, Order_form* c)
//{
//	int cn;
//	ifstream file(filename, ios::in | ios::_Nocreate);
//	if (!file)
//	{
//		cerr << " open error!" << endl;
//		abort();//�˳�����
//	}
//	file >> cn;
//	Order_form* q, * p;
//	p = new Order_form;
//	if (p == NULL)
//	{
//		cout << "p->error" << endl;
//	}
//	p = c; int i;
//	for (i = 0; cn != 0; cn--, i++)
//	{
//		q = new Order_form;
//		if (q == NULL)
//		{
//			cout << "q->error" << endl;
//		}
//		file >> *q;
//		p->next = q;
//		p = q;
//	}
//	cn = i;
//	file.close();
//	return cn;
//}

// Dijkstra�㷨���ش���ʼ�ڵ㵽���������ڵ����̾����·��
void dijkstra(int start, vector<int>& dist, vector<int>& prev) {
	const int INF = 100000; // ��ʾ�����
	const int N = 5; // ͼ�Ľڵ�����

	// ���ڽӱ��ʾ��ͼ��{Ȩ��, Ŀ��ڵ�}
	//"����У��", "��У��", "����У��", "��У��", "У����"
	vector<pair<int, int>> adj[N] = {
		{{7, 1}, {7, 2}},  // ����У�����ڽӽڵ�
		{{4, 3}, {5, 4},{7,0}},  // ��У�����ڽӽڵ�
		{{7, 0},{8,4}},          // ����У�����ڽӽڵ�
		{{4, 4},{4,1}},          // ��У�����ڽӽڵ�
		{{5,1 },{8,2},{4,3}}           // У�������ڽӽڵ�
	};
	dist.assign(N, INF); // ��ʼ����������
	prev.assign(N, -1);  // ��ʼ��ǰ���ڵ�����
	dist[start] = 0;     // ��ʼ�ڵ㵽����ľ���Ϊ0
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;//һ�����ȶ��У��洢������Ľڵ㼰�䵱ǰ���룬��ʼʱֻ������㣬����Ϊ0��
	pq.push({ 0, start });

	while (!pq.empty()) {
		int d = pq.top().first;// ��ʼ�ڵ㵽��ǰ�ڵ�ľ���
		int v = pq.top().second;// ��ǰ�ڵ�
		pq.pop();

		if (d > dist[v]) continue;// �����ǰ���������֪��̾��룬����

		for (auto edge : adj[v]) {
			int u = edge.second;
			int weight = edge.first;

			if (dist[v] + weight < dist[u]) {
				dist[u] = dist[v] + weight;
				prev[u] = v;
				pq.push({ dist[u], u });
			}
		}
	}
}

vector<int> getPath(int start, int goal, const vector<int>& prev) {
	vector<int> path;// ���ڴ洢·��
	for (int at = goal; at != -1; at = prev[at]) {
		path.push_back(at);//��Ŀ��ڵ㿪ʼ����ǰ���ڵ�����׷��·��
	}
	reverse(path.begin(), path.end());// ��ת·����ʹ�����㵽Ŀ��ڵ�
	if (path[0] == start) {// ���·���Ƿ�����㿪ʼ
		return path;// ����·��
	}
	return {}; // ���·������ʼ�ڵ㲻��start�����ؿ�·��
}
