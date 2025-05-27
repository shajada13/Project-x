#include <stdio.h>
#include <stdlib.h>
#include "../include/library.h"
#include "../include/main_menu.h"
#include "../include/student.h"
#include "../include/room.h"


// ========== Main Function ==========

int main()
{   
    system("chcp 65001"); // Set code page to UTF-8
    resetTextColor();
    CLEAR_SCREEN();
    main_menu();
    return 0;
    
}



