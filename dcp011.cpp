// https://www.geeksforgeeks.org/trie-insert-and-search/

// dcp-011
// This problem was asked by Twitter.
// Implement an autocomplete system. That is, given a query string s and a set of all possible query
// strings, return all strings in the set that have s as a prefix.
// For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].
// Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.

#include<iostream>
#include<string>

const int ALPHABET_LENGTH= 26;

struct TrieNode {
    TrieNode *children[ALPHABET_LENGTH];
    bool isEndofWord;
};

TrieNode * newNode(void) {

    TrieNode * node = new TrieNode();
    for (int i = 0; i < ALPHABET_LENGTH; i++) {
        node->children[i] = nullptr;
    }

    return node;
}

// insert if not present, 
// if the key is prefix of trienode , mark the leaf
// as leafnode

void insert(TrieNode *root, std::string keys) {
    TrieNode *pCrawl = root;

    for (int i = 0; i < keys.size(); i++) {
        int index = keys[i]- 'a';
        // if nullptr, create new node for all letters e.g. 'd', 'o', 'g'
        // for each index 3, 14, 6 from root
        if (!pCrawl->children[index])
             pCrawl->children[index] = newNode();

        // jump pCrawl pointer to the last letter i.e. keys[last index]= key[6] for 'dog'
        pCrawl = pCrawl->children[index];
    }
    // for d o g , mark last node 'g' as 'endofWord' as 'dog' is a valid word 
    pCrawl->isEndofWord = true;
}

// return true if key present else false 
bool search(TrieNode *root, std::string keys) {
    TrieNode *pCrawl = root;
    for (int i = 0; i < keys.size();i++) {
        int index = keys[i] - 'a';
        if (!pCrawl->children[index])
            return false;
        else 
            pCrawl = pCrawl->children[index];
    }
    // if the prefix/word was found, we must be at the last letter of the word,
    // just return the isEndOfWord flag
    return pCrawl->isEndofWord ; 
}


int main() {
    std::string keys[] = {"dog", "a", "the", "there", "by", "bye", "an"};

    TrieNode *root = newNode();

    for (auto x: keys)
        insert(root, x);

    std::cout << "checking dog..." << search(root, "dog") << std::endl;
    std::cout << "checking rain..." << search(root, "rain") << std::endl;
    std::cout << "checking there..." << search(root, "there") << std::endl;
    std::cout << "checking the..." << search(root, "the") << std::endl;
}