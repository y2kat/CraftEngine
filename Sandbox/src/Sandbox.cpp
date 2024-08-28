#pragma once
#include <CraftEngine.h>
#include "craftpch.h"

class Sandbox : public Craft::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Craft::Application* Craft::CreateApplication() {
	return new Sandbox();
}