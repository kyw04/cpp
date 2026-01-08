/*
부분 합 문제(Subset Sum Problem)

*/
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUGGING 1
#if DEBUGGING
    #define DEBUG(X) std::cerr << X
#else
    #define DEBUG(X)
#endif

void GetAllSubsets(std::vector<int> set, std::vector<int> subset, int index,
                    std::vector<std::vector<std::vector<int>>>& all_subsets)
{
    if (static_cast<size_t>(index) == set.size())
    {
        all_subsets[subset.size()].push_back(subset);
        return;
    }
    
    GetAllSubsets(set, subset, index + 1, all_subsets);

    subset.push_back(set[static_cast<size_t>(index)]);
    GetAllSubsets(set, subset, index + 1, all_subsets);
}

// 전수 조사 방식
bool SubsetSum_BruteForce(std::vector<int> set, int target)
{
    std::vector<std::vector<std::vector<int>>> all_subsets(set.size() + 1);
    GetAllSubsets(set, {}, 0, all_subsets);

    for (size_t size = 0; size <= set.size(); size++)
    {
        DEBUG("부분집합의 원소 개수: " << size << std::endl);
        for (auto subset : all_subsets[size])
        {
            DEBUG("\t{ ");

            int sum = 0;
            for (auto number : subset)
            {
                sum += number;
                DEBUG(number << " ");
            }
            DEBUG("} = " << sum << std::endl);

            if (sum == target)
                return true;
        }
    }

    return false;
}

int main()
{
    std::vector<int> set = { 13, 79, 45, 29 };
    int target = 10000;

    std::cout << std::boolalpha;
    std::cout << SubsetSum_BruteForce(set, target) << std::endl;

    return 0;
}
