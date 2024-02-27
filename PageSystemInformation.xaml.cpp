#include "pch.h"
#include "PageSystemInformation.xaml.h"
#if __has_include("PageSystemInformation.g.cpp")
#include "PageSystemInformation.g.cpp"
#endif

#include <windows.h>
#include <iomanip>
#include <sstream>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::App2::implementation
{
    void PageSystemInformation::InitializeComponent()
    {
        // Call base InitializeComponent() to register with the Xaml runtime
        PageSystemInformationT::InitializeComponent();
        // Can now access Xaml properties
        winrt::App2::implementation::PageSystemInformation::AddReportUI();
        
    }

    int32_t PageSystemInformation::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void PageSystemInformation::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    
}


void winrt::App2::implementation::PageSystemInformation::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    winrt::App2::implementation::PageSystemInformation::AddReportUI();
}

void winrt::App2::implementation::PageSystemInformation::AddReportUI() {
    SI_column0().Children().Clear();
    SI_column1().Children().Clear();
    Microsoft::UI::Xaml::Controls::TextBlock BP_c0;
    BP_c0.FontSize(20);
    BP_c0.Text(L"Battery Percentage");
    SI_column0().Children().Append(BP_c0);
    Microsoft::UI::Xaml::Controls::TextBlock MU_c0;
    MU_c0.FontSize(20);
    MU_c0.Text(L"Memory Usage");
    SI_column0().Children().Append(MU_c0);

    SYSTEM_POWER_STATUS spsPwr;
    double BatteryLifePercentage = 0;
    if (GetSystemPowerStatus(&spsPwr)) {
        BatteryLifePercentage = static_cast<int>(spsPwr.BatteryLifePercent);
    }
    auto Battery_Text1 = winrt::to_hstring(BatteryLifePercentage);
    Microsoft::UI::Xaml::Controls::TextBlock BP_c1;
    BP_c1.FontSize(20);
    BP_c1.Text(Battery_Text1 + L"%");
    SI_column1().Children().Append(BP_c1);

    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    float totalPhysMemMB = (float)memInfo.ullTotalPhys / 1024 / 1024;
    float physMemUsedMB = totalPhysMemMB - (float)(memInfo.ullAvailPhys / 1024 / 1024);

    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << totalPhysMemMB / 1024;
    std::string totalPhysMemGB = stream.str();
    stream.str("");
    stream << std::fixed << std::setprecision(1) << physMemUsedMB / 1024;
    std::string physMemUsedGB = stream.str();
    stream.str("");
    stream << std::fixed << std::setprecision(0) << physMemUsedMB * 100 / totalPhysMemMB;
    std::string MemUsedPercentage = stream.str();

    auto Memory_Text1 = winrt::to_hstring(physMemUsedGB);
    auto Memory_Text2 = winrt::to_hstring(totalPhysMemGB);
    auto Memory_Text3 = winrt::to_hstring(MemUsedPercentage);
    Microsoft::UI::Xaml::Controls::TextBlock MU_c1;
    MU_c1.FontSize(20);
    MU_c1.Text(Memory_Text1 + L" / " + Memory_Text2 + L" GB (" + Memory_Text3 + L"%)");
    SI_column1().Children().Append(MU_c1);
    
    
    int DiskCount = 0;
    DWORD DiskInfo = GetLogicalDrives();
    while (DiskInfo) {
        if (DiskInfo & 1)    ++DiskCount;
        DiskInfo = DiskInfo >> 1;
    }

    DWORD DSLength = GetLogicalDriveStrings(0, NULL); //49
    char DStr[100];
    GetLogicalDriveStrings(DSLength, (LPTSTR)DStr);

    //int DType;
    int si = 0;
    BOOL fResult;
    unsigned _int64 i64FreeBytesToCaller;
    unsigned _int64 i64TotalBytes;
    unsigned _int64 i64FreeBytes;

    for (int i = 0; i < DSLength / 4; i++) {
        Microsoft::UI::Xaml::Controls::TextBlock a;
        a.FontSize(20);
        a.Text(L"Disk " + winrt::to_hstring((char16_t)DStr[si]) + L": Space");
        SI_column0().Children().Append(a);

        const wchar_t dir[3] = { DStr[si], ':', '\0' };
        fResult = GetDiskFreeSpaceEx(dir, (PULARGE_INTEGER)&i64FreeBytesToCaller, (PULARGE_INTEGER)&i64TotalBytes, (PULARGE_INTEGER)&i64FreeBytes);
        if (fResult) {
            float totalspaceMB = (float)i64TotalBytes / 1024 / 1024;
            float freespaceMB = (float)i64FreeBytesToCaller / 1024 / 1024;

            stream.str("");
            stream << std::fixed << std::setprecision(1) << totalspaceMB / 1024;
            std::string totalspaceGB = stream.str();
            stream.str("");
            stream << std::fixed << std::setprecision(1) << freespaceMB / 1024;
            std::string freespaceGB = stream.str();
            auto Disk_Text1 = winrt::to_hstring(freespaceGB);
            auto Disk_Text2 = winrt::to_hstring(totalspaceGB);
            Microsoft::UI::Xaml::Controls::TextBlock a;
            a.FontSize(20);
            a.Text(Disk_Text1 + L" GB free of " + Disk_Text2 + L" GB");
            SI_column1().Children().Append(a);
        }
        else {
            Microsoft::UI::Xaml::Controls::TextBlock a;
            a.FontSize(20);
            a.Text(L"N/A");
            SI_column1().Children().Append(a);
        }
        si +=2*4;
    }

    //SI_column0().Children().Clear();
    //Microsoft::UI::Xaml::Controls::TextBlock a;
    //a.Text(s);
    //SI_column0().Children().Append(a);

}

