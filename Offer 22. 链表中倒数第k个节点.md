#### [剑指 Offer 22. 链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)

输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

**示例：**

```
给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.
```

## 代码

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        //定义尾指针
        ListNode tail = head;
        
        //循环，获得第k个节点，为的是与head保持k个距离
        for(int i = 1; i < k; i++){
            if(tail.next != null){
                tail = tail.next;
            }
        }
        
        //循环尾指针，直到尾指针指向最后一个节点，此时头节点就是所求节点
        while(tail.next != null){
            //head和tail共同指向各自的下一节点
            tail = tail.next;
            head = head.next;
        }
        return head;
    }
}
```

