#include<bits/stdc++.h>
#define S 1000000
using namespace std;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
cin>>tc;
int c=1;
while(tc--){
    int n;
    cin>>n;
    int ans=0;
    int sum=0;
    int f=0,l=0,ff=-1,fl=-1;
    int chng=0;
    for(int i=0;i<n-1;i++){
        int t;
        cin>>t;
        sum+=t;
        int prev=ans;
        ans=max(ans,sum);
        //cout<<f<<" "<<i<<" "<<sum<<" "<<ans<<" "<<fl-ff<<" "<<i-f<<endl;
        //cout<<ans<<" "<<sum<<endl;
        if(prev<ans){ff=f;fl=i;}
        else if(ans==sum && !chng){ff=f;fl=i;}
        else if(ans==sum && fl-ff<i-f && chng){ff=f;fl=i;chng=0;}


        if(sum<0){
            sum=0;
            f=i+1;
            chng=1;
        }
    }
    if(ans<=0)printf("Route %d has no nice parts\n",c++);
    else printf("The nicest part of route %d is between stops %d and %d\n",c++,ff+1,fl+2);
}


return 0;
}




