#include<bits/stdc++.h>
#define S 1000000
using namespace std;
long long int mem[52][252];
int v[52];
long long int coin_change(int n, int m){
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                if(j==0)mem[i][j]=1;
                else{
                    mem[i][j]=0;
                }
            }

            else{
                if(v[i-1]<=j){
                    mem[i][j]=mem[i][j-v[i-1]]+mem[i-1][j];
                }
                else{
                    mem[i][j]=mem[i-1][j];
                }
            }
        }
    }
    return mem[m][n];

}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
    int t;
    cin>>t;
    v[i]=t;
}

cout<<coin_change(n,m)<<endl;

/*for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
        cout<<mem[i][j]<<" ";
    }
    cout<<endl;

}*/
return 0;
}



