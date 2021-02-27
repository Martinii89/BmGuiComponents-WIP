#include "pch.h"
#include "GuiComponent.h"

using namespace gui_component;

GuiComponent::GuiComponent(std::string label): label_(std::move(label))
{
}

GuiComponent* GuiComponent::AddComponent(std::shared_ptr<GuiComponent> component)
{
	components_.push_back(std::move(component));
	return this;
}

std::shared_ptr<GuiComponent> GuiComponent::FindComponent(const std::string& label)
{
	for (const auto& comp : components_)
	{
		if (comp->label_ == label)
		{
			return comp;
		}
	}
	return nullptr;
}

std::shared_ptr<GuiComponent> GuiComponent::FindComponent(std::vector<std::string>& path)
{
	if (path.empty()) return nullptr;
	auto comp = FindComponent(path[0]);
	if (!comp) return nullptr;
	path.erase(path.begin());
	if (path.empty()) return comp;
	return comp->FindComponent(path);
}

void GuiComponent::Render()
{
	for (const auto& comp: components_)
	{
		comp->Render();
	}
}
