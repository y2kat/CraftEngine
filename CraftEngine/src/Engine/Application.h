#pragma once

#include "Core.h"
#include "Event/Event.h"
#include "Event/ApplicationEvent.h"
#include "Engine/Window.h"

namespace Craft {
	class CRAFT_API Application {
	public: 
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Craft::Window> _Window;
		bool _running = true;
	};

	Application* CreateApplication();
}

