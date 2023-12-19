#pragma once
#include <unordered_map>
#include <functional>


class CPU
{
    union Register {
        struct {
            unsigned short hi;
            unsigned short lo;
        };
        unsigned int reg;
    };

    union RegisterPair {
        Register left;
        Register right;
    };

    typedef int(*CPU::InstFunc)(unsigned int, unsigned int);
    std::unordered_map<int, std::function<int(unsigned int, unsigned int)>> m_InstructionMap;

    int Inst_DGM(unsigned int, unsigned int);

    RegisterPair m_RegAF;
    RegisterPair m_RegBD;
    RegisterPair m_RegCE;
    RegisterPair m_RegHL;

public:
    const enum IN_TYPE {
        DGM = 0x00 
    };

    CPU();
    ~CPU();

    const int ExecuteOpCode(unsigned int);

};