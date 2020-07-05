#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int w[2002],v[2002];

int knapsack(int wc,int n){
    if(wc==0 || n==0){
        return 0;
    }

    if(w[n-1]<=wc){
        return max(v[n-1]+knapsack(wc-w[n-1],n-1), knapsack(wc,n-1));
    }
    else{
        return knapsack(wc,n-1);
    }

}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

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
    cout<<knapsack(wc,n)<<endl;
}


return 0;
}



