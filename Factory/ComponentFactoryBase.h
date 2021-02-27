#pragma once
#include <memory>
#include <string>

// include instead of forward declaration so users of these can correctly cast the shared_ptr<T> to a shared_ptr<GuiComponent> 
#include "../GuiComponents.h"

namespace gui_component
{
	class ComponentFactoryBase
	{
	public:
		ComponentFactoryBase() = default;
		ComponentFactoryBase(const ComponentFactoryBase& other) = default;
		ComponentFactoryBase(ComponentFactoryBase&& other) noexcept = default;
		ComponentFactoryBase& operator=(const ComponentFactoryBase& other) = default;
		ComponentFactoryBase& operator=(ComponentFactoryBase&& other) noexcept = default;
		virtual ~ComponentFactoryBase() = default;
		
		_NODISCARD std::shared_ptr<CheckBoxComponent> CheckBoxComponent(const std::string& label, const std::string& cvar_name);
		_NODISCARD std::shared_ptr<ButtonComponent> ButtonComponent(const std::string& label, std::function<void()> callback);
		_NODISCARD std::shared_ptr<TabBarComponent> TabBarComponent(const std::string& label) const;
		_NODISCARD std::shared_ptr<TabBarItemComponent> TabBarItemComponent(const std::string& label) const;
		_NODISCARD std::shared_ptr<LabelComponent> LabelComponent(const std::string& label) const;
		_NODISCARD std::shared_ptr<SameLineComponent> SameLineComponent() const;
		_NODISCARD std::shared_ptr<SeparatorComponent> SeparatorComponent() const;
		_NODISCARD std::shared_ptr<GrayedOutComponent> GrayedOutComponent(std::function<bool()> enable_condition) const;
		_NODISCARD std::shared_ptr<SliderRangeFloatComponent> SliderRangeFloatComponent(const std::string& label, const std::string& cvar_name,float min, float max, const std::string& format = "(% .3f, % .3f)") const;
		_NODISCARD std::shared_ptr<SliderRangeIntComponent> SliderRangeIntComponent(const std::string& label, const std::string& cvar_name,float min, float max) const;
		_NODISCARD std::shared_ptr<ComboComponent> ComboComponent(const std::string& label, const std::string& cvar_name) const;
		_NODISCARD std::shared_ptr<TextInputComponent> TextInputComponent(const std::string& label, const std::string& cvar_name) const;
		_NODISCARD std::shared_ptr<PasswordComponent> PasswordComponent(const std::string& label, const std::string& cvar_name) const;
		_NODISCARD std::shared_ptr<ColorEditComponent> ColorEditComponent(const std::string& label, const std::string& cvar_name) const;
		_NODISCARD std::shared_ptr<SliderIntComponent> SliderIntComponent(const std::string& label, const std::string& cvar_name, int min, int max) const;
		_NODISCARD std::shared_ptr<SliderFloatComponent> SliderFloatComponent(const std::string& label, const std::string& cvar_name, float min, float max) const;
		_NODISCARD std::shared_ptr<AnonymousComponent> AnonymousComponent(std::function<void()> callback) const;
	private:
		_NODISCARD virtual std::shared_ptr<CVarComponentBase> CvarComponent(const std::string& cvar_name) const = 0;
		_NODISCARD virtual std::shared_ptr<SafeExecutorBase> CallbackComponent() const = 0;
	};
}



