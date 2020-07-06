#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int v[1002];
int mem[1002][1002];
int subset_sum(int s, int n){
    if(s==0)return 1;
    if(n==0)return 0;

    if(mem[n][s]!=-1)return mem[n][s];

    if(v[n-1]<=s){
        mem[n][s]=max(subset_sum(s-v[n-1], n-1), subset_sum(s,n-1));
        return mem[n][s];
    }
    else{
        mem[n][s]=subset_sum(s,n-1);
        return mem[n][s];
    }

}

int subset_sum_iter(int s,int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            //cout<<i<<j<<endl;
            if(j==0){
                mem[i][j]=1;
            }
            else if(i==0){
                mem[i][j]=0;
            }
            else{
                if(v[i-1]<=j){
                    mem[i][j]=max(mem[i-1][j-v[i-1]], mem[i-1][j]);
                }
                else{
                    mem[i][j]=mem[i-1][j];
                }
            }

        }
    }
    return mem[n][s];

}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
memset(mem, -1, sizeof(mem[0][0]) * 1002 * 1002);
int tc;
cin>>tc;
while(tc--){
    int s,n;
    cin>>n>>s;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v[i]=t;


    }
    cout<<subset_sum(s,n)<<endl;
}
/*for(int i=0;i<1002;i++){
    for(int j=0;j<1002;j++){
        if(mem[i][j]!=-1)cout<<mem[i][j]<<" "<<i<<j<<endl;
    }

}*/

return 0;
}



