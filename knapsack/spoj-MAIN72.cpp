#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int v[1002];
int mem[1002][100002];


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
                    mem[i][j]=max(mem[i-1][j-v[i-1]],mem[i-1][j]);
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
memset(mem, -1, sizeof(mem[0][0]) * 1002 * 100002);
int tc;
cin>>tc;

while(tc--){
    int n;
    cin>>n;
    long long int sum=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v[i]=t;
        sum=sum+v[i];

    }
    long long int ans=0;
    subset_sum_iter(sum,n);
    for(int i=1;i<=sum;i++){
        if(mem[n][i]){ans=ans+i;}
    }
    cout<<ans<<endl;

}


return 0;
}



