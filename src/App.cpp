//
// Created by kerem on 2/15/26.
//

#include "include/App.h"
#include <fstream>
#include <iostream>

App::App(const std::string &dictLoc) {
    this->dictLoc = dictLoc;
    this->trie = new Trie();
    this->nWords = 10;
    std::fstream file(dictLoc.c_str(), std::ios::in);
    if (!file) {
        std::cerr << " ... " << "Unable to open file " << dictLoc << "\n";
        ready = false;
    }

    for (std::string word; std::getline(file, word);) {
        trie->insert(word);
    }
    file.close();
}

App::~App() {
    delete trie;
}

void App::run() {
    std::cout << "Type something: " << std::flush;

    std::string word;
    std::string prev_word;
    std::vector<std::string> foundWords;
    int selection_index = 0;
    int mode = 0;                       // 0 : typing, 1 : selecting

    while (ready) {
        const int ch = getch_instant();


        // ESC to exit
        if (ch == 27) ready = false;

        // backspace to delete a char
        if (ch == 8 || ch == 127) {
            bool was_empty = false;
            if (word.empty() && !typedWords.empty()) {
                word = typedWords.at(typedWords.size() - 1);
                typedWords.pop_back();
                was_empty = true;
            }
            if (!was_empty) {
                if (!word.empty())
                    word.pop_back();
                if (word.empty()) {
                    foundWords.clear();
                }
            }
        }
        // space to reset
        if (ch == 32) {
            if (!word.empty()) {
                typedWords.push_back(word);
            }
            word = "";
            foundWords.clear();
            mode = 0;
            selection_index = 0;
        }

        // tab to select
        if (ch == 9) {
            if (mode == 1)
                selection_index = (selection_index + 1) % foundWords.size();
            else {
                mode = 1;
            }
        }

        // enter to confirm selection
        if (ch == 10 || ch == 13) {
            word = foundWords[selection_index];
            mode = 0;
            selection_index = 0;
        }

        // only lower case english letters supported currently
        if (ch >= 'a' && ch <= 'z') {
            word.push_back(static_cast<char>(ch));
            mode = 0;
            selection_index = 0;
        }

        std::cout << "\033[H\033[J" << std::flush;
        std::cout << "--- Trie Search ---" << std::endl;

        std::cout << "text: " << getText() << word << "_" << std::endl;

        if (!word.empty() && word != prev_word) {
            foundWords = trie->prefixSearch(word);
        }
        bool printed = false;
        for (int i = 0; i < foundWords.size(); i++) {
            if (i <= selection_index - nWords && !printed) {
                std::cout << " ... " << "(" << selection_index - nWords + 1 << ")\n";
                printed = true;
            }
            if (mode == 1 && selection_index == i) {
                print(foundWords[i] + "\n", WHITE, BLACK);
            } else {
                if (i < selection_index + nWords && i > selection_index - nWords)
                    print(foundWords[i] + "\n", BLACK, WHITE);
            }
            if (i > selection_index + nWords) {
                std::cout << " ... " << "(" << foundWords.size() - (selection_index + nWords) << ")";
                break;
            }
        }
        std::cout << std::endl;
        prev_word = word;
    }
}

std::string App::getText() const {
    std::string text;
    for (const auto& word : typedWords) {
        text.append(word + " ");
    }
    return text;
}
