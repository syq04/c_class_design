#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
const int  W = 4,H = 4;//height,width,number of expressman
int N;
struct window{
	int number[W + 1][H + 1];
	char size[W + 1][H + 1];
	bool state[W + 1][H + 1];
}win;
/*	4*4
*	small   small   small   small
*	normal  normal  normal  normal
*	big		big		big		big
*/
struct expressman {
	string name;
}expm[10000];//maxn

void initialize()
{
	//window----------
	//number
	int n = 1;
	for(int i=1;i<=H;i++)
		for (int j = 1; j <= W; j++,n++)
			win.number[i][j] = n;
	//size
	for (int i = 1; i <=W; i++)
		win.size[1][i] ='S';
	for (int i = 1; i <= W; i++)
		win.size[2][i] = 'N';
	for (int i = 1; i <= W; i++)
		win.size[3][i] ='B';
	//state
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++, n++)
			win.state[i][j] = true;
	//expm----

	freopen("expressman.in", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> expm[i].name;
	return;
}

void print()//use to test
{
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cout << win.number[i][j] << ' ';
		}
		cout << endl;
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
			cout<<win.size[i][j]<<' ';
		cout << endl;
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
			cout << win.state[i][j] << ' ';
		cout << endl;
	}
	for (int i = 1; i <= N; i++)
		cout<< expm[i].name<<' ';
	return ;
}

int	 main()
{
	initialize();
	print();
	return 0;
}