#include "stringSpliter.h"


void stringSpliter::searchForWord(std::string newCommand) {
    int amountOfWords = wordsCounter(newCommand);
    if (amountOfWords == 0) {
        if (newCommand == "PagedArray[%d]") {

        }
    } else {
        int counter;
        std::string word = "";
        for (auto x: newCommand) {
            if (counter == )
        }
    }
}

int stringSpliter::wordsCounter(std::string newCommand) {
    std::string word = "";
    int counter = 0;
    for (auto x : newCommand) {
        if (x == ' ') {
            counter++;
        }
    }

    return counter;
}