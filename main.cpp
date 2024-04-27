#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

const int W = 4, H = 4;
int N;
struct window
{
	int number;
	string size;
	bool state;
	int phone_number;
	int password;
	struct use_date
	{
		int use_time;
		struct use_time
		{
			int in_hour=0;
			int in_minute=0;
			int in_sec=0;
			int out_sec=0;
			int out_hour=0;
			int out_minute=0;
		} use_t[100];
	} use_date[10000];
} win[W + 1][W + 1];

struct expressman
{
	string name;
	string phone_number;
	string password;
	string company;

} expm[10000];

struct count
{
	string company;
	string time[100];
	int i = 1;
} cnt[6];

int getRand(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

void initialize()
{
	cnt[1].company = "SF";
	cnt[2].company = "ZT";
	cnt[3].company = "YT";
	cnt[4].company = "JD";
	cnt[5].company = "YD";
	int n = 1;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++, n++)
			win[i][j].number = n;

	for (int i = 1; i <= W; i++)
		win[1][i].size = "  Small ";
	for (int i = 1; i <= W; i++)
		win[2][i].size = " Normal ";
	for (int i = 1; i <= W; i++)
		win[3][i].size = "   Big  ";
	for (int i = 1; i <= W; i++)
		win[4][i].size = "   Big  ";

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++, n++)
			win[i][j].state = true;


	ifstream infile;
	infile.open("expressman.in");
	infile >> N;

	for (int i = 1; i <= N; i++)
		infile >> expm[i].name >> expm[i].company >> expm[i].password >> expm[i].phone_number;
	infile.close();

	for (int a = 101; a <= 1231; a++)
		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++)
				win[i][j].use_date[a].use_time = 1;
	return;
}

void print_test()
{

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
		cout << expm[i].name << endl
			 << expm[i].company << endl
			 << expm[i].password << endl
			 << expm[i].phone_number << endl
			 << endl;
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
		cout << '|' << endl
			 << "----------------------------------------" << endl;
	}

	return;
}

void record(string c, string t)
{
	for (int j = 1; j <= 5; j++)
		if (cnt[j].company == c)
		{
			cnt[j].time[cnt[j].i] = t;
			cnt[j].i++;
			break;
		}
}

void password_out()
{
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

void cnt_in_time(int a, int b, int T)
{
	time_t nowtime;
	time(&nowtime);				 
	tm *p = localtime(&nowtime); 
	int h = (p->tm_hour);
	int m = (p->tm_min);
	int s = (p->tm_sec);
	win[a][b].use_date[T].use_t[win[a][b].use_date[T].use_time].in_hour = h;
	win[a][b].use_date[T].use_t[win[a][b].use_date[T].use_time].in_minute = m;
	win[a][b].use_date[T].use_t[win[a][b].use_date[T].use_time].in_sec = s;
	system("pause");
}

void cnt_out_time(int a, int b, int T)
{
	time_t nowtime;
	time(&nowtime);				 
	tm *p = localtime(&nowtime); 

	int h = (p->tm_hour);
	int m = (p->tm_min);
	int s = (p->tm_sec);
	win[a][b].use_date[T].use_time++;
	win[a][b].use_date[T].use_t[win[a][b].use_date[T].use_time].out_hour = h;
	win[a][b].use_date[T].use_t[win[a][b].use_date[T].use_time].out_minute = m;
	win[a][b].use_date[T].use_t[win[a][b].use_date[T].use_time].out_sec = s;
}

void put_in(int T)
{
	cout << "请选择要存入的窗格号：";
	int t;
	cin >> t;
	if (t > H * W)
	{
		cout << "输入错误请重新输入。";
		Sleep(1000);
		put_in(T);
	}

	int a, b;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			if (win[i][j].number == t)
			{
				a = i, b = j;
				break;
			}
	if (win[a][b].state == false)
	{
		cout << "该窗口暂时不可用，请换一个。" << endl;
		Sleep(1000);
		put_in(T);
	}
	win[a][b].state = false;
	cout << endl
		 << "请输入顾客手机尾号后4位：";
	cin >> win[a][b].phone_number;
	while (win[a][b].phone_number < 1000 || win[a][b].phone_number > 9999)
	{
		cout << "手机号错误，请重新输入" << endl;
		cin >> win[a][b].phone_number;
	}
	win[a][b].password = getRand(1000, 9999);
	cout << endl
		 << "顾客取件码为:" << win[a][b].password << endl;
	cout << "存入完成";
	password_out();
	cnt_in_time(a, b, T);
	Sleep(1000);
	return;
}

void out_usedate(int a, int b, int d)
{
	cout << "第" << win[a][b].number << "格在" << d / 100 << "月" << d % 100 << "日被用了" << win[a][b].use_date[d].use_time << "次" << endl;
	system("pause");
}

void delivery_login(int n, int T)
{
	system("cls");

	cout << expm[n].name << ",您好。" << endl;
	cout << "您的电话号码是" << expm[n].phone_number << endl;
	cout << "请输入您的登录密码：";
	time_t now = time(0);
	char *datetime = ctime(&now);
	record(expm[n].company, datetime);
	string temp_pass;
	cin >> temp_pass;
	if (temp_pass == expm[n].password)
	{
		system("cls");
		print_state();
		put_in(T);
	}
	else
	{
		cout << "密码错误请重新输入。";
		Sleep(1500);
		delivery_login(n, T);
	}
}

void print_cnt()
{
	for (int j = 1; j <= 5; j++)
	{
		cout << cnt[j].company << "使用记录：" << endl;
		for (int k = 1; k <= cnt[j].i; k++)
		{
			cout << cnt[j].time[k] << endl;
		}
	}
	system("pause");
}

void get_out(int x, int y, int T)
{
	cout << endl
		 << "您的包裹在" << win[x][y].number << "号窗口，请输入取件码:";
	int temp;
	cin >> temp;
	while (temp != win[x][y].password)
	{
		cout << endl;
		cout << "密码错误请重新输入:";
		Sleep(1000);
		cin >> temp;
	}
	win[x][y].state = true;
	win[x][y].phone_number = 0;
	win[x][y].password = 0;
	password_out();
	cout << endl;
	cout << "请取走您的包裹";
	cnt_out_time(x, y, T);
	Sleep(1000);
	return;
}

void customer(int T)
{

	system("cls");
	cout << "您好,取件请输入手机尾号后4位：";
	int num;
	cin >> num;
	while (num < 1000 || num > 9999)
	{
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
		cout << endl
			 << "未查询到您的包裹，请重新输入";
		Sleep(1000);
		customer(T);
	}
	get_out(l, k, T);
}

int cnt_time(int x, int y, int T, int i)
{
	int a = win[x][y].use_date[T].use_t[i].in_hour * 3600.0 + win[x][y].use_date[T].use_t[i].in_minute * 60.0 + win[x][y].use_date[T].use_t[i].in_sec;
	int b = win[x][y].use_date[T].use_t[i].out_hour * 3600.0 + win[x][y].use_date[T].use_t[i].out_minute * 60.0 + win[x][y].use_date[T].use_t[i].out_sec;
	int c;
	c = b - a;
	return c;
}

void out_use_time(int date, int x, int y)
{
	int average = 0;
	for (int i = 1; i <= win[x][y].use_date[date].use_time; i++)
		average += cnt_time(x, y, date, i);

	average = average / (win[x][y].use_date[date].use_time * 1.0);
	int h, m, s;
	h = average / 3600;
	m = average % 3600 / 60;
	s = average % 60;
	cout << "在" << date / 100 << "月" << date % 100 << "日第" << x << "行" << y << "列平均使用了" << h << "小时" << m << "分" << s << "秒" << endl;
	system("pause");
}

void data()
{
	cnt[1].time[1]="Sat Apr 25 18:07:52 2024";
	cnt[2].time[1]="Sat Apr 06 12:27:32 2024";
	cnt[2].time[2]="Sun Feb 15 18:11:43 2024";
	cnt[3].time[1]="Sun Apr 01 12:04:12 2024";
	cnt[3].time[1]="Sun Apr 01 13:01:34 2024";
	cnt[4].time[1]="Thu Jan 11 11:03:52 2024";
	cnt[5].time[1]="Wed Mar 27 02:33:12 2024";
	win[1][2].use_date[425].use_time=1;
	win[2][3].use_date[406].use_time=1;
	win[3][1].use_date[215].use_time=1;
	win[4][4].use_date[401].use_time=2;
	win[1][2].use_date[117].use_time=1;
	win[1][2].use_date[327].use_time=1;

	win[1][2].use_date[425].use_t[1].in_hour = 18;
	win[1][2].use_date[425].use_t[1].in_minute = 07;
	win[1][2].use_date[425].use_t[1].in_sec = 52;
	win[1][2].use_date[425].use_t[1].out_hour = 19;
	win[1][2].use_date[425].use_t[1].out_minute = 41;
	win[1][2].use_date[425].use_t[1].out_sec = 14;
	
	win[2][3].use_date[406].use_t[1].in_hour = 12;
	win[2][3].use_date[406].use_t[1].in_minute = 27;
	win[2][3].use_date[406].use_t[1].in_sec = 52;
	win[2][3].use_date[406].use_t[1].out_hour = 19;
	win[2][3].use_date[406].use_t[1].out_minute = 41;
	win[2][3].use_date[406].use_t[1].out_sec = 14;
	
    win[3][4].use_date[215].use_t[1].in_hour = 15;
	win[3][4].use_date[215].use_t[1].in_minute = 23;
	win[3][4].use_date[215].use_t[1].in_sec = 13;
	win[3][4].use_date[215].use_t[1].out_hour = 17;
	win[3][4].use_date[215].use_t[1].out_minute = 45;
	win[3][4].use_date[215].use_t[1].out_sec = 18;
	
	win[4][4].use_date[401].use_t[1].in_hour = 12;
	win[4][4].use_date[401].use_t[1].in_minute = 27;
	win[4][4].use_date[401].use_t[1].in_sec = 52;
	win[4][4].use_date[401].use_t[1].out_hour = 19;
	win[4][4].use_date[401].use_t[1].out_minute = 41;
	win[4][4].use_date[401].use_t[1].out_sec = 14;
	win[4][4].use_date[401].use_t[2].in_hour = 15;
	win[4][4].use_date[401].use_t[2].in_minute = 24;
	win[4][4].use_date[401].use_t[2].in_sec = 27;
	win[4][4].use_date[401].use_t[2].out_hour = 19;
	win[4][4].use_date[401].use_t[2].out_minute = 43;
	win[4][4].use_date[401].use_t[2].out_sec = 10; 
	
	win[1][2].use_date[117].use_t[1].in_hour = 16;
	win[1][2].use_date[117].use_t[1].in_minute = 54;
	win[1][2].use_date[117].use_t[1].in_sec = 23;
	win[1][2].use_date[117].use_t[1].out_hour = 17;
	win[1][2].use_date[117].use_t[1].out_minute = 31;
	win[1][2].use_date[117].use_t[1].out_sec = 16;
	
	win[1][2].use_date[327].use_t[1].in_hour = 11;
	win[1][2].use_date[327].use_t[1].in_minute = 52;
	win[1][2].use_date[327].use_t[1].in_sec = 28;
	win[1][2].use_date[327].use_t[1].out_hour = 18;
	win[1][2].use_date[327].use_t[1].out_minute = 40;
	win[1][2].use_date[327].use_t[1].out_sec = 21;
	
}

void login()
{
	
	system("cls");

	cout << "时间:";
	time_t t = time(nullptr);
	tm *now = localtime(&t);
	time_t nowtime;
	time(&nowtime);
	tm *p = localtime(&nowtime);
	int T = (p->tm_mon + 1) * 100 + (p->tm_mday);

	cout << put_time(now, "%Y-%m-%d %H:%M:%S") << endl;
	cout << "欢迎使用外卖柜" << endl;
	cout << "当前使用状态：" << endl;
	print_state();
	cout << "顾客按1，骑手按2,查询快递公司使用记录按3，查询快递柜使用记录按4,查询指定日期从快递投放到用户取件的平均时长按5" << endl;

	bool flag = false;
	int identity;

	cin >> identity;
	if (identity == 2)
	{
		flag = true;
		cout << "请输入您的快递员编号:";
		int x;
		do
		{
			cin >> x;
			cout << "快递员编号错误，请重新输入" << endl;
		} while (x >= N);
		delivery_login(x, T);
		return;
	}
	if (identity == 1)
	{
		flag = true;
		customer(T);
		return;
	}
	if (identity == 3)
	{
		if (identity == 3)
		{
			flag = true;
			print_cnt();
		}
	}
	if (identity == 4)
	{
		flag = true;
		cout << "请输入需要查询窗口号和日期";
		int a, b, d, t;
		cin >> t >> d;
		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++)
				if (win[i][j].number == t)
				{
					a = i, b = j;
					break;
				}
		while (a > H || b > W || d <= 0 || d >= 9999)
		{
			cout << "输入错误请重新输入。";
			Sleep(1000);
			cin >> a >> b >> d;
		}
		out_usedate(a, b, d);
	}
	if (identity == 5)
	{
		flag = true;
		cout << "请输入需要查询窗口号和日期" << endl;
		int x, a, b, d;
		cin >> x >> d;
		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++)
				if (win[i][j].number == x)
				{
					a = i, b = j;
					break;
				}

		out_use_time(d, a, b);
	}
	if (flag == false)
	{
		cout << "输入错误，请重新输入";
		Sleep(3000);
		system("cls");
		login();
	}
}

int main()
{
	initialize();
	cout<<"是否导入模拟初始数据,y/n";
	char cha;
	cin>>cha;
	if(cha=='y')
	{
		data();
	}
	while (1)
		login();
	return 0;
}
