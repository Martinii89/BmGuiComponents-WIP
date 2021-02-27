#include "pch.h"
#include "CheckBoxComponent.h"

void gui_component::CheckBoxComponent::Render()
{
	if (cvar_->IsValid())
	{
		auto b = cvar_->GetBoolValue();
		if (ImGui::Checkbox(label_.c_str(), &b))
		{
			cvar_->SetBoolValue(b);
		}
	}
	else
	{
		ImGui::Text("%s CVar is invalid", label_.c_str());
	}
}
