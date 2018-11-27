
Debian
====================
This directory contains files used to package solbitd/solbit-qt
for Debian-based Linux systems. If you compile solbitd/solbit-qt yourself, there are some useful files here.

## solbitcash: URI support ##


solbit-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install solbit-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your solbit-qt binary to `/usr/bin`
and the `../../share/pixmaps/solbit128.png` to `/usr/share/pixmaps`

solbit-qt.protocol (KDE)

