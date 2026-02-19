#pragma once

#include <string>
#include <vector>
#include "TernarySearchTreeNode.h"

class TernarySearchTree {
public:
    explicit TernarySearchTree();
    ~TernarySearchTree();
    void Insert(const std::string& word);
    [[nodiscard]] bool Search(const std::string& word);
    [[nodiscard]] std::vector<std::string> SearchPrefix(std::string& prefix);
    [[nodiscard]] bool IsEmpty() const { return empty; }
private:
    void SearchPrefixHelper(TSTNode*, std::string&, std::vector<std::string>&);
public:
    TSTNode* root;
    bool empty;
};