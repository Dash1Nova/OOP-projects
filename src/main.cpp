#include "meniu.h"
#include "output.h"
#include "inputValid.h"
#include <vector>
#include <ctime>
#include <list>
#include <deque>
#include <chrono>
#include <iostream>

int main() {
    srand(time(NULL));

    int meniu = inputInt(
        "Koki konteineri naudoti:\n"
        "1 - vector\n"
        "2 - list\n"
        "3 - deque\n", 1, 3);

        
        if (meniu == 1) {
            std::vector<Student> Students;
            while (true) {
            int choice = showMeniu();
                
            auto full1Start = std::chrono::high_resolution_clock::now();

            if (choice == 1) manualInput(Students), handleOutput(Students);
            else if (choice == 2) generateGrades(Students), handleOutput(Students);
            else if (choice == 3) generateNamesGrades(Students), handleOutput(Students);  
            else if (choice == 4) scanFile(Students);
            else if (choice == 5) generateFile();
            else if (choice == 6) sortingStudents(Students);
            else if (choice == 7) break;
            auto full1End = std::chrono::high_resolution_clock::now();
            std::cout << "Visos programos vykdymo laikas (s): " << std::chrono::duration<double>(full1End - full1Start).count() << "\n";
        }
    } else if (meniu == 2) {
        std::list<Student> Students;
        while (true) {
            int choice = showMeniu();
            
            auto full2Start = std::chrono::high_resolution_clock::now();

            if (choice == 1) manualInput(Students), handleOutput(Students);
            else if (choice == 2) generateGrades(Students), handleOutput(Students);
            else if (choice == 3) generateNamesGrades(Students), handleOutput(Students);  
            else if (choice == 4) scanFile(Students);
            else if (choice == 5) generateFile();
            else if (choice == 6) sortingStudents(Students);
            else if (choice == 7) break;

            auto full2End = std::chrono::high_resolution_clock::now();
            std::cout << "Visos programos vykdymo laikas (s): " << std::chrono::duration<double>(full2End - full2Start).count() << "\n";
        }
    } else if (meniu == 3) {
        std::deque<Student> Students;
        while (true) {
            int choice = showMeniu();
            
            auto full3Start = std::chrono::high_resolution_clock::now();

            if (choice == 1) manualInput(Students), handleOutput(Students);
            else if (choice == 2) generateGrades(Students), handleOutput(Students);
            else if (choice == 3) generateNamesGrades(Students), handleOutput(Students);  
            else if (choice == 4) scanFile(Students);
            else if (choice == 5) generateFile();
            else if (choice == 6) sortingStudents(Students);
            else if (choice == 7) break;

            auto full3End = std::chrono::high_resolution_clock::now();
            std::cout << "Visos programos vykdymo laikas (s): " << std::chrono::duration<double>(full3End - full3Start).count() << "\n";
        }
    }
    return 0;
}