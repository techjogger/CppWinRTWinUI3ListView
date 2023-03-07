#include "pch.h"
#include "ContactViewModel.h"
#if __has_include("ContactViewModel.g.cpp")
#include "ContactViewModel.g.cpp"
#endif

namespace winrt::CppWinRTWinUI3ListView::implementation
{
     ContactViewModel::ContactViewModel() : m_ContactsList(winrt::single_threaded_observable_vector<CppWinRTWinUI3ListView::ContactModel>())
    {

         CppWinRTWinUI3ListView::ContactModel	contact1 = winrt::make<CppWinRTWinUI3ListView::implementation::ContactModel>(L"JAMES",L"SMITH ");

         CppWinRTWinUI3ListView::ContactModel	contact2 = winrt::make<CppWinRTWinUI3ListView::implementation::ContactModel>(L"JOHN", L"JOHNSON ");
         CppWinRTWinUI3ListView::ContactModel	contact3 = winrt::make<CppWinRTWinUI3ListView::implementation::ContactModel>(L"ROBERT", L"WILLIAMS ");
         CppWinRTWinUI3ListView::ContactModel	contact4 = winrt::make<CppWinRTWinUI3ListView::implementation::ContactModel>(L"MICHAEL", L"BROWN ");
         CppWinRTWinUI3ListView::ContactModel	contact5 = winrt::make<CppWinRTWinUI3ListView::implementation::ContactModel>(L"WILLIAM", L"JONES ");

         CppWinRTWinUI3ListView::ContactModel	contact6 = winrt::make<CppWinRTWinUI3ListView::implementation::ContactModel>(L"MARY", L"SMITH ");
         CppWinRTWinUI3ListView::ContactModel	contact7 = winrt::make<CppWinRTWinUI3ListView::implementation::ContactModel>(L"PATRICIA", L"JOHNSON ");
         CppWinRTWinUI3ListView::ContactModel	contact8 = winrt::make<CppWinRTWinUI3ListView::implementation::ContactModel>(L"LINDA", L"WILLIAMS ");
         CppWinRTWinUI3ListView::ContactModel	contact9 = winrt::make<CppWinRTWinUI3ListView::implementation::ContactModel>(L"BARBARA", L"BROWN ");
         CppWinRTWinUI3ListView::ContactModel	contact10 = winrt::make<CppWinRTWinUI3ListView::implementation::ContactModel>(L"ELIZABETH", L"JONES ");


         m_ContactsList.Append(contact1);
         m_ContactsList.Append(contact2);
         m_ContactsList.Append(contact3);
         m_ContactsList.Append(contact4);
         m_ContactsList.Append(contact5);
         m_ContactsList.Append(contact6);
         m_ContactsList.Append(contact7);
         m_ContactsList.Append(contact8);
         m_ContactsList.Append(contact9);
         m_ContactsList.Append(contact10);



       
    }

   
}
