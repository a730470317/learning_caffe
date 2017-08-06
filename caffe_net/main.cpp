#include <vector>
#include <iostream>
#include <caffe/blob.hpp>
#include <caffe/net.hpp>
#include <caffe/util/io.hpp>
using namespace caffe;
using namespace std;

// display the blob
template<typename T> 
void display(Blob<T> &a)
{
    cout << "====================================="<<endl;
    for(int u = 0; u < a.num(); u++)
    {
        for(int v = 0; v < a.channels(); v++)
        {
            for(int w = 0; w < a.height(); w++)
            {
                for(int x = 0; x < a.width(); x++)
                {
                    cout<<"a["<<u<<"]["<<v<<"]["<<w<<"]["<<x<<"] = "<< 
a.data_at(u, v, w, x)<<endl;
                }
            }
        }
    }
}

int main(void)
{
    std::srtring proto("deploy.prototxt");
    
}