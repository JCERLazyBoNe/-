#include <bits/stdc++.h>
#include <Windows.h>
#include <conio.h>
using namespace std;
char p[56]={'.','*','#','1','W'};
char k[16][16];
int x=1,y=1;
int f=0;
int xa=15,ya=15;
int k44=0;
void check(int a,int b)
{
	if(k[a][b]=='.')
	cout<<"一条土路"<<endl;
	else if(k[a][b]=='K')
	cout<<"一面坚硬的墙"<<endl;
	else if(k[a][b]=='*')
	cout<<"人为建造的障碍物"<<endl;
}

void clear(int x,int y)
{
	if(k[x+1][y]=='*')
	k[x+1][y]='.';
	if(k[x-1][y]=='*')
	k[x-1][y]='.';
	if(k[x+1][y-1]=='*')
	k[x+1][y-1]='.';
	if(k[x][y-1]=='*')
	k[x][y-1]='.';
	if(k[x-1][y-1]=='*')
	k[x-1][y-1]='.';
	if(k[x+1][y+1]=='*')
	k[x+1][y+1]='.';
	if(k[x][y+1]=='*')
	k[x][y+1]='.';
	if(k[x-1][y+1]=='*')
	k[x-1][y+1]='.';
}

int main()
{
	for(int i=0;i<=16;i++)
	for(int l=0;l<=16;l++)
	k[i][l]='.';
	for(int i=0;i<=16;i++)
	k[i][0]=k[i][16]=k[16][i]=k[0][i]='K';
	string a;
	k[x][y]='1';
	k[xa][ya]='2';
	for(int i=1;i<=15;i++)
	{
		for(int l=1;l<=15;l++)
		cout<<k[i][l]<<' ';
		cout<<endl;
	}
		cout<<"玩家1 wasd移动 k查看 f放置 p破坏\n";
		cout<<"玩家2 8456移动"<<(k44==100?"1自爆\n":"\n");
	f=0;
	while(1)
	{
		k44++;
		k44=min(k44,100);
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
			else if(c=='1'&&k44==100)
			{
				if(k[xa+1][ya]=='1'||k[xa][ya+1]=='1'||k[xa+1][ya+1]=='1'||k[xa][ya-1]=='1')
				{
					cout<<"1号死了"<<endl;
					return 0;
				}
				if(k[xa+1][ya-1]=='1'||k[xa-1][ya+1]=='1'||k[xa-1][ya-1]=='1'||k[xa-1][ya]=='1')
				{
					cout<<"1号死了"<<endl;
					return 0;
				}
				clear(xa,ya);
				k44=0;
			}
			k[xa][ya]='2';
			
			for(int i=1;i<=15;i++)
			{
				for(int l=1;l<=15;l++)
				cout<<k[i][l]<<' ';
				cout<<endl;
			}
			cout<<"玩家1 wasd移动 k查看 f放置 p破坏\n";
			cout<<"玩家2 8456移动"<<(k44==100?"1自爆\n":"\n");
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
				for(int i=1;i<=15;i++)
				{
					for(int l=1;l<=15;l++)
					cout<<k[i][l]<<' ';
					cout<<endl;
				}
				cout<<"玩家1 wasd移动 k查看 f放置 p破坏\n";
				cout<<"玩家2 8456移动"<<(k44==100?"1自爆\n":"\n");
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
				for(int i=1;i<=15;i++)
				{
					for(int l=1;l<=15;l++)
					cout<<k[i][l]<<' ';
					cout<<endl;
				}
				cout<<"玩家1 wasd移动 k查看 f放置 p破坏\n";
				cout<<"玩家2 8456移动"<<(k44==100?"1自爆\n":"\n");
				continue;
			}
			if(f==3&&(c<'0'||c>'9'))
			{
				f=0;
				for(int i=1;i<=15;i++)
				{
					for(int l=1;l<=15;l++)
					cout<<k[i][l]<<' ';
					cout<<endl;
				}
				cout<<"玩家1 wasd移动 k查看 f放置 p破坏\n";
				cout<<"玩家2 8456移动"<<(k44==100?"1自爆\n":"\n");
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
		for(int i=1;i<=15;i++)
		{
			for(int l=1;l<=15;l++)
			cout<<k[i][l]<<' ';
			cout<<endl;
		}
		cout<<"玩家1 wasd移动 k查看 f放置 p破坏\n";
		cout<<"玩家2 8456移动"<<(k44==100?"1自爆\n":"\n");
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
