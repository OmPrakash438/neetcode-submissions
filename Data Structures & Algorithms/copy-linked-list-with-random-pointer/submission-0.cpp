/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copy;

        Node* temp = head;
        while(temp){
            copy[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        Node* dummy = copy[head];
        while(temp){
            Node* curr = copy[temp];
            Node* next = copy[temp->next];
            Node* random = copy[temp->random];

            curr->next = next;
            curr->random = random;

            temp = temp->next;
        }

        return dummy;
    }
};
