Solbit Unlimited 0.12.1b
=========================

Setup
---------------------
[Solbit Unlimited](http://www.solbit.info) is a fork of the original Solbit client and it builds the backbone of the network.  It downloads and stores the entire history of Solbit transactions (which is currently several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.

- [Getting the most out of Xtreme thinblocks](bu-xthin.md)
- [Setting up an Xpedited Relay Network](bu-xpedited-forwarding.md)

Running
---------------------
The following are some helpful notes on how to run Solbit on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/solbit-qt` (GUI) or
- `bin/solbitd` (headless)

### Windows

Unpack the files into a directory, and then run solbit-qt.exe.

### OS X

Drag Solbit-Unlimited to your applications folder, and then run Solbit-Unlimited.

### Need Help?

* See the documentation at the [Solbit Wiki](https://en.solbit.it/wiki/Main_Page)
for help and more information.
* Ask for help on [#solbit](http://wesbtat.freenode.net?channels=solbit) on Freenode. If you don't have an IRC client use [wesbtat here](http://wesbtat.freenode.net?channels=solbit).
* Ask for help on the [SolbitTalk](https://solbittalk.org/) forums, in the [Technical Support board](https://solbittalk.org/index.php?board=4.0).

Building
---------------------
The following are developer notes on how to build Solbit on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [OS X Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The Solbit repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/solbit/doxygen/)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [Unit Tests](unit-tests.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)

### Resources
* Discuss on the [SolbitTalk](https://solbittalk.org/) forums, in the [Development & Technical Discussion board](https://solbittalk.org/index.php?board=6.0).
* Discuss project-specific development on #solbit-core-dev on Freenode. If you don't have an IRC client use [wesbtat here](http://wesbtat.freenode.net/?channels=solbit-core-dev).
* Discuss general Solbit development on #solbit-dev on Freenode. If you don't have an IRC client use [wesbtat here](http://wesbtat.freenode.net/?channels=solbit-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)

License
---------------------
Distributed under the [MIT software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
