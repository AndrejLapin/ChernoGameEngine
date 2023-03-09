#include "hzpch.h"
#include "Application.h"

// TEMPORARY
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Input.h"

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        HZ_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application()
    {
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer)
    {
        m_LayerStack.PushOverLay(layer);
        layer->OnAttach();
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowCLosed));

        HZ_CORE_INFO("{0}", e);

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(e);
            if (e.m_Handled)
                break;
        }
    }

    void Application::Run()
    {
        while (m_Running)
        {
            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();

            Vector2 mousePos = Input::GetMousePosition();
            HZ_CORE_TRACE("{0}, {1}", mousePos.x, mousePos.y);

            m_Window->OnUpdate();
            glClear(GL_COLOR_BUFFER_BIT);
        }
    }

    bool Application::OnWindowCLosed(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }
}