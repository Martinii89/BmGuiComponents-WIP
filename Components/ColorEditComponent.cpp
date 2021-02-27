#include "pch.h"
#include "ColorEditComponent.h"

#include "GuiComponents/Base/CVarComponentBase.h"

gui_component::ColorEditComponent::ColorEditComponent(std::string label, std::shared_ptr<CVarComponentBase> cvar):
	GuiComponent(std::move(label)),
	cvar_(std::move(cvar))
{
}

void gui_component::ColorEditComponent::Render()
{
	auto color = cvar_->GetColorValue() / 255;
	if (ImGui::ColorEdit4(label_.c_str(), reinterpret_cast<float*>(&color), ImGuiColorEditFlags_NoInputs))
	{
		cvar_->SetColorValue(color * 255); ////Convert 0-1 range to the more commonly used 0-255 range
	}
}
