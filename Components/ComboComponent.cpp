#include "pch.h"
#include "../Base/CVarComponentBase.h"
#include "ComboComponent.h"


gui_component::ComboComponent::ComboComponent(std::string label, std::shared_ptr<CVarComponentBase> cvar):
	GuiComponent(std::move(label)),
	cvar_(std::move(cvar))
{
	selected_index = GetSelectedIndex();
}

void gui_component::ComboComponent::Render()
{
	// The value could change from somewhere else, so we need to check this
	selected_index = GetSelectedIndex();
	
	if (ImGui::BeginCombo(label_.c_str(), GetPreviewValue().c_str()))
	{
		for (auto i = 0; i < options_.size(); ++i)
		{
			auto& option = options_[i];
			if (ImGui::Selectable(option.label.c_str(), i == selected_index))
			{
				selected_index = i;
				cvar_->SetStringValue(option.cvar_value);
			}
		}
		ImGui::EndCombo();
	}
}

gui_component::ComboComponent& gui_component::ComboComponent::AddOption(std::string label, std::string cvar_value)
{
	options_.push_back({std::move(label), std::move(cvar_value)});
	return *this;
}

gui_component::ComboComponent& gui_component::ComboComponent::AddOptions(std::vector<ComboItem> options)
{
	options_.insert(options_.end(), options.begin(), options.end());
	return *this;
}

int gui_component::ComboComponent::GetSelectedIndex()
{
	auto current_cvar_value = cvar_->GetStringValue();
	const auto it = std::find_if(options_.begin(), options_.end(),
	                             [&](const ComboItem& item) {return item.cvar_value == current_cvar_value; });
	if (it == options_.end()) return -1;
	return std::distance(options_.begin(), it);
}
