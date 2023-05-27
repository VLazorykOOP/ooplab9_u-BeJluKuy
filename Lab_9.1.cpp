//Завдання 1
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> V = { 1, 0, 2, 0, 3, 0 };

    // Пошук першого нульового елемента
    auto firstZero = std::find(V.begin(), V.end(), 0);

    // Якщо нульового елемента немає або є лише один, завершити програму
    if (firstZero == V.end() || std::find(std::next(firstZero), V.end(), 0) == V.end()) {
        std::cout << "Недостатньо нульових елементів. Вектор не змінено.\n";
        return 0;
    }

    // Пошук другого нульового елемента
    auto secondZero = std::find(std::next(firstZero), V.end(), 0);

    // Видалення другого нульового елемента
    V.erase(secondZero);

    // Вивід вектора після видалення
    for (const auto& element : V) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    return 0;
}

// Завдання 2

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::vector<int> V = { 1, 2, 3, 4, 5, 6 }; // Приклад вектора з парною кількістю елементів

    // Розбиття вектора на дві половини
    std::vector<int> firstHalf(V.begin(), V.begin() + V.size() / 2);
    std::vector<int> secondHalf(V.begin() + V.size() / 2, V.end());

    // Створення множин на основі половин вектора
    std::set<int> firstSet(firstHalf.begin(), firstHalf.end());
    std::set<int> secondSet(secondHalf.begin(), secondHalf.end());

    // Перевірка, чи містить друга множина всі значення першої множини
    bool result = std::includes(firstSet.begin(), firstSet.end(), secondSet.begin(), secondSet.end());

    // Вивід результату
    std::cout << std::boolalpha << result << std::endl;

    return 0;
}

// Завдання 3

#include <iostream>
#include <vector>
#include <algorithm>

struct Client {
    int clientCode;
    int year;
    int month;
    int duration;

    Client(int code, int y, int m, int dur) : clientCode(code), year(y), month(m), duration(dur) {}
};

bool compareByDuration(const Client& c1, const Client& c2) {
    return c1.duration < c2.duration;
}

int main() {
    std::vector<Client> clients = {
        {1, 2022, 5, 3},
        {2, 2021, 12, 2},
        {3, 2023, 1, 1},
        {4, 2023, 3, 1},
        {5, 2022, 9, 2}
    };

    auto minElement = std::min_element(clients.begin(), clients.end(), compareByDuration);

    std::cout << "Мінімальна тривалість занять: " << minElement->duration << std::endl;
    std::cout << "Рік: " << minElement->year << std::endl;
    std::cout << "Номер місяця: " << minElement->month << std::endl;

    return 0;
}

