#include<iostream>
using namespace std;
void insert(int arr[10][2]){
        cout<<"Enter value to be inserted : ";
        int val;
        cin>>val;
        int rem=val%10;
        if(arr[rem][0]==-1){
                arr[rem][0]=val;
        }
        else if(arr[rem][0]!=-1&&arr[rem][1]==-1&&arr[rem][0]%10==rem){
                int ne=rem+1;
                while(arr[ne][0]!=-1){
                        ne=(ne+1)%10;
                }
                arr[rem][1]=ne;
                arr[ne][0]=val;
        }
        else if(arr[rem][0]!=-1&&arr[rem][1]!=-1 && arr[rem][0]%10 == rem){
                int ne1=arr[rem][1];
                int ne2;
                while(ne1!=-1){
                        ne2=ne1;
                        ne1=arr[ne1][1];
                }
                int re=ne2;
                if(arr[ne2][0]!=-1){
                        while(arr[ne2][0]!=-1){
                                ne2=(ne2+1)%10;
                        }
                }
                arr[ne2][0]=val;
                arr[re][1]=ne2;
        }
        else{
                //with replacement
                int idx = val%10;
                int p = arr[idx][0]%10;
                int prev = p;
                while(arr[p][1] != idx){
                        // cout<<arr[p][0]<<" - "<<arr[p][1]<<endl;
                        p = arr[p][1];
                        prev = p;
                }
                int ne2 = p;
                while(arr[ne2][0]!=-1){
                                ne2=(ne2+1)%10;
                        }
                arr[ne2][0] = arr[idx][0];
                arr[prev][1] = ne2;
                arr[idx][0] = val;
                arr[idx][1] = -1;
 
        }       
}
void display(int arr[10][2]){
        cout<<endl;
        for(int i=0;i<10;i++){
                cout<<"("<<arr[i][0]<<","<<arr[i][1]<<") ";
        }
        cout<<endl;
}
int main(){
        int arr[10][2];
        for(int i=0;i<10;i++){
                arr[i][0]=-1;
                arr[i][1]=-1;
        }
        int a=10;
        while(a--){
                insert(arr);
                display(arr);
        }
}