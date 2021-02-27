#include "pch.h"
#include "TabBarComponent.h"

gui_component::TabBarComponent::TabBarComponent(std::string label): GuiComponent(std::move(label))
{
}

void gui_component::TabBarComponent::Render()
{
    if (ImGui::BeginTabBar(label_.c_str(), ImGuiTabBarFlags_NoCloseWithMiddleMouseButton | ImGuiTabBarFlags_NoTooltip))
    {
        GuiComponent::Render();
        ImGui::EndTabBar();
    }
}
