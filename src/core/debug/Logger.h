#pragma once

class Logger {
    static Logger* m_pInstance;
    ~Logger();

public:
    Logger();

    static const Logger* const GetInstance();
    void Log(const char* message);
};