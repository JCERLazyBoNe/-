#include <bits/stdc++.h>
#include <Windows.h>
#include <conio.h>
using namespace std;
char p[56]={'.','*','#','1','W'};
char k[14][14];
int x=7,y=7;
int xa=8,ya=8;
void check(int a,int b)
{
	if(k[a][b]=='.')
	cout<<"一条土路"<<endl;
	else if(k[a][b]=='#')
	cout<<"一面坚硬的墙"<<endl;
	else if(k[a][b]=='*')
	cout<<"人为建造的障碍物"<<endl;
}
int main()
{
	for(int i=0;i<=14;i++)
	for(int l=0;l<=14;l++)
	k[i][l]='.';
	for(int i=0;i<=14;i++)
	k[i][0]=k[i][14]=k[14][i]=k[0][i]='#';
	string a;
	k[x][y]='1';
	k[xa][ya]='2';
	for(int i=0;i<=14;i++)
	{
		for(int l=0;l<=14;l++)
		cout<<k[i][l]<<' ';
		cout<<endl;
	}
		cout<<"玩家1 wasd移动 k查看 f放置 p破坏\n";
		cout<<"玩家2 8456移动\n";
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
			
			for(int i=0;i<=14;i++)
			{
				for(int l=0;l<=14;l++)
				cout<<k[i][l]<<' ';
				cout<<endl;
			}
			cout<<"wasd移动 k查看 f放置 p破坏\n";
			cout<<"玩家2 8456移动\n";
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
		for(int i=0;i<=14;i++)
		{
			for(int l=0;l<=14;l++)
			cout<<k[i][l]<<' ';
			cout<<endl;
		}
		cout<<"wasd移动 k查看 f放置 p破坏\n";
		cout<<"玩家2 8456移动\n";
		if(c=='k')
		{
			c=_getch();
			if(c=='w')
			check(x-1,y);
			else if(c=='s')
			check(x+1,y);
			else if(c=='a')
			check(x,y-1);
			else if(c=='d')
			check(x,y+1);
			continue;
		}
		else if(c=='f')
		{
			c=_getch();
			if(c=='w')
			k[x-1][y]='*';
			else if(c=='s')
			k[x+1][y]='*';
			else if(c=='a')
			k[x][y-1]='*';
			else if(c=='d')
			k[x][y+1]='*';
			continue;
		}
		else if(c=='p')
		{
			c=_getch();
			if(c=='w'&&k[x-1][y]=='*')
			k[x-1][y]='.';
			else if(c=='s'&&k[x+1][y]=='*')
			k[x+1][y]='.';
			else if(c=='a'&&k[x][y-1]=='*')
			k[x][y-1]='.';
			else if(c=='d'&&k[x][y+1]=='*')
			k[x][y+1]='.';
		}
	}
	return 0;
}
