class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int n=nums.size();
         vector<int> temp;
    for(int i=0; i<n; i++){
        if(nums[i]!=0){
            temp.push_back(nums[i]);
        }
    }

    for(int i=0; i<temp.size(); i++){
        nums[i]=temp[i];
        
    }
    int nonZero= temp.size();
    for(int i=nonZero; i<n;i++){
        nums[i]=0;
    }
  
    
        
    }
};