class Solution {
public:
    ListNode* checkKGroup(ListNode* start, int k) {
        while (--k != 0 && start != nullptr) {
            start = start->next;
        }
        return start;
    }

    void reverse(ListNode* start, ListNode* end) {
        end = end -> next;
        ListNode* pre = nullptr;
        ListNode* cur = start;
        while (cur != end) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* end = checkKGroup(head, k);
        if (end == nullptr) return head;
        ListNode* tmp1 = end->next;
        ListNode* newHead = end;
        reverse(head, end);
        ListNode* prevEnd = head;
        prevEnd->next = tmp1;

        while (prevEnd->next != nullptr) {
            ListNode* start = prevEnd->next;
            end = checkKGroup(start, k);
            if (end == nullptr) return newHead;
            ListNode* tmp = end->next;
            reverse(start, end);
            prevEnd->next = end;
            prevEnd = start;
            prevEnd->next = tmp;
        }
        return newHead;
    }
};