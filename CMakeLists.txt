cmake_minimum_required(VERSION 3.10)
project(auto_typing_suggestion)

set(CMAKE_CXX_STANDARD 20)

add_executable(auto_typing_suggestion main.cpp
        src/TrieNode.cpp
        src/include/TrieNode.h
        src/Trie.cpp
        src/include/Trie.h
        src/App.cpp
        src/include/App.h
        src/include/Util.h
        src/include/TernarySearchTreeNode.h
        src/include/TernarySearchTree.h
        src/TernarySearchTree.cpp)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_compile_definitions(auto_typing_suggestion PUBLIC "_WIN32")
endif()