#ifndef MENIU_H
#define MENIU_H

#include <vector>
#include <list>
#include <deque>
#include "student.h"

int showMeniu();
template <typename Container>
void manualInput(Container& Students);
template <typename Container>
void generateGrades(Container& Students);
template <typename Container>
void generateNamesGrades(Container& Students);
template <typename Container>
void scanFile(Container& Students);
bool generateFile();

template <typename Container>
void sortingStudentsTemplate();

template <typename Container>
void sortingStudents(Container& Students);

#endif