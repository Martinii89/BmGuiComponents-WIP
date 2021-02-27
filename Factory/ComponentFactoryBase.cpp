#include "pch.h"
#include "ComponentFactoryBase.h"

#include "../GuiComponents.h"

std::shared_ptr<gui_component::CheckBoxComponent> gui_component::ComponentFactoryBase::CheckBoxComponent(
	const std::string& label, const std::string& cvar_name)
{
	return std::make_shared<class CheckBoxComponent>(label, CvarComponent(cvar_name));
}

std::shared_ptr<gui_component::ButtonComponent> gui_component::ComponentFactoryBase::ButtonComponent(
	const std::string& label, std::function<void()> callback)
{
	return std::make_shared<class ButtonComponent>(label, CallbackComponent(), std::move(callback));
}

std::shared_ptr<gui_component::TabBarComponent> gui_component::ComponentFactoryBase::TabBarComponent(
	const std::string& label) const
{
	return std::make_shared<class TabBarComponent>(label);
}

std::shared_ptr<gui_component::TabBarItemComponent> gui_component::ComponentFactoryBase::TabBarItemComponent(
	const std::string& label) const
{
	return std::make_shared<class TabBarItemComponent>(label);
}

std::shared_ptr<gui_component::LabelComponent> gui_component::ComponentFactoryBase::LabelComponent(
	const std::string& label) const
{
	return std::make_shared<class LabelComponent>(label);
}

std::shared_ptr<gui_component::SameLineComponent> gui_component::ComponentFactoryBase::SameLineComponent(
) const
{
	return std::make_shared<class SameLineComponent>();
}

std::shared_ptr<gui_component::SeparatorComponent> gui_component::ComponentFactoryBase::SeparatorComponent(
) const
{
	return std::make_shared<class SeparatorComponent>();
}

std::shared_ptr<gui_component::GrayedOutComponent> gui_component::ComponentFactoryBase::GrayedOutComponent(
	std::function<bool()> enable_condition) const
{
	return std::make_shared<class GrayedOutComponent>(std::move(enable_condition));
}

std::shared_ptr<gui_component::SliderRangeFloatComponent> gui_component::ComponentFactoryBase::
SliderRangeFloatComponent(const std::string& label, const std::string& cvar_name, float min, float max,
                          const std::string& format) const
{
	return std::make_shared<class SliderRangeFloatComponent>(label, CvarComponent(cvar_name), min, max, format);
}

std::shared_ptr<gui_component::SliderRangeIntComponent> gui_component::ComponentFactoryBase::SliderRangeIntComponent(
	const std::string& label, const std::string& cvar_name, float min, float max) const
{
	return std::make_shared<class SliderRangeIntComponent>(label, CvarComponent(cvar_name), min, max);
}

std::shared_ptr<gui_component::ComboComponent> gui_component::ComponentFactoryBase::ComboComponent(
	const std::string& label, const std::string& cvar_name) const
{
	return std::make_shared<class ComboComponent>(label, CvarComponent(cvar_name));
}

std::shared_ptr<gui_component::TextInputComponent> gui_component::ComponentFactoryBase::TextInputComponent(
	const std::string& label, const std::string& cvar_name) const
{
	return std::make_shared<class TextInputComponent>(label, CvarComponent(cvar_name));
}

std::shared_ptr<gui_component::PasswordComponent> gui_component::ComponentFactoryBase::PasswordComponent(
	const std::string& label, const std::string& cvar_name) const
{
	return std::make_shared<class PasswordComponent>(label, CvarComponent(cvar_name));
}

std::shared_ptr<gui_component::ColorEditComponent> gui_component::ComponentFactoryBase::ColorEditComponent(
	const std::string& label, const std::string& cvar_name) const
{
	return std::make_shared<class ColorEditComponent>(label, CvarComponent(cvar_name));

}

std::shared_ptr<gui_component::SliderIntComponent> gui_component::ComponentFactoryBase::SliderIntComponent(
	const std::string& label, const std::string& cvar_name, int min, int max) const
{
	return std::make_shared<class SliderIntComponent>(label, min, max, CvarComponent(cvar_name) );
}

std::shared_ptr<gui_component::SliderFloatComponent> gui_component::ComponentFactoryBase::SliderFloatComponent(
	const std::string& label, const std::string& cvar_name, float min, float max) const
{
	return std::make_shared<class SliderFloatComponent>(label, min, max, CvarComponent(cvar_name));
}

std::shared_ptr<gui_component::AnonymousComponent> gui_component::ComponentFactoryBase::AnonymousComponent(
	std::function<void()> callback) const
{
	return std::make_shared<class AnonymousComponent>(std::move(callback));
}
