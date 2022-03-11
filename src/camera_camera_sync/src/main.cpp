#include "camera_camera_sync/camera_camera_sync.hpp"

int main()
{

    CameraCameraSync camera_camera_sync_;

    std::string oriDirs = "/home/guoxs/Documents/ad_sensor_fusion/data/multi_camera_sync/camera_front_left_60";
    std::string dstDirs = "/home/guoxs/Documents/ad_sensor_fusion/data/multi_camera_sync/camera_front_right_60";
    // camera_camera_sync_.getImageTimeStamp(oriDirs, dstDirs);
    // std::vector<std::pair<std::string, std::string> > syncImageLists;
    // int number = camera_camera_sync_.getImageNumber();
    // if (number > 0)
    // {
    //     syncImageLists = camera_camera_sync_.imageTimeStampSyncFuncion();
    // }
    
    std::string image_path1 = oriDirs + "/1625565990.266761.png";
    std::string image_path2 = dstDirs + "/1625565990.266677.png";
    cv::Mat image1 = cv::imread(image_path1, cv::IMREAD_GRAYSCALE);
    cv::Mat image2 = cv::imread(image_path2, cv::IMREAD_GRAYSCALE);
    if( !image1.data || !image2.data )
    { 
        std::cout<< " --(!) Error reading images " << std::endl; 
        return -1;
    }
    
    camera_camera_sync_.spatialSynchronization(image1, image2);

    // for(auto syncPair : syncImageLists)
    // {
    //     cv::Mat image1 = cv::imread(syncPair.first, cv::IMREAD_GRAYSCALE);
    //     cv::Mat image2 = cv::imread(syncPair.second, cv::IMREAD_GRAYSCALE);
    //     if( !image1.data || !image2.data )
    //     { 
    //         std::cout<< " --(!) Error reading images " << std::endl; 
    //         return -1;
    //     }
        
    //     camera_camera_sync_.spatialSynchronization(image1, image2);
    // }

}
