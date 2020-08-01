#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int a[102];
int n=0;
int mem[102][102];

int mcm(int i,int j){
    if(i>=j){
        return 0;
    }
    if(mem[i][j]!=-1)return mem[i][j];
    int ans=INT_MAX;
    int t=0;
    for(int k=i;k<=j-1;k++){
        t=mcm(i,k)+mcm(k+1,j)+a[i-1]*a[k]*a[j];
        ans=min(ans,t);
    }
    mem[i][j]=ans;
    return mem[i][j];
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
cin>>tc;
while(tc--){
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a[i]=t;

    }
    memset(mem,-1,sizeof(mem[0][0])*102*102);
    cout<<mcm(1,n-1)<<endl;



}


return 0;
}



