#include <3ds.h>
#include <stdio.h>
#include <string.h>

#define BAR_TEXT "welcome to my app!!  "

int main(int argc, char **argv)
{
    gfxInitDefault();
    PrintConsole topScreen;
    consoleInit(GFX_TOP, &topScreen);

    char buffer[128];
    int offset = 0;
    const char *msg = BAR_TEXT;
    int msgLen = strlen(msg);
    int frameCounter = 5;

    while (aptMainLoop())
    {
        hidScanInput();
        u32 kDown = hidKeysDown();
        if (kDown & KEY_START)
            break;

        consoleClear();

        if (frameCounter % 5 == 0)
        {
            for (int i = 0; i < 40; i++)
            {
                buffer[i] = msg[(offset + i) % msgLen];
            }
            buffer[40] = '\0';
            offset = (offset + 1) % msgLen;
        }

        printf("%s\n", buffer);
        const char *text = "hello";
        int padding = (40 - strlen(text)) / 2;
        for (int i = 0; i < padding; i++)
        {
            printf(" ");
        }
        printf("%s\n", text);

        frameCounter++;

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}
