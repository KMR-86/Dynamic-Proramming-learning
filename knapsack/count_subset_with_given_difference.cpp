#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int mem[52][10002];
bool visited[52][10002];
int v[52];
int subset_sum_count(int n, int sum)
{
    if(sum==0)
        return 1;
    if(n==0)
        return 0;


    if(mem[n][sum]!=-1)
        return mem[n][sum];
    if(v[n-1]<=sum)
    {
        mem[n][sum]=subset_sum_count(n-1,sum-v[n-1])+subset_sum_count(n-1,sum);
        return mem[n][sum];
    }
    else
    {
        mem[n][sum]=subset_sum_count(n-1,sum);
        return mem[n][sum];
    }
}
int subset_sum_count_iter(int n,int s)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {

            if(j==0)
            {
                mem[i][j]=1;

            }
            else if(i==0)
            {
                mem[i][j]=0;
            }
            else
            {
                if(v[i-1]<=j)
                {
                    mem[i][j]= mem[i-1][j-v[i-1]] + mem[i-1][j];
                }
                else
                {
                    mem[i][j]=mem[i-1][j];
                }
            }
        }
    }
    return mem[n][s];

}
int main()
{
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,dif;
    int sum=0;
    cin>>n>>dif;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        v[i]=t;
        sum+=t;
    }

    cout<<subset_sum_count_iter(n,sum)<<endl;
    int c=0;
    for(int i=0; i<=sum; i++)
    {
        if(mem[n][i]!=0 && sum-2*i==dif)
        {
            c=c+mem[n][i];
        }
    }

    cout<<c<<endl;


    return 0;
}



