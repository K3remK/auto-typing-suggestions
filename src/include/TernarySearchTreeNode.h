#pragma once

class TSTNode {
public:
    explicit TSTNode(char character, bool endOfWord = false, TSTNode* left = nullptr, TSTNode* equal = nullptr, TSTNode* right = nullptr)
        : character(character), endOfWord(endOfWord), left(left), equal(equal), right(right) {}
    void SetEndOfWord(bool value) { endOfWord = value; }
    bool IsEndOfWord() const { return endOfWord; }
    [[nodiscard]] char GetCharacter() { return character; }
    void SetCharacter(char value) { character = value; }
    [[nodiscard]] TSTNode* GetLeft() const { return left; }
    [[nodiscard]] TSTNode* GetRight() const { return right; }
    [[nodiscard]] TSTNode* GetEqual() const { return equal; }
    void SetLeft(TSTNode* left) { this->left = left; }
    void SetRight(TSTNode* right) { this->right = right; }
    void SetEqual(TSTNode* equal) { this->equal = equal; }
    //void AddChild(TSTNode* child) {
    //    TSTNode* tmp = nullptr;
    //    if (character < child->character) {
    //        tmp = left;
    //    } else if (character > child->character) {
    //        tmp = right;
    //    } else if (character == child->character) {
    //        tmp = equal;
    //    }
    //    if (tmp == nullptr) {
    //        tmp = child;
    //    } else {
    //        tmp->AddChild(child);
    //    }
    //}
    //TSTNode* GetChild(char value) {
    //    if (left->character == value) return left;
    //    if (right->character == value) return right;
    //    if (equal->character == value) return equal;
    //    return nullptr;
    //}
private:
    char character;
    bool endOfWord;
    TSTNode* left;
    TSTNode* equal;
    TSTNode* right;
};