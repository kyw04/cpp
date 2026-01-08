/*
생성자(constructor)
    객체 생성할 때마다 실행되는 함수를 의미합니다.
    생성자(constructor)의 이름은 해당 클래스의 이름과 같습니다.
    생성자는 반환값이 없지만, void형으로 선언하지 않습니다.

디폴트 생성자(default constructor)
    객체가 생성될 때 사용자가 초깃값을 명시하지 않으면, 컴파일러가 자동으로 제공하는 생성자입니다.
    대부분의 디폴트 생성자가 0이나 NULL, 빈 문자열 등으로 초기화를 진행합니다.

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

    Player(std::string _id, std::string _password, std::string _name) : id(_id), password(_password), name(_name)
    {
        score = 0;
        std::cout << "아이디: " << id << std::endl;
        std::cout << "비밀번호: " << password << std::endl;
        std::cout << "이름: " << name << std::endl;
        std::cout << "인 플레이어를 생성하였습니다." << std::endl << std::endl;
    }
};

class Game
{
private:
    int level;

public:
    void Play()
    {
        std::cout << "레벨 " << level << " 시작" << std::endl;
    }
};

int main ()
{
    Player player1("cheolsu", "csu123!@#", "철수"); // 생성자 암시적 호출
    Player player2 = Player("yeonghui123", "Yeonghui11!!", "영희"); // 생성자 명시적 호출

    Game game1; // 디폴트 생성자 암시적 호출
    Game game2 = Game(); // 디폴트 생성자 명시적 호출
    Game* game3 = new Game; // 디폴트 생성자 암시적 호출

    return 0;
}