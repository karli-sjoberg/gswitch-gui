# gswitch-gui

Hello!

I thought it would be fun to write a GUI application to the command line script "gswitch" I recently made, to make it easier and faster to use. I've never written any QT applications before and took this as a fun learning experiment that can benefit others at the same time.

I'll explain how you can clone this project and build this yourselves, or just download the .deb files I've made to make it as easy as possible to get going!

sudo apt-get install -y build-essentials qt5-default
git clone https://github.com/karli-sjoberg/gswitch-gui
cd gswitch-gui
mkdir build
cd build
qmake ../Gswitch-GUI.pro
make
make clean
./Gswitch-GUI
