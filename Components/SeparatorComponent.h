#pragma once

#include "../Base/GuiComponent.h"

namespace gui_component
{
	class SeparatorComponent: public GuiComponent
	{
	public:
		void Render() override;
	};
}