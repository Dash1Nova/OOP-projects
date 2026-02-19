#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>
#include <ctime>

struct Student {
    std::string name, surname;
    int n, egz;
    int* nd;
};

std::string GenerateName(const std::string &vardas,
                             const std::vector<std::string> &saknys)
{
    std::string saknis = saknys.at(rand() % saknys.size());

    if (vardas.substr(vardas.size() - 2) == "as")
        return saknis + "enis";

    if (vardas.back() == 'a')
        return saknis + "aite";

    return saknis + "is";
}

void addStudent(Student* &Students, int &numb, const Student &newStudent) {
    Student* temp = new Student[numb + 1];
    for (int i = 0; i < numb; i++) {
        temp[i] = Students[i];
    }
    temp[numb] = newStudent;
    delete[] Students;
    Students = temp;
    numb++;
}

void Output(Student* Students, int numb) {
    int output;
    std::cout << "Kaip skaiciuoti galutini pazymi: naudojant vidurki - iveskite 0, naudojant mediana - iveskite 1: \n";
    std::cin >> output;
    while (std::cin.fail() || (output != 0 && output != 1)) {
        std::cout << "Klaidinga ivestis. Iveskite 0 arba 1:\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> output;
    }
    
    std::cout << " \n";
    std::cout << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << "Galutinis\n";
    std::cout << "----------------------------------------------\n";
    
    for (int i = 0; i < numb; i++) {
        double final_mark;
        if (output == 0) {
                    int sum = 0;
                    for (int j = 0; j < Students[i].n; j++) {
                    sum += Students[i].nd[j];
                    }
                    double avg = (double)sum/Students[i].n;
                    final_mark = 0.4*avg + 0.6*Students[i].egz;
                std::cout << std::left << std::setw(15) << Students[i].name << std::setw(15) << Students[i].surname << std::setw(15) << std::fixed << std::setprecision(2) << final_mark << "\n";
            } else {
                std::sort(Students[i].nd, Students[i].nd + Students[i].n);
                
                double median;
                int n = Students[i].n;
                if (n % 2 == 1) {
                    median = Students[i].nd[n/2];
                } else if (n % 2 == 0) {
                    median = (Students[i].nd[n/2 - 1] + Students[i].nd[n/2])/2.0;
                }
            
                final_mark = 0.4*median + 0.6*Students[i].egz;
                std::cout << std::left << std::setw(30) << Students[i].name << std::setw(30) << Students[i].surname << std::setw(30) << std::fixed << std::setprecision(2) << final_mark << "\n";
        }
    }
}

int main() {
    Student s;
    int mark;
    Student* Students = nullptr;
    int numb = 0;
    int choice;
    srand(time(NULL));
    
    while (true) {
        std::cout << "Pasirinkite rezima: \n";
        std::cout << "1 - iveskti viska ranka.\n";
        std::cout << "2 - generuoti tik pazymius.\n";
        std::cout << "3 - generuoti studentu vardus, pavardes ir pazymius.\n";
        std::cout << "4 - baigti darba.\n";
        std::cin >> choice;
        while (std::cin.fail() || choice < 1 || choice > 4) {
            std::cout << "Klaidinga ivestis. Iveskite skaiciu 1-4:\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }
        
        if (choice == 4) break;
        
        if (choice == 1) {
    while (true) {
    s.n = 0;
    s.nd = nullptr;

    std::cout << "Iveskite studento varda arba zodi 'STOP', jei norite baigti ivesti: \n";
    std::cin >> s.name;
    if (s.name == "STOP") break;

    std::cout << "Iveskite studento pavarde: \n";
    std::cin >> s.surname;

    std::cout << "Iveskite studento namu darbo ivertinima arba parasykite '0', jei norite baigti ivesti: \n";
    
    while (true) {
            std::cin >> mark;
            while (std::cin.fail() || mark < 0 || mark > 10) {
                std::cout << "Klaidinga ivestis. Iveskite skaiciu nuo 1 iki 10 imtinai.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> mark;
            }
            if (mark == 0) break;
            int *tempNd = new int[s.n + 1];
            for (int i = 0; i < s.n; i++) {
                tempNd[i] = s.nd[i];
            }
            tempNd[s.n] = mark;
            delete[] s.nd;
            s.nd = tempNd;
            s.n++;
        }
        
        std::cout << "Iveskite egzamino ivertinima: \n";
        std::cin >> s.egz;
        while (std::cin.fail() || s.egz <= 0 || s.egz > 10) {
            std::cout << "Klaidinga ivestis. Iveskite skaiciu nuo 1 iki 10 imtinai.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> s.egz;
    }
    addStudent(Students, numb, s);
}
    Output(Students, numb);
        }

        else if (choice == 2) {
        while (true) {
        s.n = 0;
        s.nd = nullptr;
        int n;
        std::cout << "Iveskite studento varda arba zodi 'STOP', jei norite baigti ivesti: \n";
        std::cin >> s.name;
            if (s.name == "STOP") break;
        std::cout << "Iveskite studento pavarde: \n";
        std::cin >> s.surname;
        std::cout << "Kiek namu darbu generuoti: \n";
        std::cin >> n;
        while (std::cin.fail() || n <= 0 || n > 100) {
            std::cout << "Klaidinga ivestis. Iveskite teigiama skaiciu.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> n;
        }
            s.n = n;
            for (int i = 0; i < n; i++) {
            s.nd[i] = (rand() % 10) + 1;
            }
            s.egz = (rand() % 10) + 1;
            addStudent(Students, numb, s);
        }
            Output(Students, numb);
            break;
        }
        
        else if (choice == 3) {
            s.n = 0;
            int numb;
            std::cout << "Kiek studentu generuoti?\n";
            std::cin >> numb;

    while (std::cin.fail() || numb <= 0) {
        std::cout << "Klaidinga ivestis. Iveskite teigiama skaiciu:\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> numb;
    }
    
    int nd_per_student;
    std::cout << "Kiek namu darbu generuoti: \n";
    for (int i = 0; i < numb; i++)
    {
    std::cin >> nd_per_student;
while (std::cin.fail() || nd_per_student <= 0 || nd_per_student > 100) {
    std::cout << "Klaidinga ivestis. Iveskite teigiama skaiciu nuo 1 iki 100.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> nd_per_student;
}
    }

    std::vector<std::string> Names = {"Jonas", "Domantas", "Martynas", "Edvinas", "Evelina", "Karolina", "Gabija", "Livija"};

    std::vector<std::string> Surnames = {"1Pavard", "2Pavard", "3Pavard", "4Pavard", "5Pavard"};

    s.nd = new int[s.n];
    for (int i = 0; i < numb; i++) {

        Student s;

        s.name = Names.at(rand() % Names.size());
        s.surname = GenerateName(s.name, Surnames);
        s.n = nd_per_student;

        for (int j = 0; j < s.n; j++) {
            s.nd[j] = (rand() % 10) + 1;
        }

        s.egz = (rand() % 10) + 1;

        addStudent(Students, numb, s);
    }
    
    Output(Students, numb);
}               
    }

    return 0;
}