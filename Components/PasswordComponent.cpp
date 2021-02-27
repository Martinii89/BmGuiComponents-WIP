#include "pch.h"
#include "PasswordComponent.h"

#include "../Base/CVarComponentBase.h"


gui_component::PasswordComponent::PasswordComponent(std::string label, std::shared_ptr<CVarComponentBase> cvar):
	GuiComponent(std::move(label)),
	cvar_(std::move(cvar))
{
}

void gui_component::PasswordComponent::Render()
{
	const auto str = cvar_->GetStringValue();
	strcpy_s(text_buffer_, sizeof(text_buffer_), str.c_str());

	const auto tex_flag = visible_ ? 0 : ImGuiInputTextFlags_Password;
	if (ImGui::InputText(label_.c_str(), text_buffer_, IM_ARRAYSIZE(text_buffer_), tex_flag))
	{
		const auto string_buffer = std::string(text_buffer_);
		cvar_->SetStringValue(string_buffer);
	}
	ImGui::SameLine();
	const auto lbl = visible_ ? "Hide" : "Show";
	if (ImGui::Button(lbl))
	{
		visible_ = !visible_;
	}
}
