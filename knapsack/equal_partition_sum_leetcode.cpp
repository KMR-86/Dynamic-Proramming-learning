class Solution {
public:
    int mem[202][20002];
    int equal_partition_sum(int sumA, int sumB,int n,vector<int>& v)
{
    if(sumA==sumB)
        return 1;
    if(n==0 || sumB<sumA)
        {return 0;}


    if(mem[n][sumB]!=-1)
        return mem[n][sumB];

    if(sumA<=sumB-v[n-1])
    {
        mem[n][sumB]=max(equal_partition_sum(sumA+v[n-1],sumB-v[n-1], n-1,v), equal_partition_sum(sumA,sumB,n-1,v));
        return mem[n][sumB];
    }
    else
    {
        mem[n][sumB]=equal_partition_sum(sumA,sumB,n-1,v);
        return mem[n][sumB];
    }

}

    bool canPartition(vector<int>& v) {
        memset(mem, -1, sizeof(mem[0][0]) * 202 * 20002);
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum=sum+v[i];
        }
        return equal_partition_sum(0,sum,v.size(),v);
    }
};
