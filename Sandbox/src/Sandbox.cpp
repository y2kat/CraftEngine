#pragma once
#include <CraftEngine.h>

class Sandbox : public Craft::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Craft::Application* CreateApplication() {
	return new Sandbox();
}