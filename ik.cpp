#include <bits/stdc++.h>
#include <Windows.h>
#include <conio.h>
using namespace std;
char p[56]={'.','*','#','1','W'};
char k[16][16];
int x=1,y=1;
int f=0,f2=0;
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

void clear(int x,int y)//dilei
{
	if(k[x+1][y]=='*'||k[x+1][y]=='x')
	k[x+1][y]='.';
	if(k[x-1][y]=='*'||k[x-1][y]=='x')
	k[x-1][y]='.';
	if(k[x+1][y-1]=='*'||k[x+1][y-1]=='x')
	k[x+1][y-1]='.';
	if(k[x][y-1]=='*'||k[x][y-1]=='x')
	k[x][y-1]='.';
	if(k[x-1][y-1]=='*'||k[x-1][y-1]=='x')
	k[x-1][y-1]='.';
	if(k[x+1][y+1]=='*'||k[x+1][y+1]=='x')
	k[x+1][y+1]='.';
	if(k[x][y+1]=='*'||k[x][y+1]=='x')
	k[x][y+1]='.';
	if(k[x-1][y+1]=='*'||k[x-1][y+1]=='x')
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
		cout<<"玩家1 wasd移动 k查看 f放置 p破坏 i地雷 q刀\n";
		cout<<"玩家2 8456移动 2刀 "<<(k44==100?"1自爆\n":"\n");
	f=0;
	while(1)
	{
		k44++;
		k44=min(k44,100);
		char c=_getch();
		system("cls");
		if(c-'0'>0&&c-'0'<=9)
		{
			if(f2!=0)
			{
				f2=0;
				if(c=='8')
				if(k[xa-1][ya]=='1')
				{
					cout<<"1号死了";
					return 0;
				} 
				else if(c=='5')
				if(k[xa+1][ya]=='1')
				{
					cout<<"1号死了";
					return 0;
				} 
				else if(c=='4')
				if(k[xa][ya-1]=='1')
				{
					cout<<"1号死了";
					return 0;
				} 
				else if(c=='6')
				if(k[xa][ya+1]=='1')
				{
					cout<<"1号死了";
					return 0;
				} 
				continue;
				for(int i=1;i<=15;i++)
			{
				for(int l=1;l<=15;l++)
				cout<<k[i][l]<<' ';
				cout<<endl;
			}
			cout<<"玩家1 wasd移动 k查看 f放置 p破坏 i地雷 q刀\n";
			cout<<"玩家2 8456移动 2刀 "<<(k44==100?"1自爆\n":"\n");
			}
			if(c=='2'){
				f2=1;
			}
			if(c=='8'&&(k[xa-1][ya]=='.'||k[xa-1][ya]=='x'))
			k[xa][ya]='.',xa--;
			else if(c=='5'&&(k[xa+1][ya]=='.'||k[xa+1][ya]=='x'))
			k[xa][ya]='.',xa++;
			else if(c=='4'&&(k[xa][ya-1]=='.'||k[xa][ya-1]=='x'))
			k[xa][ya]='.',ya--;
			else if(c=='6'&&(k[xa][ya+1]=='.'||k[xa][ya+1]=='x'))
			k[xa][ya]='.',ya++;
			if(k[xa][ya]=='x')
			{
				cout<<"2号死了"<<endl;
				return 0;
			}
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
			cout<<"玩家1 wasd移动 k查看 f放置 p破坏 i地雷 q刀\n";
			cout<<"玩家2 8456移动 2刀 "<<(k44==100?"1自爆\n":"\n");
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
				cout<<"玩家1 wasd移动 k查看 f放置 p破坏 i地雷 q刀\n";
				cout<<"玩家2 8456移动 2刀 "<<(k44==100?"1自爆\n":"\n");
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
				cout<<"玩家1 wasd移动 k查看 f放置 p破坏 i地雷 q刀\n";
				cout<<"玩家2 8456移动 2刀 "<<(k44==100?"1自爆\n":"\n");
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
				cout<<"玩家1 wasd移动 k查看 f放置 p破坏 i地雷 q刀\n";
				cout<<"玩家2 8456移动 2刀 "<<(k44==100?"1自爆\n":"\n");
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
			if(f==4&&(c<'0'||c>'9'))
			{
				f=0;
				if(c=='w'&&k[x-1][y]=='.')
				k[x-1][y]='x';
				else if(c=='s'&&k[x+1][y]=='.')
				k[x+1][y]='x';
				else if(c=='a'&&k[x][y-1]=='.')
				k[x][y-1]='x';
				else if(c=='d'&&k[x][y+1]=='.')
				k[x][y+1]='x';
				for(int i=1;i<=15;i++)
				{
					for(int l=1;l<=15;l++)
					cout<<k[i][l]<<' ';
					cout<<endl;
				}
				cout<<"玩家1 wasd移动 k查看 f放置 p破坏 i地雷 q刀\n";
				cout<<"玩家2 8456移动 2刀 "<<(k44==100?"1自爆\n":"\n");
				continue;
			}
			if(f==5&&(c<'0'||c>'9'))
			{
				f=0;
//				cout<<c<<endl;
//				cout<<k[x-1][y]<<' '<<k[x+1][y]<<endl;
//				cout<<k[x][y-1]<<' '<<k[x][y+1]<<endl;
				if(c=='w'&&k[x-1][y]=='2')
				{
					cout<<"2号死了";
					return 0;
				} 
				else if(c=='s'&&k[x+1][y]=='2')
				{
					cout<<"2号死了";
					return 0;
				} 
				else if(c=='a'&&k[x][y-1]=='2')
				{
					cout<<"2号死了";
					return 0;
				} 
				else if(c=='d'&&k[x][y+1]=='2')
				{
					cout<<"2号死了";
					return 0;
				} 
				for(int i=1;i<=15;i++)
				{
					for(int l=1;l<=15;l++)
					cout<<k[i][l]<<' ';
					cout<<endl;
				}
				cout<<"玩家1 wasd移动 k查看 f放置 p破坏 i地雷 q刀\n";
				cout<<"玩家2 8456移动 2刀 "<<(k44==100?"1自爆\n":"\n");
			}
			continue;
		}
		if(c=='w'&&(k[x-1][y]=='.'||k[x-1][y]=='x'))
		k[x][y]='.',x--;
		else if(c=='s'&&(k[x+1][y]=='.'||k[x+1][y]=='x'))
		k[x][y]='.',x++;
		else if(c=='a'&&(k[x][y-1]=='.'||k[x][y-1]=='x'))
		k[x][y]='.',y--;
		else if(c=='d'&&(k[x][y+1]=='.'||k[x][y+1]=='x'))
		k[x][y]='.',y++;
		if(k[x][y]=='x')
		{
			cout<<"1号死了";
			return 0;
		}
		k[x][y]='1';
		for(int i=1;i<=15;i++)
		{
			for(int l=1;l<=15;l++)
			cout<<k[i][l]<<' ';
			cout<<endl;
		}
		cout<<"玩家1 wasd移动 k查看 f放置 p破坏 i地雷 q刀\n";
		cout<<"玩家2 8456移动 2刀 "<<(k44==100?"1自爆\n":"\n");
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
		else if(c=='i')
		{
			f=4;
			continue;
		}
		else if(c=='q')
		{
			f=5;
			continue;
		}
	}
	return 0;
}
