#include <e32base.h>
#include <e32cons.h>

LOCAL_D CConsoleBase* console;

LOCAL_C void doStartL()
    {
    console->Printf(_L("Hello, world!\n"));
    console->Getch();
    }

GLDEF_C TInt E32Main()
    {
    CTrapCleanup* cleanup = CTrapCleanup::New();
    TRAPD(err, console = Console::NewL(_L("Console"), TSize(KConsFullScreen, KConsFullScreen)));
    if (!err)
        {
        TRAPD(err2, doStartL());
        delete console;
        }
    delete cleanup;
    return 0;
    }
