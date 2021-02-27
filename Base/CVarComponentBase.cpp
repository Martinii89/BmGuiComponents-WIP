#include "pch.h"
#include "CVarComponentBase.h"

gui_component::CVarComponentBase::CVarComponentBase(const std::string& cvar_name,
                                                    std::shared_ptr<SafeExecutorBase> safe_executor):
	cvar_name_(cvar_name), safe_executor_(safe_executor)
{
}

const std::string& gui_component::CVarComponentBase::GetCvarName() const
{
	return cvar_name_;
}
