#pragma once

#ifdef CRAFT_PLATFORM_WINDOWS
extern Craft::Application* Craft::CreateApplication();

int main(int arc, char** arcv) {
    Craft::Log::Init();
    auto app = Craft::CreateApplication();
    app->Run();
    delete app;
}
#else
	#error Only support Windows  
#endif 