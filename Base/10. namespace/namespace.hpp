/*
네임스페이스(namespace)의 정의
    namespace 키워드를 사용하여 사용자가 새로운 네임스페이스를 정의할 수 있습니다.
    이러한 네임스페이스는 전역 위치뿐만 아니라 다른 네임스페이스 내에서도 정의될 수 있습니다.
    하지만 블록 내에서는 정의될 수 없으며, 기본적으로 외부 연결을 가지게 됩니다.
    일반적으로 네임스페이스는 헤더 파일에서 정의되며, 언제나 새로운 이름을 추가할 수 있도록 개방되어 있습니다.
*/
namespace first
{
    double pi()
    {
        return 3.141592;
    }
    int count;
    char first_ch;
}
namespace second
{
    double pi;
    int count;
    char second_ch;
}
