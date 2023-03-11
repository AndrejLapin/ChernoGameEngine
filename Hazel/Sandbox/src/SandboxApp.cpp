#include <Hazel.h>

class ExampleLayer : public Hazel::Layer 
{
public:
    ExampleLayer()
        :Layer("Example")
    {
    }

    void OnUpdate() override
    {
        //HZ_INFO("ExampleLayer::Update");

        if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
            HZ_TRACE("Tab key is pressed!");
    }

    void OnEvent(Hazel::Event& event) override
    {
        //HZ_TRACE("{0}", event);
    }
};

class Sandobx : public Hazel::Application
{
public:
    Sandobx()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Hazel::ImGuiLayer());
    }

    ~Sandobx()
    {

    }
};

Hazel::Application* Hazel::CreateApplication()
{
    return new Sandobx();
}