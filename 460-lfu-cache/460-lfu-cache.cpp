#include <bits/stdc++.h>
using namespace std;

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

    // adds a new node in-between two pre-existing nodes
    void addNode(Node *newNode) {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        len++;
    }

    // breaks the prev and next links of the node to be removed
    void deleteNode(Node *delNode) {
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
    unordered_map<int, Node*> addrOfKey;    // hashmap for storing the address corresponding to a key
    unordered_map<int, List*> freqListMap;
    int minFreq, currSize;
    int cacheCapacity;

    void updateFreqListMap(Node *node) {
        addrOfKey.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);
        if (node->cnt == minFreq && freqListMap[node->cnt]->len == 0) {
            minFreq++;
        }
        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->addNode(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        addrOfKey[node->key] = node;
    }

public:
    LFUCache(int capacity) {
        cacheCapacity = capacity;                           // reset the max capacity of the cache
        minFreq = 0;
        currSize = 0;
    }

    int get(int key) {
        if (addrOfKey.find(key) == addrOfKey.end()) {       // if no such key exists in the record
            return -1;
        }
        Node *resNode = addrOfKey[key];                     // find the address of the key
        int res = resNode->val;                             // get the value of the key
        updateFreqListMap(resNode);
        return res;                                         // returns the value against the given key
    }

    void put(int key, int value) {
        if (cacheCapacity == 0) {
            return;
        }
        if (addrOfKey.find(key) != addrOfKey.end()) {       // if the key is not present in the address-map
            Node *existingNode = addrOfKey[key];            // find the address of the key that already exists
            existingNode->val = value;
            updateFreqListMap(existingNode);
        } else {
            if (currSize == cacheCapacity) {                // if size of the cache reaches its maximum capacity
                List *list = freqListMap[minFreq];
                Node *prevNode = list->tail->prev;          // find the LRU node in the cache
                int keyToBeErased = prevNode->key;          // find the key that is present at the LRU location
                addrOfKey.erase(keyToBeErased);             // delete the address of that key
                freqListMap[minFreq]->deleteNode(prevNode); // delete the LRU node from the LRU location
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }
            Node *newNode = new Node(key, value);           // create a new node with the key and value
            listFreq->addNode(newNode);                     // add the new node at the beginning of the cache bcz now it's MRU
            addrOfKey[key] = newNode;                       // store the new-address in the address-map
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
