//
// Created by YannickWieland on 04.12.2024.
//
#include <iostream>
#include <regex>

int main() {
    std::string input;
    std::cin >> input;
    std::regex mulRegex("((mul\\([0-9]{1,3},[0-9]{1,3}\\)))");
    auto muls_begin =
        std::sregex_iterator(input.begin(), input.end(), mulRegex);
    auto muls_end = std::sregex_iterator();

    for (std::sregex_iterator i = muls_begin; i != muls_end; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();
        std::cout << "  " << match_str << '\n';
        
    }

}