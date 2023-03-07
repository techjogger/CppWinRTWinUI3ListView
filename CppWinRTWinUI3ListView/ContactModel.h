#pragma once

#include "ContactModel.g.h"

namespace winrt::CppWinRTWinUI3ListView::implementation
{
    struct ContactModel : ContactModelT<ContactModel>
    {
        ContactModel();

		ContactModel(winrt::hstring firstname, winrt::hstring lastname);

		void FirstName(hstring const& value)
		{
			UpdateValue<hstring>(L"FirstName", m_FirstName, value);
		}

		hstring FirstName() const
		{
			return m_FirstName;
		}

		void LastName(hstring const& value)
		{
			UpdateValue<hstring>(L"LastName", m_LastName, value);
		}

		hstring LastName() const
		{
			return m_LastName;
		}


		// Property changed notifications.
		event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& value)
		{
			return m_propertyChanged.add(value);
		}

		void PropertyChanged(event_token const& token)
		{
			m_propertyChanged.remove(token);
		}

	private:

		hstring m_FirstName{ L"FirstName" };
		hstring m_LastName{ L"LastName" };


		// Property changed notification.
		event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged {};

		template <class T>
		void UpdateValue(hstring const& propertyName, T& var, T value)
		{
			if (var != value)
			{
				var = value;
				RaisePropertyChanged(propertyName);
			}
		}

		void RaisePropertyChanged(hstring const& propertyName)
		{
			m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs(propertyName));
		}
    };
}

namespace winrt::CppWinRTWinUI3ListView::factory_implementation
{
    struct ContactModel : ContactModelT<ContactModel, implementation::ContactModel>
    {
    };
}
