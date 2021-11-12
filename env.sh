#!/bin/bash

#
# Source this files to setup the environment needed by this SDK
#

export SUMERU_DIR="$( cd -- "$(dirname "${BASH_SOURCE}")" >/dev/null 2>&1 ; pwd -P )"

export PATH=${PATH}:${SUMERU_DIR}/bin
export PATH=${PATH}:${SUMERU_DIR}/riscv-gnu-toolchain/bin

export SUMERU_UART_DEVICE=/dev/ttyUSB0


grep "SETME" $SUMERU_DIR/conf/static-binary-link.lds > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "Setting SDK path in linker script: conf/static-binary-link.lds"
    a=`echo $SUMERU_DIR | sed -e 's/\//\\\\\//g'`
    sed -i -e "s/SETME/${a}/g" $SUMERU_DIR/conf/static-binary-link.lds
fi
