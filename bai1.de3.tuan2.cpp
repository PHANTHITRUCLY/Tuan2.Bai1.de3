#include"stdio.h"
#include"conio.h"
#include"iostream"
using namespace std;
#define kt 10

int thutu=2;

int trangthai[kt];


int n=10;
//int a[kt][kt]={ 0,0,0,1,0,
//			  1,0,1,1,1,
//			  0,0,0,0,1,
//			  0,0,0,0,0,
//			  0,0,0,0,0 };
	
int a[kt][kt] = {0,0,0,0,0,0,0,0,0,0,
				 1,0,0,0,0,0,0,0,0,0,
			 	 0,0,0,0,0,0,0,0,0,0,
				 0,0,0,0,0,0,0,0,0,0,
				 0,0,0,0,0,0,0,0,0,0,
				 0,0,1,0,0,0,1,1,1,1,
				 0,0,1,0,0,0,0,0,0,0,
			   	 0,0,1,0,0,0,0,0,0,0,
			 	 0,0,0,0,1,0,0,0,0,0,
				 0,0,0,0,1,0,0,0,0,0};


void XuatMT(int a[kt][kt],int n){
	
	for(int i= 0; i < n; i++){
		for(int j=0; j < n; j++){
		cout<<a[i][j];
		cout<<"\t";
		}
		cout<<"\n";
	}
	
}


void xoacung(int j){
	int k;
	for (k=0; k<=n; k++)
	 a[j][k]=0;
	
}

void ghinhan(int j,int &thutu){

	trangthai[j]=thutu;
	thutu+=1;
	xoacung(j);
}
// ham tra ve dinh ko co cung den, tra lai -1 neu ko co dinh
int dinhkd(int a[kt][kt], int n){ // dinh ko den
	int j=0,i;
	 int ktra=0;
	 while(j<=n){
	 	
		ktra=0;
		for(i=0; i<=n; i++)
			ktra = a[i][j] + ktra;
			if((ktra==0) && (trangthai[j]==0)) {
				ghinhan(j,thutu);
				return j;}
				j=j+1;
			}
	   return -1;
}


void kiemtra(int trangthai[kt],int n){
	int k,dem=0;
	for(k=0; k<=n; k++)
	if(trangthai[k]!=0)
	dem+=1;
	if(dem!=n+1) printf("\n Khong sap xep  Topo \n");
	else{
	
	for(k=2; k<=n+2; k++)
	 for(int i=0; i<n; i++)
	 if(trangthai[i]==k)
	  cout<<" "<<i;  //printf("%3d,i");
	 }
}
	

int main(){
	
 	int dinh;
 	int sddc=0;
 	
 		XuatMT(a,n);
 	
 	do {
 		dinh=dinhkd(a,n);
 		
 		if((dinh!=-1 )&& (sddc<=n)){
		 
 		  if(trangthai[dinh]!=0)
 			sddc+=1;
 		  }
				 
	 }while((dinh!=-1) && (sddc<=n));
	 
	 kiemtra(trangthai,n);

	
	cout<<"\n Xuat MT:\n";
	XuatMT(a,n);

	
	getch();
	
}
