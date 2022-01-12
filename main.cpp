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

    //wektor liczb losowych
    rand_nums = make_random_vector(20, 0, 10);
    //print
    for_each(rand_nums.begin(), rand_nums.end(), [](int& i) { std::cout << i << " "; });
    std::cout << "\n";

    //sortowanie rosnaco
    std::sort(rand_nums.begin(), rand_nums.end());
    for_each(rand_nums.begin(), rand_nums.end(), [](int& i) { std::cout << i << " "; });

    //zliczanie
    sevens = std::count(rand_nums.begin(), rand_nums.end(), 7);
    std::cout << "\nsevens: " << sevens << "\n";

    //modyfikacja sortowania roznymi sposobami
    //funkcja
    //std::sort(rand_nums.begin(), rand_nums.end(), funk);
    //funktor (struktura)
    std::sort(rand_nums.begin(), rand_nums.end(), F());
    //lambda
    //std::sort(rand_nums.begin(), rand_nums.end(), [](int a, int b) { return a > b; });
    for_each(rand_nums.begin(), rand_nums.end(), [](int& i) { std::cout << i << " "; });

    //zliczanie warunkowe
    int above_sevens =
        std::count_if(rand_nums.begin(), rand_nums.end(), [](int& i) { return i > 7; });
    std::cout << "\nabove 7: "<< above_sevens << "\n";

    //zliczanie warunkowe z inputem (lambda)
    int a = 0;
    std::cin >> a;
    int above_input = std::count_if(rand_nums.begin(), rand_nums.end(), [a](int& i){
        //std::cin >> a;
        return i > a;});
    std::cout << "above " << a << ": " << above_input << "\n ";


}

