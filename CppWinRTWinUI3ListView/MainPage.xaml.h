// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MainPage.g.h"

namespace winrt::CppWinRTWinUI3ListView::implementation
{
    struct MainPage : MainPageT<MainPage>
    {

    private:
        winrt::Microsoft::UI::Windowing::AppWindow m_mainAppWindow{ nullptr };
    public:
        MainPage();



        void OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

   


    };
}

namespace winrt::CppWinRTWinUI3ListView::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
