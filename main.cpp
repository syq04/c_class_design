#include<bits/stdc++.h>
#include <windows.h>
//#pragma warning(disable:4996)//use in visual code
using namespace std;

const int  W = 4,H = 4;//height,width,number of expressman
int N;
/*	windows size
*	small   small   small   small
*	normal  normal  normal  normal
*	big		big		big		big
*/


struct window{
	int number;
	string size;
	bool state;
	string user;
}win[W+1][W+1];

struct expressman {
	string name;
	string phone_number;
	string password;
	string company;
}expm[10000];

void initialize()//use to initialize
{
	//window----------
	//number
	int n = 1;
	for(int i=1;i<=H;i++)
		for (int j = 1; j <= W; j++,n++)
			win[i][j].number = n;
	//size
	for (int i = 1; i <=W; i++)
		win[1][i].size ="Small";
	for (int i = 1; i <= W; i++)
		win[2][i].size = "Normal";
	for (int i = 1; i <= W; i++)
		win[3][i] .size="Big";
	//state
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++, n++)
			win[i][j] .state= true;
	//expm----
	ifstream infile; 
   	infile.open("expressman.in");
	infile>>N;
	
	for (int i = 1; i <= N; i++)
		infile>>expm[i].name>>expm[i].company>>expm[i].password>>expm[i].phone_number;
	infile.close();
	return ;
}

void print()//use to test
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
			cout<<win[i][j].size<<' ';
		cout << endl;
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
			cout << win[i][j].state << ' ';
		cout << endl;
	}
	//expm
	for (int i = 1; i <= N; i++)
		cout<< expm[i].name<<endl<<expm[i].company<<endl<<expm[i].password<<endl<<expm[i].phone_number<<endl<<endl;	
	return ;
}

void login()
{		
	system("cls");
	bool flag=false;

	cout<<"时间:";
	time_t t = time(nullptr);
    tm *now = localtime(&t); 
    cout << put_time(now, "%Y-%m-%d %H:%M:%S") << endl;
	cout<<"欢迎使用外卖柜"<<endl;
	cout<<"顾客按1，骑手按2"<<endl;
	int identity;
	cin>>identity;

	if(identity==1)
	{		
		flag=true;
		delivery();
		cout<<"D";
		return;
	}
	if(identity==2)
	{
		flag=true;
		customer();
		return;
	}
	if(flag==false)
	{
		cout<<"输入错误，请重新输入";
		Sleep(3000);
		system("cls");
		login();
	}
	
}

void delivery()
{
	
}

void customer()
{
	
}

int	 main()
{
	initialize();
	//print();//use to test
	login();
	return 0;
}