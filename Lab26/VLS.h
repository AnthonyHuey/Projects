
#ifndef VLS_H
#define VLS_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <fstream>
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
 
void insertVector(vector<string>& v)
{

}
void insertList(list<string>& l)
{

}
void insertSet(list<string>& s) 
{

}

void deleteVector(vector<string>& v)
{

}
void deleteList(list<string>& l)
{

}
void deleteSet(set<string>& s) 
{

}

#endif