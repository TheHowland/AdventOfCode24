//
// Created by YannickWieland on 04.12.2024.
//
#include <iostream>
#include <regex>

int main() {
    std::string input;
    std::string completeText;
    while(std::cin >> input) {
        completeText += input;
    }
    std::regex mulRegex("(mul\\([0-9]{1,3},[0-9]{1,3}\\))");
    auto muls_begin =
        std::sregex_iterator(completeText.begin(), completeText.end(), mulRegex);
    auto muls_end = std::sregex_iterator();

    unsigned int sum = 0;
    for (std::sregex_iterator i = muls_begin; i != muls_end; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();
        std::cout << "  " << match_str << '\n';
        std::string a = match_str.substr(4, match_str.size()-5);
        unsigned long int sepereratorIndex = a.find_first_of(',');
        std::string firstNumberS = a.substr(0, sepereratorIndex);
        std::string secondNumberS = a.substr(sepereratorIndex+1, a.size()-sepereratorIndex);
        int firstNumber = std::stoi(firstNumberS);
        int secondNumber = std::stoi(secondNumberS);
        sum += firstNumber*secondNumber;

    }
    std::cout << sum << '\n';

    std::string completeText2;
    completeText2 = completeText;

    //part two
    sum = 0;

    std::vector<size_t> positionsDont;
    std::vector<size_t> positionsDo;

    std::string find1 = "don't()";
    std::string find2 = "do()";

    size_t pos = completeText2.find(find1, 0);
    while(pos != std::string::npos)
    {
        positionsDont.push_back(pos);
        pos = completeText2.find(find1,pos+1);
    }

    pos = completeText2.find(find2, 0);
    while(pos != std::string::npos)
    {
        positionsDo.push_back(pos);
        pos = completeText2.find(find2,pos+1);
    }

    size_t* startDont = positionsDont.data();
    size_t* dontPtr = positionsDont.data()+(positionsDont.size()-1);

    size_t* startDo = positionsDo.data();
    size_t* doPtr = positionsDo.data()+(positionsDont.size()-1);

    while(dontPtr >= startDont && doPtr >= startDo) {
        if(*dontPtr > *doPtr) {
            completeText2.erase(*dontPtr, *dontPtr-(completeText2.size()-*dontPtr));
            dontPtr--;
        }
        else {
            completeText2.erase(*dontPtr, *doPtr-*dontPtr+4);
            while(*dontPtr > *doPtr) {
                dontPtr--;
            }
            doPtr--;
        }
    }

    muls_begin =
    std::sregex_iterator(completeText2.begin(), completeText2.end(), mulRegex);
    muls_end = std::sregex_iterator();

    for (std::sregex_iterator i = muls_begin; i != muls_end; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();
        std::cout << "  " << match_str << '\n';
        std::string a = match_str.substr(4, match_str.size()-5);
        unsigned long int sepereratorIndex = a.find_first_of(',');
        std::string firstNumberS = a.substr(0, sepereratorIndex);
        std::string secondNumberS = a.substr(sepereratorIndex+1, a.size()-sepereratorIndex);
        int firstNumber = std::stoi(firstNumberS);
        int secondNumber = std::stoi(secondNumberS);
        sum += firstNumber*secondNumber;

    }

    std::cout << sum << '\n';
}