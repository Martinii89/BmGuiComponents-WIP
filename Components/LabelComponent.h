#pragma once
#include "../Base/GuiComponent.h"

namespace gui_component
{
	struct StringFragments
	{
		std::vector<std::string> plaintext;
		std::vector<std::string> cvars;
	};
	
	class LabelComponent: public GuiComponent
	{
	public:
		explicit LabelComponent(std::string label);
		void Render() override;
	private:
		StringFragments customString;
	};
}


