#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//КОД ДОРАБАТЫВАЕТСЯ, ПОКА ЧТО ИЩЕТ ТОЛЬКО АНГЛИЙСКИЕ СЛОВА
bool findWordInSentence(const std::string& sentence, const std::string& word) {
    size_t pos = sentence.find(word);
    if (pos != std::string::npos) {
        // Проверяем, чтобы найденное слово было отдельным словом, а не частью другого слова
        if ((pos == 0 || !isalpha(sentence[pos - 1])) &&
            (pos + word.length() == sentence.length() || !isalpha(sentence[pos + word.length()]))) {
            return true;
        }
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string word;

    std::cout << "Введите искомое слово: ";
    std::cin >> word;

    std::ifstream file("1.txt");
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла.\n";
        return 1;
    }

    std::string line;
    std::vector<std::string> sentences;

    while (std::getline(file, line)) {
        sentences.push_back(line);
    }

    bool found = false;

    for (const std::string& sentence : sentences) {
        if (findWordInSentence(sentence, word)) {
            std::cout << "\n################" << std::endl;
            std::cout << sentence << std::endl;
            std::cout << "\n################" << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Искомое слово не найдено." << std::endl;
    }

    file.close();
    system("pause");
    return 0;
}
