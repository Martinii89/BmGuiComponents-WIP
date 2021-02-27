#include "pch.h"
#include "GrayedOutComponent.h"
#include "IMGUI/imgui_internal.h"

gui_component::GrayedOutComponent::GrayedOutComponent(std::function<bool()> enable_condition): enable_condition_(
	std::move(enable_condition))
{
}

void gui_component::GrayedOutComponent::Render()
{
	const auto gray = enable_condition_();
	if (!gray)
	{
		ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
		ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.5f);
	}

	GuiComponent::Render();

	if (!gray)
	{
		ImGui::PopItemFlag();
		ImGui::PopStyleVar();
	}
}
