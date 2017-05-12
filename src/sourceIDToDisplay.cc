#include <windows.h>
#include "sourceIDToDisplay.h"

bool sourceIDToDisplayF(int sourceID, Area* res)
{

#if defined(IS_WINDOWS)

    DISPLAY_DEVICE device;
    device.cb = sizeof(device);

    if (!EnumDisplayDevices(NULL, sourceID, &device, 0) // device not found
        || !(device.StateFlags & DISPLAY_DEVICE_ACTIVE))// device is not active
    {
        return false;
    }

    DEVMODE deviceSettings;
    deviceSettings.dmSize = sizeof(deviceSettings);
    deviceSettings.dmDriverExtra = 0;
    if(!EnumDisplaySettingsEx(device.DeviceName, ENUM_CURRENT_SETTINGS,
        &deviceSettings, 0))
    {
        return false;
    }

    res->x = deviceSettings.dmPosition.x;
    res->y = deviceSettings.dmPosition.y;
    res->width = deviceSettings.dmPelsWidth;
    res->height = deviceSettings.dmPelsHeight;

    return true;

#else

    return false;

#endif

}
