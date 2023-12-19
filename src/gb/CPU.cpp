#include "CPU.h"

int CPU::Inst_DGM(unsigned int, unsigned int)
{
    return 0;
}

CPU::CPU(): m_InstructionMap()
{
    m_InstructionMap[CPU::IN_TYPE::DGM];
    auto p = std::bind(&CPU::Inst_DGM, this);
}

CPU::~CPU()
{
}

const int CPU::ExecuteOpCode(unsigned int)
{
    return 0;
}
