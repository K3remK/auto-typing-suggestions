//
// Created by kerem on 2/13/26.
//

#include "include/TrieNode.h"

#include <strings.h>

TrieNode::TrieNode(const char data) {
    this->data = data;
    children = std::vector<TrieNode*>(ALPHABET_SIZE, nullptr);
    endOfWord = false;
}

TrieNode::TrieNode() {
    this->children = std::vector<TrieNode*>(ALPHABET_SIZE, nullptr);
    this->endOfWord = false;
    this->data = '\0';
}

char TrieNode::getData() const {
    return data;
}

void TrieNode::setEndOfWord(const bool val) {
    this->endOfWord = val;
}

bool TrieNode::isEndOfWord() const {
    return this->endOfWord;
}

std::vector<TrieNode*>& TrieNode::getChildren() {
    return children;
}

TrieNode* TrieNode::getChild(const char c) const {
    if (c < 'a' || c > 'z') return nullptr;
    return children.at(c - 'a');
}

TrieNode * TrieNode::getChild(const int i) const {
    if (i < 0 || i >= ALPHABET_SIZE) return nullptr;
    return children.at(i);
}

void TrieNode::addChild(TrieNode *c) {
    if (const int index = c->getData() - 'a'; children[index] != nullptr) return;
    children[c->getData() - 'a'] = c;
}
