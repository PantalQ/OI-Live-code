// https://www.luogu.com.cn/problem/P1049
// 2021.10.30
#include<bits/stdc++.h>
using namespace std;
const int N = 20000 + 10;
int m,n;
int v[40];
int dp[N];
int main(){
    memset(dp,0,sizeof dp);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
            //cout<<i<<' '<<j<<endl;
        }
    }
    printf("%d\n",m-dp[m]);
    return 0;
}