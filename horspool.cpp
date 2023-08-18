#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<char, int> buildBadCharShift(const std::string& pattern) {
    std::unordered_map<char, int> shiftTable;
    int patternLength = pattern.length();

    for (int i = 0; i < patternLength - 1; ++i) {
        shiftTable[pattern[i]] = patternLength - 1 - i;
    }

    return shiftTable;
}

int horspoolStringMatch(const std::string& text, const std::string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    std::unordered_map<char, int> badCharShift = buildBadCharShift(pattern);

    int shift = 0;
    while (shift <= textLength - patternLength) {
        int j = patternLength - 1;
        while (j >= 0 && pattern[j] == text[shift + j]) {
            --j;
        }
        if (j < 0) {
            return shift; 
        }
        shift += badCharShift[text[shift + patternLength - 1]];
    }

    return -1; 
}

int main() {
    std::string text = "ABCHORSPMALLGORI";
    std::string pattern = "HORSE";

    int matchIndex = horspoolStringMatch(text, pattern);

    if (matchIndex != -1) {
        std::cout << "Pattern found at index " << matchIndex << std::endl;
    } else {
        std::cout << "Pattern not found in the text." << std::endl;
    }

    return 0;
}
