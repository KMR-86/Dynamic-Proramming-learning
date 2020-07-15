#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int mem[1002][1002];
string s1,s2;
int lcs_iter(int n,int m){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                mem[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
                mem[i][j]=mem[i-1][j-1]+1;
            }
            else{
                mem[i][j]=max(mem[i-1][j],mem[i][j-1]);
            }
        }
    }
    return mem[n][m];

}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
cin>>tc;

while(tc--){
    cin>>s1>>s2;
    cout<<s1.size()+s2.size()-lcs_iter(s1.size(),s2.size())<<endl;

}


return 0;
}




