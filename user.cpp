#include"user.h"
#include<iostream>

using namespace std;
//基础数据处理
void Passenger::SetData(Passenger obj)//用户信息复制（可视化使用）
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

void Driver::SetData(Driver obj)//司机复制函数（可视化使用）
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

void Order_form::SetData(Order_form obj)//订单复制函数（可视化使用）
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
}//订单由于并不在黑框下操作，所以未设置其他设置数据函数
//以下为展示各类详细数据的函数（订单未设计）
void User::Show()
{
	cout << "昵称：" << this->userid << endl;
	switch (this->kind)
	{
	case 1:cout << "乘客" << endl; break;
	case 2:cout << "司机" << endl; break;
	}
}
void Person::Show()
{
	this->User::Show();
	cout << "姓名" << this->name << endl;
	cout << "年龄" << this->age << endl;
	cout << "性别" << this->sex << endl;
	cout << "联系方式" << this->tel << endl;
}
void Passenger::Show()
{
	this->Person::Show();
	cout << "地址" << this->payPassword << endl;
}
void Driver::Show()
{
	this->Person::Show();
	cout << "车辆类型" << this->vehicle_type << endl;
}

int User::Login(string username, string password)//登陆验证函数
{
	//cout << this->password << endl;
	if (this->userid == username && this->password == password)
	{
		return 1;
	}
	else return 0;
}

//--------------------------------------
//数据添加
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
//登录验证
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


//相应的查询函数
Passenger* Find(Passenger* head, string user,string find_type)//通过用户姓名或是用户id
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
Driver* Find(Driver* head, string user, string find_type)//通过司机姓名
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

Order_form* Find(Order_form* head, int num)//通过订单编号
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
//输入检查函数
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
		// 检查字符是否为数字(0-9)，大写字母(A-Z)或小写字母(a-z)
		if (!((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))) 
		{
			// 如果字符不是数字或字母，输出该字符
			cout << str[i];
			// 返回 false 表示字符串不合法
			return false;
		}
	}
	// 如果所有字符都是合法的，返回 true
	return true;
}

//删除函数
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
//文件写入
void writeto(string filename, Passenger* head, int PN) {
	if (head == NULL) {
		cerr << "头指针为空" << endl;
		return;
	}

	// 打开文件进行输出操作
	ofstream file1(filename, ios_base::out);
	if (!file1) {
		cerr << "打开文件出错: " << filename << endl;
		abort();
	}
	file1 << PN << endl;
	file1.close();

	// 以追加模式打开文件
	ofstream file2(filename, ios::out | ios::app | ios::_Nocreate);
	if (!file2) {
		cerr << "打开文件出错: " << filename << endl;
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
//		abort();//退出程序
//	}
//	file1 << PN << endl;
//	file1.close();
//	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);//_Nocreate不覆盖,app追加,out输出
//	if (!file2)
//	{
//		cerr << " open error!" << endl;
//		abort();//退出程序
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
		cerr << "头指针为空" << endl;
		return;
	}

	// 打开文件进行输出操作
	ofstream file1(filename, ios_base::out);
	if (!file1) {
		cerr << "打开文件出错: " << filename << endl;
		abort();
	}
	file1 << DN << endl;
	file1.close();

	// 以追加模式打开文件
	ofstream file2(filename, ios::out | ios::app | ios::_Nocreate);
	if (!file2) {
		cerr << "打开文件出错: " << filename << endl;
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
//		abort();//退出程序
//	}
//	file1 << i << endl;
//	file1.close();
//	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);
//	if (!file2)
//	{
//		cerr << " open error!" << endl;
//		abort();//退出程序
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
		cerr << "头指针为空" << endl;
		return;
	}

	// 打开文件进行输出操作
	ofstream file1(filename, ios_base::out);
	if (!file1) {
		cerr << "打开文件出错: " << filename << endl;
		abort();
	}
	file1 << ON << endl;
	file1.close();

	// 以追加模式打开文件
	ofstream file2(filename, ios::out | ios::app | ios::_Nocreate);
	if (!file2) {
		cerr << "打开文件出错: " << filename << endl;
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
//		abort();//退出程序
//	}
//	file1 << i << endl;
//	file1.close();
//	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);
//	if (!file2)
//	{
//		cerr << " open error!" << endl;
//		abort();//退出程序
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
//文件读取
int readfrom(string filename, Passenger* head)
{
	int PN;
	ifstream file(filename, ios::in);
	if (!file)
	{
		cerr << "打开文件错误!" << endl;
		abort(); // 退出程序
	}

	file >> PN;
	Passenger* cur_passenger = head;
	for (int i = 0; i < PN; ++i)
	{
		cur_passenger->next = new Passenger;
		if (cur_passenger->next == NULL)
		{
			cerr << "内存分配错误!" << endl;
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
//		abort();//退出程序
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
		cerr << "打开文件错误!" << endl;
		abort(); // 退出程序
	}

	file >> DN;
	Driver* cur_driver = head;
	for (int i = 0; i < DN; ++i)
	{
		cur_driver->next = new Driver;
		if (cur_driver->next == NULL)
		{
			cerr << "内存分配错误!" << endl;
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
//		abort();//退出程序
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
		cerr << "打开文件错误!" << endl;
		abort(); // 退出程序
	}

	file >> ON;
	Order_form* cur_order = head;
	for (int i = 0; i < ON; ++i)
	{
		cur_order->next = new Order_form;
		if (cur_order->next == NULL)
		{
			cerr << "内存分配错误!" << endl;
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
//		abort();//退出程序
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

// Dijkstra算法返回从起始节点到所有其他节点的最短距离和路径
void dijkstra(int start, vector<int>& dist, vector<int>& prev) {
	const int INF = 100000; // 表示无穷大
	const int N = 5; // 图的节点数量

	// 用邻接表表示的图，{权重, 目标节点}
	//"铁道校区", "新校区", "湘雅校区", "南校区", "校本部"
	vector<pair<int, int>> adj[N] = {
		{{7, 1}, {7, 2}},  // 铁道校区的邻接节点
		{{4, 3}, {5, 4},{7,0}},  // 新校区的邻接节点
		{{7, 0},{8,4}},          // 湘雅校区的邻接节点
		{{4, 4},{4,1}},          // 南校区的邻接节点
		{{5,1 },{8,2},{4,3}}           // 校本部的邻接节点
	};
	dist.assign(N, INF); // 初始化距离数组
	prev.assign(N, -1);  // 初始化前驱节点数组
	dist[start] = 0;     // 起始节点到自身的距离为0
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;//一个优先队列，存储待处理的节点及其当前距离，初始时只包含起点，距离为0。
	pq.push({ 0, start });

	while (!pq.empty()) {
		int d = pq.top().first;// 起始节点到当前节点的距离
		int v = pq.top().second;// 当前节点
		pq.pop();

		if (d > dist[v]) continue;// 如果当前距离大于已知最短距离，跳过

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
	vector<int> path;// 用于存储路径
	for (int at = goal; at != -1; at = prev[at]) {
		path.push_back(at);//从目标节点开始，沿前驱节点逆向追溯路径
	}
	reverse(path.begin(), path.end());// 反转路径，使其从起点到目标节点
	if (path[0] == start) {// 检查路径是否以起点开始
		return path;// 返回路径
	}
	return {}; // 如果路径的起始节点不是start，返回空路径
}
