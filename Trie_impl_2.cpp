#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    int endsWith,countPrefix;
    Node() {
        for(int i=0;i<26;i++) {
            links[i] = nullptr;
        }
        endsWith = 0;
        countPrefix = 0;
    }
    bool containsKey(char ch) {
        if(links[ch-'a']==nullptr) return false;
        return true;
    }
    void addInTrie(char ch) {
        links[ch-'a'] = new Node();
    }
    Node* getMeNext(char ch) {
        return links[ch-'a'];
    }
    void increaseEnd() {
        endsWith++;
    }
    void increasePrefix() {
        countPrefix++;
    }
    void deleteEnd() {
        endsWith--;
    }
    void reducePrefix() {
        countPrefix--;
    }
    int getEnd() {
        return endsWith;
    }
    int getPrefix() {
        return countPrefix;
    }
};
class Trie{

    public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root;
        for(int i=0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                node->addInTrie(word[i]);
            }
            node = node->getMeNext(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word) {
        Node* node = root;
        for(int i=0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                return 0;
            }
            node = node->getMeNext(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word) {
        Node* node = root;
        for(int i=0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                return 0;
            }
            node = node->getMeNext(word[i]);
        }
        return node->getPrefix();   
    }

    void erase(string &word) {
        Node* node = root;
        for(int i=0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                return; 
            }
            node = node->getMeNext(word[i]);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};
