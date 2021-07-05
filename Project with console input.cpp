#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <fstream>
#include <string>
#include <clocale>
#include <Windows.h>
#include<ctype.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text;
    cout << "Введите текст для анализа:" <<endl;
    getline(std::cin, text);
    for (int i = 0; i < text.length(); i++) { // идем по символам
        if (text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z' ||
            text[i] >= 'А' && text[i] <= 'Я' || text[i] >= 'а' && text[i] <= 'я' ||
            text[i] == 'Ё' || text[i] == 'ё')
        {
            continue;
        }
        else
        {
            cout << "В предложенном вами тексте отсутствуют буквы, "
                 << "должно быть, вы ошиблись" << endl;
            cout << "Попробуйте снова:" << endl;
            getline(std::cin, text);
        }
    }
    
    map <char, int> letters; //Создание словаря
    for (int i = 0; i < text.size(); i++) //Проход по каждому символу текста
    {
        char current = text[i];
        if (text[i] <= 'Z' && text[i] >= 'A')
        {
            current = (char)((int)text[i] - (int)'A' + (int)'a');
        }
        if (text[i] <= 'Я' && text[i] >= 'А')
        {
            current = (char)((int)text[i] - (int)'А' + (int)'а');
        }
        if ((current <= 'z' && current >= 'a') || (current >= 'а' && current <= 'я')) //Проверка, использовался ли уже такой символ
        {
            if (letters.find(current) == letters.end()) letters[current] = 1; //Если отсутствует
            else letters[current]++;//Если уже есть
        }
    }
    //Сортировка и вывод
    /*vector<pair<int,char>> items;
    sort(items.begin(), items.end());
    return 0;*/
    for (const auto& p : letters) {
        std::cout << p.first << " = " << p.second << "\n";
    }

}