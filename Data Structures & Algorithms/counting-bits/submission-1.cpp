class Solution {
public:
    vector<int> countBits(int n) { 
        vector<int>result;
        for(int i=0;i<=n;i++){
            int val=i;
            int count=0;
            while(val){
                if(val&1==1) count++;
                val=val>>1;
            }
            result.push_back(count);
        }
        return result;
    }
};
