
//  Vector/List/Set functions
// Trying to organize at lease a little,
#ifndef VLS_H
#define VLS_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <fstream>
#include <algorithm>
using namespace std;
using namespace std::chrono;

const int MAX = 20000; // size of the file.

// still usefull, gets the duration for the subsequent funcs return
long long nanoOutput(high_resolution_clock::time_point start, 
                high_resolution_clock::time_point end) 
{ 
    auto duration = duration_cast<nanoseconds>(end - start);
    return duration.count(); 
}
//READ ---------- gets the container and filenname, returns the duration/long
long long readVector(const string& filename, vector<string>& temp )
{
    ifstream fin;
    fin.open(filename);
    if (fin.good()) 
    {   
        auto start = high_resolution_clock::now();
        for (int i = 0; i < MAX; i++)
        {
            string line;
            getline(fin, line);
            temp.push_back(line);
        }
        auto end = high_resolution_clock::now();
        fin.close();
        return nanoOutput(start, end);
    }
    else 
        cout << "\nFile not found.";
    return -1;
}
long long readList(const string& filename, list<string>& temp)
{
    ifstream fin;
    fin.open(filename);
    if (fin.good()) 
    {   
        auto start = high_resolution_clock::now();
        for (int i = 0; i < MAX; i++)
        {
            string line;
            getline(fin, line);
            temp.push_back(line);
        }
        auto end = high_resolution_clock::now();
        fin.close();
        return nanoOutput(start, end);
    }
    else 
        cout << "\nFile not found.";
    return -1;
}
long long readSet(const string& filename, set<string>& temp)
{
    ifstream fin;
    fin.open(filename);
    if (fin.good()) 
    {   
        auto start = high_resolution_clock::now();
        for (int i = 0; i < MAX; i++)
        {
            string line;
            getline(fin, line);
            temp.insert(line);
        }
        auto end = high_resolution_clock::now();
        fin.close();
        return nanoOutput(start, end);
    }
    else 
        cout << "\nFile not found.";
     return -1;
}
//SORT ---------- Gets container, return the duration/long
long long sortVector(vector<string>& v)
{
    auto start = high_resolution_clock::now();
    sort(v.begin(), v.end()); 
    auto end = high_resolution_clock::now();
    return nanoOutput(start, end);
}
long long sortList(list<string>& l)
{
    auto start = high_resolution_clock::now();
    l.sort();
    auto end = high_resolution_clock::now();
    return nanoOutput(start, end);
}
//INSERT ---------- Gets container, return the duration/long
long long insertVector(vector<string>& v)
{
    auto start = high_resolution_clock::now();
    v.insert(v.begin() + v.size() / 2, "TESTCODE");
    auto end = high_resolution_clock::now();
    return nanoOutput(start, end);
}
long long insertList(list<string>& l)
{
    auto it = l.begin();
    advance(it, l.size() / 2);
    auto start = high_resolution_clock::now();
    l.insert(it, "TESTCODE"); 
    auto end = high_resolution_clock::now();
    return nanoOutput(start, end);
}
long long insertSet(set<string>& s) 
{
    auto sit = s.begin(); 
    advance(sit, s.size() / 2); 
    auto start = high_resolution_clock::now(); 
    s.insert(sit, "TESTCODE"); 
    auto end = high_resolution_clock::now();
    return nanoOutput(start, end);
}
//DELETE ---------- Gets container, return the duration/long
long long deleteVector(vector<string>& v)
{
    auto start = high_resolution_clock::now();
    v.erase(v.begin() + v.size() / 2 );
    auto end = high_resolution_clock::now();
    return nanoOutput(start, end);
}
long long deleteList(list<string>& l)
{
    auto it = l.begin();
    advance(it, l.size() / 2);
    auto start = high_resolution_clock::now();
    l.erase(it); 
    auto end = high_resolution_clock::now();
    return nanoOutput(start, end);
}
long long deleteSet(set<string>& s) 
{
    auto sit = s.begin(); 
    advance(sit, s.size() / 2); 
    auto start = high_resolution_clock::now(); 
    s.erase(sit); 
    auto end = high_resolution_clock::now();
    return nanoOutput(start, end);
}

#endif