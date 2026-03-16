#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <vector>
#include <list>
#include <deque>
#include <string>
#include "student.h"

template <typename Container>
bool createFile(const Container& Students, int n);
template <typename Container>
bool readFile(const std::string& filename, Container& Students);

#endif