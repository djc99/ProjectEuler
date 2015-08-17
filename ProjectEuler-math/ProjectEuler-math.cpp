// ProjectEuler-math.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ProjectEuler-math.h"
#include <crtdbg.h>

#include <wrl.h>
using namespace Microsoft::WRL;

#define ASSERT _ASSERTE

struct Euler : RuntimeClass<RuntimeClassFlags<ClassicCom>, IEuler>
{
    HRESULT __stdcall answer(int question, int* result) override
    {
        *result = 1;
        return S_OK;
    }

};

HRESULT __stdcall createEuler(IEuler ** result)
{
    ASSERT(result);
 
    *result = nullptr;

    ComPtr<IEuler> euler = Make<Euler>();

    if (!euler)
    {
        return E_OUTOFMEMORY;
    }

    *result = euler.Detach();
    return S_OK;
}

//Project Euler #1
void __stdcall euler1(int* result)
{
    int multiples[2] = { 3,5 };
    sumOfMultiples(multiples, 2, 1000, result);
}

void __stdcall sumOfMultiples(int* multiples, int numMultiples, int maxNumber, int* result)
{
    *result = 0;

    for (int n = 1; n < maxNumber; n++)
    {
        bool isMultiple = false;
        for (int m = 0; m < numMultiples; m++)
        {
            if (n % multiples[m] == 0)
                isMultiple = true;
        }

        if (isMultiple)
        {
            *result += n;
        }
    }
}