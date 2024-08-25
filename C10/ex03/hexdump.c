#include "hexdump.h"

void hexdump_stdin() {}

int main(int argc, char **argv) {
  if (argc < 2)
    hexdump_stdin();

  hexdump(argc, argv);
}
