class Solution {
public:
    int mem[22][1002];
    int count_sum(vector <int>&nums,int n, int sum){

        if(n==0){
            if(sum==0)return 1;
            else return 0;
        }


        if(mem[n][sum]!=-1)return mem[n][sum];

        if(nums[n-1]<=sum){
            mem[n][sum]=count_sum(nums,n-1,sum-nums[n-1])+count_sum(nums,n-1,sum);
            return mem[n][sum];
        }
        else{
            mem[n][sum]=count_sum(nums,n-1,sum);
            return mem[n][sum];
        }
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        memset(mem,-1,sizeof(mem[0][0])*22*1002);

        long long int sum=accumulate(nums.begin(), nums.end(), 0);
        long long int mid=sum+S;
        if(mid%2!=0)return 0;
        if(S>sum)return 0;
        return count_sum(nums,nums.size(),(sum+S)/2);



    }
};
