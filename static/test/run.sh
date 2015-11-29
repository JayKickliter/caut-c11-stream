#!/bin/sh

OUT_BIN="caut_test"
CFLAGS="-Wall -Wextra -Werror --std=c11 -pedantic"
INCLUDES="-Igenerated/"

stack build
stack exec cauterize -- --schema caut_test.schema --output caut_test.spec
stack exec caut-c11-stream -- --spec caut_test.spec --output generated

clang ${CFLAGS} ${INCLUDES} -o ${OUT_BIN} \
      generated/caut_test_descriptors.c \
      generated/cauterize.c \
      generated/cauterize_descriptors.c \
      generated/cauterize_iterators.c \
      test_main.c

if [ $? -eq 0 ]; then
    ./${OUT_BIN};
    exit 0;
else
    echo Build failed.;
    exit 100;
fi