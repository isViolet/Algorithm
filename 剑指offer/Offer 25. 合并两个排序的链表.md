#### [剑指 Offer 25. 合并两个排序的链表](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)

输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

**示例1：**

```
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```

**限制：**

```
0 <= 链表长度 <= 1000
```

------

### 代码

#### 超出时间限制

写的复杂了。

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode l3 = null;
        ListNode l33 = null;
        ListNode t = null;
        while(l1 != null || l2 != null){
            if(l1 != null && l2 != null){
                if(l1.val <= l2.val){
                    if(l3 == null){
                        t = l1;
                        t.next = null;
                        l1 = l1.next;
                        l3 = t;
                        l33 = l3;
                    }else{
                        t = l1;
                        l1 = l1.next;
                        t.next = null;
                        l33.next = t;
                        l33 = l33.next;
                    }
                }else{
                    if(l3 == null){
                        t = l2;
                        t.next = null;
                        l2 = l2.next;
                        l3 = t;
                        l33 = l3;
                    }else{
                        t = l2;
                        l2 = l2.next;
                        t.next = null;
                        l33.next = t;
                        l33 = l33.next;
                    }
                }
            }else if(l1 != null){
                l33.next = l1;
            }else{
                l33.next = l2;
            }
        }
        return l3;
    }
}
```

------

#### 简化

```java
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dum = new ListNode(0), cur = dum;
        while(l1 != null && l2 != null) {
            if(l1.val < l2.val) {
                cur.next = l1;
                l1 = l1.next;
            }
            else {
                cur.next = l2;
                l2 = l2.next;
            }
            cur = cur.next;
        }
        cur.next = l1 != null ? l1 : l2;
        return dum.next;
    }
}
```

