
FROM osrf/ros:noetic-desktop-full


ARG USER=$USER
ARG DEBIAN_FRONTEND=noninteractive

SHELL ["/bin/bash", "-c"]

RUN apt-get update && apt-get install -y\
    git\
    sudo\
    python3-pip\
    cmake\
    python3-rosdep\
    python3-rosinstall\
    python3-rosinstall-generator\
    python3-wstool\
    build-essential\
    libopencv-dev\
    python3-opencv

WORKDIR /home/$USER







