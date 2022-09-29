#include "Settings.h"
//SIZE OF BACKGROUND
const float BACKGROUNDWIDTH = 640;    //OK
const float BACKGROUNDHEIGHT = 960;   //OK
//SIZE OF DOODLER OFFSETS
const float OFFSETNOSE = 12;          //OK
const float OFFSETBACK = 18;          //OK
//FRAMES
const int FRAMELIMIT = 240;           //OK
//PATH TO THE FILES
const char *FILENAMEBACKGROUND = "../../textures/background/smoked_rug.png";

const char *FILENAMEDOODLERRIGHT = "../../textures/doodler_dude/DoodleRight1.png";
const char *FILEMAMEDOODLERLEFT = "../../textures/doodler_dude/DoodleLeft1.png";
const char *FILENAMEDOODLERBENTLEGSLEFT = "../../textures/doodler_dude/DoodleBentLeft1.png";
const char *FILENAMEDOODLERBENTLEGSRIGHT = "../../textures/doodler_dude/DoodleBentRight1.png";

const char *FILENAMEPLATFORM = "../../textures/usual_platform/keglya.png";

const char* FILENAMEDISAPPEARINGPLATFORM = "../../textures/disappearing_platform/kover _cut.png" ;

const char *FILENAMEBREAKINGPLATFORM = "../../textures/breaking_platform/kosyakkk_single.png";
const char *FILENAMEBREAKINGPLATFORMSET = "../../textures/breaking_platform/kosyak40.png";

const char *FILENAMEHORIZONTALPLATFORM = "../../textures/horizontal_platform/keglya2.png";

const char *FILENAMEREMOVABLEPLATFORM = "../../textures/removing_platform/palets .png";

const char *FILEMAMETWITCHINGPLATFORM = "../../textures/twitching_platforms/pivo_small_cut.png";

const char *FILENAMEFONT = "../../font/Jack-Brusher-51.ttf";

const char *FILEMAMEMENU = "../../textures/menu/anima22.png";
const char *FILENAMEPLAYBUTTON = "../../textures/menu/play.png";

const char *FILENAMEGAMEOVER = "../../textures/gameOver/Boots_Back2.png";
const char *FILENAMEMENUBUTTON = "../../textures/gameOver/menu.png";
const char *FILENAMEPLAYAGAINBUTTON = "../../textures/gameOver/play_again.png";

//FALLING PLATFORM CONSTANTS
const float QUANTITYOFFRAMESFALLPLAT = 40;
const float XPLATFORMSTARTPOSITION = 44.5;  //OK
const float YPLATFORMSTARTPOSITION = 14.5;  //OK
const float DISTANCETONEXTPLATFORMX = 90;   //OK
const float DISTANCETONEXTPLATFORMY = 29;   //OK

//PHYSICAL PARAMETERS FOR DOODLER
const float SIDESPEED = 2.8;          //OK
const float STARTSPEEDY = -4.5;       //OK
const float ACCELERATION = 0.03;      //OK
//QUANTITY OF PLATFORMS IN THE GAME IN BEGINNING
const float STARTPLATFORMQUANTITY = 25; //OK
const float ENDPLATFORMQUANTITY = 12;   //OK
//CAMERA PARAMETERS
const float CAMERALEVEL = 800;        //OK
//START SCORES
const float STARTSCORES = 0;          //OK
const float SCORECOEF = -0.75;        //OK
float g_SCORESCHECKER(1000);
//FALLING PLATFORM
const float STARTFALLINGPLATFORMSPEED = 0.0;
const float MIDDLEFALLINGPLATFORMSPEED = 2;
const double DINAMICCOEF = 0.000014;
//HORIZONTAL PLATFORM
const float STARTHORIZONTALPLATFORMSPEED = 0.3;
const float MAXHORIZONTALSPEED = 1.0;
//TWITCHING PLATFORM
const float HORIZONTALSPEED = 25;
const float MAXDISTANCE = 107;
