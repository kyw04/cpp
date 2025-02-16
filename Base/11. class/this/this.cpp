/*
this 포인터
    해당 멤버 함수를 호출한 객체를 가리키게 되며, 호출된 멤버 함수의 숨은 인수로 전달됩니다.
    이렇게 하면 호출된 멤버 함수는 자신을 호출한 객체가 무엇인지 정확히 파악할 수 있습니다.

    this 포인터는 클래스, 구조체 또는 열거체 타입의 비정적 멤버 함수에서만 사용할 수 있습니다.
    정적(static) 멤버 함수는 this 포인터를 가지지 않습니다.
    this 포인터는 언제나 포인터 상수이며, 따라서 값을 재할당할 수 없습니다.
*/
#include <iostream>

class Player
{
private:
    std::string id;
    std::string password;

public:
    std::string name;
    int score;

    const Player& MoreScore(const Player& _comp_player)
    {
        if (this->score < _comp_player.score)
        {
            return _comp_player;
        }
        else
        {
            return *this;
        }
    }

    Player(std::string _name, int _score) : name(_name), score(_score) { }
};

int main ()
{
    Player player1("철수", 100);
    Player player2("영희", 30);

    const Player winner = player1.MoreScore(player2);
    std::cout << winner.name << std::endl;

    return 0;
}