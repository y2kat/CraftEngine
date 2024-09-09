#pragma once
#include "craftpch.h"
#include "Engine/Core.h"
#include "Engine/Event/Event.h"

namespace Craft {
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		WindowProps(const std::string title = "Craft engine",
			unsigned int width = 1280, unsigned int height = 720) :
			Title(title), Width(width), Height(height){}
	};

	class CRAFT_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}
		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback);
		virtual void SetVSync(bool enabled);
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}