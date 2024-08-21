#pragma once

#ifdef CRAFT_PLATFORM_WINDOWS
extern Craft::Application* Craft::CreateApplication();

int main(int arc, char** arcv) {
	auto app = Craft::CreateApplication();
	Craft::Log* log = new Craft::Log("TestLog");
	log->Print("Entry point print", __FILE__, __LINE__);
	LOG("Entry point print");
	LOG_TEST("{0} {1} random numbers", 20, 32);
	PRINT_LOG("Log");
	PRINT_INFO("Info");
	PRINT_ERROR("Error");
	app->Run();
	delete app;
}
#else
	#error Only support Windows  
#endif 