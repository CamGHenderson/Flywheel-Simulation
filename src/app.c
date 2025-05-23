#include "graphics.h"

int main()
{
    initializeGraphics();

    while(isGraphicsWindowOpen())
    {
        prepareGraphics();

        setGraphicsColor(255, 0, 0);
        drawString(100, 100, "Fuck you!");

        updateGraphics();
    }

    freeGraphics();
    
    return 0;
}

