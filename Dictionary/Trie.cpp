#include "Trie.h"

// -TrieNode
TrieNode::TrieNode(){
    for (int i = 0; i < 26; ++i)
        children[i] = nullptr;
}

// -Trie

void Trie::insert(const std::string& word, const std::string& definition){
    TrieNode* node = root;
    for (char c : word) {
        int index = c - 'a';
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->definitions.push_back(definition);
}

std::vector<std::string> Trie::search(const std::string& word){
    TrieNode* node = root;
    for (char c : word) {
        int index = c - 'a';
        if (node->children[index] == nullptr) {
            return {};
        }
        node = node->children[index];
    }
    return node->definitions;
}