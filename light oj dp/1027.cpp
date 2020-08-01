#include<bits/stdc++.h>
#define S 1000000
using namespace std;

int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;
    int c=1;
    while(tc--)
    {
        int n;
        cin>>n;
        int pos=0,sum=0;
        for(int i=0; i<n; i++)
        {
            int t;
            cin>>t;
            if(t>=0)
                pos++;
            sum+=abs(t);

        }
        if(pos==0)
            cout<<"Case "<<c++<<": "<<"inf"<<endl;
        else
        {
            //if(pos>n-pos)pos=n-pos;
            sum=sum/__gcd(sum,pos);
            pos=pos/__gcd(sum,pos);
            cout<<"Case "<<c++<<": "<<sum<<"/"<<pos<<endl;

        }
    }


    return 0;
}



