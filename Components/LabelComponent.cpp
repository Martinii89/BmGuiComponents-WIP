#include "pch.h"
#include "LabelComponent.h"

gui_component::LabelComponent::LabelComponent(std::string label): GuiComponent(std::move(label))
{
}

void gui_component::LabelComponent::Render()
{
	// todo do the cvar string interpolation
	ImGui::TextUnformatted(label_.c_str());
}
