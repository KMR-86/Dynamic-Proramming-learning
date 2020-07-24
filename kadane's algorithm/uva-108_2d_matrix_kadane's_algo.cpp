#include<bits/stdc++.h>
#define S 1000000
using namespace std;

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int n;
cin>>n;
int a[n][n];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        int t;
        cin>>t;
        if(i==0 && j==0)a[i][j]=t;
        else{
            if(i>0 && j==0) a[i][j]=a[i-1][j]+t;
            else if (j>0 && i==0)a[i][j]=a[i][j-1]+t;
            else if(j>0 && i>0)a[i][j]=a[i-1][j]+a[i][j-1]+t-a[i-1][j-1];
        }
    }
}

/*for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<a[i][j]<<" ";
    }
    cout<<"\n";
}*/
int max_sum=-1280000;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        for(int k=i;k<n;k++){
            for(int l=j;l<n;l++){
                int sum=a[k][l];
                if(i>0)sum=sum-a[i-1][l];
                if(j>0)sum=sum-a[k][j-1];
                if(i>0 && j>0)sum=sum+a[i-1][j-1];
                max_sum=max(max_sum,sum);
                //cout<<max_sum<<endl;
            }
        }
    }
}
cout<<max_sum<<endl;

return 0;
}




