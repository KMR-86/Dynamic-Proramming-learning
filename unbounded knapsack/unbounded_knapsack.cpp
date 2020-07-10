#include<bits/stdc++.h>
#define S 1000000
using namespace std;

int v[1002];
int w[1002];
int mem[1002][1002];
int unbounded_knapsack(int n,int wc){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=wc;j++){
            if(i==0 || j==0){
                mem[i][j]=0;
            }
            else{
                if(w[i-1]<=j){
                    mem[i][j]=max( v[i-1]+mem[i][j-w[i-1]] , mem[i-1][j] );
                }
                else{
                    mem[i][j]=mem[i-1][j];
                }
            }
        }
    }
    return mem[n][wc];
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
cin>>tc;
while(tc--){
    int n,wc;
    cin>>n>>wc;
    for(int i=0;i<n;i++){
        int tv,tw;
        cin>>tv;
        v[i]=tv;

    }

    for(int i=0;i<n;i++){
        int tv,tw;
        cin>>tw;
        w[i]=tw;
    }
    cout<<unbounded_knapsack(n,wc)<<endl;

    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=wc;j++){
            cout<<mem[i][j]<<" ";
        }
        cout<<endl;
    }*/
}


return 0;
}



