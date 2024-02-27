#pragma once

#include "PageAudioControl.g.h"

namespace winrt::App2::implementation
{
    struct PageAudioControl : PageAudioControlT<PageAudioControl>
    {
        PageAudioControl()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        void PageAudioControl::InitializeComponent();
        int32_t MyProperty();
        void MyProperty(int32_t value);

        
        void Speaker_All_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void Speaker_0_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::App2::factory_implementation
{
    struct PageAudioControl : PageAudioControlT<PageAudioControl, implementation::PageAudioControl>
    {
    };
}
