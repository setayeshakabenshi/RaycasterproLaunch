# RaycasterproLaunch
A small C game project built with raylib
first open the terminal on ubuntu and 
git clone https://github.com/setayeshakabenshi/RaycasterproLaunch.git
cd RaycasterproLaunch
then build the game with 
gcc main.c map.c player.c render.c -o Raycasterpro \
  -Wall -Wextra -std=c99 \
  -I./raylib/src \
  -L./raylib/src -lraylib \
  -lGL -lm -ldl -lX11 -pthread
  and then run it
./Raycasterpro
