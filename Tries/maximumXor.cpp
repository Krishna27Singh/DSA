#include<iostream>
using namespace std;

struct Node {
    Node* links[2];

    bool containsKey(int bit){
        if(links[bit] != NULL) return true;
        else return false;
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i = 31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int x){
        Node* node = root;
        int ans = 0;
        for(int i = 31; i>=0; i--){
            int bit = (x >> i) & 1;
            if(node->containsKey(!bit)){
                ans = ans | (1 << i);
                node = node->get(!bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        for(auto num : nums) trie->insert(num);
        int maxi = 0;
        for(auto x : nums){
            maxi = max(maxi, trie->getMax(x));
        }

        return maxi;
    }
};
