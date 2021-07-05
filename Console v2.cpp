#include <iostream> 
#include <map>      //Для словаря
#include <string>   //Для строки
#include <clocale>  //Для русского языка
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian"); //Русский язык в консоли
    SetConsoleCP(1251);           //<-Русский язык в консоли
    SetConsoleOutputCP(1251);     //<-для всего текста
    string forcontinue = "1"; //Переменная, отвечающая за повторы цикла
    int let = 1; //Счетчик количества букв в строке для теста, если let = 0, то просит ввести текст снова
    int a = 1;
    while (a == 1) {
        string forcontinue; //Переменная, отвечающая за повторы цикла
        string text; //Текст для анализа, вводимый с клавиатуры
        int let = 0;
        cout << "Введите текст для анализа:" << endl;
        while (let == 0) {
            //cin.ignore();
            getline(cin, text);
            for (int i = 0; i < text.size(); i++) { // идем по символам
                if (text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z' ||
                    text[i] >= 'А' && text[i] <= 'Я' || text[i] >= 'а' && text[i] <= 'я' ||
                    text[i] == 'Ё' || text[i] == 'ё')
                {
                    let++;
                }
            }
            if (let == 0) {
                cout << "В предложенном вами тексте отсутствуют буквы, "
                    << "должно быть, вы ошиблись" << endl;
                cout << "Попробуйте снова:" << endl;
            }
        }

        map <char, int> letters; //Создание словаря
        for (int i = 0; i < text.size(); i++) //Проход по каждому символу текста
        {
            char current = text[i];
            if (text[i] <= 'Z' && text[i] >= 'A')
            {
                current = (char)((int)text[i] - (int)'A' + (int)'a'); //Приведение всех символов англ алфавита к нижнему регистру
            }
            if (text[i] <= 'Я' && text[i] >= 'А')
            {
                current = (char)((int)text[i] - (int)'А' + (int)'а'); //Приведение всех символов рус алфавита к нижнему регистру
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
        for (const auto& p : letters) { //этот цикл - фишка с++11 range based for loops
            cout << p.first << " = " << p.second << "\n";
        }
        cout << "Если хотите завершить, введите любой символ  "
            << "Если хотите продолжить, введите 1: ";
        getline(cin, forcontinue);
        
        if (forcontinue == "1") a = 1;
        else {
            a = 0;
        }
    }
    cout << "Для завершения работы закройте окно...";
    system("PAUSE");
    return 0;
}