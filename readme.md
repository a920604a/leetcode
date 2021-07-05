# 資料結構

###### tags: `course notes`



## [contain](https://en.cppreference.com/w/cpp/container)
- Linked list

| algorithm | Average     | Worst case |
| --------- | ----------- | ---------- |
| space     | O(n)        | O(n)       |
| search    | O(n)        | O(n)       |
| insert    | O(1) begin  | O(n)       |
| delete    | O(1)  begin | O(n)       |

如果是doubly linked list ，end的插入、刪除也是O(1)

### [vector 陣列](https://zh.wikipedia.org/wiki/Vector_(STL))
* 存取方法 back front vec.at(i)/vec[i] data
* 修改器 push_back pop_back insert clear erase emplace_back emplace swap
* 容量 size empty resize reserve capacity shrink_to_fit
* 疊代 begin end rbegin rend cbegin cend crbegin crend

### [list](https://zh.wikipedia.org/wiki/List_(STL)) 雙向連結串列
* 存取方法 : back front 
* 修改器 : push_front/emplace_front pop_front push_back/emplace_back pop_back insert/emplace erase clear swap
* 容量 size empty resize 
* 疊代 begin end rbegin rend cbegin cend crbegin crend
* 其他操作 merge sort reverse remove/remove_if splice unique

### forward_list 才是 singly-linked list
* 存取方法 : front 
* 修改器 : push_front/emplace_front pop_front emplace_after insert_after erase_after swap clear
* 容量 resize empty 
* 疊代 begin end rbegin rend 
* 其他操作 merge sort reverse remove/remove_if splice_after unique

### array 
* 存取方法 : back front arr.at(i)/arr[i] data
* 容量 size empty 
* 疊代 begin end rbegin rend cbegin cend crbegin crend
* 其他操作 fill swap

### string 我不在container library 
存取方法 str.at(i)/str[i] front back data c_str substr
容量 size empty resize reserve length capacity 
修改器 push_back pop_back insert clear erase append copy replace swap +
find compare 
疊代 begin end rbegin rend cbegin cend crbegin crend


### Queue  可以array 、 linked list實現

| algorithm | Average | Worst case |
| --------- | ------- | ---------- |
| space     | O(n)    | O(n)       |
| search    | O(n)    | O(n)       |
| insert    | O(1)    | O(1)       |
| delete    | O(1)    | O(1)       |


* 常用方法 push pop front back size empty swap emplace
* back() front() push_back() pop_front()
### priority_queue 用vector 實作
* 常用方法 push pop top size empty swap emplace
* front() push_back() pop_back()

### deque
* 存取方法 deq.at(i)/deq[i] front back
* 容量 size empty resize max_size shrink_to_fit
* 修改器 push_back/emplace_back pop_back push_front/emplace_front pop_front insert/emplace clear erase swap 
* 疊代 begin end rbegin rend cbegin cend crbegin crend

### Stack 

| algorithm | Average | Worst case |
| --------- | ------- | ---------- |
| space     | O(k)    | O(k)       |
| search    | O(n)    | O(n)       |
| insert    | O(1)    | O(1)       |
| delete    | O(1)    | O(1)       |

* 常用方法 push pop top empty size swap emplace

### set   紅黑樹

* 容量 size empty  max_size
* 修改器  insert clear erase swap  emplace emplace_hint merge extract 
* 疊代 begin end rbegin rend cbegin cend crbegin crend
* 查詢 count find equal_range lower_bound upper_bound contain


### unordered_set hash 結構
* 容量 size empty  max_size
* 修改器 insert clear erase swap emplace emplace_hint merge extract 
* 疊代 begin end cbegin cend 
* 查詢 count find equal_range contain

* hash方法 load_factor max_load_factor rehash reserve
* bucket 接口 begin/cbegin end/cend bucket_count max_bucket_count bucket_size bucket 
### map  紅黑樹


* 存取方法 deq.at(i)/deq[i] 
* 容量 size empty 
* 修改器  insert clear erase swap  emplace emplace_hint merge extract  insert_or_assign try_emplace
* 疊代 begin end rbegin rend cbegin cend crbegin crend
* 查詢 count find equal_range lower_bound upper_bound contain


### unordered_map hash 結構
* 存取方法 deq.at(i)/deq[i] 
* 容量 size empty max_size
* 修改器  insert clear erase swap  emplace emplace_hint merge extract  insert_or_assign try_emplace
* 疊代 begin end cbegin cend 
* 查詢 count find equal_range contain

* hash方法 load_factor max_load_factor rehash reserve
* bucket 接口 begin/cbegin end/cend bucket_count max_bucket_count bucket_size bucket 
### summary
![](https://i.imgur.com/WwldmCl.png)

## sort

| case         | Bubble sort | insertion sort | selection sort | merge sort | quick sort |
| ------------ | ----------- | -------------- | -------------- | ---------- | ---------- |
| best case    | $N$         | $N$            | $N^2$          | $NlogN$    | $NlogN$    |
| average case | $N^2$       | $N^2$          | $N^2$          | $NlogN$    | $NlogN$    |
| worst case   | $N^2$       | $N^2$          | $N^2$          | $NlogN$    | $N^2$      |



## search
- linear search
- binary search 
- exponential search
- junpsearch
- Interpolation search
- FibonacciSearch


## time compleity
- 陣列sum : O(n)
- 矩陣相加: O(n^2) 
- 矩陣相乘: O(n^3)
- 階層運算：O(n!)
- 指數時間：O(2^n)
- big O: upper bound
- big omega: lower bound
- big theta: tight bound
$1<logn<n<nlogn<n^2<n^3<2^n<n!$

```java=

int f(int n){
    if(n<1) return 1;
    return f(n-1) + f(n-1);
}
// O(2^N)


(N-1) + (N-2) + (N-3) + ... + 2 + 1
// O(N^2)



int sum(Node node){
    if(node==nullptr) return 0;
    return sum(node.left) + node.val + sum(node.right);
}

// O(N) = O(2^(logN))


int factorial(int n){
    if(n<0) return -1;
    else if(n==0) return 1;
    else return n* factorial(n-1);
}

// O(n)

int fib(int n){
    if(n<=0) return 0;
    else if(n==1) return 1;
    return fib(n-1) +fib(n-2);
}
// O(2^N)
// but called n times is 
// O(2^(N+1)) = O(2^N)

int fib(int n , int []memo){
    if(n<0) return 0;
    else if(n==1) return 1;
    else if(memo[n]>0) return memo[n];
    
    memo[n] = fib(n-1, memo) + fib(n-2,memo);
    return memo[n];
}
// O(n)
```


## must-have knowledge


| Data Structures     | Algorithms           | Concepts             |
| ------------------- | -------------------- | -------------------- |
| Linked Lists        | Breadth-First Search | Bit Manipulation     |
| Tree,Tries & Graphs | Depth-First Search   | Memory(Stack & Heap) |
| Stack & Queues      | Binary Search        | Recursion            |
| Heaps               | Merge Sort           | Dynamic Programming  |
| Vectors/ArrayLists  | Quick Sort           | Big O Time & Space   |
| Hash tables         |                      |                      |
