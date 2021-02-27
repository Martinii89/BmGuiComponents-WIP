#include "pch.h"
#include "ButtonComponent.h"


gui_component::ButtonComponent::ButtonComponent(std::string label, std::shared_ptr<SafeExecutorBase> executor,
                                                std::function<void()> callback): GuiComponent(std::move(label)),
	executor_(std::move(executor)),
	callback(std::move(callback))
{
}

void gui_component::ButtonComponent::Render()
{
	if (ImGui::Button(label_.c_str()))
	{
		executor_->ExecuteSafe(callback);
	}
}
