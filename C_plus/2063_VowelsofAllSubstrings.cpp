class Solution
{
public:
    long long countVowels(string word)
    {
        long long cnt = 0, ans = 0, n = word.size();
        for (char c : word)
        {
            ++cnt;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                ans += cnt * (n - cnt + 1);
            }
        }
        return ans;
    }
};