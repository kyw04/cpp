/*
순수 가상 함수(pure virtual function)
    파생 클래스에서 반드시 재정의해야 하는 멤버 함수를 의미합니다.

추상 클래스(abstract class)
    하나 이상의 순수 가상 함수를 가지고 있는 클래스를 의미합니다.
    기본적으로 추상 클래스는 순수 가상 함수를 포함하고 있으므로, 인스턴스를 생성할 수 없습니다.
    추상 클래스를 사용하기 위해서는 먼저 자식 클래스를 만들어 추상 클래스를 상속 받은 후 
    순수 가상 함수를 모두 오버라이딩 해주어 자식 클래스의 인스턴스를 생성하여 사용합니다.
    하지만 추상 클래스 타입의 포인터와 참조는 바로 사용할 수 있습니다.
*/
#include <iostream>

class Animal
{
public:
    virtual void Cry() = 0; // 순수 가상 함수 선언
};

class Dog : public Animal
{
public:
    virtual void Cry()
    {
        std::cout << "멍멍!" << std::endl;
    }
};

class Cat : public Animal
{
public:
    virtual void Cry()
    {
        std::cout << "야옹!" << std::endl;
    }
};

int main()
{
    Animal* animal_ptr; 
    Dog dog1;
    Cat cat1;

    animal_ptr = &dog1;
    animal_ptr->Cry();
    animal_ptr = &cat1;
    animal_ptr->Cry();

    return 0;
}