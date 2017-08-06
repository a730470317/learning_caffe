#include <vector>
#include <iostream>
#include <caffe/blob.hpp>
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
                    cout<<"a["<<u<<"]["<<v<<"]["<<w<<"]["<<x<<"] = "<< a.data_at(u, v, w, x)<<endl;
                }
            }
        }
    }
}

int main(void)
{
    cout << "Hello "<<endl;
    Blob<float > a;
    cout << "Size : "<<a.shape_string() << endl;
    a.Reshape(1,2,3,4);
    cout << "Size : "<<a.shape_string() << endl;
    // 续上面代码
    float * p = a.mutable_cpu_data();
    float * q = a.mutable_cpu_diff();
    display(a);
    for(int i = 0; i < a.count(); i++)
    {
        p[i] = i;
        q[i] = a.count()-1-i;
    }
    display(a);
    a.Update();
    display(a);
    cout << "ASUM =  " <<a.asum_data()<<endl;
    cout << "SUMSQ =  " <<a.sumsq_data()<<endl;
    //
    BlobProto bp;
    a.ToProto(&bp,true);
    caffe::WriteProtoToBinaryFile(bp,"blob_bin.txt");
    caffe::WriteProtoToTextFile(bp,"blob_txt.txt");
    //     WriterProtoToBinaryFile(bp,"a.blob");
    //
    Blob<float> b;
    BlobProto bp_b;
    caffe::ReadProtoFromTextFile("blob_txt.txt",&bp_b);
    b.FromProto(bp_b);
    display(b);
    getchar();
    return 0;
}