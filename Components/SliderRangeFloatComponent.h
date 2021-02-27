#pragma once
#include <string>
#include "../Base/GuiComponent.h"

namespace gui_component
{
	class CVarComponentBase;

	class SliderRangeFloatComponent : public GuiComponent
	{
	public:

		SliderRangeFloatComponent(std::string label, std::shared_ptr<CVarComponentBase> cvar,
		                          float min, float max, std::string format);

		void Render() override;
	private:
		std::shared_ptr<CVarComponentBase> cvar_;
		std::string format_;
		float min_ = 0;
		float max_ = 100;
	};

	class SliderRangeIntComponent: public SliderRangeFloatComponent
	{
	public:

		SliderRangeIntComponent(std::string label, std::shared_ptr<CVarComponentBase> cvar, float min, float max);
	};
}
