#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool last = false;

bool isEnter()
{
    char c;
    scanf("%c", &c);
    bool valid = c == '\n';
    return valid && !last;
}

void waitEnter()
{
    while (!isEnter())
    {
        last = !last;
    }
}

void a()
{
    printf("a!!");
    //int i;
    //scanf("%i", &i);
}

void b()
{
    printf("b!!");
}

int main()
{
    printf("A\n");

    a();
    waitEnter();

    b();

    printf("B\n");
    return 0;
}