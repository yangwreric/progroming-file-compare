#include<bits/stdc++.h>
#define random(a,b) ((a)+rand()%((b)-(a)+1))
using namespace std;
const int N=10;
const int M=15;
stringstream str;
int x,y,n,m,seed;
int f[N];
int find(int x){return f[x]==x?f[x]:f[x]=find(f[x]);}
int main(int argc,char *argv[]){
    seed=time(NULL);
    if(argc){
        str.clear();
        str<<argv[1];
        str>>seed;
    }
    srand(seed);
    n=random(10,30),m=random(5,10);
    for(int i=1;i<=n;i++) f[i]=i;
    printf("%d %d\n",n,m);
    for(int cnt=1;cnt<n;){
        x=rand()%n+1;y=rand()%n+1;
        int fx=find(x),fy=find(y);
        if(fx==fy){continue;}
        f[fy]=fx;
        printf("%d %d",x,y);
        ///printf(" %d",rand());(如果边有权值，用上这段代码；如果没有，忽略这句话)
        puts("");
        cnt++;
    }
    putchar('\n');
    for(int i=1;i<=m;i++){
    	int a=random(1,n);
    	int b=random(1,n);
    	while(a==b){
    		b=random(1,n);
    	}
    	printf("%d %d\n",a,b);
    }
	return 0;
}
