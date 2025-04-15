class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
            auto compare = [](ListNode* a, ListNode* b) {
        return a->val > b->val;
    };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> minHeap(compare);

    // 将所有非空链表的头节点加入小顶堆
    for (ListNode* node : lists) {
        if (node) {
            minHeap.push(node);
        }
    }

    // 创建虚拟头节点，方便处理
    ListNode dummy(0);
    ListNode* tail = &dummy;

    // 当堆不为空时，持续合并
    while (!minHeap.empty()) {
        // 取出堆顶元素（当前最小节点）
        ListNode* smallest = minHeap.top();
        minHeap.pop();
        // 将最小节点连接到结果链表尾部
        tail->next = smallest;
        tail = tail->next;

        // 如果取出节点有下一个节点，将其加入堆中
        if (smallest->next) {
            minHeap.push(smallest->next);
        }
    }

    // 返回合并后链表的头节点
    return dummy.next;
    }
};