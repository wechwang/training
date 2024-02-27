#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif


#include <winrt/Windows.UI.Xaml.Interop.h>
using namespace winrt::Microsoft::UI::Xaml::Controls;
using namespace std;

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::App2::implementation
{
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    
}


void winrt::App2::implementation::MainWindow::nvSample_SelectionChanged(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewSelectionChangedEventArgs const& args)
{
    //auto selectedItem = args.SelectedItem();
    //if ((string)selectedItem.Tag == "PageSystemInformation") contentFrame.Navigate(typeof(PageSystemInformation));
    //else if ((string)selectedItem.Tag == "PageAudioControl") contentFrame.Navigate(typeof(PageAudioControl));
    
    //this->contentFrame().Navigate(xaml_typename<PageSystemInformation>());


    Windows::UI::Xaml::Interop::TypeName pageTypeName;
    pageTypeName.Name = unbox_value<hstring>(args.SelectedItemContainer().Tag());
    pageTypeName.Kind = Windows::UI::Xaml::Interop::TypeKind::Primitive;

    Windows::UI::Xaml::Interop::TypeName preNavPageType =
        contentFrame().CurrentSourcePageType();

    // Navigate only if the selected page isn't currently loaded.
    if (pageTypeName.Name != L"" && preNavPageType.Name != pageTypeName.Name)
    {
        if (pageTypeName.Name == L"PageSystemInformation") contentFrame().Navigate(xaml_typename<PageSystemInformation>());
        else if (pageTypeName.Name == L"PageAudioControl") contentFrame().Navigate(xaml_typename<PageAudioControl>());
        // contentFrame().Navigate(pageTypeName, nullptr, args.RecommendedNavigationTransitionInfo());
    }

}
