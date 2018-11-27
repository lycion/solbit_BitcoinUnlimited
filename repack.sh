#!/bin/bash
cd build/out || exit "run this from the gitian-builder directory"
mkdir -p tmp
cd tmp
rm -rf solbit-0.11.2/ solbitUnlimited-0.11.2/
tar xvfz ../solbit-0.11.2-linux64.tar.gz
mv solbit-0.11.2/ solbitUnlimited-0.11.2/
find solbitUnlimited-0.11.2 | sort | tar --no-recursion --mode='u+rw,go+r-w,a+X' --owner=0 --group=0 -c -T - | gzip -9n > ../solbitUnlimited-0.11.2-linux64.tar.gz

rm -rf solbitUnlimited-0.11.2/
tar xvfz ../solbit-0.11.2-linux32.tar.gz
mv solbit-0.11.2/ solbitUnlimited-0.11.2/
find solbitUnlimited-0.11.2 | sort | tar --no-recursion --mode='u+rw,go+r-w,a+X' --owner=0 --group=0 -c -T - | gzip -9n > ../solbitUnlimited-0.11.2-linux32.tar.gz

rm -rf solbit-0.11.2/ solbitUnlimited-0.11.2/

cd ../../..
