#include<bits/stdc++.h>
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

	freopen("expressman.in", "r", stdin);
	cin >> N;
	
	for (int i = 1; i <= N; i++)
		cin>>expm[i].name>>expm[i].company>>expm[i].password>>expm[i].phone_number;
	fclose(stdin);
	return;
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
		cout<< expm[i].name<<' '<<expm[i].company<<' '<<expm[i].password<<' '<<expm[i].phone_number<<endl;	
	return ;
}

void welcome()
{
	cout<<"Time:";
	time_t t = time(nullptr);
    tm *now = localtime(&t); 
    cout << put_time(now, "%Y-%m-%d %H:%M:%S") << endl;
	cout<<"Welcome to ";
}

void login()
{
	cout<<"请快递员输入手机号"<<endl;

}

void delivery()
{
	login();
}

int	 main()
{
	initialize();
	//print();//use to test
	welcome();
	delivery();
	return 0;
}