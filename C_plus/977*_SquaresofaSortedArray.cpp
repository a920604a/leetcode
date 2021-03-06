class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        // option 1 O(nlogn) sorted algorithm
        // int n = nums.size();
        // vector<int> ret;
        // for(int i:nums) ret.emplace_back(i*i);
        // sort(ret.begin(),ret.end());
        // return ret;

        // option 1.1 O(nlogn) time
        //         sort(nums.begin(), nums.end(), [](int a, int b){
        //             return abs(a)<abs(b);
        //         });

        //         for(int &a:nums) a = a*a;
        //         return nums;

        // option 2  O(n) two pointer
        // int n = nums.size();
        // vector<int> ret;
        // int l =0,r=n-1;
        // while(l<=r){
        //     if(pow(nums[l],2) >= pow(nums[r],2)){
        //         ret.emplace(ret.begin(), pow(nums[l],2));
        //         l++;
        //     }
        //     else{
        //         ret.emplace(ret.begin(), pow(nums[r],2));
        //         r--;
        //     }
        // }
        // return ret;

        // option 3 simplify faster option 2

        int n = nums.size(), l = 0, r = n - 1;
        vector<int> ret(n, 0);
        for (int i = r; i > -1; i--)
        {
            if (abs(nums[l]) > abs(nums[r]))
            {
                ret[i] = nums[l] * nums[l++];
            }
            else
                ret[i] = nums[r] * nums[r--];
        }
        return ret;
    }
};