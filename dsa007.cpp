#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct QLVatTu{
    string ma;
    string ten;
    int soLuong;
    double donGia;
    double thanhTien;
    string phanLoai;
};

struct Node
{
    QLVatTu data;
    Node * next;
};
struct List
{
    Node * head;
    Node*tail;
};
//KHoi tao
void khoiTao(List &l){
l.head= NULL;
l.tail=NULL;
}
//Tao nut
Node * taoNode(QLVatTu vt){
Node*p=new Node;
p->data=vt;
p->next=NULL;
return p;
}
//Them cuoi
void themCuoi(List &l,QLVatTu vt){
Node*p=taoNode(vt);
if (l.head==NULL){
    l.head=p;
    l.tail=p;
}
else{
    l.tail->next=p;
    l.tail=p;
}
}
void duyetIn(List &l){
    Node*p=l.head;
    if (p==NULL){
        cout<<"Danh sach trong"<<endl;

    }
    cout<<left<<setw(10)<<"Ma VT"<<setw(25)<<"Ten VT"<<setw(5)<<"SL"<<setw(10)<<"Don gia"<<setw(10)<<"Thanh tien"<<setw(5)<<"PL"<<endl;
    while(p->next!=NULL){
        cout<<left<<setw(10)<<p->data.ma<<setw(25)<<p->data.ten<<setw(5)<<p->data.soLuong<<setw(10)<<p->data.donGia<<setw(10)<<p->data.thanhTien<<setw(5)<<p->data.phanLoai<<endl;
        p=p->next;
    }
}
int demNut(List l){
    int dem=0;
    Node*p=l.head;
    while(p!=NULL){
        dem++;
        p=p->next;
    }
    return dem;

}
QLVatTu nhapVT(){
QLVatTu vt;
cout<<"Ma VT: ";
getline(cin,vt.ma);
cout<<"Ten`VT: ";
getline(cin,vt.ten);
cout<<"So luong nhap: ";
cin>>vt.soLuong;
cout<<"Don gia nhap: ";
cin>>vt.donGia;
cin.ignore();
vt.thanhTien=vt.soLuong*vt.donGia;
do{
    cout<<"Ma kho (K1/K2/K3): ";
    getline(cin,vt.phanLoai);
}while(vt.phanLoai!="K1"&&vt.phanLoai!="K2"&&vt.phanLoai!="K3");
return vt;

}
void nhapDS(List l){
int n;
cout<<"Nhap so vat tu: ";
cin>>n;
cin.ignore();
for (int i=0;i<n;i++){
    cout<<"\n Vat tu "<<i+1<<": ";
    QLVatTu vt= nhapVT();
    themCuoi(l,vt);

}
}
//-------------
//dang lam nhe
//them o nho vao dau
void ThemDau(List &l, QLVatTu vt) {
    Node *p = taoNode(vt);
    if (l.head != NULL) {
        p->next = l.head;
        l.head = p;
    } else {
        l.head = l.tail = p;
    }
}

//thêm sau
void ThemSau(List &l, Node *q, QLVatTu vt) {
    if (q == NULL) return;

    Node *p = taoNode(vt);
    p->next = q->next;
    q->next = p;
    if (q == l.tail) {
        l.tail = p;
    }
}

//chend có thứ tự
void ThemCoThuTu(List &l, QLVatTu vt) {
    Node *p = taoNode(vt);
    if (l.head == NULL || vt.thanhTien <= l.head->data.thanhTien) {
        p->next = l.head;
        l.head = p;
        if (l.tail == NULL) {
            l.tail = p;
        }
        return;
    }

    Node *q = l.head;
    while (q->next != NULL && q->next->data.thanhTien < vt.thanhTien) {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
    if (p->next == NULL) {
        l.tail = p;
    }
   
}