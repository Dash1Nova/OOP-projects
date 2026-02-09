#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>

struct Student {
    std::string name, surname;
    int n, egz;
    std::vector<int> nd;
};

int main()
{
    Student s;
    int mark;
    std::vector<Student> Students;
    
    int output;
    
    while (true) {
    
    s.nd.clear();

    std::cout << "Iveskite studento varda arba zodi 'STOP', jei norite baigti ivesti: \n";
    std::cin >> s.name;
    if (s.name == "STOP") break;

    std::cout << "Iveskite studento pavarde: \n";
    std::cin >> s.surname;
    std::cout << "Iveskite namu darbu skaiciu: \n";
    std::cin >> s.n;
    while (std::cin.fail() || s.n <= 0) {
        std::cout << "Klaidinga ivestis. Iveskite teigiama skaiciu.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> s.n;
    }

    for (int i = 0; i < s.n; i++) {
        std::cout << "Iveskite " << i + 1 << " darbo ivertinima: \n";
        std::cin >> mark;
        while (std::cin.fail() || mark <= 0 || mark > 10) {
            std::cout << "Klaidinga ivestis. Iveskite skaiciu nuo 1 iki 10 imtinai.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> mark;
        }
        s.nd.push_back(mark);
    }
    
    std::cout << "Iveskite egzamino ivertinima: \n";
    std::cin >> s.egz;
    while (std::cin.fail() || s.egz <= 0 || s.egz > 10) {
        std::cout << "Klaidinga ivestis. Iveskite skaiciu nuo 1 iki 10 imtinai.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> s.egz;
    }
    
    Students.push_back(s);
}

std::cout << "Kaip skaiciuoti galutini pazymi: naudojant vidurki - iveskite 0, naudojant mediana - iveskite 1: \n";
std::cin >> output;
while (std::cin.fail() || (output != 0 && output != 1)) {
    std::cout << "Klaidinga ivestis. Iveskite 0 arba 1:\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> output;
}

std::cout << " " << std::endl;
std::cout << "Vardas\tPavarde\tGalutinis\n";
std::cout << "----------------------------------------------\n";

for (auto& stud : Students) {
    double final_mark;
    if (output == 0) {
                int sum = 0;
                for (int mark : stud.nd) {
                sum += mark;
                }
                double avg = (double)sum/stud.nd.size();
                final_mark = 0.4*avg + 0.6*stud.egz;
            std::cout << stud.name << "\t" << stud.surname << "\t" << std::fixed << std::setprecision(2) << final_mark << "\n";
        } else {
            std::sort(stud.nd.begin(), stud.nd.end());
            double median;
            if (stud.nd.size() % 2 == 1) {
                median = stud.nd.at(stud.nd.size()/2);
            } else {
                median = (stud.nd.at(stud.nd.size()/2 - 1) + stud.nd.at(stud.nd.size()/2))/2.0;
            }
            final_mark = 0.4*median + 0.6*stud.egz;
            std::cout << stud.name << "\t" << stud.surname << "\t" << std::fixed << std::setprecision(2) << final_mark << "\n";
        }
}
    return 0;
}