#pragma once

#include "Hazel//Input.h"

namespace Hazel
{
    class WindowsInput : public Input
    {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;
        virtual bool IsMousButtonPressedImpl(int button) override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;

        virtual Vector2 GetMousePositionImpl() override;
    };
}