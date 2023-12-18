#pragma once

class Cartridge {
    unsigned char* m_Memory;
    int m_MemSize;

    void DumpMemory() const;

public:
    Cartridge();
    ~Cartridge();

    int Load(const char*);
};