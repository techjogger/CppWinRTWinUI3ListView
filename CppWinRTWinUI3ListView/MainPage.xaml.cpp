// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif
#include <MainWindow.xaml.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Windowing;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::CppWinRTWinUI3ListView::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }


    void MainPage::OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
    {

       /* winrt::Microsoft::UI::Xaml::Window window = e.Parameter().as<Microsoft::UI::Xaml::Window>();
        winrt::CppWinRTWinUI3ListView::MainWindow mainWindow = window.as<winrt::CppWinRTWinUI3ListView::MainWindow>();
        AppWindow appWindow = mainWindow.MyAppWindow();
        m_mainAppWindow = appWindow;*/

    }

   
}
