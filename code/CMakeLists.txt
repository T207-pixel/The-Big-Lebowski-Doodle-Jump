cmake_minimum_required(VERSION 3.21)
project(doodleJump)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(doodleJump main.cpp Doodler.h Doodler.cpp Map.h Map.cpp Settings.h Settings.cpp Platform.cpp Platform.h GameEngine.h GameEngine.cpp Camera.cpp Camera.h Scores.cpp Scores.h FallingPlatform.cpp FallingPlatform.h HorizontalPlatform.cpp HorizontalPlatform.h DisappearingPlatform.cpp DisappearingPlatform.h RemovablePlatform.cpp RemovablePlatform.h TwitchingPlatform.cpp TwitchingPlatform.h PlatformAppearanceProbability.cpp PlatformAppearanceProbability.h Font.cpp Font.h ActualGame.cpp ActualGame.h Menu.cpp Menu.h GameOver.cpp GameOver.h)

target_link_libraries(doodleJump sfml-graphics sfml-audio)

