#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int w[2002],v[2002];
int mem[2002][2002];
int knapsack(int wc,int n){
    if(wc==0 || n==0){
        return 0;
    }
    if(mem[wc][n]!=-1)return mem[wc][n];
    if(w[n-1]<=wc){

        mem[wc][n]= max(v[n-1]+knapsack(wc-w[n-1],n-1), knapsack(wc,n-1));
        return mem[wc][n];
    }
    else{
        mem[wc][n]= knapsack(wc,n-1);
        return mem[wc][n];
    }

}
int knapsack_iter(int wc,int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=wc;j++){
            if(i==0 || j==0){
                mem[i][j]=0;
            }

            else{
                if(w[i-1]<=j){
                    mem[i][j]=max(v[i-1]+mem[i-1][j-w[i-1]], mem[i-1][j]);
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
memset(mem, -1, sizeof(mem[0][0]) * 2002 * 2002);
int tc;
cin>>tc;
while(tc--){
    int wc,n;
    cin>>wc>>n;

    for(int i=0;i<n;i++){
        int tv,tw;
        cin>>tw>>tv;
        w[i]=tw;
        v[i]=tv;

    }
    cout<<knapsack_iter(wc,n)<<endl;
}


return 0;
}



