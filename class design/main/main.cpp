#include<bits/stdc++.h>
using namespace std;
const int  W = 4,H = 4;//height,width

struct window{
	int number[W + 1][H + 1];
	char size[W + 1][H + 1];
	bool state[W + 1][H + 1];
}w;
/*	4*4
*	small   small   small   small
*	normal  normal  normal  normal
*	big		big		big		big
*/

void initialize()
{
	//number
	int n = 1;
	for(int i=1;i<=H;i++)
		for (int j = 1; j <= W; j++,n++)
			w.number[i][j] = n;
	//size
	for (int i = 1; i <=W; i++)
		w.size[1][i] ='S';
	for (int i = 1; i <= W; i++)
		w.size[2][i] = 'N';
	for (int i = 1; i <= W; i++)
		w.size[3][i] ='B';
	//state
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++, n++)
			w.state[i][j] = true;
	return;
}

void print()//use to test
{
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cout << w.number[i][j] << ' ';
		}
		cout << endl;
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
			cout<<w.size[i][j]<<' ';
		cout << endl;
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
			cout << w.state[i][j] << ' ';
		cout << endl;
	}
	return ;
}

int	 main()
{
	initialize();
	//print();
	return 0;
}