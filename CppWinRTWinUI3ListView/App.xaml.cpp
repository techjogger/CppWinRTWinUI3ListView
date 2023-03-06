// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"

#include "App.xaml.h"
#include "MainWindow.xaml.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Navigation;
using namespace CppWinRTWinUI3ListView;
using namespace CppWinRTWinUI3ListView::implementation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

/// <summary>
/// Initializes the singleton application object.  This is the first line of authored code
/// executed, and as such is the logical equivalent of main() or WinMain().
/// </summary>
App::App()
{
    InitializeComponent();

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
    UnhandledException([this](IInspectable const&, UnhandledExceptionEventArgs const& e)
    {
        if (IsDebuggerPresent())
        {
            auto errorMessage = e.Message();
            __debugbreak();
        }
    });
#endif
}

/// <summary>
/// Invoked when the application is launched.
/// </summary>
/// <param name="e">Details about the launch request and process.</param>
void App::OnLaunched(LaunchActivatedEventArgs const&)
{
    try {
        m_window = make<MainWindow>();

        m_mainWindow =
            m_window.as<winrt::CppWinRTWinUI3ListView::MainWindow>();

        m_appwindow = m_mainWindow.MyAppWindow();

        auto windowNative{ m_mainWindow.try_as<IWindowNative>() };
        winrt::check_bool(windowNative);
        windowNative->get_WindowHandle(&m_HWnd);


        auto& currentXAMLWindow = m_window;


        m_OnWindowActivationChangedEventToken = currentXAMLWindow.Activated({ this, &App::OnWindowActivationChanged });


        Microsoft::UI::Xaml::Controls::Frame rootFrame{ nullptr };
        auto content = currentXAMLWindow.Content();
        if (content)
        {
            rootFrame = content.try_as<Microsoft::UI::Xaml::Controls::Frame>();
        }

        if (rootFrame == nullptr)
        {

            rootFrame = Microsoft::UI::Xaml::Controls::Frame();

            rootFrame.NavigationFailed({ this, &App::OnNavigationFailed });

            

            NavigateAndCaptureMainPage(rootFrame);

            // Place the frame in the current Window
            currentXAMLWindow.Content(rootFrame);
            // Ensure the current window is active
            currentXAMLWindow.Activate();

            
        }
        else
        {
            NavigateAndCaptureMainPage(rootFrame);

            // Ensure the current window is active
            currentXAMLWindow.Activate();


        }

       
       
    }
    catch (winrt::hresult const& error)
    {


    }
   
}


void App::NavigateAndCaptureMainPage(winrt::Microsoft::UI::Xaml::Controls::Frame const& rootFrame)
{
    if (rootFrame.Content() == nullptr)
    {
        // When the navigation stack isn't restored navigate to the first page,
        // configuring the new page by passing required information as a navigation
        // parameter


        if (!rootFrame.Content())
        {
            rootFrame.Navigate(xaml_typename<winrt::CppWinRTWinUI3ListView::MainPage>());
        }

        m_window.Activate();


        auto mainPageContent = rootFrame.Content();
        if (mainPageContent)
        {
            CppWinRTWinUI3ListView::MainPage theMainPage{ nullptr };

            theMainPage = mainPageContent.try_as<CppWinRTWinUI3ListView::MainPage>();

            m_MainPageInternal.copy_from(winrt::get_self<winrt::CppWinRTWinUI3ListView::implementation::MainPage>(theMainPage));
        }
    }
    else
    {
        rootFrame.Navigate(xaml_typename<CppWinRTWinUI3ListView::MainPage>());
    }
}


void App::OnWindowActivationChanged(
    winrt::Windows::Foundation::IInspectable const&,
    winrt::Microsoft::UI::Xaml::WindowActivatedEventArgs const& args)
{


}


void App::OnNavigationFailed(winrt::Windows::Foundation::IInspectable const&, Microsoft::UI::Xaml::Navigation::NavigationFailedEventArgs const& e)
{
    throw hresult_error(E_FAIL, hstring(L"Failed to load Page ") + e.SourcePageType().Name);
}

