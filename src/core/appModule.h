#pragma once



class appModule {
public:
    virtual ~appModule();
    virtual void Init();
    virtual void Terminate();
};