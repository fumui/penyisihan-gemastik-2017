#include <iostream>
#include <sstream>
#include <vector>
void splitToIntVector(std::string s, std::vector<int> &out)
{
    std::stringstream ss(s);
    std::string word;
    while (ss >> word)
    {
        int parsed = 0;
        std::stringstream num(word);
        num >> parsed;
        out.push_back(parsed);
    }
}
int func(int a, int b, std::vector<int>& C){
    int x = a*b, y = x % C.size();
    return x+C[y];
}
void printMinFValue()
{
    std::string inputNM, inputA, inputB, inputC;
    std::vector<int> A, B, C, NM, FValues;
    int minVal = INT32_MAX;

    getline(std::cin, inputNM);
    splitToIntVector(inputNM, NM);
    getline(std::cin, inputA);
    splitToIntVector(inputA, A);
    getline(std::cin, inputB);
    splitToIntVector(inputB, B);
    getline(std::cin, inputC);
    splitToIntVector(inputC, C);

    for (uint i = 0; i < A.size(); i++)
    {
        for (uint j = 0; j < B.size(); j++)
        {
            int val = func(A[i],B[j],C);
            FValues.push_back(val);
        }
    }
    for (uint i = 0; i < FValues.size(); i++)
    {
        if (minVal > FValues[i]){
            minVal = FValues[i];
        }
    }
    std::cout << minVal<<"\n";
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
        printMinFValue();
    }
}