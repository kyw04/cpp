/*
접근 제어(access control)
    접근 제어 지시자를 사용해 클래스 외부에서의 직접적인 접근을 허용하지 않는
    멤버를 설정할 수 있도록 하여, 정보 은닉을 구체화하는 것을 의미합니다.
    클래스의 기본 접근 제어 권한은 private이며, 구조체 및 공용체는 public입니다.

접근 제어 지시자
    1. public
        해당 객체를 사용하는 프로그램 어디에서나 직접 접근할 수 있습니다.
    2. private
        해당 클래스 내부에서만 사용할 수 있으며, 외부에서 공개 및 직접 접근을 할 수 없습니다.
        클래스 선언 시 private 접근 제어 지시자는 생략할 수 있습니다.
    3. protected
        파생 클래스에 대해서는 public 멤버처럼 취급되며, 외부에서는 private 멤버처럼 취급됩니다.
        이 멤버를 선언한 클래스의 멤버 함수, 이 멤버를 선언한 클래스의 프렌드, 
        이 멤버를 선언한 클래스에서 public 또는 protected 접근 제어로 파생된 클래스에 접근을 허용합니다.
*/
#include <iostream>

class Parent
{
private:
    int private_num;
    void PrintPrivateNum() { std::cout << "private_num: " << private_num << std::endl; }

public:
    int public_num;
    void PrintPublicNum() { std::cout << "public_num :"<< public_num << std::endl; }

    Parent()
    {
        private_num = 0;
        public_num = 1;
        protected_num = 2;

        std::cout << "Parent 생성자" << std::endl;   
        PrintPrivateNum();
        PrintPublicNum();
        PrintProtectedNum();
        std::cout << std::endl;
    }
    ~Parent() { std::cout << "Parent 소멸자" << std::endl; }

protected:
    int protected_num;
    void PrintProtectedNum() { std::cout << "protected_num: " << protected_num << std::endl; }

};

class Child : public Parent
{
public:
    int child_num;
    void Print()
    {
        // PrintPrivateNum(); // 오류
        PrintPublicNum();
        PrintProtectedNum();

        std::cout << "child_num: " << child_num << std::endl; 
    }

    Child()
    {
        // private_num = 40; // 오류
        public_num = 10;
        protected_num = 20;
        child_num = 30;

        std::cout << "Child 생성자" << std::endl;   
        Print();
        std::cout << std::endl;
    }
    ~Child() { std::cout << "Child 소멸자" << std::endl; }

};

int main()
{
    Parent parent;
    Child child;

    std::cout << "parent" << std::endl; 
    // parent.PrintPrivateNum(); // 오류
    parent.PrintPublicNum();
    // parent.PrintProtectedNum(); // 오류
    std::cout << std::endl;

    std::cout << "child" << std::endl; 
    // child.PrintPrivateNum(); // 오류
    child.PrintPublicNum();
    // child.PrintProtectedNum(); // 오류
    child.Print();
    std::cout << std::endl;

    return 0;
}