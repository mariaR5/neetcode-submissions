struct ListNode {
    int key;
    int val;
    ListNode* prev;
    ListNode* next;

    ListNode(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
public:
    int capacity, space;
    unordered_map<int, ListNode*> mpp;
    ListNode* head;
    ListNode* tail;


    void insert(ListNode* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
        
    }

    void remove(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;

        ListNode* node = mpp[key];
        remove(node);
        insert(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            ListNode* node = mpp[key];
            node->val = value;

            remove(node);
            insert(node);
            return;
        }
        
        if (mpp.size() == capacity) {
            ListNode* lru = tail->prev;

            remove(lru);
            mpp.erase(lru->key);
            delete lru;
        }

        ListNode* node = new ListNode(key, value);
        insert(node);
        mpp[key] = node;
        
    }
};
