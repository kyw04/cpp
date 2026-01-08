/*
이진 검색(Binary Search)
    정렬된 
*/
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <limits>
#include <functional>

bool LinearSearch(int n, std::vector<int>& arr) // 비교를 위한 선형 검색 함수
{
    for (auto& a : arr)
    {
        if (a == n) return true;
    }

    return false;
}

bool BinarySearch(int n, std::vector<int>& arr)
{
    auto first = arr.begin();
    auto last = arr.end();

    while (true)
    {
        auto range_length = std::distance(first, last);
        int mid_element_index = int(std::floor(range_length / 2));
        auto mid_element = *(first + mid_element_index);

        if (mid_element == n)
            return true;
        
        if (mid_element > n)
            std::advance(last, -mid_element_index);
        else
            std::advance(first, mid_element_index);
        
        if (range_length <= 1)
            return false;
    }
}

std::vector<int> GetRandomArray(int size)
{
    std::vector<int> result;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    for (auto i = 0; i < size; i++)
        result.push_back(dis(gen));

    return result;
}

auto GetSearchTimeToMicrosecnd(std::function<bool (int, std::vector<int>&)> fun, std::vector<int>& test_arr, int n)
{
    std::sort(test_arr.begin(), test_arr.end());

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now(); // 검색 시간 측정
    fun(n, test_arr);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); // 검색 시간 측정 종료    

    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    return diff.count();
}

int main()
{
    int size = 10000;
    std::vector<int> arr = GetRandomArray(size);
    std::cout << "배열 크기: " << size << std::endl;
    std::cout << "선형 검색 수행 시간: " << GetSearchTimeToMicrosecnd(LinearSearch, arr, 36543) << std::endl;
    std::cout << "이진 검색 수행 시간: " << GetSearchTimeToMicrosecnd(BinarySearch, arr, 36543) << std::endl;
    std::cout << std::endl;

    size *= 10;
    arr = GetRandomArray(size);
    std::cout << "배열 크기: " << size << std::endl;
    std::cout << "선형 검색 수행 시간: " << GetSearchTimeToMicrosecnd(LinearSearch, arr, 36543) << std::endl;
    std::cout << "이진 검색 수행 시간: " << GetSearchTimeToMicrosecnd(BinarySearch, arr, 36543) << std::endl;
    std::cout << std::endl;

    size *= 10;
    arr = GetRandomArray(size);
    std::cout << "배열 크기: " << size << std::endl;
    std::cout << "선형 검색 수행 시간: " << GetSearchTimeToMicrosecnd(LinearSearch, arr, 36543) << std::endl;
    std::cout << "이진 검색 수행 시간: " << GetSearchTimeToMicrosecnd(BinarySearch, arr, 36543) << std::endl;
    std::cout << std::endl;
  
    return 0;
}