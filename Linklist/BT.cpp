#include<iostream>
#include<string>
using namespace std;

// 1. định nghĩa cấu trúc sinh viên
struct SinhVien
{
	int ma;
	string hoten;
	float diemTB;
	string loai;
};

// hàm hỗ trợ in thông tin của 1 sinh viên
void inSV(SinhVien sv)
{
	cout << "Ma sv: " << sv.ma << endl;
	cout << "Ho ten: " << sv.hoten << endl;
	cout << "Diem TB: " << sv.diemTB << endl;
	cout << "Xep loai: " << sv.loai << endl;
}

// 2. định nghĩa cấu trúc nút (Node) lưu sinh viên
struct Node
{
	SinhVien data;
	Node* pNext;
};

// hàm khởi tạo 1 nút mới
Node* initNode(SinhVien value)
{
	Node* p = new Node;
	p->data = value;
	p->pNext = NULL;
	return p;
}

// 3. định nghĩa cấu trúc danh sách liên kết (List)
struct List
{
	Node* pHead;
	Node* pTail;
}; // luôn nhớ dấu chấm phẩy ở đây nha

// hàm khởi tạo danh sách rỗng
void initList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

// hàm thêm nút vào đầu danh sách
void addHead(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

// ========================================================
// viết tiếp các hàm từ câu 6 đến câu 12 theo đề bài
// ========================================================

// 6. viết hàm khởi tạo dữ liệu cho danh sách sinh viên
void khoiTaoDanhSachSV(List& dsSV)
{
	SinhVien sv1 = { 123, "Nguyen Van A", 9.1, "Chua xep loai" };
	SinhVien sv2 = { 456, "Nguyen Van B", 4.5, "Chua xep loai" };
	SinhVien sv3 = { 789, "Nguyen Van C", 7.2, "Chua xep loai" };

	addHead(dsSV, initNode(sv1));
	addHead(dsSV, initNode(sv2));
	addHead(dsSV, initNode(sv3));
}

// 7. viết hàm in danh sách sinh viên
void inDanhSachSV(List l)
{
	cout << "\n--- danh sach sinh vien ---" << endl;
	Node* p = l.pHead;
	while (p != NULL)
	{
		inSV(p->data);
		cout << "---------------------------" << endl;
		p = p->pNext;
	}
}

// 8. viết hàm cập nhật xếp loại học lực
void capNhatXepLoai(List& l)
{
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (p->data.diemTB >= 8.0)
			p->data.loai = "Gioi";
		else if (p->data.diemTB >= 6.5)
			p->data.loai = "Kha";
		else if (p->data.diemTB >= 5.0)
			p->data.loai = "Trung binh";
		else
			p->data.loai = "Yeu";

		p = p->pNext;
	}
}

// 9. viết hàm tìm điểm trung bình cao nhất (trả về giá trị float)
float timDiemTBCaoNhat(List l)
{
	if (l.pHead == NULL)
		return 0;

	float maxDiem = l.pHead->data.diemTB;
	Node* p = l.pHead->pNext;

	while (p != NULL)
	{
		if (p->data.diemTB > maxDiem)
		{
			maxDiem = p->data.diemTB;
		}
		p = p->pNext;
	}
	return maxDiem;
}

// 10. viết hàm tìm kiếm sinh viên theo mã sinh viên
Node* timSVTheoMa(List l, int maCanTim)
{
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (p->data.ma == maCanTim)
		{
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}

// 11. viết hàm tìm SV có trung bình cao nhất (trả về Node*)
Node* timSVCoTBCaoNhat(List l)
{
	if (l.pHead == NULL)
		return NULL;

	Node* nodeMax = l.pHead;
	Node* p = l.pHead->pNext;

	while (p != NULL)
	{
		if (p->data.diemTB > nodeMax->data.diemTB)
		{
			nodeMax = p;
		}
		p = p->pNext;
	}
	return nodeMax;
}

// 12. viết hàm tìm SV có điểm trung bình thấp nhất (trả về Node*)
Node* timSVCoTBThapNhat(List l)
{
	if (l.pHead == NULL)
		return NULL;

	Node* nodeMin = l.pHead;
	Node* p = l.pHead->pNext;

	while (p != NULL)
	{
		if (p->data.diemTB < nodeMin->data.diemTB)
		{
			nodeMin = p;
		}
		p = p->pNext;
	}
	return nodeMin;
}
int main()
{
	List l;
	initList(l); // khởi tạo danh sách rỗng

	// câu 6: nạp dữ liệu kiểm thử
	khoiTaoDanhSachSV(l);
	cout << "-> da khoi tao du lieu mau." << endl;

	// câu 7: in danh sách khi chưa xếp loại
	cout << "\n=== danh sach ban dau ===";
	inDanhSachSV(l);

	// câu 8: cập nhật xếp loại học lực dựa trên điểm số
	capNhatXepLoai(l);
	cout << "\n-> da cap nhat xep loai hoc luc." << endl;

	// in lại danh sách sau khi đã cập nhật xếp loại thành công
	cout << "\n=== danh sach sau khi xep loai ===";
	inDanhSachSV(l);

	// câu 9: tìm điểm trung bình cao nhất
	float maxDiem = timDiemTBCaoNhat(l);
	cout << "\ndiem trung binh cao nhat trong lop la: " << maxDiem << endl;

	// câu 10: tìm kiếm sinh viên theo mã số
	int maTim = 456;
	Node* svTimThay = timSVTheoMa(l, maTim);
	if (svTimThay != NULL)
	{
		cout << "\n[thong tin] tim thay sinh vien co ma " << maTim << ":" << endl;
		inSV(svTimThay->data);
	}
	else
	{
		cout << "\nkhong tim thay sinh vien nao co ma: " << maTim << endl;
	}

	// câu 11: tìm và in cả node sinh viên có điểm trung bình cao nhất
	Node* svMax = timSVCoTBCaoNhat(l);
	if (svMax != NULL)
	{
		cout << "\n=== sinh vien co diem tb cao nhat ===" << endl;
		inSV(svMax->data);
	}

	// câu 12: tìm và in cả node sinh viên có điểm trung bình thấp nhất
	Node* svMin = timSVCoTBThapNhat(l);
	if (svMin != NULL)
	{
		cout << "\n=== sinh vien co diem tb thap nhat ===" << endl;
		inSV(svMin->data);
	}

	return 0;
}