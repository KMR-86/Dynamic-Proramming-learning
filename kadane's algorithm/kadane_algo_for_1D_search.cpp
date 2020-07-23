#include<bits/stdc++.h>
#define S 1000000
using namespace std;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);
static const int arr[] = {4, -5, 4, -3, 4, 4, -4, 4, -5};
vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );


int ans=0;
int sum=0;

for(int i=0;i<vec.size();i++){
    sum=sum+vec[i];
    ans=max(ans,sum);
    if(sum<0)sum=0;

}

cout<<ans<<endl;

return 0;
}



