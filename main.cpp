#include<bits/stdc++.h>
//#pragma warning(disable:4996)//use in visual code
using namespace std;
const int  W = 4,H = 4;//height,width,number of expressman
int N;
struct window{
	int number;
	string size;
	bool state;
}win[W+1][W+1];
/*	4*4
*	small   small   small   small
*	normal  normal  normal  normal
*	big		big		big		big
*/
struct expressman {
	string name;
	int phone_number;
	string password;
	string company;
}expm[10000];//maxn

void initialize()
{
	//window----------
	//number
	int n = 1;
	for(int i=1;i<=H;i++)
		for (int j = 1; j <= W; j++,n++)
			win[i][j].number = n;
	//size
	for (int i = 1; i <=W; i++)
		win[1][i].size ='Small';
	for (int i = 1; i <= W; i++)
		win[2][i].size = 'Normal';
	for (int i = 1; i <= W; i++)
		win[3][i] .size='Big';
	//state
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++, n++)
			win[i][j] .state= true;
	//expm----

	freopen("expressman.in", "r", stdin);
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		string phone_n_temp;
		cin>>expm[i].name>>expm[i].company>>phone_n_temp>>expm[i].password;
		expm[i].phone_number=(int)phone_n_temp;

	}
	fclose(stdin);
	return;
}

void print()//use to test
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
			cout<<win[i][j].size<<' ';
		cout << endl;
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
			cout << win[i][j].state << ' ';
		cout << endl;
	}
	for (int i = 1; i <= N; i++)
		cout<< expm[i].name<<' '<<expm[i].phone_number<<' '<<expm[i].company<<' '<<expm[i].password<<endl;
	return ;
}

int	 main()
{
	initialize();
	print();//use to test
	return 0;
}