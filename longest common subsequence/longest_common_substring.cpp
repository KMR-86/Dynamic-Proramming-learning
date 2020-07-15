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
    if(s1[i-1]==s2[j-1] && (i==1 || j==1)){
        //cout<<s1[i-1]<<endl;
        mem[i][j]=1;
        return 1;

    }
    else if(s1[i-1]==s2[j-1] && s1[i-2]==s2[j-2]){
        mem[i][j]= max(max(1+lcs_recur(i-1,j-1),lcs_recur(i,j-1)),lcs_recur(i-1,j));
        return mem[i][j];
    }
    else{
        mem[i][j]=max(lcs_recur(i,j-1),lcs_recur(i-1,j));
        return mem[i][j];
    }

}

string backtrack(int i,int j){

    string lcs="";
    while(i!=0 && j!=0){

        if(mem[i][j]==1+mem[i-1][j-1] && s1[i-1]==s2[j-1]){
            lcs=lcs+s1[i-1];
            i--;
            j--;
        }
        else if(mem[i][j]==mem[i-1][j]){
            i=i-1;
        }
        else if(mem[i][j]==mem[i][j-1]){
            j=j-1;
        }

    }
    reverse(lcs.begin(),lcs.end());
    return lcs;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
memset(mem,-1,sizeof(mem[0][0])*1002*1002);
cin>>s1>>s2;
//cout<<s1.size()<<s2.size()<<endl;
mem[0][0]=0;
cout<<lcs_recur(s1.size(),s2.size())<<endl;

for(int i=0;i<=s1.size();i++){
    for(int j=0;j<=s2.size();j++){
        cout<<mem[i][j]<<" ";
    }
    cout<<endl;
}

//cout<<backtrack(s1.size(),s2.size())<<endl;

return 0;
}
/*
sabsca
asabcsa
*/

