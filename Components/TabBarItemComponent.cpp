#include "pch.h"
#include "TabBarItemComponent.h"

gui_component::TabBarItemComponent::TabBarItemComponent(std::string label): GuiComponent(std::move(label))
{
}

void gui_component::TabBarItemComponent::Render()
{
	if (ImGui::BeginTabItem(label_.c_str()))
	{
		GuiComponent::Render();
		ImGui::EndTabItem();
	}
}
