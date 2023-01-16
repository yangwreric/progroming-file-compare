#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+7;

int n,m,head[maxn],cnt=0,dep[maxn],f[maxn][21];
int size[maxn];
long long ans=0;
struct edge
{
	int to,pre;
}e[maxn*2];

inline void add(int x,int y)
{
	e[++cnt].pre=head[x];
	e[cnt].to=y;
	head[x]=cnt;
}

void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	for(int i=1;i<=20;++i)
		f[x][i]=f[f[x][i-1]][i-1];
		
	for(int i=head[x];i;i=e[i].pre)
	{
		int v=e[i].to;
		if(v==fa) continue;
		f[v][0]=x;
		dfs(v,x);
	}
}

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	
	for(int i=20;i>=0;--i)
	{
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
	for(int i=20;i>=0;--i)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

void aaa(int x,int fa)
{
	for(int i=head[x];i;i=e[i].pre)
	{
		int v=e[i].to;
		if(v==fa) continue;
		aaa(v,x);
		size[x]+=size[v];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);	
	}
	dfs(1,0);
	
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		int t=lca(x,y);
		size[t]-=2;
		size[x]++;size[y]++;
	}
	aaa(1,0);
	for(int i=2;i<=n;++i)
	{
		if(size[i]==0) ans+=m;
		if(size[i]==1) ans++;
	}
	printf("%lld",ans);
	return 0;
}
