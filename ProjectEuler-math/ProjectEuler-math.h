#pragma once

#include <Unknwn.h>

void __stdcall euler1(int* result);

void __stdcall sumOfMultiples(int* multiples, int numMultiples, int maxNumber, int* result);

struct __declspec(uuid("56c80ee0-b0bd-49f0-8f6d-9d91f431cae6"))
IEuler : IUnknown
{
    virtual HRESULT __stdcall answer(int question, int* result) = 0;
};

HRESULT __stdcall createEuler(IEuler ** result);