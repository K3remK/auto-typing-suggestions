//
// Created by kerem on 2/15/26.
//

#ifndef AUTO_TYPING_SUGGESTION_APP_H
#define AUTO_TYPING_SUGGESTION_APP_H

#include <string>
#include "Trie.h"
#include "TernarySearchTree.h"
#include "Util.h"

class App {
public:
    explicit App(const std::string& dictLoc);
    ~App();
    void run();
private:
    [[nodiscard]] std::string getText() const;
private:
    TernarySearchTree* trie;
    bool ready = true;
    std::vector<std::string> typedWords;
    std::string dictLoc;
    int nWords;
};


#endif //AUTO_TYPING_SUGGESTION_APP_H