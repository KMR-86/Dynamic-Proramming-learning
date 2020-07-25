#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int mem[102][50002];
int coin[102];
int min_subset_difference(int n, int sumA,int sumB){
    if(sumA>=sumB){mem[n][sumA]=sumA-sumB;return mem[n][sumA];}
    if(n==0){mem[n][sumA]=400000000;return mem[n][sumA];}

    if(mem[n][sumA]!=-1)return mem[n][sumA];

    if(sumA<=sumB){
        mem[n][sumA]=min(min_subset_difference(n-1,sumA+coin[n-1],sumB-coin[n-1]), min_subset_difference(n-1,sumA,sumB));
        return mem[n][sumA];
    }
    else{
        mem[n][sumA]=min_subset_difference(n-1,sumA,sumB);
        return mem[n][sumA];
    }

}
int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
cin>>tc;
while(tc--){
    int n;
    int sum=0;
    cin>>n;
    memset(mem,-1,sizeof(mem[0][0])*102*50002);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        coin[i]=t;
        sum+=t;
    }
    cout<<min_subset_difference(n,0,sum)<<endl;
}


return 0;
}




