
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2025;
int n,v[N],f[N][N],ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int len=n;len>=1;len--)
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            f[i][j]=max(f[i][j+1]+v[j+1]*(n-len),f[i-1][j]+v[i-1]*(n-len));
        }
    for(int i=1;i<=n;i++) ans=max(ans,f[i][i]+v[i]*n);
    printf("%d\n",ans);
    return 0;
}
