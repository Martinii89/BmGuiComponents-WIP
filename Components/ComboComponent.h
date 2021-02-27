#pragma once
#include <string>
#include <vector>
#include "../Base/GuiComponent.h"

namespace gui_component
{
	class CVarComponentBase;

	class ComboComponent: public GuiComponent
	{
	public:
		ComboComponent(std::string label, std::shared_ptr<CVarComponentBase> cvar);
		struct ComboItem
		{
			std::string label;
			std::string cvar_value;
		};
		void Render() override;
		ComboComponent& AddOption(std::string label, std::string cvar_value);
		ComboComponent& AddOptions(std::vector<ComboItem>);
	
	private:
		int selected_index = -1;
		std::vector<ComboItem> options_;
		std::shared_ptr<CVarComponentBase> cvar_;

		std::string GetPreviewValue();
		int GetSelectedIndex();
		
	};

	inline std::string ComboComponent::GetPreviewValue()
	{
		if (selected_index < 0 || selected_index >= options_.size()) return "";
		return options_[selected_index].label;
	}
}
