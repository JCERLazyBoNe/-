#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,a[105];
struct fr{string name;int tot;}k[105];
int cmd(fr a,fr b){return a.tot>b.tot;}
int maxn,minn;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=m;i++)
    {
        bool yj=true;
        string s;
        cin>>s;
        for(int l=1;l<=cnt;l++)
        {
            if(k[l].name==s)
            {
                k[l].tot++;
                yj=false;
                break;
            }
        }
        if(yj==false)continue;
        k[++cnt].name=s;
        k[cnt].tot=1;
    }
    sort(k+1,k+1+cnt,cmd);
    for(int i=1;i<=cnt;i++)
    {
        // cout<<a[i]<<' '<<k[i].tot<<endl;
        minn+=a[i]*k[i].tot;
        maxn+=a[n-i+1]*k[i].tot;
    }
    cout<<minn<<' '<<maxn<<endl;
}