#include "pch.h"
#include "ContactModel.h"
#if __has_include("ContactModel.g.cpp")
#include "ContactModel.g.cpp"
#endif

namespace winrt::CppWinRTWinUI3ListView::implementation
{

    ContactModel::ContactModel() 
    {
    }

    ContactModel::ContactModel(winrt::hstring firstname, winrt::hstring lastname) : m_FirstName(firstname), m_LastName(lastname)
    {

    }


   
}
