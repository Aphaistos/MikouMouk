#pragma once

#include "mkpch.h"

#include "MikouMouk/Core.h"
#include "MikouMouk/Events/Event.h"

namespace MikouMouk {
	struct WindowProperties {
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProperties(
			const std::string& title = "MikouMouk",
			unsigned int width = 1280,
			unsigned int height = 720
			) : title(title), width(width), height(height) {}
	};

	class MIKOUMOUK_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		// Window Attributes
		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* create(const WindowProperties& props = WindowProperties());
	};
}