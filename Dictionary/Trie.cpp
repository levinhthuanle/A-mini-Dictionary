#include "Trie.h"

// -TrieNode
TrieNode::TrieNode(){
    std::fill(std::begin(children), std::end(children), nullptr); 
}

// -Trie

void Trie::insert(const std::string& word, const std::string& definition){
    TrieNode* node = root;
    for (char c : word) {
        int index = c - ' ';
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
        int index = c - ' ';
        if (node->children[index] == nullptr) {
            return {};
        }
        node = node->children[index];
    }
    return node->definitions;
}

void Trie::clear(TrieNode*& curr)
{
    if (!curr) return; 
    for (int i = 0; i < 96; ++i)
    {
        clear(curr->children[i]); 
    }
    delete(curr); 
    curr = 0; 
}

void Trie::clear()
{
    clear(this->root); 
    return; 
}