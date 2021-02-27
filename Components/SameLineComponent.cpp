#include "pch.h"
#include "SameLineComponent.h"

gui_component::SameLineComponent::SameLineComponent(float offset_from_start_x, float spacing_w):
	offset_from_start_x(offset_from_start_x),
	spacing_w(spacing_w)
{
}

void gui_component::SameLineComponent::Render()
{
	ImGui::SameLine(offset_from_start_x, spacing_w);
}
