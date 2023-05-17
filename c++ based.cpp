
#include <opencv2/opencv.hpp>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    // Define the target dimensions
    int targetWidth = 800;
    int targetHeight = 600;

    // Specify the directory paths
    std::string sourceDirectory = "C:/Users/admin/Downloads/OpenCv projects/Experiment";
    std::string targetDirectory = "C:/Users/admin/Downloads/OpenCv projects/Experiment/New";

    // Create the target directory if it doesn't exist
    fs::create_directories(targetDirectory);

    // Iterate through the files in the source directory
    for (const auto& entry : fs::directory_iterator(sourceDirectory)) {
        if (entry.path().extension() == ".png") {
            // Load the image
            cv::Mat image = cv::imread(entry.path().string(), cv::IMREAD_UNCHANGED);

            // Resize the image
            cv::resize(image, image, cv::Size(targetWidth, targetHeight));

            // Generate the target file path
            std::string targetPath = targetDirectory + "/" + entry.path().filename().string();

            // Save the resized image to the target directory
            cv::imwrite(targetPath, image);
        }
    }

    std::cout << "Image resizing and saving complete!" << std::endl;

    return 0;
}
