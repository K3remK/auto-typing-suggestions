//
// Created by kerem on 2/13/26.
//

#ifndef AUTO_TYPING_SUGGESTION_TRIE_H
#define AUTO_TYPING_SUGGESTION_TRIE_H
#include <string>

#include "TrieNode.h"



class Trie {
public:
    Trie();
    ~Trie() = default;

    void insert(const std::string &word);
    [[nodiscard]] bool search(const std::string& word) const;
    // bool remove(std::string word);
    [[nodiscard]] std::vector<std::string> prefixSearch(const std::string &prefix) const;
    [[nodiscard]] bool isEmpty() const;
private:
    static void prefixSearchHelper(const TrieNode* node, const std::string &str, std::vector<std::string>& words);
private:
    TrieNode *root;
    bool empty;
};


#endif //AUTO_TYPING_SUGGESTION_TRIE_H