#!/usr/bin/env bash

docker exec cpp_tango mkdir -p /home/tango/cppzmq/build

if [ "$OS_TYPE" = "centos7" ]
then
	# workaroud for CentOS 7 not providing static lib for libzmq
	docker exec cpp_tango sh -c 'sed -e "s/ZeroMQ_LIBRARY AND ZeroMQ_STATIC_LIBRARY/ZeroMQ_LIBRARY OR ZeroMQ_STATIC_LIBRARY/" /home/tango/cppzmq/libzmqPkgConfigFallback.cmake > /home/tango/cppzmq/libzmqPkgConfigFallback.cmake'
fi

echo "Build cppzmq"
docker exec cpp_tango cmake -H/home/tango/cppzmq -B/home/tango/cppzmq/build -DCMAKE_INSTALL_PREFIX=/home/tango
if [ $? -ne "0" ]
then
    exit -1
fi
echo "Install cppzmq"
docker exec cpp_tango make -C /home/tango/cppzmq/build install
if [ $? -ne "0" ]
then
    exit -1
fi