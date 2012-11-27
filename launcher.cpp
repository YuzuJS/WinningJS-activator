#include <ShObjIdl.h>
#include <atlbase.h>
#include <wchar.h>

int wmain(int argc, wchar_t* argv[])
{
    HRESULT hr = S_OK;

    if (argc < 2)
    {
        hr = E_INVALIDARG;
        wprintf(L"Supply an app ID (AppUserModelId) for the application to launch.");
        return hr;
    }

    const wchar_t* appId = argv[1];

    hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    if (FAILED(hr))
    {
        wprintf(L"Error initializing COM");
        return hr;
    }

    CComPtr<IApplicationActivationManager> aam = nullptr;
    hr = CoCreateInstance(CLSID_ApplicationActivationManager, nullptr, CLSCTX_LOCAL_SERVER, IID_PPV_ARGS(&aam));
    if (FAILED(hr))
    {
        wprintf(L"Error creating ApplicationActivationManager");
        CoUninitialize();
        return hr;
    }

    hr = CoAllowSetForegroundWindow(aam, nullptr);
    if (FAILED(hr))
    {
        wprintf(L"Error calling CoAllowSetForegroundWindow");
        CoUninitialize();
        return hr;
    }

    unsigned long pid = 0;
    hr = aam->ActivateApplication(appId, nullptr, AO_NONE, &pid);
    if (FAILED(hr))
    {
        wprintf(L"Error calling ActivateApplication");
        CoUninitialize();
        return hr;
    }

    CoUninitialize();
    return hr;
}
