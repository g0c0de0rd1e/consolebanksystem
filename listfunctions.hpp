#ifndef LISTFUNCTIONS_HPP
#define LISTFUNCTIONS_HPP

#ifdef _WIN32
#include <windows.h>

#define CLEAR_SCREEN "cls"
#else
#include <termios.h>
#include <unistd.h>

#define CLEAR_SCREEN "clear"
#endif

#include "menu.hpp"
#include "header.hpp"
#include "check.hpp"
#include <fstream>
#include <stack>
#include <conio.h>
#include <codecvt>
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iomanip>


My_List* create_my_list(My_List** head) {
   
    system(CLEAR_SCREEN);

    My_List* tail = nullptr;
    reg Regist;
    bool checkEscape = false;
    std::string answer;
    

    do {
        My_List* currNode = *head;

        while (currNode) {
            tail = currNode;
            currNode = currNode->right;
        }
        const size_t max_Account_Length = 24;
        const size_t max_Name_Length = 24;
        const size_t max_Birthday_Length = 18;
        const size_t max_City_Length = 18;
        const size_t max_Street_Length = 24;
        const size_t max_House_Length = 14;
        const size_t max_Flat_Length = 18;

        while (true) {
            std::cout << "Введите рассчетный счет : ";
            getline(std::cin, Regist.Checking_Account);
             if (Regist.Checking_Account.empty()) { checkEscape = true; 
break; }
            if (Regist.Checking_Account.length() > max_Account_Length) {
                std::cout << "Ошибка: слишком много символов. Максимум 
символов: " << max_Account_Length << std::endl;
            }else if(!isNumber(Regist.Checking_Account)){std::cout << 
"Ошибка: формат ввода только цифры " << std::endl;}
            else if(!check_unique(Regist.Checking_Account, 
*head)){std::cout << "Ошибка: такой рассчетный счет уже существует" << 
std::endl;}
            else{break;}
        }

if (checkEscape) break;  // Добавим проверку выхода после каждого поля

        while(true){
            std::cout << "Введите ФИО : ";
            getline(std::cin, Regist.Name);
            if (Regist.Name.empty()) { checkEscape = true; break; }
            if(Regist.Name.length() > max_Name_Length){
                std::cout << "Ошибка: слишком много символов. Максимум 
символов: " << max_Name_Length << std::endl;
            }else if(!isAlphaWithSpaceAndDot(Regist.Name)){std::cout << 
"Ошибка: неверный формат ввода (Фамилия И.О.)" << std::endl;}
            else if(!checkInput(Regist.Name)){std::cout << "Ошибка: поле 
не может содержать только один пробел" << std::endl;}
            else{break;}
        }
        
        if (checkEscape) break;  // Добавим проверку выхода после каждого 
поля

        while(true){
            std::cout << "Введите дату рождения (ДД.ММ.ГГГГ) : ";
            getline(std::cin, Regist.Birthday);
            if (Regist.Birthday.empty()) { checkEscape = true; break; }
            if(Regist.Birthday.length() > max_Birthday_Length){
                std::cout << "Ошибка: слишком много символов. Максимум 
символов: " << max_Birthday_Length << std::endl;
            }else if(!isValidDate(Regist.Birthday)){std::cout << "Ошибка: 
неверный формат" <<std::endl;}
             else if(!checkInput(Regist.Birthday)){std::cout << "Ошибка: 
поле не может содержать только один пробел" << std::endl;}
            else{break;}
        } 
        
        if (checkEscape) { break; }
        
        while(1){
            std::cout << "Введите город : ";
            getline(std::cin, Regist.City);
            if (Regist.City.empty()) { checkEscape = true; break; }
            if(Regist.City.length() > max_City_Length){
                std::cout << "Ошибка: неверный формат или слишком много 
символов. Максимум символов: " << max_City_Length << std::endl;
            }else if(!isAlphaWithSpace(Regist.City)){std::cout << "Ошибка: 
неверный формат, используйте только буквы и пробел" << std::endl;}
            else if(!checkInput(Regist.City)){std::cout << "Ошибка: поле 
не может содержать только один пробел" << std::endl;}
            else{break;}
        } 

if (checkEscape) { break; }

        while(true){
            std::cout << "Введите улицу : ";
            getline(std::cin, Regist.Street);
            if (Regist.Street.empty()) { checkEscape = true; break; }
            if(Regist.Street.length() > max_Street_Length){
                std::cout << "Ошибка: слишком много символов. Максимум 
символов: " << max_Street_Length << std::endl;
            }else if(!isAlphaWithSpaceAndHyphen(Regist.Street)){std::cout 
<< "Ошибка: неверный формат, используйте только буквы, дефис и пробел" << 
std::endl;}
            else if(!checkInput(Regist.Street)){std::cout << "Ошибка: поле 
не может содержать только один пробел" << std::endl;}
            else{break;}
        }

if (checkEscape) { break; }

        while(true){
            std::cout << "Введите номер дома : ";
            getline(std::cin, Regist.House);
            if (Regist.House.empty()) { checkEscape = true; break; }
            if(Regist.House.length() > max_House_Length){
                std::cout << "Ошибка: слишком много символов. Максимум 
символов: " << max_House_Length << std::endl;
            }else if(!isAlphaNumericWithHyphen(Regist.House)){std::cout << 
"Ошибка: неверный формат, используйте только цифры, буквы и дефис" << 
std::endl;}
            else if(!checkInput(Regist.House)){std::cout << "Ошибка: поле 
не может содержать только один пробел" << std::endl;}
            else{break;}
        } 

if (checkEscape) { break; }

        while(true){
            std::cout << "Введите номер квартиры : ";
            getline(std::cin, Regist.Flat);
            if (Regist.Flat.empty()) { checkEscape = true; break; }
            if(Regist.Flat.length() > max_Flat_Length){
                std::cout << "Ошибка: слишком много символов. Максимум 
символов: " << max_Flat_Length << std::endl;
            }else if(!isNumber(Regist.Flat)){std::cout << "Ошибка: 
неверный формат, разрешены только цифры" << std::endl;}
            else if(!checkInput(Regist.Flat)){std::cout << "Ошибка: поле 
не может содержать только один пробел" << std::endl;}
            else{break;}
        }
        
        if (checkEscape) { break; }
        
        bool incorrectDeposit = false;
        do {
            std::cout << "Введите сумму вклада: ";
            std::string depositInput;
            getline(std::cin, depositInput);
            if (depositInput.empty()) { checkEscape = true; break; }
            incorrectDeposit = false;

            try {
                Regist.Deposit_Amount = std::stod(depositInput);
            } catch (const std::exception&) {
                std::cout << "Ошибка: Некорректный ввод суммы. Пожалуйста, 
введите корректное число." << std::endl;
                incorrectDeposit = true;
                continue;
            }

            if (Regist.Deposit_Amount < 0) {
                std::cout << "Ошибка: Сумма вклада не может быть 
отрицательной." << std::endl;
                incorrectDeposit = true;
            }
        } while (incorrectDeposit);

        My_List* newNode = new My_List;
        newNode->data = Regist;
        newNode->left = nullptr;
        newNode->right = nullptr;
        
        if (checkEscape) { 
            delete newNode;  // освобождаем ноду при выходе 
            break; 
        } else {
            if (head == nullptr) {
                *head = newNode;
                tail = newNode;
            } else {
                tail->right = newNode;
                newNode->left = tail;
                tail = newNode;
            }
        } 
        tail = newNode;
 
        std::cout << "Желаете добавить еще записей? (y/n): ";
        std::cin >> answer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 
'\n');
        system(CLEAR_SCREEN);
    } while (answer == "y" || answer == "yes" ); // Продолжаем, если 
пользователь хочет добавить еще записей

    return *head;
}

int showbase(My_List* head, int ItemsPerPage, int currentPage) {
    system(CLEAR_SCREEN);
    My_List* cur = head;
    int index = 1, pages = 1;

    if (head == nullptr) {
        std::cout << "Список пуст!" << std::endl;
    }

    int TotalItems = 0;
    My_List* countCur = head;
    while (countCur != nullptr) {
        TotalItems++;
        countCur = countCur->right;
    }

    int TotalPages = (TotalItems + ItemsPerPage - 1) / ItemsPerPage;

    if (currentPage < 1) {
        currentPage = 1;
    } else if (currentPage > TotalPages) {
        currentPage = TotalPages;
    }
    
    int itemsToSkip = (currentPage - 1) * ItemsPerPage;
    while (itemsToSkip > 0 && cur != nullptr) {
        cur = cur->right;
        index++;
        itemsToSkip--;
    }

    std::cout << std::left
   << "Номер"      << std::string(6, ' ') << "|"
   << "Рассчетный счет" << std::string(1, ' ') << "|"
   << "ФИО"           << std::string(11, ' ') << "|"
   << "Дата рождения"    << std::string(2, ' ') << "|"
   << "Город"            << std::string(9, ' ') << "|"
   << "Улица проживания" << std::string(1, ' ')<< "|"
   << "Номер дома"       << std::string(5, ' ') << "|"
   << "Номер квартиры "  << std::string(2, ' ')<< "|"
   << "Сумма вклада"
   << std::endl
   << std::string(129, '-')
   << std::endl;

    int itemCount = 0;
    while (cur != nullptr && itemCount < ItemsPerPage) {
    std::cout << std::left
        << index                           << std::string(5 - 
std::to_string(index).length(), ' ') << "|"
        << cur->data.Checking_Account      << std::string(15 - cur-
>data.Checking_Account.length(), ' ') << "|"
        << cur->data.Name                  << std::string(15 - cur-
>data.Name.length(), ' ') << "|"
        << cur->data.Birthday              << std::string(15 - cur-
>data.Birthday.length(), ' ') << "|"
        << cur->data.City                  << std::string(15 - cur-
>data.City.length(), ' ') << "|"
        << cur->data.Street                << std::string(17 - cur-
>data.Street.length(), ' ') << "|"
        << cur->data.House                 << std::string(15 - cur-
>data.House.length(), ' ') << "|"
        << cur->data.Flat                  << std::string(15 - cur-
>data.Flat.length(), ' ') << "|"
        << cur->data.Deposit_Amount
        << std::endl;

    cur = cur->right;
        index++;
        itemCount++;
}
    std::cout << "\nСтраница " << currentPage << " из " << TotalPages << 
std::endl;

    if (currentPage > 1) {
        std::cout << "↑ Предыдущая страница ";
    }
    if (currentPage < TotalPages) {
        std::cout << "Следующая страница ↓";
    }
    std::cout << std::endl;

    int key;
    std::cout << std::endl;

    bool exitLoop = false;
    int requestedPage = currentPage;
    while (!exitLoop) {
        char key = read_key_press();
        switch (key) {
        #ifdef _WIN32
        case 72:
        #else
            case 65: // стрелка влево
        #endif
                if (currentPage > 1) {
                    showbase(head, ItemsPerPage, currentPage - 1);
                }
                requestedPage = currentPage - 1;
                exitLoop = true;
                break;
            #ifdef _WIN32
            case 80:
            #else
            case 66: // стрелка вправо
        #endif
                if (currentPage < TotalPages) {
                    showbase(head, ItemsPerPage, currentPage + 1);
                }   
                requestedPage = currentPage + 1;
                exitLoop = true;
                break;
            #ifdef _WIN32
            case 13:
            #else
            case '\n':  // код клавиши Enter
            case '\r':  // В некоторых случаях код клавиши Enter окажется 
'\r'
            #endif
                exitLoop = true;
                break;
        }
    }
    return requestedPage;
}

void clearList(My_List **head) {
    My_List* tmp;
    while (*head) {
        tmp = (*head)->right;
        delete *head;
        *head = tmp;
    }
}

void editCheckingAccount(reg& Regist){
system(CLEAR_SCREEN);
My_List *head;
const size_t max_Account_Length = 24;
    
     while(true){
        std::cout << "Введите новый расчетный счет: ";
        getline(std::cin, Regist.Checking_Account);
        if (Regist.Checking_Account.empty()) {
            std::cout << "Ошибка: значение не может быть пустым" << 
std::endl;
            continue;
        }
        if(Regist.Checking_Account.length() > max_Account_Length){
            std::cout << "Ошибка: слишком много символов. Максимум 
символов: " << max_Account_Length << std::endl;
        }else if(!isNumber(Regist.Checking_Account) && 
!check_unique(Regist.Checking_Account, head)){
            std::cout << "Ошибка: неверный формат" << std::endl;
        }else{
            break;
        }
    }
}

void editName(reg& Regist){
system(CLEAR_SCREEN);
const size_t max_Name_Length = 24;

while(true){
        std::cout << "Введите новые данные. Заполните ФИО : ";
        getline(std::cin, Regist.Name);
        if (Regist.Name.empty()) {
            std::cout << "Ошибка: значение не может быть пустым" << 
std::endl;
            continue;
        }
        if(Regist.Name.length() > max_Name_Length){
            std::cout << "Ошибка: слишком много символов. Максимум 
символов: " << max_Name_Length << std::endl;
        }else if(!isAlphaWithSpaceAndDot(Regist.Name)){
            std::cout << "Ошибка: неверный формат ввода (Фамилия И.О.)" << 
std::endl;
        }else{break;}
    }
}

void editStreet(reg& Regist){
system(CLEAR_SCREEN);
const size_t max_Street_Length = 24;
My_List *head;

while(true){
std::cout << "Введите новый адрес: ";
getline(std::cin, Regist.Street);
if(Regist.Street.empty()){
std::cout << "Ошибка: значение не может быть пустым" << std::endl;
continue;
}
if(Regist.Street.length() > max_Street_Length){
std::cout << "Ошибка: слишком много символов. Максимум символов: " 
<< max_Street_Length << std::endl;
}else if(!isAlphaWithSpaceAndHyphen(Regist.Street)){
std::cout << "Ошибка: неверный формат" << std::endl;
}else{
break;
}
}
}


void editHouse(reg& Regist){
system(CLEAR_SCREEN);
const size_t max_House_Length = 14;

My_List *head;

while(true){
    std::cout << "Введите новый номер дома: ";
    getline(std::cin, Regist.House);
    if(Regist.Street.empty()){
    std::cout << "Ошибка: значение не может быть пустым" << std::endl;
continue;
}
if(Regist.House.length() > max_House_Length){
std::cout << "Ошибка: слишком много символов. Максимум символов: " 
<< max_House_Length << std::endl;
}else if(!isAlphaNumericWithHyphen(Regist.House)){
std::cout << "Ошибка: неверный формат" << std::endl;
}else{
break;
}
}
}

void editBirthday(reg& Regist){
system(CLEAR_SCREEN);
const size_t max_Birthday_Length = 18;

My_List *head;

while(true){
        std::cout << "Введите новую дату рождения (ДД.ММ.ГГГГ) : ";
        getline(std::cin, Regist.Birthday);
        if (Regist.Birthday.empty()) {
            std::cout << "Ошибка: значение не может быть пустым" << 
std::endl;
            continue;
        }
        if(Regist.Birthday.length() > max_Birthday_Length){
            std::cout << "Ошибка: слишком много символов. Максимум 
символов: " << max_Birthday_Length << std::endl;
        } else if(!isValidDate(Regist.Birthday)){
            std::cout << "Ошибка: неверный формат" << std::endl;
        } else {
            break;
        }
    }
}

void editFlat(reg& Regist){
system(CLEAR_SCREEN);
const size_t max_Flat_Length = 18;

My_List *head;

while(true){
    std::cout << "Введите новый номер квартиры: ";
    getline(std::cin, Regist.Flat);
    if(Regist.Flat.empty()){
    std::cout << "Ошибка: значение не может быть пустым" << std::endl;
continue;
}
if(Regist.Flat.length() > max_Flat_Length){
std::cout << "Ошибка: слишком много символов. Максимум символов: " 
<< max_Flat_Length << std::endl;
}else if(!isNumber(Regist.Flat)){
std::cout << "Ошибка: неверный формат" << std::endl;
}else{
break;
}
}
}

void editCity(reg& Regist){
system(CLEAR_SCREEN);
const size_t max_City_Length = 18;

My_List *head;

while(true){
    std::cout << "Введите новый город: ";
getline(std::cin, Regist.City);
if (Regist.City.empty()){
std::cout << "Ошибка: значение не может быть пустым" << std::endl;
continue;
} 
if(Regist.City.length() > max_City_Length){
std::cout << "Ошибка: слишком много символов. Максимум символов: " 
<< max_City_Length << std::endl;
} else if(!isAlphaWithSpace(Regist.City)){
std::cout << "Ошибка: Неверный формат" << std::endl;
} else {
break;
}
}
}

void editDeposit(reg& Regist){
system(CLEAR_SCREEN);

My_List *head;

bool incorrectDeposit = false;
    do {
        std::cout << "Введите новую сумму вклада : ";
        std::string depositInput;
        getline(std::cin, depositInput);
        if(depositInput.empty()) {
           std::cout << "Ошибка: значение не может быть пустым" << 
std::endl;
           continue;
        }
        incorrectDeposit = false;

        try {
            Regist.Deposit_Amount = std::stod(depositInput);
        } catch (const std::exception&) {
            std::cout << "Ошибка: некорректный ввод. Пожалуйста, введите 
число." << std::endl;
            incorrectDeposit = true;
            continue;
        }

        if(Regist.Deposit_Amount < 0){
            std::cout << "Ошибка: сумма вклада не может быть 
отрицательной." << std::endl;
            incorrectDeposit = true;
        }

    } while (incorrectDeposit);
}

void printRecord(const reg& Regist) {
    std::cout << std::left << std::setw(30) << "Расчетный счет"
              << std::setw(30) << "ФИО"
              << std::setw(20) << "Дата рождения"
              << std::setw(20) << "Город"
              << std::setw(20) << "Улица"
              << std::setw(10) << "Дом"
              << std::setw(10) << "Квартира"
              << std::setw(10) << "Вклад" << std::endl;

    std::cout << std::left << std::setw(30) << Regist.Checking_Account
              << std::setw(30) << Regist.Name
              << std::setw(20) << Regist.Birthday
              << std::setw(20) << Regist.City
              << std::setw(20) << Regist.Street
              << std::setw(10) << Regist.House
              << std::setw(10) << Regist.Flat
              << std::setw(10) << Regist.Deposit_Amount << std::endl;
}

void edit_field(My_List* head){
    system(CLEAR_SCREEN);
    My_List* currNode = head;

    std::string accountNumber;
    
    std::cout << "Введите расчетный счет, который хотите поменять: ";
    getline(std::cin, accountNumber);

    // Находим нужный узел
    while (currNode && currNode->data.Checking_Account != accountNumber) {
        currNode = currNode->right;
    }

    // Если не нашли узел с таким номером счёта
    if(!currNode){
        std::cout << "Ошибка: нет записи с таким номером счёта" << 
std::endl;
        return;
    }

    reg& Regist = currNode->data; // Для удобства, чтобы не писать каждый 
раз currNode->data

    bool isEditing = true;
    while(isEditing){
        int fieldToEdit = sort_menu();
        // Выводим найденную запись
        switch(fieldToEdit){
            case 1:
                editCheckingAccount(Regist);
                break;
            case 2:
                editName(Regist);
                break;
            case 3:
                editCity(Regist);
                break;
            case 4:
            editStreet(Regist);
            break;
            case 5:
            editHouse(Regist);
            break;
            case 6:
            editBirthday(Regist);
            break;
            case 7:
            editFlat(Regist);
            break;
            case 8:
            editDeposit(Regist);
            break;
            case 9:
            isEditing = false;
            break;
            default:
                isEditing = false;
                break;
        }
    }
}


void save_to_text_file(My_List *head) {
    system(CLEAR_SCREEN);

    std::cout << "Напишите имя файла : ";

    std::string filename; std::cin >> filename;

if(filename == "exit"){
return;
}

    std::ofstream outFile(filename + ".txt");
    if (!outFile) {
        std::cerr << "Не удалось открыть файл для записи: " << filename << 
std::endl;
        return;
    }

    My_List *currentNode = head;
    while (currentNode) {
        reg item = currentNode->data;
        outFile << item.Checking_Account << ","
                << item.Name << ","
                << item.Birthday << ","
                << item.City << ","
                << item.Street << ","
                << item.House << ","
                << item.Flat << ","
                << item.Deposit_Amount << std::endl;
        currentNode = currentNode->right;
    }
    outFile.close();
}

void save_to_binary_file(My_List *head) {
    system(CLEAR_SCREEN);

    std::cout << "Enter the name of the file (or exit to leave): ";

    std::string filename; std::cin >> filename;
    
    // user wants to cancel the action
    if(filename == "exit"){ return; }

    std::ofstream outFile(filename + ".dat", std::ios::binary);
    if (!outFile) {
        std::cerr << "Couldn't open file for writing: " << filename << 
std::endl;
        return;
    }

    My_List *currentNode = head;
    
    while (currentNode) {
        reg item = currentNode->data;
        // for each string field in reg
        for (const auto& str_member : { item.Checking_Account, item.Name, 
item.City, item.Street, item.House, item.Birthday, item.Flat }) {
            // saving the length of the string
            int len = str_member.size();
            outFile.write(reinterpret_cast<const char*>(&len), 
sizeof(int));
            // saving the string char by char
            outFile.write(str_member.c_str(), len);
        }
        // save the Deposit_Amount
        outFile.write(reinterpret_cast<const char 
*>(&item.Deposit_Amount), sizeof(float));
        
        currentNode = currentNode->right;
    }
    outFile.close();
}

void clear_data(My_List *node){
if (node != nullptr) {
        clear_data(node->left);
        clear_data(node->right);
        delete node;
        node = nullptr;
    }
}

void delete_list(My_List* node) {
system(CLEAR_SCREEN);
    if (node != nullptr) {
        delete_list(node->left);
        delete_list(node->right);
        delete node;
        node = nullptr;
        std::cout << "Записи удалены";
    }
    else{
    std::cout << "Список пуст!";
}

    std::cout << "\nНажмите Enter для возврата в главное меню...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.get();
}

void read_from_text_file(My_List **head) {
    system(CLEAR_SCREEN);

    clearList(head);

    std::string filename;

    std::cout << "Напишите имя файла: ";

    std::cin >> filename;

    std::ifstream inFile(filename + ".txt");
    if (!inFile) {
        std::cerr << "Не удалось открыть файл для чтения: " << filename << 
std::endl;
        return;
    }

    reg item;
    My_List *currentNode = nullptr;
    std::string house_str, flat_str, deposit_amount_str;
    int localCount = 0;
    while (std::getline(inFile, item.Checking_Account, ',')
            && std::getline(inFile, item.Name, ',')
            && std::getline(inFile, item.Birthday, ',')
            && std::getline(inFile, item.City, ',')
            && std::getline(inFile, item.Street, ',')
            && std::getline(inFile, house_str, ',')
            && std::getline(inFile, flat_str, ',')
            && std::getline(inFile, deposit_amount_str)) {

        item.House = std::move(house_str);
        item.Flat = std::move(flat_str);
        item.Deposit_Amount = std::stof(deposit_amount_str);

        My_List *newNode = new My_List{item, nullptr};
        if (*head == nullptr) {
            *head = newNode;
        } else {
            currentNode->right = newNode;
        }

        currentNode = newNode;
        ++localCount;

       if (localCount > 10) {
   int userChoice = ask_delete_menu();
    if (userChoice == 2) {
        break;
    } 
}
    }
    inFile.close();
}

void read_from_binary_file(My_List **head) {
system(CLEAR_SCREEN);

clearList(head);

std::string filename;

std::cout << "Напишите имя файла: ";
std::cin >> filename;

std::ifstream inFile(filename + ".dat", std::ios::binary);
if (!inFile) {
    std::cerr << "Не удалось открыть файл для чтения: " << filename << 
std::endl;
    return;
}

My_List *prevNode = nullptr;

int count = 0; // счётчик записей

while (true) {
    int len;
    reg item;
    // для каждого поля string в reg

    for (auto& str_member : { &item.Checking_Account, &item.Name, 
&item.City, &item.Street, &item.House, &item.Birthday, &item.Flat }) {
        if (!inFile.read(reinterpret_cast<char*>(&len), sizeof(int))) { 
break; } // чтение длины строки
        str_member->resize(len);
        if (!inFile.read(&(*str_member)[0], len)) { break; } // чтение 
строки
    }

    if (!inFile.read(reinterpret_cast<char *>(&item.Deposit_Amount), 
sizeof(float))) { break; } // чтение Deposit_Amount

    // Если чтение было неполным, выходим из цикла
    if (inFile.eof()) { break; }

    // Добавление элемента в список
    My_List *newNode = new My_List{item, nullptr, nullptr};
    if (*head == nullptr) {
        *head = newNode;
    } else {
        prevNode->right = newNode;
        newNode->left = prevNode;
    }

    prevNode = newNode;
    count++;
    if (count > 10) {
   int userChoice = ask_delete_menu();
    if (userChoice == 2) {
        break;
    } 
}
}
inFile.close();
}

void swap_data(reg& a, reg& b){
    reg tmp = a;
    a = b;
    b = tmp;
}
    
void sort(My_List* head) {
    system(CLEAR_SCREEN);

    if (head == nullptr) {
        std::cout << "Список пуст. Нажмите Enter для выхода из функции." 
<< std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 
'\n');
        std::cin.get();
        return;
    }

    int field_key = sort_menu();
    int order = asc_desc_menu();

    bool asc = (order == 1); // По возрастанию, если order равен 1

    system(CLEAR_SCREEN);
    My_List* current = head;
    while (current != nullptr) {
        My_List* min = current;
        My_List* search = current->right;
        while (search != nullptr) {
            if (compare_fields(search->data, min->data, field_key, asc)) {
                min = search;
            }
            search = search->right;
        }
        if (min != current) {
            swap_data(current->data, min->data);
            std::cout << "Записи успешно отсортированы по полю с индексом 
" << field_key << " в порядке " << (asc ? "по возрастанию" : "по убыванию") << 
std::endl;
        }
        current = current->right;
    }
    std::cout << "Нажмите Enter для выхода из функции." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); // Ждем нажатия Enter
}

void delete_node(My_List** head_ref) {
    system(CLEAR_SCREEN);

    if (*head_ref == nullptr) { // Проверяем пустой ли список
        std::cout << "Список пуст. Нажмите Enter для выхода из функции." 
<< std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 
'\n');
        std::cin.get();
        return;
    }

    int filter_criteria = delete_menu();

    std::string field_value;
    system(CLEAR_SCREEN);
    std::cout << "Введите значение поля: ";
    std::getline(std::cin, field_value);

    // Создаем указатель на первый узел списка
    My_List* curr = *head_ref;
    // Создаем указатель на предыдущий узел (для возможности перекрепления 
указателей)
    My_List* prev = NULL;

    bool is_found = false;
    while (curr != NULL) {
        bool is_match = (field_value.compare(filter_criteria == 1 ? curr-
>data.Checking_Account :
                                filter_criteria == 2 ? curr->data.Name :
                                filter_criteria == 3 ? curr->data.City :
                                filter_criteria == 4 ? curr->data.Street :
                                filter_criteria == 5 ? curr->data.House :
                                filter_criteria == 6 ? curr->data.Birthday 
: curr->data.Flat) == 0);

        if (is_match) {
            is_found = true;
            if (prev != NULL) {
                prev->right = curr->right;
            } else {
                *head_ref = curr->right;
            }

            My_List* to_free = curr;
            curr = curr->right;
            delete to_free;
        } else {
            prev = curr;
            curr = curr->right;
        }
    }

    if (is_found) {
        std::cout << "Все записи успешно удалены" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 
'\n');
        std::cin.get();
    } else {
        std::cout << "Записи с таким значением поля не найдены" << 
std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 
'\n');
        std::cin.get();
    }
}

void findTop5LargestDepositors(My_List* head) {
    system(CLEAR_SCREEN);

    if (head == nullptr) {
        std::cout << "Список пуст." << std::endl;
        std::cout << "Для выхода нажмите Enter." << std::endl;
        int key;
        do {
            key = std::cin.get();
        } while (key != '\n'); // Ожидание нажатия Enter
        return;
    }

    // Инициализируем массивы для хранения имен и сумм вкладов
    std::string topNames[5];
    float topDeposits[5] = {0.0};

    My_List* currentNode = head;
    int count = 0;

    while (currentNode) {
        float deposit = currentNode->data.Deposit_Amount;

        // Проверяем, может ли текущий вклад войти в топ-5
        for (int i = 0; i < 5; ++i) {
            if (deposit > topDeposits[i]) {
                // Сдвигаем элементы в массиве, чтобы вставить текущую 
сумму вклада
                for (int j = 4; j > i; --j) {
                    topDeposits[j] = topDeposits[j - 1];
                    topNames[j] = topNames[j - 1];
                }
                // Вставляем текущий вклад и имя пользователя в топ-5
                topDeposits[i] = deposit;
                topNames[i] = currentNode->data.Name;
                break; // Выходим из цикла, так как текущий вклад уже 
обработан
            }
        }

        currentNode = currentNode->right;
        ++count;
    }

    if (count < 5) {
        std::cout << "В списке всего " << count << " элемент(а)." << 
std::endl;
        std::cout << "Топ-" << count <<" пользователей с самыми большими 
суммами вкладов:" << std::endl;
    } else {
        std::cout << "Топ-5 пользователей с самыми большими суммами 
вкладов:" << std::endl;
    }

    for (int i = 0; i < count && i < 5; ++i) {
        std::cout << "   Имя: " << topNames[i] << ", Сумма вклада: " << 
topDeposits[i] << std::endl;
    }

    int key;
    do {
        key = std::cin.get();
        if (key == 27) { // 27 - код клавиши Escape
            std::cout << "Выход без сохранения изменений" << std::endl;
            return;
        }
    } while (key != '\n'); // 10 - код клавиши Enter (на самом деле, это 
'\n' - символ новой строки)
}

void printClientInfo(My_List* head) {
   system(CLEAR_SCREEN);

   if (head == nullptr) {
      std::cout << "Список пуст." << std::endl;
      std::cout << "Для выхода нажмите Enter." << std::endl;
      int key;
      do {
          key = std::cin.get();
      } while (key != '\n'); // Ожидание нажатия Enter
      return;
   }

   int choice = show_search_menu();

   std::string searchValue;
   std::cout << "Введите значение для поиска: ";
   std::cin.ignore(); // Очистка буфера ввода перед считыванием строки
   std::getline(std::cin, searchValue);

   bool found = false;
   const My_List* currentNode = head;

   // Выводим заголовок таблицы
   std::cout << "Результаты поиска:" << std::endl;
   std::cout << 
"_______________________________________________________________________________
________________________________" << std::endl;
   std::cout << "Расчеиный счет | Имя          | Город          | Улица        
| Дом   | Дата рождения   | Квартира   | Вклад   " << std::endl;
   std::cout << 
"_______________________________________________________________________________
________________________________" << std::endl;

   while (currentNode) {
      const reg& client = currentNode->data;
      bool match = false;

      switch (choice) {
          case 1:
              match = (client.Checking_Account == searchValue);
              break;
          case 2:
              match = (client.Name == searchValue);
              break;
          case 3:
              match = (client.City == searchValue);
              break;
          case 4:
              match = (client.Street == searchValue);
              break;
          case 5:
              match = (client.House == searchValue);
              break;
          case 6:
              match = (client.Birthday == searchValue);
              break;
          case 7:
              match = (client.Flat == searchValue);
              break;
          default:
              std::cout << "Некорректный выбор поля." << std::endl;
              return;
      }

      if (match) {
          found = true;
          std::cout << client.Checking_Account << " | " << client.Name << 
" | " << client.City << " | " << client.Street << " | " << client.House << " | " 
<< client.Birthday << " | " << client.Flat << " | " << client.Deposit_Amount << 
std::endl;
      }

      currentNode = currentNode->right;
   }

   if (!found) {
      std::cout << "Клиентов с указанными данными не найдено." << 
std::endl;
   }
   int key;
   do {
      key = std::cin.get();
      if (key == 27) { // 27 - код клавиши Escape
          std::cout << "Выход без сохранения изменений" << std::endl;
          return;
      }
   } while (key != '\n'); // 10 - код клавиши Enter (на самом деле, это 
'\n' - символ новой строки)
}

#define MAX_STREETS 10000

void findMax(My_List* head) {
    system(CLEAR_SCREEN);
    std::string streets[MAX_STREETS];
    int count[MAX_STREETS] = {0};
    int total_streets = 0;
    My_List* node = head;

    // Построение списка и подсчета улиц
    while (node) {
        bool found = false;
        for (int i = 0; i < total_streets; ++i) {
            if (streets[i] == node->data.Street) {
                count[i]++;
                found = true;
            }
        }

        if (!found && total_streets < MAX_STREETS) {
            streets[total_streets] = node->data.Street;
            count[total_streets]++;
            total_streets++;
        }

        node = node->right;
    }

    // Выводим 5 наиболее часто встречающихся улиц
for (int x = 0; x < 5 && x < total_streets; ++x) {
        int maxCountIndex = 0;
            for(int i=1; i < total_streets; i++)
            {
                if (count[i] > count[maxCountIndex])
                    maxCountIndex = i;
            }
        std::cout << "Улица: " << streets[maxCountIndex] << ", Клиенты: " 
<< count[maxCountIndex] << std::endl;
            count[maxCountIndex] = -1;  // так, мы исключаем улицу, 
которую уже обработали
}

    int key;
    do {
        key = std::cin.get();
        if (key == 27) { // 27 - код клавиши Escape
            return;
        }
    } while (key != '\n'); // 10 - код клавиши Enter (на самом деле, это 
'\n' - символ новой строки)
}

#endif
