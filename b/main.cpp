#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

void splitToFloatVector(std::string s, std::vector<float> &out)
{
    std::stringstream ss(s);
    std::string word;
    while (ss >> word)
    {
        float parsed = 0;
        std::stringstream num(word);
        num >> parsed;
        out.push_back(parsed);
    }
}
void printPNTimes(int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "P";
    }
}
void printCombination()
{
    std::string input;
    std::vector<float> in;
    getline(std::cin, input);
    splitToFloatVector(input, in);
    if (in[0] == 0)
    {
        if (in[2] < in[1])
        {
            std::cout << "mustahil\n";
            return;
        }
        printPNTimes(in[1]);
        std::cout << "\n";
        return;
    }
    if (in[2] < in[1] / in[0])
    {
        std::cout << "mustahil\n";
        return;
    }
    int modP = (int)in[1] % (int)in[0],
        commonP = ceil(in[1] / in[0]);

    for (int i = 0; i < in[0]; i++)
    {
        std::cout << "L";
        printPNTimes(commonP);
        if (i < modP)
        {
            printPNTimes(1);
        }
    }
    std::cout << "\n";
}
int main()
{
    std::string inputN;
    int N;

    getline(std::cin, inputN);
    std::stringstream num(inputN);
    num >> N;
    for (uint i = 0; i < N; i++)
    {
        printCombination();
    }
}