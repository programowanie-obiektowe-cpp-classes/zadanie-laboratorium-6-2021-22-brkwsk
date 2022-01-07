#pragma once

#include "Human.hpp"

#include <algorithm>
#include <list>
#include <vector>

std::vector< char > foo(std::list< Human >& people)
{
    std::vector< char > ret_v(people.size());
    ret_v.clear();

    //std::for_each(people.rbegin(), people.rend(), [ret_v](Human& person) { 
    //    person.birthday(); 
    //    });

    std::transform(people.rbegin(), people.rend(), std::back_inserter(ret_v), [](Human& person) {
        person.birthday();
        if (person.isMonster() == true)
            return 'n';
        else
            return 'y';
    });

    return ret_v;
}
