#include<bits/stdc++.h>
#define S 1000000
using namespace std;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
while(true){
    cin>>tc;
    if(tc==0)break;
    int a[tc];
    for(int i=0;i<tc;i++){
        int t;
        cin>>t;
        a[i]=t;
    }
    int sum=0;
    int k=-INT_MAX;
    for(int i=0;i<tc;i++){
        sum=sum+a[i];
        if(k<sum)k=sum;
        if(sum<0)sum=0;
    }
    if(k<=0){
        cout<<"Losing streak."<<endl;
    }
    else{
        cout<<"The maximum winning streak is "<<k<<".\n";

    }
}


return 0;
}



