/*
This file contains the functions that all the other files need to use.
*/

#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <termio.h>
#include <stdio.h>
#include "global.h"

using namespace std;


void clear_screen();

string get_word();

bool leave_or_not();

void print_hint();

char keyboard();

location explain_input(char word);

#endif