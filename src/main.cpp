#include <ShObjIdl.h>
#include <wchar.h>

HRESULT CreateAAM(IApplicationActivationManager*& aam)
{
    return CoCreateInstance(CLSID_ApplicationActivationManager, nullptr, CLSCTX_LOCAL_SERVER, IID_PPV_ARGS(&aam));
}

HRESULT ActivateApp(IApplicationActivationManager* aam, const wchar_t* appId)
{
    unsigned long unused = 0;
    return aam->ActivateApplication(appId, nullptr, AO_NONE, &unused);
}

int wmain(int argc, wchar_t* argv[])
{
    HRESULT hr = S_OK;

    if (argc < 2)
    {
        hr = E_INVALIDARG;
        wprintf(L"Supply an app ID (AppUserModelId) for the application to activate.");
    }
    else
    {
        hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
        if (FAILED(hr))
        {
            wprintf(L"Error initializing COM");
        }
        else
        {
            IApplicationActivationManager* aam = nullptr;
            hr = CreateAAM(aam);
            if (FAILED(hr))
            {
                wprintf(L"Error creating ApplicationActivationManager");
            }
            else
            {
                hr = CoAllowSetForegroundWindow(aam, nullptr);
                if (FAILED(hr))
                {
                    wprintf(L"Error calling CoAllowSetForegroundWindow");
                }
                else
                {
                    hr = ActivateApp(aam, argv[1]);
                    if (FAILED(hr))
                    {
                        wprintf(L"Error calling ActivateApplication");
                    }
                }

                aam->Release();
            }

            CoUninitialize();
        }
    }

    return hr;
}
