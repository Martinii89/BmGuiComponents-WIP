#include "pch.h"
#include "SafeExecutor.h"

gui_component::plugin::SafeExecutor::SafeExecutor(std::shared_ptr<GameWrapper> gw): gw_(std::move(gw))
{
}

void gui_component::plugin::SafeExecutor::ExecuteSafe(std::function<void()> callback)
{
	gw_->Execute([f = std::move(callback)](...){f(); });
}
