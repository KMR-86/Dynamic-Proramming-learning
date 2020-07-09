#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int v[22];
bool visited[22][1002];
int mem[22][1002];


int subset_sum_iter(int s,int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(j==0){
                mem[i][j]=1;
            }
            else if(i==0){
                mem[i][j]=0;
            }
            else{
                if(v[i-1]<=j){
                    mem[i][j]=mem[i-1][j-v[i-1]] + mem[i-1][j] ;

                }
                else{
                    mem[i][j]=mem[i-1][j];
                }
            }

        }
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
    int s,n,target;
    s=0;
    cin>>n>>target;
    memset(mem, 0, sizeof(mem[0][0]) * 22 * 1002);
    memset(visited, false, sizeof(mem[0][0]) * 22 * 1002);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v[i]=t;
        s+=t;


    }
    int ans=0;
    subset_sum_iter(s,n);
    for(int i=0;i<=s;i++){
        if(mem[n][i]>0 && s-2*i==target){
            ans+=mem[n][i];
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            cout<<mem[i][j]<<" ";
        }
        cout<<endl;
    }


}



return 0;
}
/*
tricky test case:
1
5
1
0 0 0 0 1



*/


