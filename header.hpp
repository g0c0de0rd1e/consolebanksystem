#ifndef HEADER_HPP
#define HEADER_HPP
#include <string>

struct reg{ // Данные о пользователях банка
    std::string Checking_Account, Name, City, Street, House, Birthday, 
Flat; //Номер счета, ФИО, город, улица, дом, квартира
    float Deposit_Amount; // Рассчетный счёт
};

struct My_List{ //Структура для работы с двунаправленным списком
    reg data;
    My_List* left;
    My_List* right;
};

const int len_pages = 10;
const int len_items = 12;

unsigned int default_mode, activate_colour, inactive_colour, item, prev;
int key;

My_List *beg, *end, *cur;
reg Regist;
std::string answer;

#endif
