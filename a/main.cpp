#include <iostream>
#include <sstream>
#include <vector>

void splitToIntVector(std::string s, std::string delimiter, std::vector<int> &out)
{
    std::stringstream ss(s);
    std::string word;
    int count = 0;
    while (ss >> word)
    {
        std::stringstream num(word);
        num >> out[count];
        count++;
    }
}
int sum(std::vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int N;
    std::string inputN, inputA, inputB, delimiter = " ";
    std::vector<int> A = {}, B = {};
    getline(std::cin, inputN);
    std::stringstream num(inputN);
    num >> N;
    A.resize(N);
    B.resize(N);
    if (N == 1)
    {
        delimiter = "";
    }
    getline(std::cin, inputA);
    getline(std::cin, inputB);
    splitToIntVector(inputA, delimiter, A);
    splitToIntVector(inputB, delimiter, B);
    int sumA = sum(A);
    int sumB = sum(B);
    std::cout << (sumA + sumB) * N << "\n";
}
