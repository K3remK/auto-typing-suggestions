#include "src/include/App.h"
#include <fstream>
#include <string>

int main() {
    const auto app = new App("../dictionary.txt");
    app->run();
    delete app;
    

    return 0;
}