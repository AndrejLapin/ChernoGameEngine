#include "hzpch.h" // probably temporary
#include <Hazel.h>

class Sandobx : public Hazel::Application
{
public:
    Sandobx()
    {

    }

    ~Sandobx()
    {

    }
};

Hazel::Application* Hazel::CreateApplication()
{
    return new Sandobx();
}