
#ifndef VLS_H
#define VLS_H
#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

vector<string> readVector(const string& filename)
list<string> readList(const string& filename)
set<string> readSet(const string& filename)
 
void insertVector(vector<string>& v)
void insertList(list<string>& l)
void insertSet(list<string>& s) 

void deleteVector(vector<string>& v)
void deleteList(list<string>& l)
void deleteSet(set<string>& s) 

#endif