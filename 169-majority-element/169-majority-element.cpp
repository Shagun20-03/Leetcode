class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second>n/2){
                ans=i.first;
                //return ans;
            }
        }
        return ans;
    }
};