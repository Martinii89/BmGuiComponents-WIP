#include "pch.h"
#include "AnonymousComponent.h"

gui_component::AnonymousComponent::AnonymousComponent(std::function<void()> callback): callback_(std::move(callback))
{
}

void gui_component::AnonymousComponent::Render()
{
	callback_();
}
