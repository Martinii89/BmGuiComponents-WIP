#include "pch.h"
#include "TextInputComponent.h"

#include "GuiComponents/Base/CVarComponentBase.h"


gui_component::TextInputComponent::TextInputComponent(std::string label, std::shared_ptr<CVarComponentBase> cvar):
	GuiComponent(std::move(label)),
	cvar_(std::move(cvar))
{
}

void gui_component::TextInputComponent::Render()
{
	const auto str = cvar_->GetStringValue();
	strcpy_s(text_buffer_, sizeof(text_buffer_), str.c_str());

	if (ImGui::InputText(label_.c_str(), text_buffer_, IM_ARRAYSIZE(text_buffer_)))
	{
		const auto string_buffer = std::string(text_buffer_);
		cvar_->SetStringValue(string_buffer);
	}
}
