#pragma once

#include "PageSystemInformation.g.h"

namespace winrt::App2::implementation
{
    struct PageSystemInformation : PageSystemInformationT<PageSystemInformation>
    {
        PageSystemInformation()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        void PageSystemInformation::InitializeComponent();
        int32_t MyProperty();
        void MyProperty(int32_t value);

        
        void Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void winrt::App2::implementation::PageSystemInformation::AddReportUI();
    };
}

namespace winrt::App2::factory_implementation
{
    struct PageSystemInformation : PageSystemInformationT<PageSystemInformation, implementation::PageSystemInformation>
    {
    };
}
