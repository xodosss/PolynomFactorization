#pragma once
#ifndef GUI
#define GUI

#include <iostream>
#include "Polynom.h"
using namespace std;

int menuChoise(char **menu, int pointCount);
void outputFactorization(vector <pair <Polynom, long long>> multipliers);

#endif