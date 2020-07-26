#include<bits/stdc++.h>
#define S 1000000
using namespace std;

int main()
{
//freopen("input.txt","r",stdin);
    freopen("input.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc=0;



    for(int i=1; i<=30; i++)
    {
        for(int j=0; j<=i*i; j++)
        {
            tc++;
        }

    }
    cout<<tc<<endl;
    for(int i=1; i<=30; i++)
    {
        for(int j=0; j<=i*i; j++)
        {
            cout<<i<<" "<<j<<endl;
        }

    }



    return 0;
}



