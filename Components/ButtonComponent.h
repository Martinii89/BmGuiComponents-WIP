#pragma once
#include "GuiComponents/Base/GuiComponent.h"
#include "GuiComponents/Base/SafeExecutorBase.h"

namespace gui_component
{
	class ButtonComponent: public GuiComponent
	{
	public:
		ButtonComponent(std::string label, std::shared_ptr<SafeExecutorBase> executor, std::function<void()> callback);
		void Render() override;

	private:
		std::shared_ptr<SafeExecutorBase> executor_;
		std::function<void()> callback;
	};

}

