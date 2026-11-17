# Remove Nth Node From End of List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

 

 **Example 1:** 

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

```

 **Example 2:** 

```
Input: head = [1], n = 1
Output: []

```

 **Example 3:** 

```
Input: head = [1,2], n = 1
Output: [1]

```

 

 **Constraints:** 

- The number of nodes in the list is sz.
- 1 <= sz <= 30
- 0 <= Node.val <= 100
- 1 <= n <= sz

 

 **Follow up:**  Could you do this in one pass?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 15 MB (beats 16.19%)  
**Submitted:** 2026-11-17T16:35:24.420Z  

```cpp

class Solution {
public:
    int size(ListNode*head)
    {
        ListNode* tmp = head;
        int count = 0;
        while(tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int jabe = size(head) - n;
        ListNode* tmp = head ;
        if( size(head) == n)
        {
            head = head->next;
            return head;
        }
        for(int i = 1 ; i < jabe ; i++)
        {
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        
        return head;
    }
    
};
```

---

[View on LeetCode](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)