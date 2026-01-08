/*
가상 함수(virtual function)
    파생 클래스에서 재정의할 것으로 기대하는 멤버 함수를 의미합니다.
    자신을 호출하는 객체의 동적 타입에 따라 실제 호출할 함수가 결정됩니다.
    자식 클래스에서 변경 될 수 있는 모든 함수는 가상 함수로 설정하는 것이 좋습니다.
*/
#include <iostream>

class Person
{
private:
    std::string name;
    int age;

public:
    Person(const std::string _name, int _age) : name(_name), age(_age) { }
    virtual ~Person() // 오류가 발생할 수 있기에 부모 클래스의 소멸자는 가상 클래스를 사용
    {
        std::cout << name << "(이)가 삭제 되었습니다." << std::endl;
    }

    virtual void ShowInfo()
    {
        std::cout << "이름: " << name << " 나이: " << age << std::endl;
    }
};

class Student : public Person
{
private:
    int id;

public:
    Student(const std::string _name, int _age, int _id) : Person(_name, _age), id(_id) { }
    ~Student() // 부모 클래스에서 가상함수로 설정하였기 때문에 키워드 생략 가능
    {
        std::cout << "학생 아이디 " << id << " ";
    }

    virtual void ShowInfo() // 가독성을 위해 키워드 작성 권장
    {
        std::cout << "학생 아이디: " << id << std::endl;
    }
};

int main()
{
    Person* person_ptr;
    Person* person1 = new Person("철수", 20);
    Student* student1 = new Student("영희", 21, 20250303);

    person_ptr = person1;
    person_ptr->ShowInfo();
    person_ptr = student1;
    person_ptr->ShowInfo();

    delete person1;
    delete student1;
    
    return 0;
}