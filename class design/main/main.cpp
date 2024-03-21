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
	for (int i = 1; i <= W; i++)
		w.size[1][w] = 'S';
	for (int i = 1; i <= W; i++)
		w.size[2][w] = 'N';
	for (int i = 1; i <= W; i++)
		w.size[3][w] = 'B';

	return;
}

void print(int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << w.size[i][j]<<' ';
		}
		cout << endl;
	}
}

int	 main()
{
	initialize();
	print(H, W);
	return 0;
}