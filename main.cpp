#include <iostream>
#include <vector>
#include "make_random_vector.hpp"

int funk(const int& a, const int& b)
{
    return a > b;
};

struct F
{
    int operator()(const int& a, const int& b) { return a > b; };
};

int main()
{
    std::vector< int > rand_nums;
    unsigned _int64       sevens = 0;

    rand_nums = make_random_vector(20, 0, 10);
    for_each(rand_nums.begin(), rand_nums.end(), [](int& i) { std::cout << i << " "; });
    std::cout << "\n";

    std::sort(rand_nums.begin(), rand_nums.end());
    for_each(rand_nums.begin(), rand_nums.end(), [](int& i) { std::cout << i << " "; });

    sevens = std::count(rand_nums.begin(), rand_nums.end(), 7);
    std::cout << "\nsevens: " << sevens << "\n";

    //funkcja
    //std::sort(rand_nums.begin(), rand_nums.end(), funk);
    //funktor (struktura)
    std::sort(rand_nums.begin(), rand_nums.end(), F());
    //lambda
    //std::sort(rand_nums.begin(), rand_nums.end(), [](int a, int b) { return a > b; });
    for_each(rand_nums.begin(), rand_nums.end(), [](int& i) { std::cout << i << " "; });

}

