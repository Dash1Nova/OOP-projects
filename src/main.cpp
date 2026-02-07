#include <iostream>
#include <iomanip>

struct Student {
    std::string name, surname;
    int n, nd, egz, sum;
    double final_mark, avg;
};

int main()
{
    Student s;
    std::cout << "Iveskite studento varda: \n";
    std::cin >> s.name;
    std::cout << "Iveskite studento pavarde: \n";
    std::cin >> s.surname;
    std::cout << "Iveskite namu darbu skaiciu: \n";
    std::cin >> s.n;
    while (s.n <= 0) {
        std::cout << "Klaidinga ivestis. Iveskite teigiama skaiciu.\n";
        std::cin >> s.n;
    }
    s.sum = 0;
    for (int i = 0; i < s.n; i++) {
        std::cout << "Iveskite " << i + 1 << " darbo ivertinima: \n";
        std::cin >> s.nd;
        while (s.nd <= 0 || s.nd > 10) {
        std::cout << "Klaidinga ivestis. Iveskite skaiciu nuo 1 iki 10 imtinai.\n";
        std::cin >> s.nd;
        }
        s.sum += s.nd;
    }
    s.avg = (double)s.sum/s.n;
    std::cout << "Iveskite egzamino ivertinima: \n";
    std::cin >> s.egz;
    while (s.egz <= 0 || s.egz > 10) {
        std::cout << "Klaidinga ivestis. Iveskite skaiciu nuo 1 iki 10 imtinai.\n";
        std::cin >> s.egz;
        }
    s.final_mark = 0.4*s.avg + 0.6*s.egz;
    std::cout << " " << std::endl;
    std::cout << "Vardas\tPavarde\tGalutinis (Vid.)\n";
    std::cout << "----------------------------------------------------\n";
    std::cout << s.name << "\t" << s.surname << "\t" << std::fixed << std::setprecision(2) << s.final_mark << "\n";
    return 0;
}