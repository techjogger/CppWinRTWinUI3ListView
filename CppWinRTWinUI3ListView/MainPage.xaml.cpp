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

        if (MainPageListView().SelectedItem() != nullptr)
        {
            selectedItemFirstNameTextBlock().Text(L"Selected item First Name: " + MainPageListView().SelectedItem().as<CppWinRTWinUI3ListView::ContactModel>().FirstName());
            selectedItemLastNameTextBlock().Text(L"Selected item Last Name: " + MainPageListView().SelectedItem().as<CppWinRTWinUI3ListView::ContactModel>().LastName());

        }
        else
        {
            selectedItemFirstNameTextBlock().Text(L"Selected item First Name: NULL");
            selectedItemLastNameTextBlock().Text(L"Selected item Last Name: NULL");

        }

        int index = MainPageListView().SelectedIndex();
        int size = MainPageListView().SelectedItems().Size();

        winrt::hstring selectedIndextext{ L" Selected Index: " + winrt::to_hstring(index) };
        winrt::hstring numOfSelected{ L" Items selected: " + winrt::to_hstring(size) };


        selectedIndexTextBlock().Text(selectedIndextext);
        selectedItemCountTextBlock().Text(numOfSelected);

      

        winrt::hstring Addedtext{ L"Added: NULL" };
        winrt::hstring Removedtext{ L"Removed:  NULL"};


        addedItemsTextBlock().Text(Addedtext);
        removedItemsTextBlock().Text(Removedtext);


       

           
    }


    winrt::Windows::Foundation::IAsyncAction MainPage::MainPageListView_Drop(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::DragEventArgs const& e)
    {
        if (e.DataView().Contains(winrt::Windows::ApplicationModel::DataTransfer::StandardDataFormats::Text()))
        {
            // We need to take the deferral as the source will read _deletedItem which
            // we cannot set synchronously
            auto def = e.GetDeferral();

            winrt::hstring item = co_await e.DataView().GetTextAsync();


            e.AcceptedOperation(winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation::Move);
            def.Complete();

           
        }
    }

    void MainPage::MainPageListView_DropCompleted(winrt::Microsoft::UI::Xaml::UIElement const& sender, winrt::Microsoft::UI::Xaml::DropCompletedEventArgs const& args)
    {
        Microsoft::UI::Xaml::Controls::ListView target = sender.as<Microsoft::UI::Xaml::Controls::ListView>();

    }

    void MainPage::MainPageListView_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
    {

        if (MainPageListView().SelectedItem() != nullptr)
        {
            selectedItemFirstNameTextBlock().Text(L"Selected item First Name: " + MainPageListView().SelectedItem().as<CppWinRTWinUI3ListView::ContactModel>().FirstName());
            selectedItemLastNameTextBlock().Text(L"Selected item Last Name: " + MainPageListView().SelectedItem().as<CppWinRTWinUI3ListView::ContactModel>().LastName());

        }
        else
        {
            selectedItemFirstNameTextBlock().Text(L"Selected item First Name: NULL");
            selectedItemLastNameTextBlock().Text(L"Selected item Last Name: NULL" );
            
        }

        int index = MainPageListView().SelectedIndex();
        int size = MainPageListView().SelectedItems().Size();

        winrt::hstring selectedIndextext{ L" Selected Index: " + winrt::to_hstring(index) };
        winrt::hstring numOfSelected{ L" Items selected: " + winrt::to_hstring(size) };


        selectedIndexTextBlock().Text(selectedIndextext);
        selectedItemCountTextBlock().Text(numOfSelected);

        int Added = e.AddedItems().Size();
        int Removed = e.RemovedItems().Size();

        winrt::hstring Addedtext{ L"Added: " + winrt::to_hstring(Added) };
        winrt::hstring Removedtext{ L"Removed: " + winrt::to_hstring(Removed) };


        addedItemsTextBlock().Text(Addedtext);
        removedItemsTextBlock().Text(Removedtext);


        
    }


   

    void MainPage::MainPageListView_DragItemsStarting(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::DragItemsStartingEventArgs const& e)
    {
        if (e.Items().Size() == 1)
        {
            winrt::Windows::Foundation::IInspectable temp = e.Items().GetAt(0);
            CppWinRTWinUI3ListView::ContactModel cm = temp.as<CppWinRTWinUI3ListView::ContactModel>();

            winrt::hstring fName = cm.FirstName();
           // winrt::hstring value = unbox_value<winrt::hstring>(cm.);
            e.Data().SetText(fName);


           // e.Data().SetText(dynamic_cast<String^>());
            //// Reorder or move to trash are always a move
            //e->Data->RequestedOperation = DataPackageOperation::Move;
            //_deletedItem = nullptr;
        }
    }
   
}











