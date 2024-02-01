# minesweeper
A minesweeper clone built using C++ and Qt

## Installation Guide
`brew install qt5`  
`brew link qt5 --force` (to use `qmake`)  
`export PATH="/opt/homebrew/Cellar/qt5/bin=$PATH"` - this is for Apple silicon (location of qt5 may be different on your machine)  
`qmake -o Makefile app.pro` - to build Makefile  
`make` - to build application, find application and run it  