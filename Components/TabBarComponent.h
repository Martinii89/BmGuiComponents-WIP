#pragma once
#include "../Base/GuiComponent.h"

namespace gui_component
{
	class TabBarComponent: public GuiComponent
	{
	public:

		explicit TabBarComponent(std::string label);

		void Render() override;
	};

}

