#include "pch.h"
#include "ComponentFactory.h"

#include "CVarComponent.h"

gui_component::plugin::ComponentFactory::ComponentFactory(std::shared_ptr<CVarManagerWrapper> cw,
	std::shared_ptr<GameWrapper> gw) : cw_(std::move(cw)),
	gw_(std::move(gw))
{
	safe_executor_ = std::make_shared<SafeExecutor>(gw_);
}

std::shared_ptr<gui_component::CVarComponentBase> gui_component::plugin::ComponentFactory::CvarComponent(
	const std::string& cvar_name) const
{
	return std::make_shared<CVarComponent>(cvar_name, cw_.get(), CallbackComponent());
}


std::shared_ptr<gui_component::SafeExecutorBase> gui_component::plugin::ComponentFactory::CallbackComponent() const
{
	return safe_executor_;
}
