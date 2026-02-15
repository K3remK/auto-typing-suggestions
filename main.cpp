#include "src/include/App.h"

int main() {
    const auto app = new App("dictionary.txt");
    app->run();
    delete app;
    return 0;
}