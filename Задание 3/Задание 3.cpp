#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;
int main()
{
    ifstream fin;
    fin.open("input.txt");

    string line;
    getline(fin, line);

    fin.close();

    string::iterator it_step = find(line.begin(), line.end(), ',');
    int S = atoi(string(line.begin(), it_step).c_str());
    string::iterator it = (it_step + 1); // итератор на первое число 0 или 1

    int count = S;
    bool unit_passed = false;

    ofstream fout;
    fout.open("output.txt");


    while (it != line.end()) {
        if ((*it) == '1') {
            if (count < S)
            {
                fout << "False";
                return 0;
            }
            count = 0;
            unit_passed = true;
        }

        if (unit_passed && (*it) == '0') {
            count++;
        }
        if ((it + 1) != line.end()) {
            ++(++it); // пропускаем запятую
        }
        else
            break;
    }
    fout << "True";
    return 0;
}
