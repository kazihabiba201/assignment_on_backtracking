//Task1

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

void backtrack(std::string &s, std::vector<std::string> &result, int start) {
  
    if (start == s.size()) {
        result.push_back(s);
        return;
    }

 
    for (int i = start; i < s.size(); i++) {
        std::swap(s[start], s[i]);  
        backtrack(s, result, start + 1); 
        std::swap(s[start], s[i]);  
    }
}

std::vector<std::string> generatePermutations(std::string s) {
    std::vector<std::string> result;
    backtrack(s, result, 0);
    return result;
}

bool hasUniqueCharacters(const std::string &s) {
    std::unordered_set<char> charSet;
    for (char c : s) {
        // If character is already in the set, it is not unique
        if (charSet.find(c) != charSet.end()) {
            return false;
        }
        charSet.insert(c);
    }
    return true;
}

std::string removeQuotes(const std::string &input) {
    std::string result;
    for (char c : input) {
        if (c != '"') {
            result += c; 
        }
    }
    return result;
}

int main() {

    std::string input;
    std::cout << "Enter a string with unique characters (enclosed in double quotes): ";
    std::getline(std::cin, input);

    // Remove quotes from the input
    std::string cleanedInput = removeQuotes(input);

 
    if (!hasUniqueCharacters(cleanedInput)) {
        std::cout << "Error: The string must contain unique characters only." << std::endl;
        return 1; // Exit the program with an error code
    }


    std::vector<std::string> permutations = generatePermutations(cleanedInput);

    // Output the results
    std::cout << "[ ";
    for (size_t i = 0; i < permutations.size(); ++i) {
        std::cout << "\"" << permutations[i] << "\"";
        if (i != permutations.size() - 1) {
            std::cout << ", "; // Add a comma only if it's not the last element
        }
    }
    std::cout << " ]" << std::endl;  // Close the output with a bracket

    return 0;
}

//Time Complexity:O(n ⋅ n!)
//Space Complexity:O(n ⋅ n!)
