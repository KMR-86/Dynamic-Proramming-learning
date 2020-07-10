#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int v[102];
int mem[102][102];
int rod_cutting(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                mem[i][j]=0;
            }
            else{
                if(i<=j){
                    mem[i][j]=max(v[i-1]+mem[i][j-i],mem[i-1][j]);
                }
                else{
                    mem[i][j]=mem[i-1][j];
                }
            }
        }
    }
    return mem[n][n];
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
cin>>tc;
while(tc--){
    memset(mem,-1,sizeof(mem[0][0])*102*102);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v[i]=t;
    }
    cout<<rod_cutting(n)<<endl;


}


return 0;
}



