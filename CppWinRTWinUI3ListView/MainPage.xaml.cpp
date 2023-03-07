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

        m_DefaultViewModel = winrt::make<CppWinRTWinUI3ListView::implementation::ContactViewModel>();
        MainPageListView().ItemsSource(DefaultViewModel().ContactsList());

    }

    void MainPage::MainPageListView_DragItemsCompleted(winrt::Microsoft::UI::Xaml::Controls::ListViewBase const& sender, winrt::Microsoft::UI::Xaml::Controls::DragItemsCompletedEventArgs const& args)
    {
        UpdateDebugXAMLUI();

           
    }


    void MainPage::MainPageListView_DropCompleted(winrt::Microsoft::UI::Xaml::UIElement const& sender, winrt::Microsoft::UI::Xaml::DropCompletedEventArgs const& args)
    {
        Microsoft::UI::Xaml::Controls::ListView target = sender.as<Microsoft::UI::Xaml::Controls::ListView>();

    }

    void MainPage::MainPageListView_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
    {
        UpdateDebugXAMLUI();
    }


    void  MainPage::UpdateDebugXAMLUI()
    {
        int numofselecteditems = MainPageListView().SelectedItems().Size();
        winrt::hstring itmesHString = winrt::to_hstring(numofselecteditems);
        itmesHString = L"numofselecteditems" + itmesHString + L"\n";


        winrt::Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> items = MainPageListView().SelectedItems();

        int size = MainPageListView().SelectedItems().Size();
        int index = MainPageListView().SelectedIndex();

        winrt::hstring numOfSelected{ L" Number of Selected items: " + winrt::to_hstring(size) };
        winrt::hstring selectedIndex{ L" Selected Index: " + winrt::to_hstring(index) };

       
        if(size > 0) {
            CppWinRTWinUI3ListView::ContactModel model = MainPageListView().SelectedItems().GetAt(0).try_as<CppWinRTWinUI3ListView::ContactModel>();


            NumberOfSelectedItems().Text(numOfSelected);
            SelectedIndexTextBlock().Text(selectedIndex);
            SelectedFirstNameTextBlock().Text(model.FirstName());
            SelectedLastNameTextBlock().Text(model.LastName());

        }
        else {

            NumberOfSelectedItems().Text(L"Null");
            SelectedIndexTextBlock().Text(L"Null");
            SelectedFirstNameTextBlock().Text(L"Null");
            SelectedLastNameTextBlock().Text(L"Null");
        }

       
        

    }
   
}





