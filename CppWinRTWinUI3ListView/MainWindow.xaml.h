// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MainWindow.g.h"

namespace winrt::CppWinRTWinUI3ListView::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
        winrt::Microsoft::UI::Windowing::AppWindow MyAppWindow();



        void NavigationView_Loaded(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

    private:

        winrt::Microsoft::UI::Windowing::AppWindow GetAppWindowForCurrentWindow();

        winrt::Microsoft::UI::Windowing::AppWindow m_mainAppWindow{ nullptr };


    };
}

namespace winrt::CppWinRTWinUI3ListView::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
