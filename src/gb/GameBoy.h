#pragma once

//class Bus;
//class CPU;
class Cartridge;
class GLRenderer;

class GameBoy {
    //Bus* bus;
    //CPU* cpu;
    Cartridge* m_pCartridge;
    GLRenderer* m_pRenderer;

    int Init();
    void Loop();


public:
    GameBoy();
    ~GameBoy();
    void Start();
};