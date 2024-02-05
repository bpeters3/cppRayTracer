#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer{
public: 
    Timer()
    {
        m_start =std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
        Stop();
    }

    void Stop(){
        auto endTime = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_start).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::milliseconds>(endTime).time_since_epoch().count();

        auto duration = end-start;
        std::clog << "Time elapsed: " << duration << "ms" << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
};
#endif