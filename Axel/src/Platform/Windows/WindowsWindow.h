#pragma once

#include "Axel/Window.h"
#include "Axel/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Axel {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return m_data.width; }
		inline unsigned int getHeight() const override { return m_data.height; }

		// Window attributes
		inline void setEventCallback(const EventCallbackFn& callback) override { m_data.eventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;

		inline virtual void* getNativeWindow() const { return m_window; }
	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();
	private:
		GLFWwindow* m_window;
		GraphicsContext* m_context;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData m_data;
	};
}