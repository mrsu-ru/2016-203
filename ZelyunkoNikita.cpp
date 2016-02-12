#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main(){
float a=0;
float z=pow(10,9);
for(double i=1;i<=z;i++){
a+=float(1/pow(i,2));

}
cout<<a<<endl;
a=0;
for(double i=z;i>=1;i--){
a+=float(1/pow(i,2));
}
cout<<a<<endl;
return(0);
}
