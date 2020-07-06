#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int v[1002];
bool visited[1002][1002];
bool mem[1002][1002];
bool subset_sum(int s, int n){
    if(s==0)return true;
    if(n==0)return false;

    if(visited[n][s])return mem[n][s];

    if(v[n-1]<=s){
        mem[n][s]=subset_sum(s-v[n-1], n-1) || subset_sum(s,n-1);
        visited[n][s]=true;
        return mem[n][s];
    }
    else{
        mem[n][s]=subset_sum(s,n-1);
        visited[n][s]=true;
        return mem[n][s];
    }

}

int subset_sum_iter(int s,int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(j==0){
                mem[i][j]=true;
            }
            else if(i==0){
                mem[i][j]=false;
            }
            else{
                if(v[i-1]<=j){
                    mem[i][j]=mem[i-1][j-v[i-1]] || mem[i-1][j];

                }
                else{
                    mem[i][j]=mem[i-1][j];
                }
            }

        }
    }
    return mem[n][s];

}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

ios_base::sync_with_stdio(0);
cin.tie(0);

int tc;
cin>>tc;
while(tc--){
    int s,n;
    cin>>n>>s;
    memset(mem, false, sizeof(mem[0][0]) * 1002 * 1002);
    memset(visited, false, sizeof(mem[0][0]) * 1002 * 1002);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v[i]=t;


    }
    cout<<subset_sum_iter(s,n)<<endl;
}


return 0;
}
/*
tricky test case:
2
2 1
0 1
3 1
2 3 2


*/


