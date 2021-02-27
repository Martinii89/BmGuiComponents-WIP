#pragma once
#include "../Base/GuiComponent.h"

namespace gui_component
{
	class TabBarItemComponent: public GuiComponent
	{
	public:
		explicit TabBarItemComponent(std::string label);
		void Render() override;
	};

}

