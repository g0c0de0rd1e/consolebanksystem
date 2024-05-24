
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#endif

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

int show_menu3();

// Функция для вывода текста определенного цвета
void printColorText(const std::string& text, int colorCode) {
    // Сменим цвет текста
    std::cout << "\033[" << colorCode << "m" << text << "\033[0m";
}


int show_menu(int selected_option){
const int num_options = 14;
const std::string highlight_start = "\033[1;31m";
const std::string highlight_end = "\033[0m";
std::string separator_part1 = 
"////////////////////////////////////////////////////////// ";
    std::string separator_part2 = "𝖉𝖞𝖓𝖆𝖘𝖞 𝖔𝖋 𝖉𝖔𝖔𝖒";
    
    std::string header[] =  {
"        ╭━╮        ╭╮",
"╭━┳━┳┳┳┳┫━╋━┳┳┳┳━┳┳┫┣╮",
"┃━┫╋┃┃┃╭╋━┃┻┫┃┃┃╋┃╭┫━┫",
"╰━┻━┻━┻╯╰━┻━┻━━┻━┻╯╰┻╯"
    };

std::string options[] = {
"Создать список",
"Вывести базу данных на экран",
"Отсортировать данные",
"Удалить данные",
"Вывести людей с наибольшим депозитом",
"Вывести улицы, на которых проживает наибольшее количество 
пользователей",
"Вывести данные о пользователе",
"Изменить запись",
"Создать текстовый файл",
"Создать бинарный файл",
"Прочтение текстового файла",
"Прочтение бинарного файла",
"Открыть GitHub автора",
"Выход"
};

int current_selection = selected_option;
for (;;){
system(CLEAR_SCREEN); 
std::cout << "\033[31m" << separator_part1 << highlight_end << 
separator_part2 << std::endl << std::endl;

for (const auto& line : header)
        printColorText(line+"\n", 37);

for (int i = 1; i <= num_options; ++i){ 
if(i == current_selection){
std::cout << highlight_start << "> " << options[i - 1] << 
highlight_end << std::endl;
} else{
std::cout << " " << options[i - 1] << std::endl;
}
}
std::cout << "\033[31m" << separator_part1 << highlight_end;

int arrow_key = _getch();
if (arrow_key == 0 || arrow_key == 224) {
    arrow_key = _getch();
    if (arrow_key == 72) 
    {
        if (current_selection > 1) {
            current_selection--;
        }
    }
    else if (arrow_key == 80) 
    {
        if (current_selection < num_options) {
            current_selection++;
        }
    }
}
if (arrow_key == 10 || arrow_key == 13){
break;
}
}
return current_selection;
}


int show_menu2(){
system(CLEAR_SCREEN);
const int num_options = 5;

const std::string highlight_start = "\033[1;31m";
const std::string highlight_end = "\033[0m";
std::string separator_part1 = 
"////////////////////////////////////////////////////////// ";
    std::string separator_part2 = "𝖉𝖞𝖓𝖆𝖘𝖞 𝖔𝖋 𝖉𝖔𝖔𝖒";
    
    std::string header[] =  {
"        ╭━╮        ╭╮",
"╭━┳━┳┳┳┳┫━╋━┳┳┳┳━┳┳┫┣╮",
"┃━┫╋┃┃┃╭╋━┃┻┫┃┃┃╋┃╭┫━┫",
"╰━┻━┻━┻╯╰━┻━┻━━┻━┻╯╰┻╯"
    };

std::string options[] = {
"Сохранение в текстовый файл и выход",
        "Сохранение в бинарный файл и выход",
        "Сохранение в текстовый и бинарный файлы и выход",
        "Вернутся в первое меню",
        "Выйти без сохранения"
};
int current_selection = 1;

for(;;){
system(CLEAR_SCREEN);
std::cout << "Выберите операцию:\n";
std::cout << "\033[31m" << separator_part1 << highlight_end << 
separator_part2 << std::endl << std::endl;
for (const auto& line : header)
        printColorText(line+"\n", 37);
for(int i = 1; i <= num_options; ++i){
if(i == current_selection){
std::cout << highlight_start << "> " << options[i - 1] << 
highlight_end << std::endl;
}else{
std::cout << " " << options[i - 1] << std::endl;
}
}
std::cout << "\033[31m" << separator_part1 << highlight_end;

int arrow_key = _getch();
if(arrow_key == 0 || arrow_key == 224){
arrow_key = _getch();
if (arrow_key == 72){
if(current_selection > 1){
current_selection--;
}
}
if (arrow_key == 80){
if (current_selection < num_options){
current_selection++;
}
}
}
if (arrow_key == 10 || arrow_key == 13){
break;
}
}
return current_selection;
}

int show_menu3(){
system(CLEAR_SCREEN);

const std::string highlight_start = "\033[1;31m";
const std::string highlight_end = "\033[0m";
std::string separator_part1 = 
"////////////////////////////////////////////////////////// ";
    std::string separator_part2 = "𝖉𝖞𝖓𝖆𝖘𝖞 𝖔𝖋 𝖉𝖔𝖔𝖒";
    
    std::string header[] =  {
"        ╭━╮        ╭╮",
"╭━┳━┳┳┳┳┫━╋━┳┳┳┳━┳┳┫┣╮",
"┃━┫╋┃┃┃╭╋━┃┻┫┃┃┃╋┃╭┫━┫",
"╰━┻━┻━┻╯╰━┻━┻━━┻━┻╯╰┻╯"
    };

std::cout << "Вы точно хотите выйти (Да/Нет)?\n";

int current_selection = 1;
const int num_options = 2;

for (;;) {

        system(CLEAR_SCREEN);
        std::cout << "\033[31m" << separator_part1 << highlight_end << 
separator_part2 << std::endl << std::endl;
        for (const auto& line : header)
        printColorText(line+"\n", 37);
        std::cout << "Вы точно хотите выйти (Да/Нет)?\n";
        if (current_selection == 1) {
            std::cout << highlight_start << ">Да" << highlight_end << 
std::endl;
            std::cout << " Нет" << std::endl;
        } else {
            std::cout << " Да" << std::endl;
            std::cout << highlight_start << ">Нет" << highlight_end << 
std::endl;
        }
std::cout << "\033[31m" << separator_part1 << highlight_end;

       int arrow_key = _getch();
        if(arrow_key == 0 || arrow_key == 224){
        arrow_key = _getch();
        if (arrow_key == 72){
        if(current_selection > 1){
        current_selection--;
        }
        }
        if (arrow_key == 80){
        if (current_selection < num_options){
        current_selection++;
        }
        }
        }
        if (arrow_key == 10 || arrow_key == 13){
        break;
        }
    }
    return current_selection;
}

int sort_menu(){
system(CLEAR_SCREEN);

const std::string highlight_start = "\033[1;31m";
const std::string highlight_end = "\033[0m";
std::string separator_part1 = 
"////////////////////////////////////////////////////////// ";
    std::string separator_part2 = "𝖉𝖞𝖓𝖆𝖘𝖞 𝖔𝖋 𝖉𝖔𝖔𝖒";
    
    std::string header[] =  {
"        ╭━╮        ╭╮",
"╭━┳━┳┳┳┳┫━╋━┳┳┳┳━┳┳┫┣╮",
"┃━┫╋┃┃┃╭╋━┃┻┫┃┃┃╋┃╭┫━┫",
"╰━┻━┻━┻╯╰━┻━┻━━┻━┻╯╰┻╯"
    };

std::cout << "Для выхода в любой момент можете нажать клавишу esc" << 
std::endl;
    std::cout << "Выберите по какому пункту хотите проводить сортировку" 
<< std::endl;
    
    std::string options[] = {
    "Рассчетный счет",
        "ФИО",
        "Город",
        "Улица",
        "Дом",
        "Дата рождения",
        "Номер квартиры",
        "Сумма вклада",
        "Выйти"
    };
    int num_options = 9;
    
    int current_selection = 1;
    
    for(;;){
    system(CLEAR_SCREEN);
    std::cout << "\033[31m" << separator_part1 << highlight_end << 
separator_part2 << std::endl << std::endl;
    for (const auto& line : header)
        printColorText(line+"\n", 37);
    std::cout << "Выберите операцию:\n";
        for (int i = 1; i <= num_options; ++i) {
            if (i == current_selection) {
                std::cout << highlight_start << "> " << options[i - 1] << 
highlight_end << std::endl;
            } else {
                std::cout << "  " << options[i - 1] << std::endl;
            }
        }
        std::cout << "\033[31m" << separator_part1 << highlight_end;

    int arrow_key = _getch();
    if(arrow_key == 0 || arrow_key == 224){
    arrow_key = _getch();
    if (arrow_key == 72){
    if (current_selection > 1){
    current_selection--;
    }
    }
    if (arrow_key == 80){
    if (current_selection < num_options){
    current_selection++;
    }
    }
    }
    if (arrow_key == 10 || arrow_key == 13){
    break;
    }
    }
    return current_selection;
}

int asc_desc_menu(){
system(CLEAR_SCREEN);

const std::string highlight_start = "\033[1;31m";
const std::string highlight_end = "\033[0m";
std::string separator_part1 = 
"////////////////////////////////////////////////////////// ";
    std::string separator_part2 = "𝖉𝖞𝖓𝖆𝖘𝖞 𝖔𝖋 𝖉𝖔𝖔𝖒";

std::cout << "Для выхода в любой момент можете нажать клавишу esc" << 
std::endl;
    std::cout << "Выберите как вы хотите сделать сортировку" << std::endl;
    
    std::string header[] =  {
"        ╭━╮        ╭╮",
"╭━┳━┳┳┳┳┫━╋━┳┳┳┳━┳┳┫┣╮",
"┃━┫╋┃┃┃╭╋━┃┻┫┃┃┃╋┃╭┫━┫",
"╰━┻━┻━┻╯╰━┻━┻━━┻━┻╯╰┻╯"
    };
    
    std::string options[] = {
    "1. По возрастанию",
        "2. По убыванию"
    };
    
    int num_options = 2;
    
    int current_selection = 1;
    
    for(;;){
    system(CLEAR_SCREEN);
    std::cout << "\033[31m" << separator_part1 << highlight_end << 
separator_part2 << std::endl << std::endl;
    for (const auto& line : header)
        printColorText(line+"\n", 37);
        std::cout << "Выберите операцию:\n";
        for (int i = 1; i <= num_options; ++i) {
            if (i == current_selection) {
                std::cout << highlight_start << "> " << options[i - 1] << 
highlight_end << std::endl;
            } else {
                std::cout << "  " << options[i - 1] << std::endl;
            }
        }
        std::cout << "\033[31m" << separator_part1 << highlight_end;
        
        int arrow_key = _getch();
        if(arrow_key == 0 || arrow_key == 224){
        arrow_key = _getch();
        if (arrow_key == 72){
        if(current_selection > 1){
        current_selection--;
        }
        }
        if (arrow_key == 80){
        if (current_selection < num_options){
        current_selection++;
        }
        }
        }
        if (arrow_key == 10 || arrow_key == 13){
        break;
        }
    }
    return current_selection;
}

int delete_menu(){
system(CLEAR_SCREEN);

const std::string highlight_start = "\033[1;31m";
const std ::string highlight_end = "\033[0m";

std::cout << "Для выхода в любой момент можете нажать клавишу esc" << 
std::endl;
    std::cout << "Выберите по какому пункту хотите удалить список" << 
std::endl;
    std::string separator_part1 = 
"////////////////////////////////////////////////////////// ";
    std::string separator_part2 = "𝖉𝖞𝖓𝖆𝖘𝖞 𝖔𝖋 𝖉𝖔𝖔𝖒";
    
    std::string header[] =  {
"        ╭━╮        ╭╮",
"╭━┳━┳┳┳┳┫━╋━┳┳┳┳━┳┳┫┣╮",
"┃━┫╋┃┃┃╭╋━┃┻┫┃┃┃╋┃╭┫━┫",
"╰━┻━┻━┻╯╰━┻━┻━━┻━┻╯╰┻╯"
    };
    
    std::string options[] = {
    "1. Рассчетный счет",
        "2. ФИО",
        "3. Город",
        "4. Улица",
        "5. Дом",
        "6. Дата рождения",
        "7. Номер квартиры"
};
int num_options = 7;

int current_selection = 1;

for(;;){
system(CLEAR_SCREEN);
std::cout << "\033[31m" << separator_part1 << highlight_end << 
separator_part2 << std::endl << std::endl;
for (const auto& line : header)
        printColorText(line+"\n", 37);
std::cout << "Выберите операцию:\n";
        for (int i = 1; i <= num_options; ++i) {
            if (i == current_selection) {
                std::cout << highlight_start << "> " << options[i - 1] << 
highlight_end << std::endl;
            } else {
                std::cout << "  " << options[i - 1] << std::endl;
            }
        }
        std::cout << "\033[31m" << separator_part1 << highlight_end;
        
        int arrow_key = _getch();
        if(arrow_key == 0 || arrow_key == 224){
        arrow_key = _getch();
        if (arrow_key == 72){
        if (current_selection > 1){
        current_selection--;
        }
        }
        if (arrow_key == 80){
        if (current_selection < num_options){
        current_selection++;
}
        }
        }
        if (arrow_key == 10 || arrow_key == 13){
        break;
        }
}
return current_selection;
}

int ask_delete_menu(){
system(CLEAR_SCREEN);

const std::string highlight_start = "\033[1;31m";
    const std::string highlight_end = "\033[0m";
    std::string separator_part1 = 
"////////////////////////////////////////////////////////// ";
    std::string separator_part2 = "𝖉𝖞𝖓𝖆𝖘𝖞 𝖔𝖋 𝖉𝖔𝖔𝖒";

    std::cout << "Для выхода в любой момент можете нажать клавишу esc" << 
std::endl;
    std::cout << "Вы уверены, что хотите удалить запись?" << std::endl;
    
    std::string header[] =  {
"        ╭━╮        ╭╮",
"╭━┳━┳┳┳┳┫━╋━┳┳┳┳━┳┳┫┣╮",
"┃━┫╋┃┃┃╭╋━┃┻┫┃┃┃╋┃╭┫━┫",
"╰━┻━┻━┻╯╰━┻━┻━━┻━┻╯╰┻╯"
    };

    std::string options[] = {
        "1. Да",
        "2. Нет"
    };

int num_options = 2;

int current_selection = 1;

for(;;){
system(CLEAR_SCREEN);
std::cout << "\033[31m" << separator_part1 << highlight_end << 
separator_part2 << std::endl << std::endl;
for (const auto& line : header)
        printColorText(line+"\n", 37);
std::cout << "Выберите операцию:\n";
        for (int i = 1; i <= num_options; ++i) {
            if (i == current_selection) {
                std::cout << highlight_start << "> " << options[i - 1] << 
highlight_end << std::endl;
            } else {
                std::cout << "  " << options[i - 1] << std::endl;
            }
        }
        std::cout << "\033[31m" << separator_part1 << highlight_end;
        
        int arrow_key = _getch();
        if (arrow_key == 0 || arrow_key == 224){
        arrow_key = _getch();
        if (arrow_key == 72){
        if (current_selection > 1){
        current_selection--;
        }
        }
        if (arrow_key == 80){
        if (current_selection < num_options){
        current_selection++;
        }
        }
        }
        if(arrow_key == 10 || arrow_key == 13){
        break;
        }
}
return current_selection;
}

int show_search_menu(){
    const int num_options = 7;
    const std::string highlight_start = "\033[1;31m";
    const std::string highlight_end = "\033[0m";
    std::string separator_part1 = 
"////////////////////////////////////////////////////////// ";
    std::string separator_part2 = "𝖉𝖞𝖓𝖆𝖘𝖞 𝖔𝖋 𝖉𝖔𝖔𝖒";
    
    std::string header[] =  {
"        ╭━╮        ╭╮",
"╭━┳━┳┳┳┳┫━╋━┳┳┳┳━┳┳┫┣╮",
"┃━┫╋┃┃┃╭╋━┃┻┫┃┃┃╋┃╭┫━┫",
"╰━┻━┻━┻╯╰━┻━┻━━┻━┻╯╰┻╯"
    };
    
    std::string options[] = {
        "Расчетный счет",
        "Имя",
        "Город",
        "Улица",
        "Дом",
        "Дата рождения",
        "Квартира"
    };

    int current_selection = 1;
    for (;;){
        system(CLEAR_SCREEN);
        std::cout << "\033[31m" << separator_part1 << highlight_end << 
separator_part2 << std::endl << std::endl;
        for (const auto& line : header)
        printColorText(line+"\n", 37);
        for (int i = 1; i <= num_options; ++i){ 
            if(i == current_selection){
                std::cout << highlight_start << "> " << options[i - 1] << 
highlight_end << std::endl;
            } else{
                std::cout << " " << options[i - 1] << std::endl;
            }
        }

std::cout << "\033[31m" << separator_part1 << highlight_end;
        int arrow_key = _getch();
        if (arrow_key == 0 || arrow_key == 224) {
            arrow_key = _getch();
            if (arrow_key == 72) 
            {
                if (current_selection > 1) {
                    current_selection--;
                }
            }
            else if (arrow_key == 80) 
            {
                if (current_selection < num_options) {
                    current_selection++;
                }
            }   
        }
        if (arrow_key == 10 || arrow_key == 13){
            break;
        }
    }
    return current_selection;
}

// Функция для отображения консольного меню
void displayMenu()
{
    std::string separator_part1 = 
"////////////////////////////////////////////////////////// ";
    std::string separator_part2 = "𝖉𝖞𝖓𝖆𝖘𝖞 𝖔𝖋 𝖉𝖔𝖔𝖒";
    std::string header[] =  {
"        ╭━╮        ╭╮",
"╭━┳━┳┳┳┳┫━╋━┳┳┳┳━┳┳┫┣╮",
"┃━┫╋┃┃┃╭╋━┃┻┫┃┃┃╋┃╭┫━┫",
"╰━┻━┻━┻╯╰━┻━┻━━┻━┻╯╰┻╯"
    };
    std::string name = "Валерий Шевченко\n\n     ";
    std::string description = "Дан файл с информацией о клиентах банка. 
Структура записей имеет следующий вид: "
                              "ФИО клиента, дата рождения, пол, адрес 
проживания (улица, дом, квартира). "
                              "Выберите 5 улиц, на которых проживают 
больше всего клиентов банка, "
                              "и укажите средний возраст этих клиентов.";
std::string warning = "Осторожно!!!!!!!!!! "
  "В этой программе есть вредоносное ПО =)";
    printColorText(separator_part1, 31);
    printColorText(separator_part2+" \n", 37);

    // Вывод заголовка
    for (const auto& line : header)
        printColorText(line+"\n", 37);
    
    // Вывод имени
    printColorText(name+"\n", 31);

// Вывод предупреждения белым текстом на красном фоне по центру
    std::cout << "\033[1;37;41m " << warning << "\033[m" << std::endl;

    // Вывод описания
    std::vector<std::string> words;
    std::istringstream stream(description);
    std::string word;
    while(stream >> word)
        words.push_back(word);
    
    int lineWidth = 0;
    for (const auto& word : words) {
        if (lineWidth + word.size() > 80) {
            std::cout << std::endl;
            lineWidth = 0;
        }
        std::cout << word << ' ';
        lineWidth += word.size() + 1;
    }
    std::cout << std::endl;
    printColorText(separator_part1, 31);
    std::cin.get();
}

#endif
