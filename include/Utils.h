#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iomanip>
#include <string>

void log(std::string msg);
void log(std::string header,std::string msg);
void log(std::string header,std::string msg,bool check=true);

#endif