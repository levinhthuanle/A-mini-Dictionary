#include "Trie.h"


TrieNode::TrieNode(){
    std::fill(std::begin(children), std::end(children), nullptr); 
}

TrieNode::~TrieNode() {
    for (int i = 0; i < 26; ++i) {
        if (children[i]) {
            delete children[i];
            children[i] = nullptr;
        }
    }
}

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    deleteNode(root);
}

void Trie::deleteNode(TrieNode* node) {
    if (!node) return;

    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            deleteNode(node->children[i]);
        }
    }
    delete node;
}

void Trie::insert(const std::string& word, const std::string& definition) {
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

std::vector<std::string> Trie::search(const std::string& word) {
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

void Trie::remove(const std::string& word)
{
	std::stack<TrieNode*> search_path({ root });
	TrieNode* curr = root;
	std::string::const_iterator it = word.begin();
	while (it != word.end())
	{

		if (curr->children[std::tolower(*it) - ' '] == 0) return;
		curr = curr->children[std::tolower(*(it++)) - ' '];
		search_path.push(curr);

	}
	if (!curr -> definitions.empty())
	{
        curr->definitions.clear();

		while (!search_path.empty())
		{
			TrieNode*& rm = search_path.top();
			search_path.pop();
			if (it != word.end()) rm->children[*it - ' '] = 0;
            if(it != word.begin()) --it;
            if (std::find_if(std::begin(rm->children), std::end(rm->children),
				[](TrieNode* nextptr) { return (nextptr != 0); }
			) != std::end(rm->children)) return;
			
            clear(rm);
		}
	}
	return;

}

