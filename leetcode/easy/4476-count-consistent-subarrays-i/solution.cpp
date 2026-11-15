class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int sz = nums.size(),count = 0;

        for(int i = 0; i < sz; i++)
        {
            int current_min = nums[i];
            int current_and = nums[i];
            for(int j = i; j < sz; j++)
            {
                current_and = current_and & nums[j];
                current_min = min(current_min, nums[j]);

                if(current_min == current_and) count++;
            }
        }
        return count;
    }
};