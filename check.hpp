#ifndef CHECK_HPP
#define CHECK_HPP
#ifdef _WIN32
#include <windows.h>

#define CLEAR_SCREEN "cls"
#else
#include <termios.h>
#include <unistd.h>

#define CLEAR_SCREEN "clear"
#endif

#include "header.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <algorithm>
#include <cctype>
#include <codecvt>
#include <locale>
#include <cstdio>
#include <stdlib.h>

bool isNumber(const std::string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

bool isCyrillic(char32_t c) {
    return (c >= 0x0400 && c <= 0x04FF) || (c >= 0x0500 && c <= 0x052F) || 
c == 0x2DE0 || c == 0x2E00 || c == 0xA640 || c == 0xA680; 
}

bool isValidChar(const std::u32string& s, const std::string& 
allowed_specials) {
    std::string spec_str = allowed_specials;
    for (const auto& ch : spec_str) {
        std::u32string spec(1, ch);
        if (s.find(spec) != std::u32string::npos) {
            continue;
        }
    }
    if (!allowed_specials.empty()) spec_str.append(" ");

    return std::any_of(s.begin(), s.end(), [&](char32_t c) { 
        return isCyrillic(c) || spec_str.find(c) != std::string::npos; 
    });
}

bool isAlphaWithSpace(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
    std::u32string u32str = conv.from_bytes(str);

    return !u32str.empty() && isValidChar(u32str, " ");
}

bool isAlphaWithSpaceAndHyphen(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
    std::u32string u32str = conv.from_bytes(str);

    return !u32str.empty() && isValidChar(u32str, " -");
}

bool isAlphaWithSpaceAndDot(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
    std::u32string u32str = conv.from_bytes(str);

    return !u32str.empty() && isValidChar(u32str, " .");
}

bool isAlphaNumericWithHyphen(const std::string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), [](unsigned char 
ch) { return isalnum(ch) || ch == '-'; });
}

bool isValidDate(const std::string& str) {
    if (str.size() != 10 || str[2] != '.' || str[5] != '.') {
        return false;
    }

    int day = stoi(str.substr(0, 2));
    int month = stoi(str.substr(3, 2));
    int year = stoi(str.substr(6, 4));

    if (month < 1 || month > 12 || day < 1) {
        return false;
    }

    int maxDays = 31;

    if (month == 2) {
        maxDays = 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDays = 30;
    }

    return day <= maxDays;
}

bool check_unique(const std::string& newAccount, My_List* head) {
    My_List* current = head;

    while (current != nullptr) {
        if (current->data.Checking_Account == newAccount) {
            // Рассчетный счет уже существует в списке
            return false;
        }
        current = current->right;
    }

    // Рассчетный счет уникален
    return true;
}

#ifdef _WIN32
// Windows
#include <conio.h>

bool checkEscape() {
    if (_kbhit()) {
        return _getch() == 27; // 27 is ASCII for Escape key
    }
    return false;
}

#else 
// Unix/Linux
bool checkEscape() {
    char ch;
    struct termios original, modified;

    tcgetattr(STDIN_FILENO, &original);
    modified = original;

    modified.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &modified);

    // Read character
    ssize_t charsRead = read(STDIN_FILENO, &ch, 1);
    if (charsRead < 0) {
        std::perror("read");
        exit(1);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &original);

    return ch == 27;
}

#endif

bool compare_fields(reg a, reg b, int field_key, bool asc) {
    bool result;
  
    switch (field_key) {
        case 1:
            result = a.Checking_Account < b.Checking_Account;
            break;
        case 2:
            result = a.Name < b.Name;
            break;
        case 3:
            result = a.City < b.City;
            break;
        case 4:
            result = a.Street < b.Street;
            break;
        case 5:
            result = a.House < b.House;
            break;
        case 6:
            result = a.Birthday < b.Birthday;
            break;
        case 7:
            result = a.Flat < b.Flat;
            break;
        case 8:
            result = a.Deposit_Amount < b.Deposit_Amount;
            break;
        default:
            throw "Неизвестное поле";
    }
  
    return asc ? result : !result;
}

int get_field_key(const std::string& field) {
    if (field == "Рассчетный аккаунт") {
        return 1;
    } else if (field == "Имя") {
        return 2;
    } else if (field == "Город") {
        return 3;
    } else if (field == "Улица") {
        return 4;
    } else if (field == "Дом") {
        return 5;
    } else if (field == "Дата рождения") {
        return 6;
    } else if (field == "Квартира") {
        return 7;
    } else if (field == "Сумма вклада") {
        return 8;
    } else {
        throw "Неизвестное поле";
    }
}

bool user_wants_to_exit() {
    std::string input;
    std::cout << "Нажмите Enter для выхода из функции: ";
    std::getline(std::cin, input);
    return input.empty();
}

bool checkInput(std::string& input) {
    if (!input.empty() && input[0] == ' ') {
        return false;
    }
    return true;
}

#endif

