/*
다중 상속(multiple inheritance)
    두 개 이상의 클래스를 상속 받아 파생 클래스를 생성하는 것을 의미합니다.
    반드시 다중 상속을 사용해야만 풀 수 있는 문제란 거의 없으므로, 될 수 있으면 사용을 자제하는 것이 좋습니다.

문제점
    1. 상속받은 여러 기초 클래스에 같은 이름의 멤버가 존재할 가능성이 있습니다.
    2. 하나의 클래스를 간접적으로 두 번 이상 상속받을 가능성이 있습니다.
    3. 가상 클래스가 아닌 기초 클래스를 다중 상속하면, 기초 클래스 타입의 포인터로 파생 클래스를 가리킬 수 없습니다.
*/
#include <iostream>

class Player 
{
private:
    std::string name;
public:
    Player(const std::string _name) : name(_name) { }
    void ShowInfo() { std::cout << "플레이어 이름 :" << name << std::endl; }
};

class Interact
{
private:
    std::string use_item_name;
public:
    Interact(const std::string _item_name) : use_item_name(_item_name) { }
    void UseItem() { std::cout << use_item_name << " 사용" << std::endl; }
};

class Warrior : public Player, public Interact // 다중 상속
{
private:
    std::string skill_name;

public:
    Warrior(const std::string _start_skill_name,const std::string _name, const std::string _use_item_name) : Player(_name), Interact(_use_item_name), skill_name(_start_skill_name) { }
    void UseSkill() { std::cout << skill_name << "!" << std::endl; }
};

int main()
{
    Warrior warrior("베기", "홍길동", "포션");
    warrior.UseSkill();
    warrior.ShowInfo();
    warrior.UseItem();

    return 0;
}