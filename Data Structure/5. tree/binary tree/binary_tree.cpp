/*
이진 트리(Binary Tree)
    이진 트리는 부모 노드가 자식 노드를 최대 2개까지 가질 수 있는 자료구조입니다.
    이진 트리는 일차원 배열로 표현이 가능하다는 특징이 있습니다.
    일차원 배열로 표현한 경우 공간의 제약이나 데이터의 삽입, 삭제시에 기존 데이터의 이동과 같은 단점이 있습니다.
    일차원 배열로 표현한 경우 첫 번째 인덱스는 비워두고 값이 채울 경우 연산을 통해 원하는 값에 빠르게 접근할 수 있습니다.
    
    일차원 배열로 표현한 이진 트리의 연산
        루트 노드 : 1
        노드 i의 부모 : i / 2
        노드 i의 왼쪽 자식 : i * 2
        노드 i의 오른쪽 자식 : i * 2 + 1 

    이진 트리의 종류
        정 이진 트리(Full Binary Tree), 엄격한 이진 트리(Strcit Binary Tree)
            모든 노드가 2개의 자식을 가지고 있거나 자식이 없는 경우를 뜻합니다.
            자식이 한 개인 노드가 없어야 정 이진 트리입니다.

        포화 이진 트리(Perfect Binary Tree)
            모든 노드가 2개의 자식을 가지고 있어야 하며 리프(leaf) 노드가 모두 같은 레벨(level)에 있는 경우를 뜻합니다.
            이진트리에서 노드 갯수는 2의 k + 1 제곱 -1의 특징을 갖습니다.(k: 0부터 level까지 모든 수를 더한 값)

        완전 이진 트리(Complete binary tree)
            마지막 레벨(level)을 제외하고 모든 노드가 채워져 있고 노드가 왼쪽부터 오른쪽으로 채워져 있는 경우를 뜻합니다.
            포화 이진 트리(Perfect binary tree)도 완전 이진 트리에 속할 수 있습니다.
            하지만 완전 이진트리라고 해서 포화이진트리라는 역은 성립하지 않습니다.
*/
#include <iostream>
#define TREE_SIZE 7

int tree[TREE_SIZE];
int main()
{
    tree[1] = 1;
    tree[2] = 2;
    tree[3] = 3;
    tree[4] = 4;
    tree[5] = 5;
    tree[6] = 6;
    
    std::cout << "루트 노드의 값: " << tree[1] << std::endl;
    std::cout << "2번 노드 부모의 값: " << tree[2 / 2] << std::endl;
    std::cout << "2번 노드의 왼쪽 자식 값: " << tree[2 * 2] << std::endl;
    std::cout << "2번 노드의 오른쪽 자식 값: " << tree[2 * 2 + 1] << std::endl;

    return 0;
}