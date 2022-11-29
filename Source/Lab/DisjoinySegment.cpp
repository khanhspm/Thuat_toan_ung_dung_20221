#include<bits/stdc++.h>
using namespace std;

int n;
int a[], b[], c[];

void swap(int &x, int &y){
    int t = x;
    x = y; 
    y = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // khai báo phần tử đánh dâu pivot
    int left = low;   //khai báo biến bên trái
    int right = high - 1; //khai báo biến bên phải
    while(true){
        while(left <= right && arr[left] < pivot) left++; // tìm phần tử >= phần tử pivot trong mảng
        while(right >= left && arr[right] > pivot) right--; // tìm phần tử <= phần tử pivot trong mảng
        if (left >= right) break; // sau khi duyệt xong thì thoát khỏi vòng lặp
        swap(arr[left], arr[right]); // nếu chưa xong thì sử dụng hàm swap() để tráo đổi.
        swap(a[left],b[left]);
        left++; // Vì left hiện tại đã xét, nên cần tăng
        right--; // Vì right hiện tại đã xét, nên cần giảm
    }
    swap(arr[left], arr[high]);
    return left; // Trả về chỉ số sẽ dùng để chia đôi mảng
}
  
/* Hàm thực hiện giải thuật quick sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // index là chỉ số nơi phần tử này đã đứng đúng vị trí và đây là phần tử chia mảng làm 2 mảng con trái & phải 
        int index = partition(arr, low, high);
  
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }
}

void DisSeg (int a1[], int a2[], int a3[]){
    for(int i = 0; i < n; i++){
        if(a1[i] == a[0]){
            for(int j = 0; j < n; j++){
                
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        c[i] = b[i] = a[i];
    }
    quickSort(c, 0, n);
}