#include "Logger.h"
#include <iostream>

Logger::Logger()
{
}

Logger::~Logger()
{
    if (m_pInstance)
    {
        delete m_pInstance;
        m_pInstance = nullptr;
    }
}

const Logger *const Logger::GetInstance()
{
    if (!m_pInstance) m_pInstance = new Logger();
    return m_pInstance;
}


void Logger::Log(const char* message)
{
    std::cout << message << std::endl;
}