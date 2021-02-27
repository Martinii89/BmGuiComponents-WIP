#include "pch.h"
#include "../Base/SafeExecutorBase.h"
#include "CVarComponent.h"


gui_component::plugin::CVarComponent::CVarComponent(const std::string& cvar_name, CVarManagerWrapper* cvar_manager,
                                                    std::shared_ptr<SafeExecutorBase> safe_executor):
	CVarComponentBase(cvar_name, safe_executor),
	cvar_(cvar_manager->getCvar(cvar_name))
{
}

gui_component::plugin::CVarComponent::CVarComponent(CVarWrapper cvar, std::shared_ptr<SafeExecutorBase> safe_executor):
	CVarComponentBase(cvar.IsNull() ? "invalid cvar" : cvar.getCVarName(), safe_executor),
	cvar_(cvar)
{
}

bool gui_component::plugin::CVarComponent::IsValid()
{
	return !cvar_.IsNull();
}

int gui_component::plugin::CVarComponent::GetIntValue()
{
	return cvar_.getIntValue();
}

float gui_component::plugin::CVarComponent::GetFloatValue()
{
	return cvar_.getFloatValue();
}

bool gui_component::plugin::CVarComponent::GetBoolValue()
{
	return cvar_.getBoolValue();
}

LinearColor gui_component::plugin::CVarComponent::GetColorValue()
{
	return cvar_.getColorValue();
}

std::string gui_component::plugin::CVarComponent::GetStringValue()
{
	return cvar_.getStringValue();
}

void gui_component::plugin::CVarComponent::SetIntValue(int value)
{
	safe_executor_->ExecuteSafe([this, value](...) { cvar_.setValue(value); });
}

void gui_component::plugin::CVarComponent::SetFloatValue(float value)
{
	safe_executor_->ExecuteSafe([this, value](...) { cvar_.setValue(value); });
}

void gui_component::plugin::CVarComponent::SetBoolValue(bool value)
{
	safe_executor_->ExecuteSafe([this, value](...) { cvar_.setValue(value); });
}

void gui_component::plugin::CVarComponent::SetColorValue(LinearColor value)
{
	safe_executor_->ExecuteSafe([this, value](...) { cvar_.setValue(value); });
}

void gui_component::plugin::CVarComponent::SetStringValue(std::string value)
{
	safe_executor_->ExecuteSafe([this, value](...) { cvar_.setValue(value); });
}
