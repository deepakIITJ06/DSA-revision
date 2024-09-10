#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
int mod = 1e9+7;

// 🔴🔴🔴🔴🔴🔴🔴 LOGIC 🔴🔴🔴🔴🔴🔴🔴
/**
     *
     * Basically we are using the concept of LRUCache in this LFUCache question but with a twist
     *
     * We're creating separate Lists for each use-frequency of the Nodes,
     * and we're adding the nodes in those Lists following the LRU algorithm
     *
     * Everytime a key is being accessed (get/put), we're fetching the Node corresponding to that key
     * and the List corresponding to that Node, then we're deleting the Node from the LRU position of
     * the List, the Node is residing in and adding that same Node at the front (MRU position) of the List
     * having Nodes with use-frequency 1 greater than the use-frequency of the Node that was recently deleted.
     *
     * (list is mapped against use-frequency of the Nodes, means in a List all the nodes have
     * the same use-frequency and those Nodes are stored following the LRU mechanism)
     *
     */

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
    void addNode(Node *newNode) {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        len++;
    }
    void deleteNode(Node *delNode) {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        len--;
    }
};
class LFUCache {
private:
    unordered_map<int, Node*> addrOfKey;
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
                freqListMap[minFreq]->deleteNode(prevNode);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq]; 
            }
            Node *newNode = new Node(key, value);listFreq->addNode(newNode);
            addrOfKey[key] = newNode;
            freqListMap[minFreq] = listFreq;
        }
    }
};