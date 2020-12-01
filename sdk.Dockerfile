# Copyright 2020 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

FROM ubuntu:bionic

RUN apt-get update && apt-get -y dist-upgrade && apt-get install -y --no-install-recommends \
    ca-certificates \
    curl \
    git \
    gcc \
    python3 \
    xz-utils

RUN curl -LO https://github.com/bazelbuild/bazelisk/releases/download/v1.7.4/bazelisk-linux-amd64
RUN mv bazelisk-linux-amd64 /usr/bin/bazel
RUN chmod +x usr/bin/bazel

RUN mkdir -p /home/.cache
RUN chmod 777 /home
RUN chmod 777 /home/.cache
