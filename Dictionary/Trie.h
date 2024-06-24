#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class TrieNode {
public:
    TrieNode* children[26];
    std::vector<std::string> definitions;

    TrieNode();
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word, const std::string& definition);

    std::vector<std::string> search(const std::string& word);
};