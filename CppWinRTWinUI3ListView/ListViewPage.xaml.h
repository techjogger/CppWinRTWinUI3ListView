// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "ListViewPage.g.h"

namespace winrt::CppWinRTWinUI3ListView::implementation
{
    struct ListViewPage : ListViewPageT<ListViewPage>
    {
        ListViewPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::CppWinRTWinUI3ListView::factory_implementation
{
    struct ListViewPage : ListViewPageT<ListViewPage, implementation::ListViewPage>
    {
    };
}
