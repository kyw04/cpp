/*
오버라이딩(overriding)
    멤버 함수의 동작만을 재정의하는 것을 의미합니다.
*/
#include <iostream>

class Animal
{
private:
    std::string name;
    int age;

public:
    Animal(const std::string& _name, int _age) : name(_name), age(_age) { }
    virtual void ShowAnimalInfo()
    {
        std::cout << "이 동물의 이름은 " << this->name << "이고 나이는 " << this->age << "살 입니다." << std::endl;
    }
};

class Cat : public Animal
{
private:
    std::string type;

public:
    Cat(const std::string& _type, const std::string& _name, int _age) : Animal(_name, _age), type(_type) { } // 파생 클래스의 생성자 이용
    virtual void ShowAnimalInfo() // 파생 클래스에서 상속받은 멤버 함수의 재정의  
    {
        std::cout << "이 고양이의 종류는 " << type << "입니다." << std::endl;
    }
};

int main()
{
    Cat cat("소코케", "두부", 1);
    Animal dog("힌둥이", 2);

    cat.ShowAnimalInfo();
    cat.Animal::ShowAnimalInfo(); // 부모 클래스의 원래 멤버 함수 호출
    dog.ShowAnimalInfo();

    std::cout << std::endl;

    Animal* animal_ptr;
    animal_ptr = &cat;
    animal_ptr->ShowAnimalInfo(); // 가상 함수로 선언하지 않을 경우 포인터의 변수에 해당하는 함수로 실행 됩니다.
    animal_ptr = &dog;
    animal_ptr->ShowAnimalInfo();

    return 0;
}