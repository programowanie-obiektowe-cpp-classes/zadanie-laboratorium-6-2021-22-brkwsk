#include <iostream>
#include <vector>
#include "make_random_vector.hpp"


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

    std::sort(rand_nums.begin(), rand_nums.end(), [](int a, int b) { return a > b; });
    for_each(rand_nums.begin(), rand_nums.end(), [](int& i) { std::cout << i << " "; });

}

