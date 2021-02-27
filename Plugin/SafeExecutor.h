#pragma once
#include "GuiComponents/Base/SafeExecutorBase.h"

namespace gui_component::plugin
{
	class SafeExecutor: public SafeExecutorBase
	{
	public:
		explicit SafeExecutor(std::shared_ptr<GameWrapper> gw);

		void ExecuteSafe(std::function<void()> callback) override;
	private:
		std::shared_ptr<GameWrapper> gw_;
	};

}

