#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <xutility>
#include <stack>
class TrieNode {
public:
    TrieNode* children[96];
    std::vector<std::string> definitions;

    TrieNode();
};

class Trie {
private:
    TrieNode* root = 0;
    void clear(TrieNode*&);
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word, const std::string& definition);

    std::vector<std::string> search(const std::string& word);

    void clear();

    void remove(const std::string& word);

};