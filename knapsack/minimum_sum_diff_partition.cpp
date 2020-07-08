#include<bits/stdc++.h>
#define S 1000000
using namespace std;
bool mem[52][10002];
int v[52];
bool visited[52][10002];


void subset_sum_iter(int sum, int n){

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0){
                mem[i][j]=true;
            }
            else if(i==0){
                mem[i][j]=false;
            }
            else{
                if(v[i-1]<=j){
                    mem[i][j]= mem[i-1][j-v[i-1]] || mem[i-1][j];
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
    memset(mem,false,sizeof(mem[0][0])*52*10002);
    memset(visited,false,sizeof(visited[0][0])*52*10002);
    int n;
    int sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v[i]=t;
        sum+=t;
    }

    subset_sum_iter(sum,n);

    int s1=0;

    for(int i=0;i<=sum/2;i++){
        if(mem[n][i]==true){
            s1=i;
        }
    }
    cout<<sum-2*s1<<endl;


}


return 0;
}



