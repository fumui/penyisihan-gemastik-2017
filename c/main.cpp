#include <iostream>
#include <sstream>
#include <vector>
#include <set>

void splitToStringVector(std::string s,std::vector<std::string> &out)
{
    std::stringstream ss(s);
    std::string word;
    int count = 0;
    while (ss >> word)
    {
        out.push_back(word);
    }
}
void printDiffMax()
{
    std::string inputX, inputN, inputS;
    std::vector<std::string> inputP = {}, S = {};
    std::vector<std::vector<std::string>> P = {};
    std::set<std::string> entity;
    int N;
    getline(std::cin, inputN);
    std::stringstream num(inputN);
    num >> N;

    getline(std::cin, inputS);
    splitToStringVector(inputS, S);
    inputP.resize(S.size());
    for (uint i = 0; i < S.size(); i++)
    {
        getline(std::cin, inputP[i]);
        std::vector<std::string> Pi = {};
        splitToStringVector(inputP[i], Pi);
        P.push_back(Pi);
    }
    for (uint i = 0; i < P.size(); i++)
    {
        for (uint j = 1; j < P[i].size(); j++)
        {
            entity.insert(P[i][j]);
        }
    }
    std::cout << (entity.size() + S.size()) << "\n";
}
int main()
{
    std::string inputX;
    int X;

    getline(std::cin, inputX);
    std::stringstream num(inputX);
    num >> X;
    for (uint i = 0; i < X; i++)
    {
        printDiffMax();
    }
}