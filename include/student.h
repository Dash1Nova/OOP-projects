#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    std::string name, surname;
    int egz;
    std::vector<int> nd;
    double finalAvg, finalMed;
};

#endif