# 189. Rotate Array

## [problem](https://leetcode.com/problems/rotate-array/)

## solution


#### option 1 
```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // copy vector
        vector<int> temp = nums;
        for(int i=0;i<n;++i){
            nums[i] = temp[(n-k+i)%n];
        }
    }
};
```

#### option 2 - *reverse
```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k%=n;
        reverse(nums.begin(),nums.begin()+(n-k) );
        reverse(nums.begin()+(n-k), nums.end());
        reverse(nums.begin(), nums.end());      
    }
};

```


## analysis
- option 1  
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`