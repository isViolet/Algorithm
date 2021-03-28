#### [剑指 Offer 24. 反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)

定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

**示例:**

```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```

**限制：**

```
0 <= 节点个数 <= 5000
```

### 代码

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
    public ListNode reverseList(ListNode head) {
        //定义新的返回链表，置空
        ListNode newHead = null;
        while(head != null){
            //临时节点，用于存放在新链表头
            ListNode n = head;
            //旧链表头指向下一个节点
            head = head.next;
            //新链表头的next指向之前的新链表头
            n.next = newHead;
            //重新设置新链表头
            newHead = n;
        }
        return newHead;
    }
}
```

