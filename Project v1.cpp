#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    string text;
    string path = "data.txt"; //Произведем чтение текста из файла
    ifstream fin;
    fin.open(path);
    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        cout << "Файл открыт" << endl;
        string str;
        while (!fin.eof()) //Метод eof отлавливает конец файла
        {
            fin >> str;
            text += str;
        }
    }
    fin.close();

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
