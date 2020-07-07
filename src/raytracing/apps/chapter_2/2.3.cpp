#include <iostream>

auto main() -> int
{
    const int image_width = 256;
    const int image_height = 256;

    constexpr static double kBlue = 0.25;
    constexpr static double k256 = 255.999;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >=0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = kBlue;

            int ir = static_cast<int>(k256 * r);
            int ig = static_cast<int>(k256 * g);
            int ib = static_cast<int>(k256 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << "\n";
        }
    }
    std::cerr << "\nDone.\n";
}