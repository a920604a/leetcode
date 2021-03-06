class Solution
{
public:
    map<tuple<int, int>, int> memo;
    int distance(string s1, string s2, int i, int j)
    {

        if (i == -1)
            return j + 1;
        if (j == -1)
            return i + 1;

        if (memo.count(make_pair(i, j)))
            return memo[make_pair(i, j)];

        if (s1[i] == s2[j])
        {
            memo[make_pair(i, j)] = distance(s1, s2, i - 1, j - 1);
            return memo[make_pair(i, j)];
        }

        memo[make_pair(i, j)] = min(min(
                                        distance(s1, s2, i - 1, j) + 1, // 刪除，
                                        distance(s1, s2, i, j - 1) + 1  // 插入，相當於在 s1 後面插入 s2[j] ，插入後 j--

                                        ),
                                    distance(s1, s2, i - 1, j - 1) + 1 // 替換
        );
        return memo[make_pair(i, j)];
    }

    int dp(string s1, string s2, int i, int j)
    {
        //base case
        if (i == -1)
            return j + 1;
        if (j == -1)
            return i + 1;

        if (s1[i] == s2[j])
            return dp(s1, s2, i - 1, j - 1); // 往前走
        else
        {
            return Getmin(
                dp(s1, s2, i, j - 1) + 1,    // 插入
                dp(s1, s2, i - 1, j) + 1,    // 刪除
                dp(s1, s2, i - 1, j - 1) + 1 // 替換
            );
        }
    }
    int Getmin(int a, int b, int c)
    {
        return min(a, min(b, c));
    }
    int minDistance(string word1, string word2)
    {
        // option 1 dp brute force  -> time out
        // 三種操作 替代、刪除、插入
        // 雙指標從字串尾部開始遍歷，遇到字符相同，就什麼都別做skip，i--,j--
        // if s1[i] == s2[j]:
        //     啥都别做（skip）
        //     i, j 同时向前移动
        // 三種操作都是用遞迴遍歷尋找最小編輯距離
        // else:
        //     三选一：
        //         插入（insert）
        //         删除（delete）
        //         替换（replace）

        //
        // return dp(word1, word2, word1.size()-1, word2.size()-1);

        // option 2 memo 避免重疊子問題
        return distance(word1, word2, word1.size() - 1, word2.size() - 1);
        // s1[i-1] !=s2[j-1] , dp[i][j] = min(insert, delete, replace)
        // s1[i-1] !=s2[j-1] , dp[i][j] = min(dp[i][j-1] +1 , dp[i-1][j]+1, dp[i-1][j-1])
        // s1[i] == s2[j] , dp[i][j] = dp[i-1][j-1]
        // option 3 dp
        //dp
        //          h   o   r   s   e
        //      0   1   2   3   4   5
        //r     1   1   2   2   3   4
        //o     2   2   1   2   3   4
        //s     3   3   2   2   2   3

        // 替換/跳過   刪除
        // 插入       現在狀態
        //    dp[i][j] = dp[i-1][j-1]
        //    dp[i][j] = min(  dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);

        int m = word1.size(), n = word2.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= n; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(
                        dp[i - 1][j] + 1, min(dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1));
            }
        }
        return dp[m][n];
    }
};