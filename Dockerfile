# Image dependencies
FROM estebanmatias92/gccplus:latest as buildeps
FROM estebanmatias92/gccplus-coding:latest as devdeps


#
# Image to compile the source code to binary
#
FROM buildeps as builder
# Modifyble through cli args
ARG PROJECT_NAME
ARG CMAKE_VERSION
ARG buildpath

WORKDIR /code
# Pull the source code
COPY . .
# Add the build script commands to the shell session and run the build instruction
RUN ./build.sh && ./install.sh


#
# Preparing the runtime artifacs
#
FROM debian:stable-slim as runtime
# Copy the binaries from the build to the current directory
COPY --from=builder /usr/local/ /usr/local/
# Regenerate the shared-library cache.
RUN ldconfig


#
# VS Code Stage 
# (This is preferred to run as a Docker Dev Environment)
#
FROM devdeps AS development
# Modifyble through cli args
ARG WORKDIR=/com.docker.devenvironments.code
ARG USER="vscode"
# Create and change user
RUN useradd -s /bin/bash -m $USER \
    && groupadd docker \
    && usermod -aG docker $USER
USER $USER
# Get the build script commands added to the shell session
COPY --chown=$USER script.sh $WORKDIR/
RUN echo "\n# Add script for building\n. ${WORKDIR}/script.sh" >> $HOME/.bashrc 
# Keep the container alive
CMD ["sleep", "infinity"]


#
# Production Target Stage 
# Normally called without specifying "target" in compose
#
FROM runtime as production

# Run the container as an executable
ENTRYPOINT $PROJECT_NAME