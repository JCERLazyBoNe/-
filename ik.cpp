#include <bits/stdc++.h>
#include <Windows.h>
#include <conio.h>
using namespace std;
char p[56]={'.','*','#','1','W'};
char k[14][14];
int x=7,y=7;
int f=0;
int xa=8,ya=8;
void check(int a,int b)
{
	if(k[a][b]=='.')
	cout<<"һ����·"<<endl;
	else if(k[a][b]=='K')
	cout<<"һ���Ӳ��ǽ"<<endl;
	else if(k[a][b]=='*')
	cout<<"��Ϊ������ϰ���"<<endl;
}
int main()
{
	for(int i=0;i<=14;i++)
	for(int l=0;l<=14;l++)
	k[i][l]='.';
	for(int i=0;i<=14;i++)
	k[i][0]=k[i][14]=k[14][i]=k[0][i]='K';
	string a;
	k[x][y]='1';
	k[xa][ya]='2';
	for(int i=1;i<=13;i++)
	{
		for(int l=1;l<=13;l++)
		cout<<k[i][l]<<' ';
		cout<<endl;
	}
		cout<<"���1 wasd�ƶ� k�鿴 f���� p�ƻ�\n";
		cout<<"���2 8456�ƶ�\n";
	f=0;
	while(1)
	{
		char c=_getch();
		system("cls");
		if(c-'0'>0&&c-'0'<=9)
		{
			if(c=='8'&&k[xa-1][ya]=='.')
			k[xa][ya]='.',xa--;
			else if(c=='5'&&k[xa+1][ya]=='.')
			k[xa][ya]='.',xa++;
			else if(c=='4'&&k[xa][ya-1]=='.')
			k[xa][ya]='.',ya--;
			else if(c=='6'&&k[xa][ya+1]=='.')
			k[xa][ya]='.',ya++;
			k[xa][ya]='2';
			
			for(int i=1;i<=13;i++)
			{
				for(int l=1;l<=13;l++)
				cout<<k[i][l]<<' ';
				cout<<endl;
			}
			cout<<"���1 wasd�ƶ� k�鿴 f���� p�ƻ�\n";
			cout<<"���2 8456�ƶ�\n";
			continue;
		}
		if(f!=0&&(c<'0'||c>'9'))
		{
//			cout<<f<<' '<<(f!=0)<<endl;
			if(f==1&&(c<'0'||c>'9'))
			{
				f=0;
				if(c=='w'&&k[x-1][y]=='.')
				k[x-1][y]='*';
				else if(c=='s'&&k[x+1][y]=='.')
				k[x+1][y]='*';
				else if(c=='a'&&k[x][y-1]=='.')
				k[x][y-1]='*';
				else if(c=='d'&&k[x][y+1]=='.')
				k[x][y+1]='*';
				for(int i=1;i<=13;i++)
				{
					for(int l=1;l<=13;l++)
					cout<<k[i][l]<<' ';
					cout<<endl;
				}
				cout<<"���1 wasd�ƶ� k�鿴 f���� p�ƻ�\n";
				cout<<"���2 8456�ƶ�\n";
				continue;
			}
			if(f==2&&(c<'0'||c>'9'))
			{
				f=0;
				if(c=='w'&&k[x-1][y]=='*')
				k[x-1][y]='.';
				else if(c=='s'&&k[x+1][y]=='*')
				k[x+1][y]='.';
				else if(c=='a'&&k[x][y-1]=='*')
				k[x][y-1]='.';
				else if(c=='d'&&k[x][y+1]=='*')
				k[x][y+1]='.';
				f=0;
				for(int i=1;i<=13;i++)
				{
					for(int l=1;l<=13;l++)
					cout<<k[i][l]<<' ';
					cout<<endl;
				}
				cout<<"���1 wasd�ƶ� k�鿴 f���� p�ƻ�\n";
				cout<<"���2 8456�ƶ�\n";
				continue;
			}
			if(f==3&&(c<'0'||c>'9'))
			{
				f=0;
				for(int i=1;i<=13;i++)
				{
					for(int l=1;l<=13;l++)
					cout<<k[i][l]<<' ';
					cout<<endl;
				}
				cout<<"���1 wasd�ƶ� k�鿴 f���� p�ƻ�\n";
				cout<<"���2 8456�ƶ�\n";
				if(c=='w')
				check(x-1,y);
				else if(c=='s')
				check(x+1,y);
				else if(c=='a')
				check(x,y-1);
				else if(c=='d')
				check(x,y+1);
				f=0;
				f=0;
			}
			continue;
		}
		if(c=='w'&&k[x-1][y]=='.')
		k[x][y]='.',x--;
		else if(c=='s'&&k[x+1][y]=='.')
		k[x][y]='.',x++;
		else if(c=='a'&&k[x][y-1]=='.')
		k[x][y]='.',y--;
		else if(c=='d'&&k[x][y+1]=='.')
		k[x][y]='.',y++;
		k[x][y]='1';
		for(int i=1;i<=13;i++)
		{
			for(int l=1;l<=13;l++)
			cout<<k[i][l]<<' ';
			cout<<endl;
		}
		cout<<"���1 wasd�ƶ� k�鿴 f���� p�ƻ�\n";
		cout<<"���2 8456�ƶ�\n";
		f=0;
		if(c=='k')
		{
			f=3;
			continue;
		}
		else if(c=='f')
		{
			f=1;
			continue;
		}
		else if(c=='p')
		{
			f=2;
			continue;
		}
	}
	return 0;
}
