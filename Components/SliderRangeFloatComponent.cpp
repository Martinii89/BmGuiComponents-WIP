#include "pch.h"
#include "SliderRangeFloatComponent.h"

#include <utils/parser.h>

#include "GuiComponents/Base/CVarComponentBase.h"
#include "imgui/imgui_rangeslider.h"

gui_component::SliderRangeFloatComponent::SliderRangeFloatComponent(std::string label,
                                                                    std::shared_ptr<CVarComponentBase> cvar,
                                                                    float min, float max, std::string format):
	GuiComponent(std::move(label)),
	cvar_(std::move(cvar)),
	format_(std::move(format)),
	min_(min),
	max_(max)
{
}

void gui_component::SliderRangeFloatComponent::Render()
{
	const auto string_val = cvar_->GetStringValue();
	float bottom;
	float top;
	if (is_parsable(string_val))
	{
		const auto lower = string_val.substr(1, string_val.find(',') - 1);
		auto upper = string_val.substr(string_val.find(',') + 1);
		upper = upper.substr(0, upper.size() - 1);
		bottom = std::stof(lower);
		top = std::stof(upper);
		if (bottom > top)
		{
			std::swap(top, bottom);
		}
	}
	else
	{
		top = std::stof(string_val);
		bottom = top;
	}
	if (ImGui::RangeSliderFloat(label_.c_str(), &bottom, &top, min_, max_, format_.c_str()))
	{
		const auto new_value = "(" + std::to_string(bottom) + ", " + std::to_string(top) + ")";
		cvar_->SetStringValue(new_value);
	}
}

gui_component::SliderRangeIntComponent::SliderRangeIntComponent(std::string label,
                                                                std::shared_ptr<CVarComponentBase> cvar, float min,
                                                                float max)
	: SliderRangeFloatComponent(std::move(label), std::move(cvar), min, max, "(%.0f, %.0f)")
{
}
