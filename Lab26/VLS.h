
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

const int MAX = 20000;

//probably getting rid of this
void nanoOutput(high_resolution_clock::time_point start, 
                high_resolution_clock::time_point end) 
{ 
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "\t| " << duration.count() << " |"; 
}
//READ ----------
vector<string> readVector(const string& filename)
{
    vector<string> temp;
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
        nanoOutput(start, end);
        fin.close();
    }
    else 
        cout << "\nFile not found.";
    return temp;
}
list<string> readList(const string& filename)
{
    list<string> temp;
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
        nanoOutput(start, end);
        fin.close();
    }
    else 
        cout << "\nFile not found.";
        return temp;
}
set<string> readSet(const string& filename)
{
    set<string> temp;
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
        nanoOutput(start, end);
        fin.close();
    }
    else 
        cout << "\nFile not found.";
    return temp;
}
//SORT ----------
void sortVector(vector<string>& v)
{
    auto start = high_resolution_clock::now();
    sort(v.begin(), v.end()); 
    auto end = high_resolution_clock::now();
    nanoOutput(start, end);
}
void sortList(list<string>& l)
{
    auto start = high_resolution_clock::now();
    l.sort();
    auto end = high_resolution_clock::now();
    nanoOutput(start, end);
}
//INSERT ---------- 
void insertVector(vector<string>& v)
{
    auto start = high_resolution_clock::now();
    v.insert(v.begin() + v.size() / 2, "TESTCODE");
    auto end = high_resolution_clock::now();
    nanoOutput(start, end);
}
void insertList(list<string>& l)
{
    auto it = l.begin();
    advance(it, l.size() / 2);
    auto start = high_resolution_clock::now();
    l.insert(it, "TESTCODE"); 
    auto end = high_resolution_clock::now();
    nanoOutput(start, end);
}
void insertSet(set<string>& s) 
{
    auto sit = s.begin(); 
    advance(sit, s.size() / 2); 
    auto start = high_resolution_clock::now(); 
    s.insert(sit, "TESTCODE"); 
    auto end = high_resolution_clock::now();
    nanoOutput(start, end);
}
//DELETE ----------
void deleteVector(vector<string>& v)
{
    auto start = high_resolution_clock::now();
    v.erase(v.begin() + v.size() / 2 );
    auto end = high_resolution_clock::now();
    nanoOutput(start, end);
}
void deleteList(list<string>& l)
{
    auto it = l.begin();
    advance(it, l.size() / 2);
    auto start = high_resolution_clock::now();
    l.erase(it); 
    auto end = high_resolution_clock::now();
    nanoOutput(start, end);
}
void deleteSet(set<string>& s) 
{
    auto sit = s.begin(); 
    advance(sit, s.size() / 2); 
    auto start = high_resolution_clock::now(); 
    s.erase(sit); 
    auto end = high_resolution_clock::now();
    nanoOutput(start, end);
}

#endif