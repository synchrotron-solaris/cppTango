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
    cmake3 \
 && groupadd -g "$APP_GID" tango \
 && useradd -u "$APP_UID" -g "$APP_GID" -ms /bin/sh tango \
 # create folder structure for building rpms
 && su tango -c 'rpmdev-setuptree' \
 # cleanup
 && yum clean all \
 && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /var/cache/yum/*

ENV PKG_CONFIG_PATH=/home/tango/lib/pkgconfig
USER tango
WORKDIR /home/tango
