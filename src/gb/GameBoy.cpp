#include "GameBoy.h"
#include "Cartridge.h"
#include "../core/render/GLRenderer.h"
#include "tinyfd/tinyfiledialogs.h"

GameBoy::GameBoy()
{
    m_pCartridge = new Cartridge();
    m_pRenderer = new GLRenderer();
}

GameBoy::~GameBoy()
{
    if (m_pCartridge) delete m_pCartridge;
    if (m_pRenderer) delete m_pRenderer;
}

int GameBoy::Init()
{
    const char* filters = {"*.gb"};
    const char* fileToOpen = tinyfd_openFileDialog("GrainBoy - Open GameBoy ROM", nullptr, 1, &filters, "GameBoy ROM (*.gb)", 0);

    int errorCode = fileToOpen != nullptr;
    if (errorCode != 0) return errorCode;

    errorCode = m_pCartridge->Load(fileToOpen);
    if (errorCode != 0) return errorCode;

    errorCode = m_pRenderer->Init(160, 144, fileToOpen);
    if (errorCode != 0) return errorCode;

    return 0;
}

void GameBoy::Start()
{
    if (Init() == 0)
        Loop();
}

void GameBoy::Loop()
{
    while(!m_pRenderer->IsWindowClosed())
    {
        /*
        * TODO: Implement cycles later

        const int MAXCYCLES = 69905 ;
        int cyclesThisUpdate = 0 ;

        while (cyclesThisUpdate < MAXCYCLES)
        {
            int cycles = ExecuteNextOpcode( ) ;
            cyclesThisUpdate+=cycles ;
            UpdateTimers(cycles) ;
            UpdateGraphics(cycles) ;
            DoInterupts( ) ;
        }
        */
        m_pRenderer->Render();
    }
}
