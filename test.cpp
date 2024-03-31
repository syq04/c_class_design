#include<bits/stdc++.h>
//#pragma warning(disable:4996)//use in visual code
using namespace std;

int N,H=4,W=4;
struct expressman {
	string name;
	string phone_number;
	string password;
	string company;
}expm[10000];

void print()//use to test
{
    cout<<"sad"<<endl;
	//expm
	for (int i = 1; i <= N; i++)
		cout<< expm[i].name<<' '<<expm[i].company<<' '<<expm[i].password<<' '<<expm[i].phone_number<<endl;	
	return ;
}

int main()
{
    FILE *fp1;
	fp1=fopen("expressman.in","r");
    fscanf(fp1,"%d",&N);
    for (int i = 1; i <= N; i++)
	{
        expm[i].name.resize(20);
        expm[i].company.resize(20);
        expm[i].password.resize(20);
        expm[i].phone_number.resize(20);
		fgets(expm[i].name,sizeof(expm[i].name),fp1);
		fscanf(fp1,"%s",&expm[i].company);
		fscanf(fp1,"%s",&expm[i].password);
		fscanf(fp1,"%s",&expm[i].phone_number);
	}
    print();
    return 0;
}