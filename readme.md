
# The Big Lebowski Doodle Jump
____

## About project
____
This project is a parody of a popular game _Doodle jump_. The main goal is to jump on platforms and not fall

My version has unique _dudes_ style. I was inspired by film _Big Lebowski_. So, in game you may see many references to
this movie (_which I really recommend to watch_).

To control the character, press "**A**" button if you prefer to direct him to the left, or press "**D**" button if you
prefer to direct him to fhe right.
___

## Authors
___
Code: **Novikov Tim** <br>
Artist/designer: **[Victoria Koroleva](https://vk.com/vwika_artt)**
___

## Preview
___
![](/home/tim/Загрузки/2291111_2000.gif)
___

## Main game mechanic and remarks
___
- Code contains two _Map_ objects _(map, nextMap)_.<br>
_map_ is located lower than _nextMap_, and player is able only to see area which is shown with camera scale. Actually
camera's area of visibility is the same as scale of the map. That is why camera smoothly goes up, until it's center does not
stay on same position as _nextMap's_ center. If camera and _nextMap_ have same center I update _nextMap_ by creating new
platforms on it, also I copy previous _nextMap_ platforms (their entities), delete _map_ platforms and fill it with
previous _nextMap_ platform entities, moreover I put down camera to _map_ center.
- Game has dynamic levels. Its idea is to reduce quantity of platforms due to increase of scores.
- Types of platforms also change due to increase, hereby generates more platforms with increased diffuculty.
- Best score is loads from file in the beginning. Also, best score stores in file if it was beaten.
___

## Type of platforms
___
1. `Usuall`: It is the simplest type of platform, because it is static.
2. `Falling`: It is fake animated type of platform which breaks if you step on it.
3. `Horizontal`: It is moving horizontally type of platform, also it increases speed while your scores increase.
4. `Disappearing`: It is animated type of platform which disappears forever if you step on it.
5. `Removable`: It is animated type of platform which affects all platforms of its type even if you step only on one 
of them. So firstly you see the disappearance of platforms, after that they change their position and smoothly appear 
on new position.
6. `Twitching`: It is type of platform which affects all platforms of its type even if you step only on one
of them. So all platforms twitch in random direction sharply.
___

## Development tools
___
- **Programming language: C++20**
- **Audio and graphics lib: SFML 2.5.1**
- **std::vector<T>**
- **std::rand**
- **std::thread**
- **std::chrono**
