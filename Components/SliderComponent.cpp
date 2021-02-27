#include "pch.h"
#include "SliderComponent.h"

#include "GuiComponents/Base/CVarComponentBase.h"

gui_component::SliderIntComponent::SliderIntComponent(std::string label, int min, int max,
                                                      std::shared_ptr<CVarComponentBase> cvar):
	GuiComponent(std::move(label)),
	min_(min),
	max_(max),
	cvar_(std::move(cvar))
{
}

void gui_component::SliderIntComponent::Render()
{
	auto value = cvar_->GetIntValue();
	if (ImGui::SliderInt(label_.c_str(), &value, min_, max_))
	{
		cvar_->SetIntValue(std::clamp(value, min_, max_));
	}
}

gui_component::SliderFloatComponent::SliderFloatComponent(std::string label, float min, float max,
                                                          std::shared_ptr<CVarComponentBase> cvar):
	GuiComponent(std::move(label)),
	min_(min),
	max_(max),
	cvar_(std::move(cvar))
{
}

void gui_component::SliderFloatComponent::Render()
{
	auto value = cvar_->GetFloatValue();
	if (ImGui::SliderFloat(label_.c_str(), &value, min_, max_))
	{
		cvar_->SetFloatValue(std::clamp(value, min_, max_));
	}
}
