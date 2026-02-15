//
// Created by kerem on 2/13/26.
//

#ifndef AUTO_TYPING_SUGGESTION_TRIENODE_H
#define AUTO_TYPING_SUGGESTION_TRIENODE_H
#include <vector>

constexpr int ALPHABET_SIZE = 26;

class TrieNode {
public:
    explicit TrieNode(char data);
    TrieNode();
    ~TrieNode() = default;
    [[nodiscard]] char getData() const;
    void setEndOfWord(bool val);
    [[nodiscard]] bool isEndOfWord() const;
    std::vector<TrieNode*>& getChildren();
    [[nodiscard]] TrieNode* getChild(char c) const;
    [[nodiscard]] TrieNode* getChild(int i) const;
    void addChild(TrieNode* c);
private:
    char data;
    std::vector<TrieNode*> children;
    bool endOfWord;
};

#endif //AUTO_TYPING_SUGGESTION_TRIENODE_H