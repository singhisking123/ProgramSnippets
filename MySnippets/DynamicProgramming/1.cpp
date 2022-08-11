class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                int new_target = target - nums[i] - nums[j];

                int left = j + 1, right = n - 1;


                while (left < right) {
                    int sum = nums[left] + nums[right];
                    if (sum < new_target) {
                        left++;
                        // do{left++;}while(nums[left-1]==nums[left]);
                    }
                    else if (sum > new_target) {
                        right--;
                        // do{right--;}while(nums[right+1]==nums[right]);
                    }
                    else if (sum == new_target) {
                        vector<int> quads(4, 0);
                        quads[0] = nums[i];
                        quads[1] = nums[j];
                        quads[2] = nums[left];
                        quads[3] = nums[right];
                        res.push_back(quads);
                        do {left++;} while ( nums[left - 1] == nums[left]);
                        do {right--;} while ( nums[right + 1] == nums[right]);
                    }
                }



                // while(j<n-1 && nums[j]==nums[j+1]){
                //     j++;
                // }
            }
            // while(i<n-1 && nums[i]==nums[i+1]){
            //     i++;
            // }
        }
        return res;
    }
};