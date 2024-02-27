#include "pch.h"
#include "PageAudioControl.xaml.h"
#if __has_include("PageAudioControl.g.cpp")
#include "PageAudioControl.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::App2::implementation
{
    void PageAudioControl::InitializeComponent()
    {
        // Call base InitializeComponent() to register with the Xaml runtime
        PageAudioControlT::InitializeComponent();
        // Can now access Xaml properties
        //winrt::App2::implementation::PageAudioControl::AddReportUI();
    }
    int32_t PageAudioControl::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void PageAudioControl::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

}


void winrt::App2::implementation::PageAudioControl::Speaker_All_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    Microsoft::UI::Xaml::Controls::ToggleSwitch toggleSwitch = sender.as<Microsoft::UI::Xaml::Controls::ToggleSwitch>();
    if (toggleSwitch)
    {
        if (toggleSwitch.IsOn())
        {
            Speaker_0().IsEnabled(L"False");
            Speaker_1().IsEnabled(L"True");
        }
        else
        {
            Speaker_0().IsEnabled(L"True");
            Speaker_1().IsEnabled(L"False");
        }
    }
}


void winrt::App2::implementation::PageAudioControl::Speaker_0_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{

}
