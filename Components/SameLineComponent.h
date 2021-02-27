#pragma once
#include "../Base/GuiComponent.h"

namespace gui_component
{
	//      offset_from_start_x == 0 : follow right after previous item
	//      offset_from_start_x != 0 : align to specified x position (relative to window/group left)
	//      spacing_w < 0            : use default spacing if pos_x == 0, no spacing if pos_x != 0
	//      spacing_w >= 0           : enforce spacing amount
	class SameLineComponent: public GuiComponent
	{
	public:
		explicit SameLineComponent(float offset_from_start_x = 0, float spacing_w = 0);

		void Render() override;
	private:
		float offset_from_start_x = 0;
		float spacing_w = 0;
	};
}
