class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int rem=target-nums[i];
            if(mpp.contains(rem)) {return {mpp[rem],i};
            }
            else{
                mpp[nums[i]]=i;
            }
        }

        return {};
    }
};
