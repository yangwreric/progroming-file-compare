#include <iostream>
#include<cstdio>
#include<string.h>
#include<vector>
using namespace std;
const int lg=20;
int n,m,a,b;
long long cnt; 
vector<int> q[20007];
int num[10007];
int f[10007][lg+1],d[10007];
void dfs(int x,int fa){
	d[x]=d[fa]+1;
	for(int i=1;i<=lg;i++){
		//if(f[x][i-1]){
			f[x][i]=f[f[x][i-1]][i-1];
			//cout<<x<<" "<<i<<":"<<f[x][i]<<endl;
		//}
		//else break;
	}
	for(int i=0;i<q[x].size();i++){
		int y=q[x][i];
		if(y==fa) continue;
		//cout<<y<<"->"<<x<<endl;
		f[y][0]=x;
		dfs(y,x);
	}
}
void dd(int x,int fa){
	for(int i=0;i<q[x].size();i++){
		int y=q[x][i];
		if(y==fa) continue;
		dd(y,x);
		num[x]+=num[y];
	}
}

int lca(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	for(int i=lg;i>=0;i--){
		if(d[f[x][i]]>=d[y]) x=f[x][i];
		if(x==y) return x;
	}
	//if(x==y) return x;
	for(int i=lg;i>=0;--i){
		//cout<<i<<":"<<f[3][i]<<" "<<f[4][i]<<endl;
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
			//cout<<i<<"---"<<x<<" "<<y<<endl;
		}
	}
	//cout<<x<<" "<<y<<endl;
	return f[x][0];
}
int main(){ 
	//memset(f,0,sizeof(f));
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		q[a].push_back(b);
		q[b].push_back(a);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		num[a]++;
		num[b]++;
		//cout<<lca(a,b)<<endl;
		num[lca(a,b)]-=2;
	}
	//
	dd(1,0);
	for(int i=2;i<=n;++i){
		if(num[i]==0) cnt+=m;
		if(num[i]==1) cnt++;
	}
	//for(int i=1;i<=n;i++) cout<<num[i]<<" ";
	printf("%lld",cnt);
	return 0;
}
//


