class Node {
public:
    Node* next;
    Node* prev;
    int key;
    int value;
    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    int cap;
    unordered_map<int, Node*> mpp;
    Node *head, *tail;

public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    Node* addNode(int k, int v) {
        Node* newnode = new Node(k, v);
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
        return newnode;
    }

    void deletenode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            int val = node->value;
            deletenode(node);
            mpp.erase(key);
            mpp[key] = addNode(key, val);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            deletenode(mpp[key]);
            mpp.erase(key);
        }
        if (mpp.size() >= cap) {
            Node* temp = tail->prev;
            mpp.erase(temp->key);
            deletenode(temp);
        }
        mpp[key] = addNode(key, value);
    }
};
