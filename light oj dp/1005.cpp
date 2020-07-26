#include<bits/stdc++.h>
#define S 1000000
using namespace std;
long long int mem[32][32];
long long int rooks(long long int n,long long int m, long long int k)
{
    //cout<<n<<" "<<m<<" "<<k<<endl;
    if(k>n || k>m )return 0;
    if(k==0) return 1;
    if(k==1)
    {

        return n*m;
    }

    if(m==1 || n==1)
    {

        return 0;
    }

    if(mem[n][k]!=-1)
        return mem[n][k];

    if(k>1 && n>1 && m>1)
    {

        mem[n][k]=m*rooks(n-1,m-1,k-1)+rooks(n-1,m,k);

        return mem[n][k];
    }



}
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;
    int c=1;
    while(tc--){
        memset(mem,-1,sizeof(mem[0][0])*32*32);
        long long int n,k;
        cin>>n>>k;
        long long int ans=rooks(n,n,k);
        //cout<<"Case "<<c++<<": "<<ans<<endl;
        printf("Case %d: %lld\n",c++,ans);


    }



    return 0;
}




