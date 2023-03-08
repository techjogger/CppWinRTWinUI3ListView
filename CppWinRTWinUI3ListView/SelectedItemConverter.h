#pragma once

#include "SelectedItemConverter.g.h"

namespace winrt::CppWinRTWinUI3ListView::implementation
{
    struct SelectedItemConverter : SelectedItemConverterT<SelectedItemConverter>
    {
        SelectedItemConverter() = default;

        Windows::Foundation::IInspectable Convert(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& targetType, Windows::Foundation::IInspectable const& parameter, hstring const& language);
        Windows::Foundation::IInspectable ConvertBack(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& targetType, Windows::Foundation::IInspectable const& parameter, hstring const& language);
    };
}

namespace winrt::CppWinRTWinUI3ListView::factory_implementation
{
    struct SelectedItemConverter : SelectedItemConverterT<SelectedItemConverter, implementation::SelectedItemConverter>
    {
    };
}
