#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int mem[52][1002];
int v[52];
int min_subset_diff(int sumA,int sumB,int n){
if(sumA==0)return sumB;
if(sumB==0)return sumA;
if(mem[n][sumB]!=-1)return mem[n][sumB];

if(v[n-1]<=sumB){
    mem[n][sumB]=min(min_subset_diff(sumA+v[n-1],sumB-v[n-1],n-1),min_subset_diff(sumA,sumB,n-1));
    return mem[n][sumB];
}
else{
    mem[n][sumB]=min_subset_diff(sumA,sumB,n-1);
    return mem[n][sumB];
}


}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
cin>>tc;
while(tc--){
    memset(mem,-1,sizeof(mem[0][0])*52*1002);
    int n;
    int sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v[i]=t;
        sum+=t;
    }

    cout<<min_subset_diff(0,sum,n)<<endl;


}


return 0;
}



