#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "user32.lib")

int main()
{
    int aElements[2] = {COLOR_WINDOW, COLOR_ACTIVECAPTION};
    DWORD aOldColors[2];
    DWORD aNewColors[2];

    // Get the current color of the window background.

    aOldColors[0] = GetSysColor(aElements[0]);

    printf("Current window color: {0x%x, 0x%x, 0x%x}\n",
        GetRValue(aOldColors[0]),
        GetGValue(aOldColors[0]),
        GetBValue(aOldColors[0]));

    // Get the current color of the active caption.

    aOldColors[1] = GetSysColor(aElements[1]);

    printf("Current active caption color: {0x%x, 0x%x, 0x%x}\n",
        GetRValue(aOldColors[1]),
        GetGValue(aOldColors[1]),
        GetBValue(aOldColors[1]));

    // Define new colors for the elements

    aNewColors[0] = RGB(0x80, 0x80, 0x80);  // light gray
    aNewColors[1] = RGB(0x80, 0x00, 0x80);  // dark purple

    printf("\nNew window color: {0x%x, 0x%x, 0x%x}\n",
        GetRValue(aNewColors[0]),
        GetGValue(aNewColors[0]),
        GetBValue(aNewColors[0]));

    printf("New active caption color: {0x%x, 0x%x, 0x%x}\n",
        GetRValue(aNewColors[1]),
        GetGValue(aNewColors[1]),
        GetBValue(aNewColors[1]));

    // Set the elements defined in aElements to the colors defined
    // in aNewColors

    SetSysColors(2, aElements, aNewColors);

    printf("\nWindow background and active border have been changed.\n");
    printf("Reverting to previous colors in 10 seconds...\n");

    Sleep(10000);

    // Restore the elements to their original colors
	system("pause>nul");
    SetSysColors(2, aElements, aOldColors);
    return 0;
}
