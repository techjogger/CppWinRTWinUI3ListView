// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
//using namespace winrt::Microsoft::UI::Xaml::Controls::Frame;

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Windowing;




#include "MainPage.xaml.h"
#include <winrt/Windows.UI.Xaml.Interop.h>


// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::CppWinRTWinUI3ListView::implementation
{


    MainWindow::MainWindow()
    {
        InitializeComponent();

        m_mainAppWindow = GetAppWindowForCurrentWindow();

        auto windowNative{ this->try_as<::IWindowNative>() };
        winrt::check_bool(windowNative);

        HWND hWnd{ 0 };
        windowNative->get_WindowHandle(&hWnd);

        //this->Title(m_windowTitle);
    }


    winrt::Microsoft::UI::Windowing::AppWindow MainWindow::MyAppWindow()
    {
        return m_mainAppWindow;
    }

    void MainWindow::NavigationView_Loaded(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {




    }



    

    winrt::Microsoft::UI::Windowing::AppWindow MainWindow::GetAppWindowForCurrentWindow()
    {
        // Get access to IWindowNative
        winrt::CppWinRTWinUI3ListView::MainWindow thisWindow = *this;
        winrt::com_ptr<IWindowNative> windowNative = thisWindow.as<IWindowNative>();

        //Get the HWND for the XAML Window
        HWND hWnd;
        windowNative->get_WindowHandle(&hWnd);

        // Get the WindowId for our window
        winrt::Microsoft::UI::WindowId windowId;
        windowId = winrt::Microsoft::UI::GetWindowIdFromWindow(hWnd);

        // Get the AppWindow for the WindowId
        Microsoft::UI::Windowing::AppWindow appWindow = Microsoft::UI::Windowing::AppWindow::GetFromWindowId(windowId);

        return appWindow;
    }
}
