# ⌨️ Auto Typing Suggestion

A C++ terminal-based application that provides real-time typing suggestions using a Trie data structure.

## ℹ️ Overview

### ⚡ What it does
This application acts as an intelligent autocomplete tool in your terminal. As you type, it instantly queries a pre-loaded dictionary to suggest words that complete your current prefix.

### 🛠️ How it does it
*   🌳 **Data Structure:** Utilization of a **Trie (Prefix Tree)** allows for O(L) time complexity for insertions and searches (where L is the length of the word), making suggestion lookups extremely fast even with a large dictionary.
*   🖥️ **Terminal Interaction:** The application bypasses standard buffered input to read keystrokes directly (`getch` implementation via `termios` on Linux/macOS and `conio.h` on Windows).
*   🎨 **Rendering:** It uses ANSI escape codes to handle cursor positioning and text highlighting, creating a dynamic TUI (Text User Interface) experience without heavy GUI libraries.

### 💡 Why it is useful
*   🎓 **Educational Value:** Demonstrates a practical implementation of Trie data structures for autocomplete systems.
*   🐧 **Low-Level & Cross-Platform:** Shows how to handle raw terminal input and portable coding techniques across different operating systems.
*   🧮 **Algorithms:** Efficiently handles prefix-based querying which is the backbone of search engines and typing assistants.

## 🏗️ Build Instructions

This project uses CMake. Ensure you have CMake and a C++ compiler installed.

1.  Create a build directory:
    ```bash
    mkdir build
    ```

2.  Run CMake to configure the project:
    ```bash
    cmake -S . -B build
    ```

3.  Build the executable:
    ```bash
    cmake --build build
    ```

## 🚀 Usage

**⚠️ IMPORTANT: Run in a Native Terminal ⚠️**
Please run the executable from a **native system terminal** (e.g., Terminal, iTerm2, cmd.exe, PowerShell).
**Do NOT** run this inside an IDE's integrated terminal (like CLion, VS Code, or IntelliJ) or an output window. These environments often do not support the raw input modes and ANSI escape sequences required for the interactive UI, leading to erratic behavior.

1.  Make sure `dictionary.txt` is in the working directory (usually handled by running from the project root or copying the file to the build folder, depending on how you launch it. The code expects `dictionary.txt` in the current working directory).

2.  Run the application:
    ```bash
    ./build/auto_typing_suggestion
    ```

### 🎮 Controls
*   ⌨️ **Typing (a-z):** Input characters to filter suggestions.
*   🔄 **TAB:** Switch to **Selection Mode** and cycle through the suggestion list.
*   ↩️ **ENTER:** Confirm the selected suggestion.
*   ␣ **SPACE:** Confirm the current word (if typed) and reset for the next word.
*   🔙 **BACKSPACE:** Delete the last character.
*   ❌ **ESC:** Exit the application.
