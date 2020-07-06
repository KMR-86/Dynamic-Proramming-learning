#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int v[1002];
int mem[110][100002];
int equal_partition_sum(int sumA, int sumB,int n)
{
    if(sumA==sumB)
        return 1;
    if(n==0 || sumB<sumA)
        {return 0;}


    if(mem[n][sumB]!=-1)
        return mem[n][sumB];

    if(sumA<=sumB-v[n-1])
    {
        mem[n][sumB]=max(equal_partition_sum(sumA+v[n-1],sumB-v[n-1], n-1), equal_partition_sum(sumA,sumB,n-1));
        return mem[n][sumB];
    }
    else
    {
        mem[n][sumB]=equal_partition_sum(sumA,sumB,n-1);
        return mem[n][sumB];
    }

}
int equal_sum_partition_iter(int sum,int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0 && j==0){
                mem[i][j]=1;
            }
            else if(i==0 || j==0){
                mem[i][j]=0;
            }
            else{

            }
        }
    }
}
int main()
{
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

    int tc;
    cin>>tc;
    while(tc--)
    {
        memset(mem, -1, sizeof(mem[0][0]) * 110 * 100002);
        int s,n;
        cin>>n;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            int t;
            cin>>t;
            v[i]=t;
            sum+=v[i];

        }
        if(equal_partition_sum(0,sum,n))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    /*for(int i=0;i<1002;i++){
        for(int j=0;j<1002;j++){
            if(mem[i][j]!=-1)cout<<mem[i][j]<<" "<<i<<j<<endl;
        }

    }*/

    return 0;
}


