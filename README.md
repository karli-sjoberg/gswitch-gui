# gswitch-gui

Hello!

I thought it would be fun to write a GUI application to the command line script "gswitch" I recently made, to make it easier and faster to use. I've never written any QT applications before and took this as a fun learning experiment that can benefit others at the same time.

![screenshot_20181127_101224](https://user-images.githubusercontent.com/17517732/49071542-7af39000-f22e-11e8-92db-ff70bd6aff6e.png)

I'll explain how you can clone this project and build this yourselves!

sudo apt-get install -y build-essentials qt5-default</br>
git clone https://github.com/karli-sjoberg/gswitch-gui</br>
cd gswitch-gui</br>
mkdir build</br>
cd build</br>
qmake ../Gswitch-GUI.pro</br>
make</br>
make clean</br>
./Gswitch-GUI
