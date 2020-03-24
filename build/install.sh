#!/bin/sh
cd "${0%/*}"
if [ "$(id -u)" != "0" ]; then
  echo "Error: Execute with sudo."
else
  rm -rf /usr/local/include/PhQ
  mkdir -p -m 755 /usr/local/include/PhQ
  cp -r ../lib/* /usr/local/include/PhQ/.
  echo "Copied library headers to: /usr/local/include/PhQ"
fi

