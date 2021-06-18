class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ret = 0;
        int _min = INT_MAX;
        for (int i : prices)
        {
            ret = max(ret, i - _min);
            _min = min(i, _min);
        }
        return ret;
    }
};