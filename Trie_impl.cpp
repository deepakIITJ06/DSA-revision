#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MP make_pair
#define F first
#define S second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define rep(x,y) for(int i=x;i<y;i++)
using ii = pair<int,int>;
int mod = 1e9+7;

struct Node {   
    Node* links[26];
    bool flag;
    Node() {
        for (int i=0;i<26;i++) {
            links[i] = nullptr;
        }
        flag = false;
    }
    bool containsKey(char ch) {
        if(links[ch-'a']==nullptr) {
            return false;
        }
        return true;
    }
    void addInTrie(char ch) {
        links[ch-'a'] = new Node();
    }
    Node* getMeNextPointer(char ch) {
        return links[ch-'a'];
    }
    void makeItEnd() {
        flag = true;
    }
    bool checkEnd() {
        return flag;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                node->addInTrie(word[i]);
            }
            node = node->getMeNextPointer(word[i]);
        }
        node->makeItEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->getMeNextPointer(word[i]);
        }
        if(node->checkEnd()==true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.length();i++) {
            if(!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->getMeNextPointer(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */