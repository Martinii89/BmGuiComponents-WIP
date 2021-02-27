#pragma once
#include "../Base/GuiComponent.h"

namespace gui_component
{
	class CVarComponentBase;

	class SliderIntComponent : public GuiComponent
	{
	public:
		SliderIntComponent(std::string label, int min, int max, std::shared_ptr<CVarComponentBase> cvar);
		void Render() override;
	private:
		int min_;
		int max_;
		std::shared_ptr<CVarComponentBase> cvar_;
	};

	class SliderFloatComponent : public GuiComponent
	{
	public:
		SliderFloatComponent(std::string label, float min, float max, std::shared_ptr<CVarComponentBase> cvar);
		void Render() override;
	private:
		float min_;
		float max_;
		std::shared_ptr<CVarComponentBase> cvar_;
	};
}
