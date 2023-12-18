#include "gb/GameBoy.h" 

int main() {
    auto* gameboy = new GameBoy();
    gameboy->Start();
    delete gameboy;
    return 0;
}