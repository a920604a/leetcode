class Solution
{
public:
    vector<int> grayCode(int n)
    {
        // 參考https://leetcode.com/discuss/explore/july-leetcoding-challenge-2021/1308587/Gray-Code-or-Recursion-%2B-Iterative-wExplanation

        // option 1
        // if n= 1 ,  {0,1}
        // if n=2 , {00,01,11,10}
        // if n= 3, {000,001,011,010,110,111,101,100}
        // 以n=3當例子，前半段{000,001,011,010} 可以當作是n=2 {00,01,11,10} 在前面加上0，
        // 後半段{110,111,101,100} ，沒那麼直觀，是 reverse {00,01,11,10}(={10,11,01,00}) 再前面加上1

        //         vector<string> gray = {"0","1"};

        //         if(n==1) return {0,1};

        //         for(int i=2;i<=n;i++){
        //             int size = gray.size();
        //             vector<string> second = gray;
        //             for(auto &r :gray){
        //                 r = "0"+r;
        //             }

        //             reverse(second.begin(), second.end());
        //             for(auto &s:second){
        //                 s = "1" +s;
        //             }
        //             gray.insert(gray.end(), second.begin(), second.end());
        //         }

        //         // consert string to int
        //         vector<int> ret;
        //         for(string g:gray) ret.push_back(stoi(g,0,2)); // better than stoi(g);
        //         return ret;

        // option 2 bit manipulation
        // n = 2 {00,01,11,10} 長度 4 = 1<<2
        // n = 3 {000,001,011,010,110,111,101,100} 長度 8 1<<3
        // n = 2 為例，
        // 00^(00) = 00 , i=0
        // 01^(00) = 01 , i=1
        // 10^(01) = 11, i=2
        // 11^(01) = 10, i=3
        vector<int> ans;
        for (int i = 0; i < (1 << n); i++)
        {
            ans.push_back(i ^ (i >> 1));
        }
        return ans;
    }
};