// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "App.xaml.g.h"
#include "MainPage.xaml.h"
namespace winrt::CppWinRTWinUI3ListView::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

        void OnWindowActivationChanged(
            winrt::Windows::Foundation::IInspectable const&,
            winrt::Microsoft::UI::Xaml::WindowActivatedEventArgs const& args
        );

        void OnNavigationFailed(winrt::Windows::Foundation::IInspectable const&, Microsoft::UI::Xaml::Navigation::NavigationFailedEventArgs const& e);

        void NavigateAndCaptureMainPage(winrt::Microsoft::UI::Xaml::Controls::Frame const& rootFrame);

    private:
        winrt::Microsoft::UI::Xaml::Window m_window{ nullptr };

        winrt::CppWinRTWinUI3ListView::MainWindow m_mainWindow{ nullptr };
        winrt::Microsoft::UI::Windowing::AppWindow m_appwindow{ nullptr };

        winrt::com_ptr<winrt::CppWinRTWinUI3ListView::implementation::MainPage> m_MainPageInternal;
        winrt::event_token  m_OnWindowActivationChangedEventToken;


        HWND m_HWnd{ nullptr };
    };
}
