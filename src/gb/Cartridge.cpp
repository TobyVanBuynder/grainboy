#include "Cartridge.h"
#include <cstring>
#include <fstream>
#include <iostream>

Cartridge::Cartridge()
{
    m_MemSize = 0;
}

Cartridge::~Cartridge()
{
    if (m_Memory) delete m_Memory;
}

int Cartridge::Load(const char* fileName)
{
    std::basic_ifstream cartridgeFile = std::basic_ifstream<unsigned char>(fileName, std::ios_base::binary | std::ios_base::ate);
    if (!(cartridgeFile.tellg() > 0)) {
        std::cout << "Failed to open file " << fileName << std::endl;
        return -1;
    }
    m_MemSize = cartridgeFile.tellg();
    m_Memory = new unsigned char(m_MemSize);

    cartridgeFile.seekg(0, std::ios::beg);
    cartridgeFile.read(m_Memory, m_MemSize);
    
    cartridgeFile.close();

    return 0;
}