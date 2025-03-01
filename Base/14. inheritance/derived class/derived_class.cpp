/*
클래스 상속(class inheritance)
    기존에 정의되어 있는 클래스의 모든 멤버 변수와 멤버 함수를 물려받아, 새로운 클래스를 작성하는 것을 의미합니다.
    기존에 정의 되어 있던 클래스를 기초 클래스(base class) 또는 부모 클래스(parent class), 상위 클래스(super class)라고합니다.
    상속을 통해 새로 작성되는 클래스는 파생 클래스(derived class) 또는 자식 클래스(child class), 하위 클래스(sub class)라고합니다.

    상속의 장점으로는 부모 클래스의 멤버를 물려받아 재활용할 수 있습니다.
    또한 중복되는 부분을 부모 클래스에서 미리 작성하여 중복을 제거할 수도 있습니다.

*/
#include <iostream>

class Animal // 부모 클래스
{
private:
    std::string name;
    int age;

public:
    Animal(const std::string& _name, int _age) : name(_name), age(_age) { }
    void ShowAnimalInfo()
    {
        std::cout << "이름: " << this->name << std:: endl;
        std::cout << "나이: " << this->age << std:: endl;
    }
};

class Cat : public Animal // 자식 클래스
{
private:
    std::string type;

public:
    Cat(const std::string& _type, const std::string& _name, int _age) : Animal(_name, _age), type(_type) { } // 파생 클래스의 생성자 이용
    void ShowCatInfo()
    {
        std::cout << "종류: " << type << std::endl;
        ShowAnimalInfo(); // 부모 클래스의 함수 사용
    }
};

int main()
{
    Cat cat("소코케", "두부", 1);
    cat.ShowCatInfo();

    return 0;
}