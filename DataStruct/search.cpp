/*
 * @Author: yuan
 * @Date: 2021-06-20 12:13:00
 * @LastEditTime: 2021-07-15 14:26:04
 * @FilePath: /leet_code/DataStruct/search.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

int LinearSearch(int arr[], int size, int x)
{

    for (int i = 0; i < size; ++i)
    {
        if (x == arr[i])
            return i;
    }
    return -1;
}
int BinarySearch(int arr[], int n, int x)
{

    // option 1 iterator version
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int BinarySearch_r(int arr[], int l, int r, int target)
{
    if (l > r)
        return -1;

    int mid = l + (r - l) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return BinarySearch_r(arr, l, mid - 1, target);
    return BinarySearch_r(arr, mid + 1, r, target);
}

int ExponentialSearch(int arr[], int size, int x)
{
    if (arr[0] == x)
        return 0;

    int i = 1;
    while (i < size && arr[i] < x)
        i *= 2;
    return BinarySearch_r(arr, i / 2,
                          min(i, size - 1), x);
}
int JumpSearch(vector<int> &nums);          // https://www.geeksforgeeks.org/jump-search/
int InterpolationSearch(vector<int> &nums); // https://www.geeksforgeeks.org/interpolation-search/

int FibonacciSearch(vector<int> &nums); // https://www.geeksforgeeks.org/fibonacci-search/


char f(char c){
    if(c >='a' && c<='z'){
        return c + 'A' - 'a';
    }
    return c;
}


int main()
{
    // int arr[] = {2, 3, 4, 10, 40};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int result = ExponentialSearch(arr, size, 4);

    // if (result == -1)
    // {
    //     std::cout << "not found" << endl;
    // }
    // else
    //     std::cout << result << endl;

    // std::vector<bool> vec {false, false};
    // std::vector<char> vec {'a', 'b'};
    // for(auto &x : vec) {
    //     x = 'z'; // all elements be true. 直接修改原始vec
    // }
    // for(auto x : vec)  cout<<x<<endl;

    // char c = 'a';
    // cout<< c+'A'-'a';
    cout<<f('a')<<endl;
    cout<<f('A')<<endl;

    // int a[] = {1,2,3,4,5,6};
    // cout<< (a+1)[2];


    return 0;
}