class Solution {
public:
    int mem[1002][1002];
    string s1,s2;
    string scs_iter(int n,int m){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=m;j++){
                    if(i==0 || j==0){
                        mem[i][j]=0;
                    }
                    else if(s1[i-1]==s2[j-1]){
                        mem[i][j]=mem[i-1][j-1]+1;
                    }
                    else{
                        mem[i][j]=max(mem[i-1][j],mem[i][j-1]);
                    }
                }
            }

            string scs="";

            int i=n;
            int j=m;
            while(i>0 && j>0){
                if(s1[i-1]==s2[j-1]){
                    scs=scs+s1[i-1];
                    i--;
                    j--;
                }
                else if(mem[i][j]==mem[i-1][j]){
                    i--;
                }
                else if(mem[i][j]==mem[i][j-1]){
                    j--;
                }
            }
            reverse(scs.begin(),scs.end());
            return scs;

    }
    string shortestCommonSupersequence(string str1, string str2) {




    s1=str1;
    s2=str2;

    string scs=scs_iter(s1.size(),s2.size());
    int l=s1.size()+s2.size()-scs.size();
    int j=0;
    int ind=0;
    int i1=0;
    int i2=0;
    int i=0;
    string ans="";

    while(i<l){
        while(s1[i1]!=scs[j] && i1<s1.size() && j<l){
            //cout<<"h1"<<s1[i1]<<"h1"<<endl;
            ans+=s1[i1];
            i1++;
            i++;

        }
        while(s2[i2]!=scs[j]  && i2<s2.size() && j<l){
            ans+=s2[i2];
            //cout<<"h2"<<s2[i2]<<"h2"<<endl;
            i2++;
            i++;

        }
        while(s1[i1]==scs[j] && s2[i2]==scs[j] && j<l && i1<s1.size() && i2<s2.size()){
            ans+=scs[j];
            //cout<<"h3"<<scs[j]<<"h3"<<endl;
            j++;
            i++;
            i1++;
            i2++;
        }
    }

    return ans;
    }


};
