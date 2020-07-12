#include<bits/stdc++.h>
#define S 1000000
using namespace std;
int v[1000000];
long long int coin_change(int n, int sum)
{
    long long int mem[n+2][sum+2];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {

            if(i==0)
            {
                mem[i][j]=INT_MAX-1;
            }

            else if(j==0)
            {
                mem[i][j]=0;
            }
            /*else if(i==1)
            {
                if(j%v[i-1]==0 && v[i-1]!=0)
                    mem[i][j]=j/v[i-1];
                else
                {
                    mem[i][j]=INT_MAX-1;
                }
            }*/

            else
            {
                if(v[i-1]<=j)
                {
                    mem[i][j]=min(1+mem[i][j-v[i-1]],mem[i-1][j]);
                }
                else
                {
                    mem[i][j]=mem[i-1][j];
                }
            }
        }
    }
    return mem[n][sum];

}
int main()
{
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,m;
        cin>>m>>n;
        for(int i=0; i<n; i++)
        {
            int t;
            cin>>t;
            v[i]=t;
        }

        int ans = coin_change(n,m);
        if(ans==INT_MAX-1){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
        /*for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                cout<<mem[i][j]<<" ";
            }
            cout<<endl;

        }*/

    }


    return 0;
}
/*
1
5 3
1 2 3


*/


