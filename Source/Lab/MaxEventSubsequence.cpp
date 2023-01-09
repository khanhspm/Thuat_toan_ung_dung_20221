#include <bits/stdc++.h>
using namespace std;
int vt;
 
//Hàm quy hoạch động
int QHD(int a[], int n)
{
    int temp=0,                     //Biến temp hiểu là biến sum(tổng tạm thời),
        maxsum=0;                      // maxsum là tổng trọng số dãy con lớn nhất tìm được
    for(int i=0;i<n;i++)
    {
//Nếu temp < 0 thì gắn => đoạn đó có tổng nhỏ hơn 0 nên ta gắn lại temp = 0 để bắt đầu tính tổng từ vị trí tiếp theo
//Ngược lại ta cộng dồn  temp+=a[i]
        temp+a[i]<0?temp=0:temp+=a[i];
 
//Nếu temp mà lớn hớn maxsum trước đó tìm được
        if(temp > maxsum){
            maxsum = temp;vt=i; //Gắn lại maxsum và vị trí kết thúc của dãy con
        }
    }
    return maxsum;
}

void input(int n, int a[]){
    
}

int main ()
{
   
    int a[]={-5,0,-4,1,5,-2,5};
    int n = sizeof(a)/4;
     
     
    int sum = QHD(a,n); //Gọi  uy hoạch động với dãy a
 
//In ra tổng trọng số
    cout<<sum<<endl;
 
/*Vì ta chỉ lưu vị trí dãy con kết thúc nên ta sẽ duyệt mảng a từ vị trí đó
ngược lại qua đầu mảng và in ra từng phần tử, trừ dần đi phần tử đến khi nào sum = 0 thì tức là tổng
trọng số ta tính từ đoạn đó trở đi
*/
    while(sum>0)
    {
        cout<<a[vt]<<" ";
        sum-=a[vt];vt--;
    }
return 0;
}