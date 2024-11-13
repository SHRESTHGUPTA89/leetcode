class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Interleave the copied nodes with the original nodes
        Node* current = head;
        while (current) {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }

        // Step 2: Set random pointers for the copied nodes
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Step 3: Separate the copied list from the original list
        current = head;
        Node* copiedHead = head->next;
        Node* copy = copiedHead;

        while (current) {
            current->next = current->next->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            current = current->next;
            copy = copy->next;
        }

        return copiedHead;
    }
};
