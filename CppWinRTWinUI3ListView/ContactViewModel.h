#pragma once

#include "ContactViewModel.g.h"
#include "ContactModel.h"

namespace winrt::CppWinRTWinUI3ListView::implementation
{
    struct ContactViewModel : ContactViewModelT<ContactViewModel>
    {
        ContactViewModel();

        Windows::Foundation::Collections::IObservableVector<CppWinRTWinUI3ListView::ContactModel> ContactsList()
        {

            return m_ContactsList;
        };

    private:

        Windows::Foundation::Collections::IObservableVector<CppWinRTWinUI3ListView::ContactModel> m_ContactsList {nullptr};


    };
}

namespace winrt::CppWinRTWinUI3ListView::factory_implementation
{
    struct ContactViewModel : ContactViewModelT<ContactViewModel, implementation::ContactViewModel>
    {
    };
}
