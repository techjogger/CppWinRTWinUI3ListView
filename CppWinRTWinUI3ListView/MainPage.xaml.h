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

    public:
        void MainPageListView_DragItemsCompleted(winrt::Microsoft::UI::Xaml::Controls::ListViewBase const& sender, winrt::Microsoft::UI::Xaml::Controls::DragItemsCompletedEventArgs const& args);
        void MainPageListView_DropCompleted(winrt::Microsoft::UI::Xaml::UIElement const& sender, winrt::Microsoft::UI::Xaml::DropCompletedEventArgs const& args);
        void MainPageListView_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e);
        void MainPageListView_DragItemsStarting(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::DragItemsStartingEventArgs const& e);
        winrt::Windows::Foundation::IAsyncAction MainPageListView_Drop(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::DragEventArgs const& e);
    };
}

namespace winrt::CppWinRTWinUI3ListView::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
