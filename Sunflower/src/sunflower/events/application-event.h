#pragma once

#include "event.h"
#include <sstream>

namespace Sunflower {

	/// <summary>
	/// WindowresizeEvent
	/// </summary>
	/// Handles Windwo Resize Event 
	/// <version author="Francisco Sousa" date="8/29/2024" version="2.0"/>
	/// <seealso cref="Event" />
	class SUNFLOWER_API WindowResizeEvent : public Event
	{
	public: 
		WindowResizeEvent(unsigned int width, unsigned int height) : m_width(width), m_height(height){}

		inline unsigned int GetWidth()  const { return m_width; }
		inline unsigned int GetHeight()  const { return m_height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_width << ", " << m_height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_width;
		unsigned int m_height;
	};

	/// <summary>
	/// WindowCloseEvent
	/// </summary>
	/// Handles Window Close Event
	/// <version author="Francisco Sousa" date="8/29/2024" version="2.0"/>
	/// <seealso cref="Event" />
	class SUNFLOWER_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}