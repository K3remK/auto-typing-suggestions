//
// Created by kerem on 2/13/26.
//

#include "include/Trie.h"

#include <iostream>
#include <ostream>

Trie::Trie() {
    this->root = new TrieNode();
}

void Trie::insert(const std::string &word) {
    TrieNode* tmp = root;
    for (int i = 0; i < word.length(); i++) {
        const char c = word[i];
        tmp->addChild(new TrieNode(c));
        tmp = tmp->getChild(c);
    }
    tmp->setEndOfWord(true);
    empty = false;
}

bool Trie::search(const std::string& word) const {
    const TrieNode* tmp = root;
    for (int i = 0; i < word.length(); i++) {
        const char c = word[i];
        tmp = tmp->getChild(c);
        if (tmp == nullptr) return false;
    }

    return tmp->isEndOfWord();
}

std::vector<std::string> Trie::prefixSearch(const std::string &prefix) const {
    const TrieNode* tmp = root;
    std::vector<std::string> words;
    for (int i = 0; i < prefix.length(); i++) {
        const char c = prefix[i];
        tmp = tmp->getChild(c);
        if (tmp == nullptr) return words;
    }
    prefixSearchHelper(tmp, prefix, words);
    return words;
}

bool Trie::isEmpty() const {
    return empty;
}

void Trie::prefixSearchHelper(const TrieNode* node, const std::string& str, std::vector<std::string>& words) {
    if (node->isEndOfWord()) {
        words.push_back(str);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        const TrieNode* child = node->getChild(i);
        if (child == nullptr) continue;
        prefixSearchHelper(child, str + child->getData(), words);
    }
}
