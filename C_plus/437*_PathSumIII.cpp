/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int countPathsWithSumFromNode(TreeNode *node, int targetSum, int currentSum)
    {
        if (!node)
            return 0;

        currentSum += node->val;
        int totalPaths = 0;
        if (currentSum == targetSum)
        { // Found a path from the root
            totalPaths++;
        }

        totalPaths += countPathsWithSumFromNode(node->left, targetSum, currentSum);
        totalPaths += countPathsWithSumFromNode(node->right, targetSum, currentSum);
        return totalPaths;
    }
    int countPathsWithSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;

        /* Count paths with sum starting from the root. */
        int pathsFromRoot = countPathsWithSumFromNode(root, targetSum, 0);

        /* Try the nodes on the left and right. */
        int pathsOnLeft = countPathsWithSum(root->left, targetSum);
        int pathsOnRight = countPathsWithSum(root->right, targetSum);
        return pathsFromRoot + pathsOnLeft + pathsOnRight;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        // option1 DFS O(N log N) times
        // return countPathsWithSum(root, targetSum);

        // option 2 DFS + hash table O(N) or O(logN) for balanced tree
        unordered_map<int, int> pathCount;
        // pathCount[0] = 1;
        int ret = countPathWitheSum(root, targetSum, 0, pathCount);

        return ret;
    }

    int countPathWitheSum(TreeNode *root, int targetSum, int curSum, unordered_map<int, int> &pathCount)
    {
        if (!root)
            return 0; // Base case

        /* Count paths with sum ending at the the current node */
        curSum += root->val;
        int sum = curSum - targetSum;
        // int totalPaths = pathCount.count(sum)?pathCount[sum]:0;
        int totalPaths = pathCount[sum];

        /*  If curSum eaquls targetSum , then one additionl path starts at root. 
        Add in this path */
        if (curSum == targetSum)
            totalPaths++;

        /*  Increment pathCount, recurse, then decrement pathCount. */
        // incrementHashTable(pathCount, curSum, 1);
        pathCount[curSum]++;
        totalPaths += countPathWitheSum(root->left, targetSum, curSum, pathCount);
        totalPaths += countPathWitheSum(root->right, targetSum, curSum, pathCount);
        // incrementHashTable(pathCount, curSum, -1);
        pathCount[curSum]--;
        return totalPaths;
    }
    void incrementHashTable(unordered_map<int, int> &pathCount, int key, int delta)
    {
        int newCount = pathCount.count(key) ? pathCount[key] : 0;
        newCount += delta;
        if (newCount == 0)
            pathCount.erase(key);
        else
            pathCount[key] = newCount;
    }
};

