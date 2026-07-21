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
    ListNode* dummyStart = new ListNode(0, 0);
    ListNode* dummyEnd = new ListNode(0, 0);


    void insert(ListNode* node) {
        node->next = dummyStart->next;
        dummyStart->next->prev = node;
        dummyStart->next = node;
        node->prev = dummyStart;
        space--;
    }

    void deleteNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = nullptr;
        node->next = nullptr;
        space++;
    }

    LRUCache(int capacity) {
        dummyStart->next = dummyEnd;
        dummyEnd->prev = dummyStart;
        this->capacity = capacity;
        space = capacity;
    }
    
    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            deleteNode(mpp[key]);
            insert(mpp[key]);
            return mpp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            deleteNode(mpp[key]);
            mpp[key]->val = value;
            insert(mpp[key]);
        }
        else {
            if (space == 0) {
                ListNode* lru = dummyEnd->prev;
                deleteNode(lru);
                mpp.erase(lru->key);
                delete lru;
            }
            ListNode* newNode = new ListNode(key, value);
            insert(newNode);
            mpp[key] = newNode;
        }
    }
};
