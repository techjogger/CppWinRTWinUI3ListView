// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MainPage.g.h"
#include "ContactViewModel.h"
namespace winrt::CppWinRTWinUI3ListView::implementation
{
    struct MainPage : MainPageT<MainPage>
    {

    private:
        winrt::Microsoft::UI::Windowing::AppWindow m_mainAppWindow{ nullptr };
    public:
        MainPage();



        void OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

   
        // Retreives collection of Photo objects for thumbnail view.
        CppWinRTWinUI3ListView::ContactViewModel DefaultViewModel()
        {
            return m_DefaultViewModel;
        };
        
    private:

        CppWinRTWinUI3ListView::ContactViewModel m_DefaultViewModel{ nullptr };

    };
}

namespace winrt::CppWinRTWinUI3ListView::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
