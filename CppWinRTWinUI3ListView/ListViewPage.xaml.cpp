// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "ListViewPage.xaml.h"
#if __has_include("ListViewPage.g.cpp")
#include "ListViewPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::CppWinRTWinUI3ListView::implementation
{
    ListViewPage::ListViewPage()
    {
        InitializeComponent();
    }

    int32_t ListViewPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void ListViewPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void ListViewPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }
}
