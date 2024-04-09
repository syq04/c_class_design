﻿#include<bits/stdc++.h>
#include <windows.h>
//#pragma warning(disable:4996)//use in visual code
using namespace std;

const int  W = 4, H = 4;//height,width,number of expressman
int N;
/*	windows size
*	small   small   small   small
*	normal  normal  normal  normal
*	big		big		big		big
*/


struct window {
	int number;
	string size;
	bool state;
	int phone_number;
	int password;
	int use_date[10000];
}win[W + 1][W + 1];

struct expressman {
	string name;
	string phone_number;
	string password;
	string company;
	
}expm[10000];

struct count{
	string company;
	string time[100];
	int i=1;
}cnt[6];

int getRand(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

void initialize()//use to initialize
{
	cnt[1].company="SF";
	cnt[2].company="ZT";
	cnt[3].company="YT";
	cnt[4].company="JD";
	cnt[5].company="YD";

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			for(int k=1;k<=9999;k++)
				win[i][j].use_date[k]=0;

	int n = 1;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++, n++)
			win[i][j].number = n;
	//size
	for (int i = 1; i <= W; i++)
		win[1][i].size = "  Small ";
	for (int i = 1; i <= W; i++)
		win[2][i].size = " Normal ";
	for (int i = 1; i <= W; i++)
		win[3][i].size = "   Big  ";
	for (int i = 1; i <= W; i++)
		win[4][i].size = "   Big  ";
	//state
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++, n++)
			win[i][j].state = true;
	//expm----


	ifstream infile;
	infile.open("expressman.in");
	infile >> N;

	for (int i = 1; i <= N; i++)
		infile >> expm[i].name >> expm[i].company >> expm[i].password >> expm[i].phone_number;
	infile.close();
	return;
}

void print_test()//use to test
{
	//windows
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cout << win[i][j].number << ' ';
		}
		cout << endl;
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
			cout << win[i][j].size << ' ';
		cout << endl;
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
			cout << win[i][j].state << ' ';
		cout << endl;
	}


	for (int i = 1; i <= N; i++)
		cout << expm[i].name << endl << expm[i].company << endl << expm[i].password << endl << expm[i].phone_number << endl << endl;
	return;
}

void print_state()
{

	cout << "----------------------------------------" << endl;
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{

			cout << "|";
			if (win[i][j].number < 10)
				cout << "0";
			cout << win[i][j].number;
			if (win[i][j].state == true)
				cout << "可用  ";
			else
				cout << "不可用";
		}
		cout << "|";
		cout << endl;
		for (int j = 1; j <= W; j++)
		{
			cout << "|";
			cout << win[i][j].size;
		}
		cout << '|' << endl << "----------------------------------------" << endl;
	}

	return;
}

void record(string c,string t){
	for(int j=1;j<=5;j++)
		if(cnt[j].company==c)
		{
			cnt[j].time[cnt[j].i]=t;
			cnt[j].i++;			
			break;
		}
	
		
}


void password_out() {
	ofstream outfile;
	outfile.open("password.out");
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (win[i][j].state == false)
				outfile << "|" << win[i][j].password;
			else
				outfile << "|" << "XXXX";
		}
		outfile << "|" << endl;
	}
	outfile.close();
}

void cnt_use_time(int a,int b){
	time_t nowtime;
	time(&nowtime); //获取1970年1月1日0点0分0秒到现在经过的秒数
	tm* p = localtime(&nowtime); //将秒数转换为本地时间,年从1900算起,需要+1900,月为0-11,所以要+1
	win[a][b].use_date[(p->tm_mon + 1)*100+(p->tm_mday)]++;

}

void put_in()
{
	cout << "请选择要存入的窗格号：";
	int t;
	cin >> t;
	if (t > H * W) {
		cout << "输入错误请重新输入。";
		Sleep(1000);
		put_in();
	}

	int x, y;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			if (win[i][j].number == t)
			{
				x = i, y = j;
				break;
			}
	if (win[x][y].state == false)
	{
		cout << "该窗口暂时不可用，请换一个。" << endl;
		Sleep(1000);
		put_in();
	}
	win[x][y].state = false;

	cnt_use_time(x,y);

	cout << endl << "请输入顾客手机尾号后4位：";
	cin >> win[x][y].phone_number;
	while (win[x][y].phone_number < 1000 || win[x][y].phone_number>9999) {
		cout << "手机号错误，请重新输入" << endl;
		cin >> win[x][y].phone_number;
	}
	win[x][y].password = getRand(1000, 9999);
	cout << endl << "顾客取件码为:" << win[x][y].password;
	password_out();
	
	cout << "存入完成";
	Sleep(1000);
	return;
}

void out_usedate(int a,int b,int d)
{
	cout<<"第"<<win[a][b].number<<"格在"<<d/100<<"月"<<d%100<<"日被用了"<<win[a][b].use_date[d]<<"次"<<endl;
	system("pause");
}

void delivery_login(int n)
{
	system("cls");

	cout << expm[n].name << ",您好。" << endl;
	cout << "您的电话号码是" << expm[n].phone_number << endl;
	cout << "请输入您的登录密码：";
	time_t now = time(0);
    char* datetime = ctime(&now);
	record(expm[n].company,datetime);
	string temp_pass;
	cin >> temp_pass;
	if (temp_pass == expm[n].password)
	{
		system("cls");
		print_state();
		put_in();
	}
	else
	{
		cout << "密码错误请重新输入。";
		Sleep(1500);
		delivery_login(n);
	}
}

void print_cnt()
{
	for(int j=1;j<=5;j++)
	{
		cout<<cnt[j].company<<"使用记录："<<endl;
		for(int k=1;k<=cnt[j].i;k++)
		{
			cout<<cnt[j].time[k]<<endl;
		}
	}
	system("pause");
}

void get_out(int x, int y)
{
	cout << endl << "您的包裹在" << win[x][y].number << "号窗口，请输入取件码:";
	int temp;
	cin >> temp;
	if (temp != win[x][y].password)
	{
		cout << endl << "密码错误请重新输入:";
		Sleep(1000);
		get_out(x, y);
	}
	else
	{
		win[x][y].state = true;
		win[x][y].phone_number = 0;
		win[x][y].password = 0;
		password_out();
		cout << endl << "请取走您的包裹";
		Sleep(1000);
		return;
	}
}

void customer()
{
	system("cls");
	cout << "您好,取件请输入手机尾号后4位：";
	int num;
	cin >> num;
	while (num < 1000 || num>9999) {
		cin >> num;
		cout << "手机号错误，请重新输入" << endl;
	}
	int l, k;
	bool flag = false;
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (win[i][j].phone_number == num)
			{
				flag = true;
				l = i, k = j;
			}
		}
	}
	if (flag == false)
	{
		cout << endl << "未查询到您的包裹，请重新输入";
		Sleep(1000);
		customer();
	}
	get_out(l, k);
}

void login()
{
	system("cls");
	bool flag = false;

	cout << "时间:";
	time_t t = time(nullptr);
	tm* now = localtime(&t);
	cout << put_time(now, "%Y-%m-%d %H:%M:%S") << endl;
	cout << "欢迎使用外卖柜" << endl;
	cout << "当前使用状态：" << endl;
	print_state();
	cout << "顾客按1，骑手按2,查询快递公司使用记录按3，查询快递柜使用记录按4" << endl;
	int identity;
	cin >> identity;

	if (identity == 2)
	{
		flag = true;
		cout << "请输入您的快递员编号:";
		int t;
		do {
			cin >> t;
			cout << "快递员编号错误，请重新输入" << endl;
		} while (t >= N);
		delivery_login(t);
		return;
	}
	if (identity == 1)
	{
		flag = true;
		customer();
		return;
	}
	if (identity == 3)
	{
		flag = true;
		print_cnt();
	}
	if(identity == 4)
	{
		flag = true;
		cout<<"请输入需要查询窗口号和日期";		
		int a,b,d,t;
		cin>>t>>d;
		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++)
				if (win[i][j].number == t)
				{
					a = i, b = j;
					break;
				}
		while(a > H||b>W||d<=0||d>=9999) {
			cout << "输入错误请重新输入。";
			Sleep(1000);
			cin>>a>>b>>d;
		}
		out_usedate(a,b,d);
	}
	if (flag == false)
	{
		cout << "输入错误，请重新输入";
		Sleep(3000);
		system("cls");
		login();
	}

}



int	 main()
{
	initialize();
	while (1)
		login();
	return 0;
}