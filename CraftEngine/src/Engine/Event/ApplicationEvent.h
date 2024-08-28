#pragma once

#include "craftpch.h"
#include "Engine/Core.h"
#include "Event.h"

namespace Craft {
	class CRAFT_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: _width(width), _height(height){}

		inline unsigned int GetWidth() { return _width; }
		inline unsigned int GetHeight() { return _height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Window resize event: " << _width << ", " << _height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private: 
		unsigned int _width;
		unsigned int _height;
	};
		
	class CRAFT_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent(){}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}