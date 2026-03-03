#include "calculations.h"
#include <algorithm>

double med(const std::vector<int> &nd, int egz) {
    std::vector<int> temp = nd;
    if (nd.empty()) return 0.6 * egz;
    std::sort(temp.begin(), temp.end());
    double median;
    if (temp.size() % 2 == 1) {
        median = temp.at(temp.size()/2);
    } else {
        median = (temp.at(temp.size()/2 - 1) + temp.at(temp.size()/2))/2.0;
    }
    return 0.4*median + 0.6*egz;
}

double avg(const std::vector<int> &nd, int egz) {
    if (nd.empty()) return 0.6*egz;
    int sum = 0;
        for (int mark : nd) {
            sum += mark;
        }
    return 0.4*(double(sum)/nd.size()) + 0.6*egz;
}

std::string GenerateName(const std::string &vardas, const std::vector<std::string> &saknys) {
    std::string saknis = saknys.at(rand() % saknys.size());

    if (vardas.substr(vardas.size() - 2) == "as")
        return saknis + "enis";

    if (vardas.back() == 'a')
        return saknis + "aite";

    return saknis + "is";
}

bool compareByName(const Student &a, const Student &b) {
    if (a.name.length() != b.name.length()) {
        return a.name.length() < b.name.length();
    }
    return a.name < b.name;
}

bool compareBySurname(const Student &a, const Student &b) {
    if (a.surname.length() != b.surname.length()) {
        return a.surname.length() < b.surname.length();
    }
    return a.surname < b.surname;
}

bool compareByMed(const Student &a, const Student &b) {
    return a.finalMed < b.finalMed;
}

bool compareByAvg(const Student &a, const Student &b) {
    return a.finalAvg < b.finalAvg;
}