#include <cstdio>
#include "comp/list.h"

int main()
{
    List<int> intList;

    for(int i = 10; i > 0; --i)
    {
        intList.add(i);
    }

    for(int i = 0; i < intList.size; ++i)
    {
        printf("%d ", intList[i]);
    }
    printf("\n%d\n", intList.size);

    intList.remove(5);
    intList.remove(2);
    intList.remove(11);

    printf("%d\n", intList.size);

    for(int i = 0; i < intList.size; ++i)
    {
        printf("%d ", intList[i]);
    }
    printf("\n");
}
