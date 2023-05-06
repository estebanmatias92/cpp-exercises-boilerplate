# C/C++ Docker Dev Environment

Docker Compose template to build an app/service with vanilla C/C++.

You can change the **project_name** and the **cmake_version** in the .env file and compose files or with args from the docker compose CLI commands.

## Use

There are three main stages, _Builder_, _Development_ and _Production_. (see [Dockerfile](https://github.com/estebanmatias92/cpp-exercises-boilerplate/blob/main/Dockerfile))<br/>
**Builder:** is used to compile the source files and it is used by other stages/images.<br/>
**Development:** is used to set the dev dependencies and system user for the IDE.<br/>
**Production:** is a slim version of debian that pulls the binaries and can only run the executable.

### From outside the container/dev-environment

This option will run the production container, it acts as an executable.

**Build (1st time) and run service with compose:**

_`docker compose run --rm app`_

### Inside the dev-environment

All the bash scripts for dev workflow ([script.sh](https://github.com/estebanmatias92/cpp-exercises-boilerplate/blob/main/script.sh), [install.sh](https://github.com/estebanmatias92/cpp-exercises-boilerplate/blob/main/install.sh) and [build.sh](https://github.com/estebanmatias92/cpp-exercises-boilerplate/blob/main/build.sh)) are source with **$HOME/.bashrc** in the _Development_ stage ([Dockerfile](https://github.com/estebanmatias92/cpp-exercises-boilerplate/blob/main/Dockerfile)).

**Compile and run within the C/C++ environment:**

_`/bin/bash build && run`_

## Folder structure

I use the [The Pitchfork Layout (PFL)](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs) in order to structure the project.

Modules/Libraries names must be the same as the directory name in which they are.

The src/CmakeLists.txt will search for every subdirectory and add those who have a CMakeLists.txt in it as libraries automatically.
