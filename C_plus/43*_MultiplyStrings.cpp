class Solution
{
public:
    string multiply(string num1, string num2)
    {

        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);
        // 從個位數開始逐位相乘
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {

                int mul = (num1[i] - '0') * (num2[j] - '0');
                // 乘積在res 對應的索引位置
                int p1 = i + j, p2 = i + j + 1;
                // 疊加到res上
                int sum = mul + res[p2];
                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }
        // remove zero-leading
        int i = 0;
        for(; i<res.size() && res[i]==0 ;i++);

        // 結果轉為字串
        string str;
        for (; i < res.size(); ++i)
            str.push_back('0' + res[i]);

        return str.size() == 0 ? "0" : str;
    }
};