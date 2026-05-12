#pragma once
#include <vector>
#include <memory>
#include <type_traits>

#include "appModule.h"

template <class T>
inline appModule* newModule()
{
    return (new T);
}

class AppHead {
private:
    inline static std::vector<appModule*> Modules;

public:
    template <class startingModule>
    static void startModule()
    {
        static_assert(std::is_base_of<appModule, startingModule>::value,
                      "startingModule must be derived from appModule");
        
        appModule* InitClass = newModule<startingModule>();
        InitClass->Init();
        Modules.push_back(InitClass);
    }
    static void KillApp() {
        for (appModule* Module : Modules) {
            Module->Terminate();
            delete Module;
        }
    }

};

