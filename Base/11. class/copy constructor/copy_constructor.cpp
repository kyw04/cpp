/*
복사 생성자(copy constructor)
    자신과 같은 클래스 타입의 다른 객체에 대한 참조(reference)를 인수로 전달받아,
    그 참조를 가지고 자신을 초기화하는 방법입니다.
    새롭게 생성되는 객체는 완전한 독립성을 가지됩니다.
*/
#include <iostream>

class Player
{
public:
    std::string name;
    int score;

    Player(std::string _name, int _score) : name(_name), score(_score) { }
    Player(const Player& _origin) // 복사 생성자
    {
        this->name = _origin.name;
        this->score = _origin.score;
    }
};

int main()
{
    Player player1("철수", 100);
    Player player2(player1);

    std::cout << "player1 => name: " << player1.name << ", score: " << player1.score << std::endl;
    std::cout << "player2 => name: " << player2.name << ", score: " << player2.score << std::endl;

    return 0;
}