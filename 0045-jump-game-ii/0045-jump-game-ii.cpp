class Solution {
public:
  int jump(vector<int>& nums) {
    int left = 0, right = 0;
    int count = 0;
    while (right < nums.size() - 1) {
    int max_reach = 0;
      for (int i = left; i <= right; i++) {
        max_reach = max(max_reach, i + nums[i]);
      }
      left = right + 1;
      right = max_reach;
      count++;
    }
    return count;
  }
};
