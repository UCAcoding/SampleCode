
//ehglobal.h 부터



//Program.cpp
#include "App.h"
int main()
{
    App *app = new App();
    app->Run();
    delete app;
    return 0;
}