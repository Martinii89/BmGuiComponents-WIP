#pragma once
#include "SafeExecutor.h"
#include "GuiComponents/Factory/ComponentFactoryBase.h"

namespace gui_component::plugin
{
	class ComponentFactory : public ComponentFactoryBase
	{
	public:
		ComponentFactory(std::shared_ptr<CVarManagerWrapper> cw, std::shared_ptr<GameWrapper> gw);

	private:
		std::shared_ptr<CVarManagerWrapper> cw_;
		std::shared_ptr<GameWrapper> gw_;
		std::shared_ptr<SafeExecutor> safe_executor_;
		
		std::shared_ptr<CVarComponentBase> CvarComponent(const std::string& cvar_name) const override;
		std::shared_ptr<SafeExecutorBase> CallbackComponent() const override;
	};

}

