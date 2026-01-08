#include <iostream> // iostream(표준 입출력 클래스를 정의 하고있는 헤더 파일)

int main()
{
    std::string name;

    std::cin >> name; // 입력(std::cin)
    std::cout << name << " Hello World" << std::endl; // 출력(std::cout), 줄바꿈(std::endl)

    return 0;
}