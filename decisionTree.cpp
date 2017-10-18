#include<iostream>
#include <sstream>
#include <string>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
int arr[100][100000]={0};
int arr1[100][100000]={0};
int arr2[100][100000]={0};
struct db {
    int year;
	string age;
    int ed;
    string locality;
    string cod;
};
struct codNode {
	string data;
	struct db *heart;
    struct db *cancer;
    struct db *stroke;
    struct db *other;
};
struct yearNode {
    int data;
    codNode* old;
    codNode* now;
};
struct localityNode {
    string data;
    yearNode* metro;
    yearNode* nonmetro;
    yearNode* all;
};

struct localityNode1 {
    string data;
    codNode* metro;
    codNode* nonmetro;
    codNode* all;
};
struct ageNode1 {
    string data;
    yearNode* working;
    yearNode* senior;
};

struct ageNode {
	string data;
	localityNode1* working;
	localityNode1* senior;
};
db* GetNewNode8(int year,string age,int ed,string locality,string cod,int *count3,int c[],int arr2[][100000]) {
    db* newNode=new db();
    newNode->year=year;
    newNode->age=age;
    newNode->ed=ed;
    newNode->locality=locality;
    newNode->cod=cod;
    arr2[*count3][c[*count3]]=ed;
    c[*count3]=c[*count3]+1;
    return newNode;
}
db* GetNewNode7(int year,string age,int ed,string locality,string cod,int *count2,int b[],int arr1[][100000]) {
    db* newNode=new db();
    newNode->year=year;
    newNode->age=age;
    newNode->ed=ed;
    newNode->locality=locality;
    newNode->cod=cod;
    arr1[*count2][b[*count2]]=ed;
    b[*count2]=b[*count2]+1;
    return newNode;
}
db* GetNewNode6(int year,string age,int ed,string locality,string cod,int *count1,int a[],int arr[][100000]) {
	db* newNode=new db();
    newNode->year=year;
    newNode->age=age;
    newNode->ed=ed;
    newNode->locality=locality;
    newNode->cod=cod;
    arr[*count1][a[*count1]]=ed;
    a[*count1]=a[*count1]+1;
    return newNode;
}
codNode* GetNewNode5(string cod) {
	codNode* newNode = new codNode();
	newNode->data = cod;
	newNode->heart = newNode->cancer = newNode->stroke = newNode->other= NULL;
	return newNode;
}
yearNode* GetNewNode4(int data){
    yearNode* newNode = new yearNode();
    newNode->data=data;
    newNode->old = newNode->now = NULL;
}
localityNode1* GetNewNode3(string data) {
    localityNode1* newNode = new localityNode1();
    newNode->data = data;
    newNode->metro  = newNode->nonmetro = newNode->all = NULL;
    return newNode;
}
localityNode* GetNewNode2(string data) {
    localityNode* newNode = new localityNode();
    newNode->data = data;
    newNode->metro  = newNode->nonmetro = newNode->all = NULL;
    return newNode;
}
ageNode1* GetNewnode1(string data){
    ageNode1* newNode = new ageNode1();
    newNode->working = newNode->senior = NULL;
    return newNode;
}
ageNode* GetNewNode(string data) {
	ageNode* newNode = new ageNode();
	newNode->data = data;
	newNode->working  = newNode->senior = NULL;
	return newNode;
}
db* Insert20(db* root11,int year,string age,int ed,string locality,string cod,int *count3,int c[],int arr2[][100000])
{
    root11=GetNewNode6(year,age,ed,locality,cod,count3,c,arr2);
    return root11;
}
db* Insert19(db* root11,codNode* root8,int year,string age,int ed,string locality,string cod,int *count3,int c[],int arr2[][100000])
{
    if(cod.compare("Heart Disease")==0){
        root8->heart=Insert20(root11,year,age,ed,locality,cod,count3,c,arr2);
        root11=root8->heart;
    }
    else if(cod.compare("Cancer")==0){
        *count3=*count3+1;
        root8->cancer=Insert20(root11,year,age,ed,locality,cod,count3,c,arr2);
        root11=root8->cancer;
    }
    else if(cod.compare("Stroke")==0){
        *count3=*count3+2;
        root8->stroke=Insert20(root11,year,age,ed,locality,cod,count3,c,arr2);
        root11=root8->stroke;  
    }
    else{
        *count3=*count3+3;
        root8->other=Insert20(root11,year,age,ed,locality,cod,count3,c,arr2);
        root11=root8->other;
    }
    return root11;
}
db* Insert18(db* root10,int year,string age,int ed,string locality,string cod,int *count2,int b[],int arr1[][100000])
{
    root10=GetNewNode7(year,age,ed,locality,cod,count2,b,arr1);
    return root10;
}
db* Insert17(db* root10,codNode* root7,int year,string age,int ed,string locality,string cod,int *count2,int b[],int arr1[][100000])
{
    if(cod.compare("Heart Disease")==0){
        root7->heart=Insert18(root10,year,age,ed,locality,cod,count2,b,arr1);
        root10=root7->heart;
    }
    else if(cod.compare("Cancer")==0){
        *count2=*count2+1;
        root7->cancer=Insert18(root10,year,age,ed,locality,cod,count2,b,arr1);
        root10=root7->cancer;
    }
    else if(cod.compare("Stroke")==0){
        *count2=*count2+2;
        root7->stroke=Insert18(root10,year,age,ed,locality,cod,count2,b,arr1);
        root10=root7->stroke;  
    }
    else{
        *count2=*count2+3;
        root7->other=Insert18(root10,year,age,ed,locality,cod,count2,b,arr1);
        root10=root7->other;
    }
    return root10;
}
db* Insert16(db* root9,int year,string age,int ed,string locality,string cod,int *count1,int a[],int arr[][100000])
{
    root9=GetNewNode6(year,age,ed,locality,cod,count1,a,arr);
    return root9;
}
db* Insert15(db* root9,codNode* root6,int year,string age,int ed,string locality,string cod,int *count1,int a[],int arr[][100000])
{
    if(cod.compare("Heart Disease")==0){
        root6->heart=Insert16(root9,year,age,ed,locality,cod,count1,a,arr);
        root9=root6->heart;
    }
    else if(cod.compare("Cancer")==0){
        *count1=*count1+1;
        root6->cancer=Insert16(root9,year,age,ed,locality,cod,count1,a,arr);
        root9=root6->cancer;
    }
    else if(cod.compare("Stroke")==0){
        *count1=*count1+2;
        root6->stroke=Insert16(root9,year,age,ed,locality,cod,count1,a,arr);
        root9=root6->stroke;  
    }
    else{
        *count1=*count1+3;
        root6->other=Insert16(root9,year,age,ed,locality,cod,count1,a,arr);
        root9=root6->other;
    }
    return root9;
}
codNode* Insert14(codNode* root8 , string cod){
    root8 = GetNewNode5(cod);
    return root8;
}
codNode* Insert13(codNode* root8,yearNode* root5,int data, string cod,int *count3,int c[],int arr2[][100000])
{
    if(data<=2010){
        root5->old = Insert14(root8,cod);
        root8=root5->old;
    }
    else
    {
        *count3=*count3+4;
        root5->now = Insert14(root8,cod);
        root8=root5->now;
    }
    return root8;
}
codNode* Insert12(codNode* root7 , string cod){
    root7 = GetNewNode5(cod);
    return root7;
}
codNode* Insert11(codNode* root7,yearNode* root4,int data, string cod,int *count2,int b[],int arr1[][100000])
{
    if(data<=2010){
        root4->old = Insert12(root7,cod);
        root7=root4->old;
    }
    else
    {        
        *count2=*count2+4;
        root4->now = Insert12(root7,cod);
        root7=root4->now;
    }
    return root7;
}
codNode* Insert10(codNode* root6 ,string cod){
    root6 = GetNewNode5(cod);
    return root6;
}
codNode* Insert9(codNode* root6,localityNode1* root3,string data, string cod,int *count1,int a[],int arr[][100000])
{
    if(data.compare("Metropolitan") == 0){
        root3->metro = Insert10(root6,cod);
        root6=root3->metro;
    }
    else if(data.compare("Nonmetropolitan")==0){
        *count1=*count1+4;
        root3->nonmetro = Insert10(root6,cod);
        root6=root3->nonmetro;
    }
    else
    {
        *count1=*count1+8;
        root3->all = Insert10(root6,cod);
        root6=root3->all;
    }
    return root6;
}
yearNode* Insert8(yearNode* root5,int year) {
    root5 = GetNewNode4(year);
    return root5;
}
yearNode* Insert7(yearNode* root5,localityNode* root2,string data,int year,int *count3,int c[],int arr2[][100000])
{
    if(data.compare("Metropolitan") == 0) {
        root2->metro = Insert8(root5,year);
        root5=root2->metro;
    }
    else if(data.compare("Nonmetropolitan")==0){
        *count3=*count3+8;
        root2->nonmetro = Insert8(root5,year);
        root5=root2->nonmetro;
    }

    else{
        *count3=*count3+16;
        root2->all = Insert8(root5,year);
        root5=root2->all;
    }
    return root5;
}
yearNode* Insert6(yearNode* root4,int year) {
    root4 = GetNewNode4(year);
    return root4;
}
yearNode* Insert5(yearNode* root4,ageNode1* root1,string data,int year,int *count2,int b[],int arr1[][100000])
{
    if(data.compare("0-49") == 0) {
        root1->working = Insert6(root4,year);
        root4=root1->working;
    }

    else{
        *count2=*count2+8;
        root1->senior = Insert6(root4,year);
        root4=root1->senior;
    }
    return root4;
}
localityNode1* Insert4(localityNode1* root3,string locality) {
    root3 = GetNewNode3(locality);
    return root3;
    }
localityNode1* Insert3(localityNode1* root3,ageNode* root,string data,string locality,int *count1,int a[],int arr[][100000]){
    if(data.compare("0-49") == 0) {
		root->working = Insert4(root3,locality);
		root3=root->working;
	}

	else{
        *count1=*count1+12;
        root->senior = Insert4(root3,locality);
        root3=root->senior;
	}
	return root3;
}
localityNode* Insert2(localityNode* root2, string data){
    root2=GetNewNode2(data);
    return root2;
}
ageNode1* Insert1(ageNode1* root1, string data){
    root1=GetNewnode1(data);
    return root1;
}
ageNode* Insert(ageNode* root,string data) {
    root = GetNewNode(data);
	return root;
}
void split(const string &s, char delim, string elems[])
{
    stringstream ss(s);
    string item;
    int i = 0;
    while (getline(ss, item, delim))
    {
            elems[i++] = item;
    }
}
int stoi(string s)
{
    int l= s.length();
    int k=0;
    for(int i=0;i<l;i++)
    {
        k=k*10+(s[i]-48);
    }
    return k;
}
int main() {
    ifstream infile("cod.txt");
    string line;
    string columns[12];
    int s=1,z=0,count1,count2,count3,a[100]={0},b[100]={0},c[100]={0};
    while (getline(infile, line))
    {
        split(line,',', columns);
        if(s==1){     
            s=0;
            continue;
        }   
        int year=stoi(columns[0]);
        string age=columns[5];
        int ed=stoi(columns[11]);
        string locality=columns[7];
        string cod=columns[1];
        ageNode* root = NULL;
        ageNode1* root1 = NULL;
        localityNode* root2=NULL;
        localityNode1* root3=NULL;
        yearNode* root4 =NULL;
        yearNode* root5=NULL;
        codNode* root6=NULL;
        codNode* root7=NULL;
        codNode* root8=NULL;
        db* root9=NULL;
        db* root10=NULL;
        db* root11=NULL;
        count1=0;
        count2=0;
        count3=0;
        root = Insert(root,age);
        root1 = Insert1(root1,age);
        root2 = Insert2(root2,locality);
        root3 = Insert3(root3,root,age,locality,&count1,a,arr);
        root4 = Insert5(root4,root1,age,year,&count2,b,arr1);
        root5 = Insert7(root5,root2,locality,year,&count3,c,arr2);
        root6 = Insert9(root6,root3,locality,cod,&count1,a,arr);
        root7 = Insert11(root7,root4,year,cod,&count2,b,arr1);
        root8 = Insert13(root8,root5,year,cod,&count3,c,arr2);
        root9 = Insert15(root9,root6,year,age,ed,locality,cod,&count1,a,arr);
        root10 = Insert17(root10,root7,year,age,ed,locality,cod,&count2,b,arr1);
        root11 = Insert19(root11,root8,year,age,ed,locality,cod,&count3,c,arr2);
    }
    int er,l,p=0,c1=0,c2=0,c3=0,p1=0,p2=0,p3=0,v;
    float percent;
    for(er=0;er<24;er++)
    {
        while(p<a[er]&&p<c[er])
        {
            if(arr[er][p]<arr2[er][p])
            {
                c1++;
                p1++;
            }
            else if(arr[er][p]>arr2[er][p])
            {
                p3++;
            }   c3++;
            p++;
        }
    }
    if(c1>c3)
    {
        percent=p1/(float)(p1+p3);
        percent=percent*100;
        v=1;
        cout<<"C1 beats C3 by "<<percent<<"%\n";
        p=0;
        p1=0;
        l=1;
        c1=0;
        for(er=0;er<16;er++)
        {
            while(p<a[er]&&p<b[er])
            {
                if(arr[er][p]<arr2[er][p])
                    {
                        c1++;
                        p1++;
                    }
                else if(arr[er][p]>arr2[er][p])
                    {
                        p2++;
                        c2++;
                    }
                p++;
            }
        }
    }
    else
    {
        v=3;
        percent=p3/(float)(p1+p3);
        percent=percent*100;
        cout<<"C3 beats C1 by "<<percent<<"%\n";
        p=0;
        p3=0;
        l=3;
        c3=0;
        for(er=0;er<16;er++)
        {
            while(p<b[er]&&p<c[er])
            {
                if(arr1[er][p]<arr2[er][p])
                    {
                        c2++;
                        p2++;
                    }
                else if(arr1[er][p]>arr2[er][p])
                    {
                        c3++;
                        p3++;
                    }
                p++;
            }
        }
    }
    if(l<c2)
    {
        if(v==1)
        {
            percent=p2/(float)(p1+p2);
        }
        else
            percent=p2/(float)(p2+p3);
        percent=percent*100;
        cout<<"C"<<2<<" beats C"<<v<<" by "<<percent<<"%";   
    }
    else
    {
        if(v==1)
        {
            percent=p1/(float)(p1+p2);
        }
        else
            percent=p3/(float)(p2+p3);
        percent=percent*100;
        cout<<"C"<<v<<" beats C"<<2<<" by "<<percent<<"%";
    }   

    return 0;
}