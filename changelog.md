# PBL2
15/10/2021
- chuyển các mảng đối tượng thành vector
- Tách hàm createSanPham thành createSanPham và WriteToFileMayTinh(ghi vào file).
- Hàm createSanPham đầu tiên sẽ tăng kích thước vector (đang xem xét cách tăng) -> nhập đối tượng cuối cùng trong vector -> ghi đối tượng đó vào file -> tăng count lên 1
- Trong hàm ReadSanPham, thực hiện kiểm tra biến đầu tiên của mỗi hàng, nếu biến đó có độ dài <=1 thì break hoặc continue => kết thúc đọc file khi gặp dòng trống (mục đích là vì trước eof/end of file có thể có nhiều dòng trống khiến cho việc đọc dữ liệu bị lỗi)
- Thêm hàm sửa dữ liệu và xóa dữ liệu. PP như trong báo cáo.
