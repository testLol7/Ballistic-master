#include "pch.h"
#include <Windows.h>
#include <string>
#include <vector>
#include "offsets.hpp"
#include "RenderView.hpp" // Include RenderView header
#include "DataModel.hpp" // Include DataModel header

extern "C" __declspec(dllexport) LRESULT CALLBACK NextHook(int code, WPARAM wParam, LPARAM lParam) {
    return CallNextHookEx(NULL, code, wParam, lParam);
}

void start() {
    /*MessageBoxA(0, "printsploit lol", "", MB_TOPMOST);*/
    roblox_print(1, "t");
    roblox_print(1, "Thanks for using InfDragon V0.1");
    roblox_print(0, "Current identity is 0");

    // Obtain the render view pointer
    uintptr_t renderViewPointer = RBX::Graphics::RenderView->Get();

    // Format the pointer as a hexadecimal address
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "Render view is 0x%p", (void*)renderViewPointer);
    roblox_print(2, buffer);

    // Obtain the data model pointer
    uintptr_t dataModelPointer = RBX::DataModel->Get();

    // Check if the data model pointer is valid
    if (dataModelPointer != 0) {
        // Get the children of the DataModel
        std::vector<uintptr_t> children = RBX::DataModel->GetChildren(dataModelPointer);
        for (uintptr_t child : children) {
            std::string childName = RBX::DataModel->GetName(child);
            roblox_print(2, ("Child: " + childName).c_str());
        }
    }
    else {
        roblox_print(2, "Error: Data model pointer is invalid");
    }

    roblox_print(3, "Highly in alpha, can only print text to console");
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {
        start();
    }

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
