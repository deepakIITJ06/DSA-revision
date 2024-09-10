#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node * next;
        Node * prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = NULL;
            prev = NULL;
        }
    };
    unordered_map<int,Node*> mp;
    Node * head = new Node(-1, -1);
    Node * tail = new Node(-1, -1);
    int sz;
    LRUCache(int capacity) {
        sz = capacity;
        head->next = tail;
        tail-> prev = head;
    }

    void insertAtHead(Node* node) {
        Node* cur = head->next;
        node->next = cur;
        node->prev = head;
        head->next = node;
        cur->prev = node;
    }

    void deleteAtTail(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int key) {
        if(mp.count(key)) {
            Node* temp = mp[key];
            int myval = temp->val;
            mp.erase(key);
            deleteAtTail(temp);
            insertAtHead(temp);
            mp[key] = head->next;
            return myval;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            Node* cur = mp[key];
            mp.erase(key);
            deleteAtTail(cur);
        }
        if(mp.size()==sz) {
            mp.erase(tail->prev->key);
            deleteAtTail(tail->prev);
        }
        insertAtHead(new Node(key,value));
        mp[key]=head->next;
    }
};