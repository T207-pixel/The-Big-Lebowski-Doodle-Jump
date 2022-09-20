#pragma  once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
//SIZE OF BACKGROUND
extern const float BACKGROUNDWIDTH;
extern const float BACKGROUNDHEIGHT;
//SIZE OF DOODLER
extern const float OFFSETNOSE;
extern const float OFFSETBACK;
//FRAMES
extern const int FRAMELIMIT;
//PATH TO THE FILES
//BACKGROUND
extern const char *FILENAMEBACKGROUND;
//DOODLER
extern const char *FILENAMEDOODLERRIGHT;
extern const char *FILEMAMEDOODLERLEFT;
extern const char *FILENAMEDOODLERBENTLEGSLEFT;
extern const char *FILENAMEDOODLERBENTLEGSRIGHT;
extern const char* FILENAMEBREAKINGPLATFORMSET;
extern const char *FILENAMEHORIZONTALPLATFORM;
//FALLING PLATFORM CONSTANTS
extern const float QUANTITYOFFRAMESFALLPLAT;
extern const float XPLATFORMSTARTPOSITION;
extern const float YPLATFORMSTARTPOSITION;
extern const float DISTANCETONEXTPLATFORMX;
extern const float DISTANCETONEXTPLATFORMY;
//USUAL PLATFORM
extern const char *FILENAMEPLATFORM;
//BREAKING PLATFORM
extern const char *FILENAMEBREAKINGPLATFORM;
//DISAPPEARING PLATFORM
extern const char* FILENAMEDISAPPEARINGPLATFORM;
//PHYSICAL PARAMETERS
extern const float SIDESPEED;
extern const float STARTSPEEDY;
extern const float ACCELERATION;
//QUANTITY OF PLATFORMS IN THE GAME IN BEGINNING
extern const float STARTPLATFORMQUANTITY;
extern const float ENDPLATFORMQUANTITY;
//CAMERA PARAMETERS
extern const float CAMERALEVEL;
//START SCORES
extern const float STARTSCORES;
extern const float SCORECOEF;
extern float g_SCORESCHECKER;
//FALLING PLATFORM
extern const float STARTFALLINGPLATFORMSPEED;
extern const float MIDDLEFALLINGPLATFORMSPEED;
extern const double DINAMICCOEF;
#define FALLINGPLATFORMFRAMESQUANTITY 6
//HORIZONTAL PLATFORM
extern const float STARTHORIZONTALPLATFORMSPEED;
extern const float MAXHORIZONTALSPEED;
//REMOVABLE PLATFORM
extern const char *FILENAMEREMOVABLEPLATFORM;
//TWITCHING PLATFORM
extern const char *FILEMAMETWITCHINGPLATFORM;
extern const float HORIZONTALSPEED;
extern const float MAXDISTANCE;
//FONT FILENAME
extern const char *FILENAMEFONT;
extern const char *FILEMAMEMENU;
extern const char *FILENAMEPLAYBUTTON;
extern const char *FILENAMEGAMEOVER;
extern const char *FILENAMEMENUBUTTON;