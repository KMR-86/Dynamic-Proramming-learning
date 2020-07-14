#include<bits/stdc++.h>
#define S 1000000
using namespace std;
string s1,s2;
int mem[1002][1002];
int lcs_recur(int i,int j){
    if(i==0 || j==0){
        mem[i][j]=0;
        ///cout<<i<<j<<endl;
        return mem[i][j];
    }
    if(mem[i][j]!=-1)return mem[i][j];
    if(s1[i-1]==s2[j-1]){
        //cout<<s1[i-1]<<endl;
        mem[i][j]= max(max(1+lcs_recur(i-1,j-1),lcs_recur(i,j-1)),lcs_recur(i-1,j));
        return mem[i][j];
    }
    else{
        mem[i][j]=max(lcs_recur(i,j-1),lcs_recur(i-1,j));
        return mem[i][j];
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
    memset(mem,-1,sizeof(mem[0][0])*1002*1002);
    int n,m;
    cin>>n>>m;
    cin>>s1>>s2;
    cout<<lcs_recur(n,m)<<endl;


}

/*for(int i=0;i<=s1.size();i++){
    for(int j=0;j<=s2.size();j++){
        cout<<mem[i][j]<<" ";
    }
    cout<<endl;
}*/
return 0;
}

/*
sabsca
asabcsa
*/

