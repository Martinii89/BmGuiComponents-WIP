#pragma once
#include "../Base/GuiComponent.h"

namespace gui_component
{
	class GrayedOutComponent: public GuiComponent
	{
	public:

		explicit GrayedOutComponent(std::function<bool()> enable_condition);

		void Render() override;
	private:
		std::function<bool()> enable_condition_;
	};
}
