# 76. Minimum Window Substring


###### tags: `leetcode` `Hash table` `Siliding Window`

## [problem](https://leetcode.com/problems/minimum-window-substring/)

## solution

- 兩指標，分別指向窗口的左右索引，窗口不斷向右移動，當滿族條件時，則收縮左邊的索引。
```c++
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need, window;
        for(char c:t) need[c]++;
        int start = -1, len = INT_MAX,l=0,r=0, n = s.size(),valid = 0;
        while(r<n){
            char c = s[r++];
            if(need.find(c)!=need.end()){
                window[c]++;
                if(need[c] == window[c]) valid++;
            }
            while(valid == need.size()){
                if(r-l<len){
                    len = r-l;
                    start = l;
                }
                char d =s[l++];
                if(need.find(d) != need.end()){
                    if(need[d] == window[d]) valid--;
                    window[d]--;
                }
            }
        }
        return len==INT_MAX?"":s.substr(start, len);
    }
};
```
## analysis
- time complexity `O(n)`
- speed complexity `O(n)`