#!/bin/sh
cd "${0%/*}"
if [ "$(id -u)" != "0" ]; then
  echo "Error: Execute with sudo."
else
  rm -rf /usr/local/include/PhQ
  echo "Removed library headers from: /usr/local/include/PhQ"
fi

