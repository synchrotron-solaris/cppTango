FROM centos:7

ARG APP_UID=2000
ARG APP_GID=2000

RUN yum update -y && yum install -y epel-release \
 # necessary tools
 && yum groupinstall -y "Development tools" \
 && yum install -y \
    rpmdevtools \
    omniORB-devel \
    zeromq-devel \
    wget \
 && wget --no-check-certificate https://cmake.org/files/v3.10/cmake-3.10.0-Linux-x86_64.sh -O /tmp/cmake-install.sh \
 && chmod +x /tmp/cmake-install.sh \
 && /tmp/cmake-install.sh --skip-license --exclude-subdir \
 && groupadd -g "$APP_GID" tango \
 && useradd -u "$APP_UID" -g "$APP_GID" -ms /bin/bash tango \
 # create folder structure for building rpms
 && su tango -c 'rpmdev-setuptree' \
 # cleanup
 && yum clean all \
 && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /var/cache/yum/*

ENV PKG_CONFIG_PATH=/home/tango/lib/pkgconfig
USER tango
WORKDIR /home/tango
