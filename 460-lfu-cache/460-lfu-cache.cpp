// Doubly Linked-List-Node class with prev and next pointers
class Node {
public:
    int key, val, cnt;
    Node *next, *prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        cnt = 1;
    }
};


// Doubly List class with head and tail pointers
class List {
public:
    int len;
    Node *head, *tail;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        len = 0;
    }

    void addInFront(Node *node) {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        len++;
    }

    void removeNode(Node *delNode) {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        len--;
    }
};


// LFU Cache class
class LFUCache {
private:
    unordered_map<int, Node*> addrOfKey;
    unordered_map<int, List*> freqListMap;
    int minFreq, currSize;
    int cacheCapacity;
    
    void updateFreqListMap(Node *node) {
        addrOfKey.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if (node->cnt == minFreq && freqListMap[node->cnt]->len == 0) {
            minFreq++;
        }

        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->addInFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        addrOfKey[node->key] = node;
    }
    
public:
    LFUCache(int capacity) {
        cacheCapacity = capacity;
        minFreq = 0;
        currSize = 0;
    }

    int get(int key) {
        if (addrOfKey.find(key) == addrOfKey.end()) {
            return -1;
        }
        Node *resNode = addrOfKey[key];
        int res = resNode->val;
        updateFreqListMap(resNode);
        return res;
    }

    void put(int key, int value) {
        if (cacheCapacity == 0) {
            return;
        }
        if (addrOfKey.find(key) != addrOfKey.end()) {
            Node *existingNode = addrOfKey[key];
            existingNode->val = value;
            updateFreqListMap(existingNode);
        } else {
            if (currSize == cacheCapacity) {
                List *list = freqListMap[minFreq];
                Node *prevNode = list->tail->prev;
                int keyToBeErased = prevNode->key;
                addrOfKey.erase(keyToBeErased);
                freqListMap[minFreq]->removeNode(prevNode);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }
            Node *newNode = new Node(key, value);
            listFreq->addInFront(newNode);
            addrOfKey[key] = newNode;
            freqListMap[minFreq] = listFreq;
        }
    }
};



/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
