#pragma once
#include "craftpch.h"
#include "Engine/Core.h"
#include "Event.h"

namespace Craft {
	class CRAFT_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return _keyCode;  }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keyCode) : _keyCode(keyCode) {}
			int _keyCode;
	};

	class CRAFT_API KeyPressedEvent : public KeyEvent {
	public: 
		KeyPressedEvent(int keyCode, int repeateCount)
			: KeyEvent(keyCode), _repeateCount(repeateCount) {}
		
		
		std::string ToString() {
			std::stringstream ss;
			ss << "Key Pressed Event: " << _keyCode << "(" << _repeateCount << ")";
			return ss.str();
	}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int _repeateCount;
	};

	class CRAFT_API KeyReleaseEvent : public KeyEvent {
	public: KeyReleaseEvent(int keyCode) : KeyEvent(keyCode){}

		  std::string ToString() const override {
			  std::stringstream ss;
			  ss << "Key Released Event: " << _keyCode;
			  return ss.str();
		  }

	EVENT_CLASS_TYPE(KeyReleased)
	};
}