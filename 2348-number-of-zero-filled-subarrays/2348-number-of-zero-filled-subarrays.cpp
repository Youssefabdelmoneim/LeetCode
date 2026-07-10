class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
      unsigned long long  res = 0;
      unsigned long long  seg = 0;
        for ( auto num : nums)
        {
          if ( num == 0 ) seg ++;
          else {
            res += seg * ( seg + 1) / 2;
            seg = 0;
          }
        }
     res += seg * ( seg + 1) / 2;
        return res;
    }
};
