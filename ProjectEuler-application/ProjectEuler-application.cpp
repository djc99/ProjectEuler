// ProjectEuler-application.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ProjectEuler-math.h"

int main()
{
    int n = 0;
    euler1(&n);
    printf("solution 1: %d\n", n);

    IEuler* euler;
    HRESULT h = createEuler(&euler);
    euler->answer(0, &n);
    printf("the final answer: %d\n", n);
}

