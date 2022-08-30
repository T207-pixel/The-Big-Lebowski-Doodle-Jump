#include "Settings.h"
//SIZE OF BACKGROUND
const float BACKGROUNDWIDTH = 640;    //OK
const float BACKGROUNDHEIGHT = 960;   //OK
//SIZE OF DOODLER
const float OFFSETNOSE = 23;          //OK
const float OFFSETBACK = 12;          //OK
//FRAMES
const int FRAMELIMIT = 240;           //OK
//PATH TO THE FILES
const char *FILENAMEBACKGROUND = "/home/tim/C++/sfml/doodleJump/textures/background/smoked_rug.png";

const char *FILENAMEDOODLERRIGHT = "/home/tim/C++/sfml/doodleJump/textures/doomerDoodle_small_tima.png";
const char *FILEMAMEDOODLERLEFT = "/home/tim/C++/sfml/doodleJump/textures/doomerDoodle_small_tima_left.png";
const char *FILENAMEDOODLERBENTLEGSLEFT = "/home/tim/C++/sfml/doodleJump/textures/doomerDoodle_small_legs_left.png";
const char *FILENAMEDOODLERBENTLEGSRIGHT = "/home/tim/C++/sfml/doodleJump/textures/doomerDoodle_small_legs_right.png";

const char *FILENAMEPLATFORM = "/home/tim/C++/sfml/doodleJump/textures/usual_platform/keglya.png";

const char* FILENAMEDISAPPEARINGPLATFORM = "/home/tim/C++/sfml/doodleJump/textures/disappearing_platform/kover _cut.png" ;

const char *FILENAMEBREAKINGPLATFORM = "/home/tim/C++/sfml/doodleJump/textures/breaking_platform/kosyakkk_single.png";
const char *FILENAMEBREAKINGPLATFORMSET = "/home/tim/C++/sfml/doodleJump/textures/breaking_platform/kosyak40.png"; // change

const char *FILENAMEHORIZONTALPLATFORM = "/home/tim/C++/sfml/doodleJump/textures/horizontal_platform/keglya.png";

const char *FILENAMEREMOVABLEPLATFORM = "/home/tim/C++/sfml/doodleJump/textures/removing_platform/palets .png";

const char *FILEMAMETWITCHINGPLATFORM = "/home/tim/C++/sfml/doodleJump/textures/twitching_platforms/pivo_small_cut.png";

const char *FILENAMEFONT = "/home/tim/C++/sfml/doodleJump/font/Jack-Brusher-51.ttf";

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
const float STARTPLATFORMQUANTITY = 12;//25
const float ENDPLATFORMQUANTITY = 12;
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
