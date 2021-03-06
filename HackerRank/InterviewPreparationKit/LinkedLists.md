
## Insert a node at a specific position in a linked list
```cpp
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode *node = new SinglyLinkedListNode(data);
    if(position==0) {
        node->next = llist;
        llist = node;
        return llist;
    }
    SinglyLinkedListNode *pre = llist, *p = llist;
    while(position){
        position--;
        pre = p;
        p=p->next;        
    }
    if(p==nullptr){
        pre->next = node;
    }
    else{
        pre->next= node;
        node->next = p;
        
    }
    return llist;
}
```

```python

def insertNodeAtPosition(llist, data, position):
    position-=1
    p = llist
    while position:
        p = p.next
        position-=1
    
    post = p.next 
    p.next = SinglyLinkedListNode(data)
    p.next.next = post
    return llist
```
## Inserting a Node Into a Sorted Doubly Linked List

```cpp
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode * node = new DoublyLinkedListNode(data);
    DoublyLinkedListNode * p = llist, *pre = llist;
    if(node->data < p->data){
        node->next = p;
        p->prev = node;
        llist = node;
        return llist;
    }
    while(p && p->data < node->data){
        
        pre = p;
        p = p->next;
        
    }
    node->prev = pre;
    pre->next = node;
    node->next = p;
    if(p)  p->prev = node;
    return llist;
    
}
```

```python
def sortedInsert(llist, data):
    # Write your code here
    node = DoublyLinkedListNode(data)
    pre, p = llist, llist
    # insert head
    if(node.data < p.data):
        node.next = llist
        node.prev = None
        llist.prev = node
        return node        
    while(p and p.data < node.data):
        pre = p
        p =p.next
    
    pre.next =node
    node.prev = pre
    node.next = p
    if p is not None:
        p.prev = node
    return llist

```
## Linked Lists: Detect a Cycle

```cpp
bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node *slow = head, *fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast ) return true;
    }
    return false;
        
}
```

```python

def has_cycle(head):
    if head is None or head.next is None:
        return False    
    slow , fast = head, head
    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next
        if(slow is fast):return True
    return False
```

## Find Merge Point of Two Lists
```cpp
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    
    SinglyLinkedListNode *a = head1 , * b = head2;
    while(a != b){
        if(a== nullptr ) a = head2;
        else a=a->next;
        if(b == nullptr) b = head1;
        else b= b->next;
        
        if(a==b) return a->data;
    }
    return -1;
}
```

```python
def findMergeNode(head1, head2):
    a , b = head1, head2    
    while( a !=b):        
        if a == None:
            a = head2
        else :
            a = a.next
        if b == None:
            b = head1
        else:
            b = b.next
        if a==b: return a.data
    return -1
```
## Reverse a doubly linked list

```cpp
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if(!llist || !llist->next) return llist;
    DoublyLinkedListNode *pre = nullptr, * cur = llist, *post = cur->next;
    while(post){
        cur->next = pre;
        if(pre) pre->prev = cur;
        
        pre = cur;
        cur = post;
        post = post->next;      
    }
    cur->next = pre;
    if(pre) pre->prev = cur;
    return cur;  
}
```


```python
def reverse(llist):
    # Write your code here
    if llist is None or llist.next is None:
        return llist
    pre, cur, post = None, llist, llist.next
    while post:
        cur.next = pre
        if pre: pre.prev = cur
        pre = cur
        cur = post
        post = post.next
    cur.next = pre
    if pre: pre.prev = cur
    return cur
    
```