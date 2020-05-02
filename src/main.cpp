#include <spdlog/spdlog.h>

#include <iostream>

auto main([[maybe_unused]] int argc, [[maybe_unused]] const char **argv) -> int
{
  //Use the default logger (stdout, multi-threaded, colored)
  spdlog::info("Hello, {}!", "World");

  fmt::print("Hello, from {}\n", "{fmt}");
}
