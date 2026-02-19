#include "include/TernarySearchTree.h"

TernarySearchTree::TernarySearchTree()
{
    this->root = nullptr;
    empty = true;
}

TernarySearchTree::~TernarySearchTree()
{
    delete root;
}

#include <iostream>
void TernarySearchTree::Insert(const std::string &word)
{
    int idx = 0;
    auto tmp = root;
    auto last = root;
    int last_idx = -1;                   // 0 : left, 1 : equal, 2 : right
    while (tmp != nullptr) {
        // recurse on proper subtree
        if (word[idx] < tmp->GetCharacter()) {
            last = tmp;
            tmp = tmp->GetLeft();
            last_idx = 0;
        } else if (word[idx] > tmp->GetCharacter()) {
            last = tmp;
            tmp = tmp->GetRight();
            last_idx = 2;
        } else {
            idx += 1;
            last = tmp;
            tmp = tmp->GetEqual();
            last_idx = 1;
            if (idx == word.length()) {
                last->SetEndOfWord(true);
                return;
            }
        }

    }
    tmp = new TSTNode(word[idx]);

    if (last_idx == -1) {
        root = tmp;
    } else if (last_idx == 2) {
        last->SetRight(tmp);
    } else if (last_idx == 0) {
        last->SetLeft(tmp);
    } else if (last_idx == 1) {
        last->SetEqual(tmp);
    }
    idx += 1;

    for (idx; idx < word.length(); idx++) {
        tmp->SetEqual(new TSTNode(word[idx]));
        last = tmp;
        tmp = tmp->GetEqual();
    }
    tmp->SetEndOfWord(true);
}

bool TernarySearchTree::Search(const std::string &word)
{
    if (root == nullptr) return false;
    if (word.empty()) return false;
    int idx = 0;
    auto tmp = root;
    while (tmp != nullptr) {
        if (word[idx] < tmp->GetCharacter())
            tmp = tmp->GetLeft();
        else if (word[idx] > tmp->GetCharacter())
            tmp = tmp->GetRight();
        else {
            idx += 1;
            if (idx == word.length())
                return tmp->IsEndOfWord();
            tmp = tmp->GetEqual();
        }
    }
    return false;
}

std::vector<std::string> TernarySearchTree::SearchPrefix(std::string &prefix)
{
    std::vector<std::string> res;
    if (root == nullptr) return res;
    int idx = 0;
    auto tmp = root;
    while (tmp != nullptr) {
        if (prefix[idx] < tmp->GetCharacter())
            tmp = tmp->GetLeft();
        else if (prefix[idx] > tmp->GetCharacter())
            tmp = tmp->GetRight();
        else {
            idx += 1;
            if (idx == prefix.length())
                break;
            tmp = tmp->GetEqual();
        }
    }
    if (tmp == nullptr) return res;
    if (tmp->IsEndOfWord()) res.push_back(prefix);
    SearchPrefixHelper(tmp, prefix, res);
    return res;
}

void TernarySearchTree::SearchPrefixHelper(TSTNode* node, std::string& prefix, std::vector<std::string>& arr) {
    if (node == nullptr) return;
    std::string s = prefix + node->GetCharacter();
    if (node->IsEndOfWord()) arr.push_back(s);


    
    SearchPrefixHelper(node->GetLeft(), prefix, arr);
    SearchPrefixHelper(node->GetEqual(), s, arr);
    SearchPrefixHelper(node->GetRight(), prefix, arr);
}
