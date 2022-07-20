#include <iostream>
#include <pcl/io/pcd_io.h>  
#include <pcl/point_types.h>  
#include <pcl/filters/voxel_grid.h>

using namespace std;

void pclDownsize(pcl::PointCloud<pcl::PointXYZ>::Ptr in, pcl::PointCloud<pcl::PointXYZ>::Ptr out)
{
    pcl::VoxelGrid<pcl::PointXYZ> down_filter;
    float leaf = 0.1;
    down_filter.setLeafSize(leaf, leaf, leaf);
    down_filter.setInputCloud(in);
    down_filter.filter(*out);
}


int main(int argc, char *argv[])
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out(new pcl::PointCloud<pcl::PointXYZ>);
    // Fill in the cloud data  
    if (pcl::io::loadPCDFile<pcl::PointXYZ>("/home/zhangyuhe/pcd2txt/src/f_2022-06-14-10-01-47-830.pcd", *cloud) == -1)
    {
        PCL_ERROR("Couldn't read file chuli.pcd\n");
        return (-1);
    }
    // pclDownsize(cloud,cloud_out);

    cout << "points cloud is successfully loaded! " << endl;
    //for (size_t i = 0; i < cloud->points.size(); i++)
    //  std::cout << " " << cloud->points[i].x << " " << cloud->points[i].y
    //  <<" "<< cloud->points[i].z << std::endl;
    int Num = cloud->points.size();
    double *X = new double[Num] {0};
    double *Y = new double[Num] {0};
    double *Z = new double[Num] {0};
    cout << "size is : " << cloud->points.size() << endl;
    for (size_t i = 0; i <  cloud->points.size(); ++i)
    {
        X[i] = cloud->points[i].x;
        Y[i] = cloud->points[i].y;
        Z[i] = cloud->points[i].z ; 
        cout << "first  " << i << " of " << Num << endl;
    }

    
    ofstream zos("f_2022-06-14-10-01-47-830.txt");
    for (int i = 0; i< cloud->points.size(); i++)
    {
        zos << X[i] << " " << Y[i] << " " << Z[i] << endl;
        cout << "second  " << i << " of " << Num << endl;
    }
    cout << "trans has done!!!" << endl;
    // cin.get();
    return 0;
}


