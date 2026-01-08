/*
클래스(class)
    구조체의 상위 호환으로 이해할 수 있습니다.
    구조체와 클래스는 기본 접근 제어의 차이를 가집니다.
    클래스의 멤버 변수를 프로퍼티(property), 멤버 함수를 메소드(method)라고도 합니다.

인스턴스(instance)
    클래스는 구조체와 마찬가지로 사용자가 정의할 수 있는 일종의 타입입니다.
    따라서 클래스를 사용하기 위해서는 우선 해당 클래스 타입의 객체를 선언해야 합니다.
    이렇게 선언된 해당 클래스 타입의 객체를 인스턴스(instance)라고 하며, 메모리에 대입된 객체를 의미합니다.
    클래스는 인스턴스(instance)를 찍어내는 틀이라고 생각하면 편합니다.
    
*/
#include <iostream>

class Cat // class 클래스이름
{
private: // 접근 제어자(pricate 접근 제어자만 생략 가능 나머지 접근 제어자는 생략 불가)
public: // 접근 제어자
    std::string name; // 멤버변수1의타입 멤버변수1의이름;
    int age; // 멤버변수2의타입 멤버변수2의이름;
    float weight; // ...

    Cat(); // 생성자
    ~Cat(); // 소멸자
    void Mew(); // 멤버함수1의 원형
    void Eat(float); // 멤버함수2의 원형
    void Info(); // ...
};

Cat::Cat() // 생성자
{
    this->age = 1;
    std::cout << "새로운 고양이 생성" << std::endl;
}
Cat::~Cat() // 소멸자
{
    std::cout << this->name << " 삭제" << std::endl;
}

void Cat::Eat(float _value) // 반환타입 클래스이름::멤버함수이름(매개변수목록)
{
    // 함수의 몸체
    this->weight += _value;
}
void Cat::Mew()
{
    std::cout << "야옹" << std::endl;
}
void Cat::Info()
{
    std::cout << "이름: " << this->name << std::endl;
    std::cout << "나이: " << this->age << std::endl;
    std::cout << "무게: " << this->weight << std::endl;
}

int main()
{
    Cat my_cat; // 인스턴스(instance)

    my_cat.name = "고냥이"; // 객체이름.멤버변수이름;

    my_cat.Eat(0.5f); // 객체이름.멤버함수이름(전달할인수목록); 
    my_cat.Mew();
    my_cat.Info();

    return 0;
}