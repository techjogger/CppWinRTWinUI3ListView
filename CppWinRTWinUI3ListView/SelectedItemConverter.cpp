#include "pch.h"
#include "SelectedItemConverter.h"
#if __has_include("SelectedItemConverter.g.cpp")
#include "SelectedItemConverter.g.cpp"
#endif


#include <sstream>

namespace winrt::CppWinRTWinUI3ListView::implementation
{
    Windows::Foundation::IInspectable SelectedItemConverter::Convert(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& /*targetType*/, Windows::Foundation::IInspectable const& /*parameter*/, hstring const& /*language*/)
    {
      


       

        return nullptr;
    }

    Windows::Foundation::IInspectable SelectedItemConverter::ConvertBack(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& /*targetType*/, Windows::Foundation::IInspectable const& /*parameter*/, hstring const& /*language*/)
    {
        return value;
    }
}
