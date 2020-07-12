#include<bits/stdc++.h>
#define S 1000000
using namespace std;
long long int mem[302][302];
int v[52];
long long int coin_change(int n, int sum)
{
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
            else if(i==1)
            {
                if(j%v[i-1]==0 && v[i-1]!=0)
                    mem[i][j]=j/v[i-1];
                else
                {
                    mem[i][j]=INT_MAX-1;
                }
            }

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
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int t;
            cin>>t;
            v[i]=t;
        }
        cin>>m;
        cout<<coin_change(n,m)<<endl;
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
3
1 2 3
5

*/


