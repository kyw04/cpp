/*
정적 멤버 변수(static member variable)
    클래스의 모든 객체가 공유하는 멤버를 의미합니다.
    해당 클래스의 모든 객체에 대해 하나의 데이터만이 유지 관리됩니다.
    외부 연결(external linkage)을 가지므로, 여러 파일에서 접근할 수 있습니다.
    정적 멤버 변수는 클래스 멤버의 접근 제한 규칙이 적용됩니다.

*/
#include <iostream>

class Player
{
private:
    std::string id;

public:
    static int total_player_count; // 정적 멤버 변수 선언
    static void PrintTotalPlayerCount(); // 정적 멤버 함수 선언 

    std::string name;
    int level;

    Player() { total_player_count++; }
    ~Player() { total_player_count--; }
};

int Player::total_player_count = 0; // 정적 멤버 변수 초기확 

int main()
{
    Player *p1 = new Player();
    Player *p2 = new Player();
    Player *p3 = new Player();
    
    Player::PrintTotalPlayerCount(); // 정적 멤버 함수 접근(크래스명::함수명)
    delete(p1);
    delete(p3);
    Player::PrintTotalPlayerCount();

    return 0;
}

void Player::PrintTotalPlayerCount() // 정적 멤버 함수 정의
{
    std::cout << "현제 플레이어의 수: " << Player::total_player_count << std::endl; // 정적 멤버 변수 접근(크래스명::변수명) 
}